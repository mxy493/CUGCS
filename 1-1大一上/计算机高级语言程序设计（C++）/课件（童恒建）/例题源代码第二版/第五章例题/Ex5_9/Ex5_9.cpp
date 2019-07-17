//【例5.9】本例用指针代替【例4.3】的引用实现两数据的交换。
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
	cout<<"请输入x和y的值"<<'\n';
	cin>>x>>y;
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	swap(&x,&y);
//	swap1(x,y);
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	return 0;
}
