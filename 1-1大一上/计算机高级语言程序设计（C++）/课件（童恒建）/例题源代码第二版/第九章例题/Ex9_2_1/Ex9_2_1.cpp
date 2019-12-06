//【例9.2_1】采用流操作子的浮点数输出。
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double fnum=31.415926535;
	cout<<"缺省域宽为:"<<cout.width()<<"位"<<'\n'; 
	cout<<"缺省精度为:"<<cout.precision()<<"位"<<'\n';  //floatfield为0x1800
	cout<<"缺省表达方式:"<<fnum<<'\n';       //按值大小,自动决定定点还是科学数方式
	cout<<"科学数表达方式:"<<scientific<<fnum<<'\n';  //设为科学数方式
	cout<<"定点表达方式:"<<fixed<<fnum<<'\n';         //设为定点,取消科学数方式
	cout<<"9位科学数表达方式"<<setprecision(9)<<scientific<<fnum<<'\n';//精度9位指小数点后9位
	return 0;
}
