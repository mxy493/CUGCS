#include <iostream>
using namespace std;
#define M 5                   //进程数量
#define N 3                   //资源种类
int Max[M][N] = { {5,5,9},{5,3,6},{3,0,8},{4,2,5},{4,2,4} };        //各进程对各种资源总的需求量
int Available[N] = { 2,3,3 };                                       //当前系统可用的各种资源量
int Allocation[M][N] = { {2,1,2},{4,0,2},{3,0,5},{2,0,4},{3,1,4} }; //各进程当前已分配到的各类资源
int Need[M + 1][N] = { {3,4,7},{1,3,4},{0,0,3},{2,2,1},{1,1,0} };   //各进程对资源的剩余需求量
int Request[N] = { 0,0,0 };                                         //当前某进程请求的各资源量

void show()   //显示系统现状
{
	cout << "系统可用资源数为:";
	for (int j = 0; j < N; j++) {
		cout << Available[j] << " ";
	}
	cout << endl;
	cout << "各进程的对资源的总需求" << endl;;
	for (int i = 1; i <= M; i++) {
		cout << "进程" << i << ":";
		for (int j = 0; j < N; j++) {
			cout << Max[i - 1][j] << " ";
		}
		cout << endl;
	}
	cout << "各进程已得到的资源" << endl;
	for (int i = 1; i <= M; i++) {
		cout << "进程" << i << ":";
		for (int j = 0; j < N; j++) {
			cout << Allocation[i - 1][j] << " ";
		}
		cout << endl;
	}
	cout << "各进程还需要的资源" << endl;
	for (int i = 1; i <= M; i++) {
		cout << "进程" << i << ":";
		for (int j = 0; j < N; j++) {
			cout << Need[i - 1][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void chang(int i) {    //当请求被允许时，修改系统各参数
	for (int j = 0; j < N; j++) {
		Available[j] = Available[j] - Request[j];
		Allocation[i][j] = Allocation[i][j] + Request[j];
		Need[i][j] = Need[i][j] - Request[j];
	}
}

void rstor(int i) {    //当请求不被允许时，恢复系统各参数
	cout << "该请求将使系统产生死锁，拒绝执行!" << endl;
	for (int j = 0; j < N; j++) {
		Available[j] = Available[j] + Request[j];
		Allocation[i][j] = Allocation[i][j] - Request[j];
		Need[i][j] = Need[i][j] + Request[j];
	}
}

int chkerr() {      //当有请求时，判断是否会使系统产生死锁，若否，输出当前的安全序列
	int Finish[M] = { 0 };
	int Result[M] = { 0 };
	int Work[N];
	int sum = 0;
	for (int i = 0; i < N; i++)
		Work[i] = Available[i];
	while (true) {
		int flag1, flag2 = 0;
		for (int i = 0; i < M; i++) {
			flag1 = 1;
			if (Finish[i] == 0) {
				for (int j = 0; j < N; j++) {
					if (Need[i][j] > Work[j]) flag1 = 0;
				}
				if (flag1) {
					flag2 = 1;
					for (int j = 0; j < N; j++)
						Work[j] = Work[j] + Allocation[i][j];
					Finish[i] = 1;
					Result[sum] = i + 1;
					sum++;
				}
			}
		}
		if (sum == M) {
			cout << "当前系统的安全序列为:";
			for (int i = 0; i < M; i++) {
				cout << Result[i] << " ";
			}
			cout << endl;
			cout << endl;
			return 0;
		}
			return 1;
		}
	}
}

int run(int flag) {   //方便进行循环操作
	int i = 0;
	show();
	if (flag == 1) {
		cout << "输入需申请资源的进程号:";
		cin >> i;
		cout << "请输入进程" << i << "申请的资源数" << endl;
		i--;
		cout << "资源A、B、C:";
		cin >> Request[0] >> Request[1] >> Request[2];
		cout << endl;
		chang(i);
		if (chkerr()) {
			rstor(i);
			show();
		}
		else
			show();
		cout << "是否继续演示银行家算法，1是，0否:";
		cin >> flag;
	}
	return flag;
}
int main() {
	int a = 1;
	a = run(a);
	while (a == 1)
		a = run(a);
	return 0;
}