//����4.4�����ò�ͬ���ط�ʽ������������������ıȽϡ�
#include<iostream>
using namespace std;

double temp;
double fsqr1(double a){
	temp=a*a ; return temp;
}
double & fsqr2(double a){
	temp=a*a ; return temp;
}
int main(){
	double x=fsqr1(5.5);//��һ�����
	double y=fsqr2(5.5);//�ڶ������
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	return 0;
}
