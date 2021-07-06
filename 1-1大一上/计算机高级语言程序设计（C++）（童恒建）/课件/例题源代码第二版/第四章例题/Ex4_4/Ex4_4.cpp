//【例4.4】采用不同返回方式的求正方形面积函数的比较。
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
	double x=fsqr1(5.5);//第一种情况
	double y=fsqr2(5.5);//第二种情况
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	return 0;
}
