//����4.3��ʹ��һ�������������������ݡ���Աȡ���3.10����
#include<iostream>
using namespace std;

void swap(double & d1,double & d2){
	double temp ;
	temp=d1 ; d1=d2 ; d2=temp ;
}
int main(void){
	double x , y ;
	cout<<"������x��y��ֵ"<<'\n';
	cin>>x>>y ;
	cout<<"x="<<x<<'\t'<<"y="<<y<<'\n';
	swap(x,y) ;
	cout<<"x="<<x<<'\t'<<"y="<<y<<'\n';
	return 0;
}
