//【例2.11】计算1+2+3+…+100的值。

#include <iostream>
using namespace std;

const int n=100; //用常变量利于修改程序
int main(){
	int i=1,sum=0;		 //循环初始条件
	while(i<=n){
		sum+=i;
		i++;			 //修改循环条件
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}
