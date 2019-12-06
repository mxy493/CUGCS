//【例3.9】显示同名变量可见性的例子。
#include<iostream>
using namespace std;
int n=100;

int main(){
	 int i=200,j=300;
	 cout<< n<<'\t'<<i<<'\t'<<j<<endl;{		//输出全局变量n和外层局部变量i,j
		 int i=500,j=600,n;              //内层块
		 n=i+j;
		 cout<< n<<'\t'<<i<<'\t'<<j<< endl;		//输出内层局部变量n和i,j
		 cout<<::n<<endl;					//输出全局变量n
	 }
	 n=i+j;								//修改全局变量
	 cout<< n<<'\t'<<i<<'\t'<<j<< endl;		//输出全局变量n和外层局部变量i,j
	 return 0;
}
