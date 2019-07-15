//【例2.23】输入一个8位二进制数，将其转换为十进制数输出。

#include<iostream>
using namespace std;

const int n=8;
int main(){
	char bin[n];
	int x=2,a,dec,i;
	cout<<"输入二进制序列："<<endl;
	for(i=n-1;i>=0;i--)  cin>>bin[i];      //先输入的是高位数
	dec=0;	
	for(i=n-1;i>=0;i--){
	      a=bin[i]-'0';		             	//数字字符转换为数字
		  dec= dec*x+a;
	}
	cout<<"二进制序列(";
	for(i=n-1;i>=0;i--)  cout<<bin[i];
	cout<<")的值为:"<<dec<<endl;
	return 0;
}
