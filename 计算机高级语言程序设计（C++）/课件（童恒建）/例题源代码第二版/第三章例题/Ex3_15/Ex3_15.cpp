//【例3.15】用递归法求解Fibonacii数列。
#include<iostream>
#include<iomanip>
using namespace std;

int fib(int n){
	 if(n==0) return 0;
	 else if(n==1) return 1;
		else return fib(n-1)+fib(n-2);
}
int main(){
	int i;
	for(i=0;i<=19;i++){
		if(i%5==0) cout<<endl;
		cout<<setw(6)<<fib(i);
	 }
	 cout<<endl;
	 return 0;
}
