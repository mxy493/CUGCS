//����5.9��������ָ����桾��4.3��������ʵ�������ݵĽ�����
#include<iostream>
using namespace std;

void swap(double *d1,double *d2){
	double temp;
	temp=*d1;*d1=*d2;*d2=temp;
}
/*
void swap1(double d1,double d2)
{
	double temp;
	temp=d1;d1=d2;d2=temp;
}
*/
int main(void){
	double x,y;
	cout<<"������x��y��ֵ"<<'\n';
	cin>>x>>y;
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	swap(&x,&y);
//	swap1(x,y);
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	return 0;
}
