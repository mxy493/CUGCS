//【例4.3】使用一个函数来交换两个数据。请对比【例3.10】。
#include<iostream>
using namespace std;

void swap(double & d1,double & d2){
	double temp ;
	temp=d1 ; d1=d2 ; d2=temp ;
}
int main(void){
	double x , y ;
	cout<<"请输入x和y的值"<<'\n';
	cin>>x>>y ;
	cout<<"x="<<x<<'\t'<<"y="<<y<<'\n';
	swap(x,y) ;
	cout<<"x="<<x<<'\t'<<"y="<<y<<'\n';
	return 0;
}
