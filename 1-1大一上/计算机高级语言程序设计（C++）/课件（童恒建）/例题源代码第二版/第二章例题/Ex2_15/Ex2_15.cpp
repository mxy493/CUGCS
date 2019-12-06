//【例2.15】输入一个不超过9位的正整数，将其反向后输出。例如输入247，变成742输出。

#include <iostream>
using namespace std;
int main(){
	int i,num,subscript;
	int digit[9];
	cout<<"输入一个不超过9位的正整数："<<endl;
	cin>>num;
	cout<<"原来整数为："<<num<<endl;
	subscript=0;						//数组下标初值
	do{
		digit[subscript]=num%10;
		num=num/10;
		subscript++;					//修改下标
	} while (num>0);
	for(i=0;i<subscript;i++)		//整数的反向组合
		num=num*10+digit[i];
	cout<<"反向后整数为："<<num<<endl;
	return 0;
}
