//【例3.5】 多个函数使用全局变量的例子。
#include<iostream>
using namespace std; 
int n=100;

void func(){
	 n*=2;
}
int main(){
	n*=2;
	cout<<n<<endl;
	func();
	cout<<n<<endl;
	return 0;
}
