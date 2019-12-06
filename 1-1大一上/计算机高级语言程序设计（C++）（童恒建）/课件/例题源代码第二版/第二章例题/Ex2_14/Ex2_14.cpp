/*【例2.14】这是一个古罗马数学家伦纳德 斐波那契提出的有趣的问题。假定每对兔子每月生出一对小兔子，
新生的一对小兔子三个月后又可以生小兔子，假定所有兔子都不会死，一年后会有多少对兔子。具体说，第
一个月只有一对兔子，第二个月由于新生小兔子不能生育，仍然只有一对兔子，第三个月小兔子开始生育，因
此当月有两对小兔子，此后每个月的兔子数都是上个月和当月新生兔子数之和。由此可抽象出一个数列：
0,1,1,2,3,5,8,……。这个数列称为Fibonacii数列，
设计程序输出Fibonacii数列的前20项，要求每行输出5个数据。
*/
#include<iostream>
#include<iomanip>
using namespace std;

const int m=20;
int main(){
	int n,fib0=0,fib1=1,fib2;
	cout<<setw(15)<<fib0<<setw(15)<<fib1;
	for(n=3;n<=m;n++){
		fib2=fib0+fib1;
		cout<<setw(15)<<fib2;
		if(n%5==0)  cout<<endl;			//控制每行5个数据
		fib0=fib1;  fib1=fib2;
	}
	return 0;
}
