//【例9.2】浮点数输出。
#include<iostream>
using namespace std;

int main(){
	double fnum=31.415926535;
	cout<<"缺省域宽为:"<<cout.width()<<"位"<<'\n'; 
	cout<<"缺省精度为:"<<cout.precision()<<"位"<<'\n';  //floatfield为0x1800
	cout<<"缺省表达方式:"<<fnum<<'\n';       //按值大小,自动决定定点还是科学数方式
	cout.setf(ios::scientific,ios::floatfield);        //floatfield为0x1800
	cout<<"科学数表达方式:"<<fnum<<'\n';
	cout.setf(ios::fixed,ios::floatfield);            //设为定点,取消科学数方式
	cout<<"定点表达方式:"<<fnum<<'\n';
	cout.precision(9);                                //精度为9位，小数点后9位
	cout.setf(ios::scientific,ios::floatfield); 
	cout<<"9位科学数表达方式"<<fnum<<'\n';
	return 0;
}
