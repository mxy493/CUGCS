// MPI_Primes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <mpi.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

//checks wheather or not a number is prime with in O(n) time
//判断是否素数
bool isPrime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int n;//上界
int world_size; //number of processes involved in our calculations
int* curPrimes;//the primes that we will calculate in THIS process
int k;//素数个数
int* recvPrimes;//temperary variable for primes the main process will recieve from secondary ones
vector <int> allPrimes;//保存所有素数

int main(int argc, char** argv)
{
	FILE* stream;
	/*
	//打印参数信息
	int x = argc;//传入的参数个数
	printf("传入参数个数: %d\n", x);//格式化输出
	for (int i = 0; i < x; i++)
		cout << "参数" << i + 1 << ": " << argv[i] << endl;
	*/

	//check if we have the right number of arguments
	//只接受除运行程序命令argv[0]外的一个参数argv[1]
	if (argc != 2)
	{
		cout << "Invalid number of arguments" << endl;
		return 0;
	}
	//calculate n as per requrenment
	n = 10000 * atoi(argv[1]);
	//we cant have more than n/2 primes becuase even numbers for sure cant be prime
	//素数不可能超过n/2,因为偶数不可能是素数
	curPrimes = new int[n / 2];//分配n/2空间的数组

	//init mpi
	MPI_Init(NULL, NULL);

	//find out how many processes are there
	//当前有多少个进程
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	//find out which process are we in
	//找出当前所在进程
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	//calculate prime numbers each process will calculate its own portion
	for (int i = n * world_rank / world_size; i < n * (world_rank + 1) / world_size; i++)
		if (isPrime(i))
			curPrimes[k++] = i;
	//if we are not in the main process(process with rank 0) send our prime numbers to main process
	if (world_rank != 0)
	{
		MPI_Send(&k, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Send(curPrimes, k, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	int recvSize;
	if (world_rank == 0)
	{
		//this runs only on main process
		//add the primes calculated here to our large prime vector
		for (int i = 0; i < k; i++)
			allPrimes.push_back(curPrimes[i]);
		//clear the memory of our primes
		delete[] curPrimes;
		//go through all the recieved primes and add them to our vector
		for (int i = 1; i < world_size; i++)
		{
			MPI_Recv(&recvSize, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			cout << "Recieved " << recvSize << " primes\nretrieving" << endl;
			recvPrimes = new int[recvSize];
			MPI_Recv(recvPrimes, recvSize, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			for (int j = 0; j < recvSize; j++)
				allPrimes.push_back(recvPrimes[j]);
			delete[] recvPrimes;
		}

		string file_name = "primes.txt";
		cout << "\nOverall " << allPrimes.size() << " primes. " << endl;
		cout << "所有素数将写入到文件 " << file_name << " 中！" << endl;
		//output all primes to a file
		freopen_s(&stream, "primes.txt", "w", stdout);
		for (int i = 0; i < allPrimes.size(); i++)
		{
			cout << allPrimes[i] << " ";
			if (i % 20 == 0)
				cout << "\n";
		}
		printf("\n");
		freopen_s(&stream, "CON", "w", stdout);
	}
	MPI_Finalize();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
