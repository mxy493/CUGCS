//����3.16�����غ�����Ӧ�á�
#include<iostream>
using namespace std;

int sum(int a,int b){
	return a+b;				
}
double sum(double a,double b){
	return a+b;
}
float sum(float a,float b,float c){
	return a+b+c;
}
int main(){
	cout<<"3+5="<<sum(3,5)<<endl;       //����sum(int,int)
	cout<<"2.2+5.6="<<sum(2.2,5.6)<<endl;  //����double(double,double)
	cout<<"3.5+4+8="<<sum(3.5,4,8)<<endl;  //����float sum(float,float,float)
	return 0;
}
