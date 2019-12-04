// Primes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <time.h>

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
int* curPrimes;//临时保存找到的素数
int k;//素数个数
vector <int> allPrimes;//保存所有素数

int main(int argc, char** argv)
{
	clock_t startTime, endTime;
	startTime = clock();
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

	//calculate prime numbers each process will calculate its own portion
	for (int i = 1; i < n; i++)
		if (isPrime(i))
			curPrimes[k++] = i;
	//add the primes calculated here to our large prime vector
	for (int i = 0; i < k; i++)
		allPrimes.push_back(curPrimes[i]);
	//clear the memory of our primes
	delete[] curPrimes;

	string file_name = "primes.txt";
	cout << "\nOverall " << allPrimes.size() << " primes. " << endl;
	cout << "所有素数将写入到文件 " << file_name << " 中！" << endl;
	//output all primes to a file
	FILE* stream;
	freopen_s(&stream, "primes.txt", "w", stdout);
	for (int i = 0; i < allPrimes.size(); i++)
	{
		cout << allPrimes[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}
	printf("\n");
	freopen_s(&stream, "CON", "w", stdout);
	endTime = clock();
	cout << "Totle Time : " << ((double)endTime - (double)startTime) / CLOCKS_PER_SEC << "s" << endl;
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
