//【例3.6】 使用局部变量的例子。
#include<iostream>
using namespace std;

void fun(){
	auto int t=5;					// fun()中的局部变量，auto可省略
	cout<<"fun()中的t="<<t<<endl;
}
int main(){
	float t=3.5;					//main()函数中的局部变量
	cout<<"main()中的t="<<t<<endl;
	fun();
	cout<<"main()中的t="<<t<<endl;
	return 0;
}
