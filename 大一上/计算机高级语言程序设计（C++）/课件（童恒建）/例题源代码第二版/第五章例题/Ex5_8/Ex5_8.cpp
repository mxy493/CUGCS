//【例5.8】指针与数组相关的运算:
#include <iostream>
using namespace std;

int main(){
	int i,fibon[10]={0,1,1,2,3,5,8,13,21,34},*pfib1,*pfib2;
	pfib1=pfib2=fibon;                         //也可以用pfib1=pfib2=&fibon[0]
	cout<<"使用数组显示斐波那契数列"<<endl;
	for(i=0;i<10;i++)
		cout<<fibon[i]<<'\t'<<pfib1[i]<<endl;
	cout<<"使用指针显示斐波那契数列"<<endl;
	for(i=0;i<10;i++)
		cout<<*(fibon+i)<<'\t'<<*pfib2++<<endl;   //注意：fibon++是错误的，而pfib2++是正确的
	cout<<"显示指针相减,应为数组长度:";
	cout<<pfib2-pfib1<<endl;                  //pfib2已指向数组末尾
	return 0;
}
