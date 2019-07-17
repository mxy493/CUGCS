/*【例2.21】用欧几里德算法（也称辗转法）求两个整数的最大公约数。
假定两个整数分别为num1和num2，最大公约数应当是不超过其中较小数的一个整数。
辗转法的思想是：用num1除以num2，求出余数resd，如果resd==0，则当前num2就是最大公约数，
否则（resd!=0），num1=num2, num2=resd, 重复以上过程，直到resd==0为止。
*/
#include<iostream>
using namespace std;

int main(){
	 int num1,num2,resd;
	 cout<<"输入两个整数："<<endl;
	 cin>>num1>>num2;
	 cout<<num1<<"和"<<num2<<"的最大公约数为：";
	 for(;;){
		resd=num1%num2;
		if(resd==0)  break;
		num1=num2;  num2=resd;
	 }
	 cout<<num2<<endl;
	 return 0;
}
