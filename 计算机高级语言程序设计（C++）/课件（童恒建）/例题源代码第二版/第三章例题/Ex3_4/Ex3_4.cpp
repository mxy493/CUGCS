//【例3.4】 输出所有满足下列条件的正整数m：10<m<1000且m、m2、m3均为回文数。
#include<iostream>
#include<iomanip>
using namespace std;

bool palindrome(int);						//函数原型
int main(){
	int m;
	cout<<setw(10)<<'m'<<setw(20)<<"m*m"<<setw(20)<<"m*m*m"<<endl;
	for(m=11;m<1000;m++)
		if(palindrome(m)&&palindrome(m*m)&&palindrome(m*m*m))
			cout<<setw(10)<<m<<setw(20)<<m*m<<setw(20)<<m*m*m<<endl;
	return 0;
}
bool palindrome(int n){						//判断回文数
	int digit[10];
	int m=n,i=0;
	do{
		digit[i]=n%10;					    //将各位分离开
		n/=10;
		i++;
	}while(n>0);
	for(int j=0;j<i;j++) n=n*10+digit[j];		//反向装配
	return (n==m);
}
