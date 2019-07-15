//【例4.8_1】 用友元函数重载运算符，实现复数的运算。
#include <iostream>
#include <cmath>
using namespace std;
class Complex{
	double	Real,Image ;
public :
    Complex(double r=0.0, double i=0.0){Real=r;Image=i;}//定义构造函数
    Complex(Complex &com){
		Real=com.Real ; Image=com.Image ;
	}     //定义拷贝构造函数
	void  Print(){
		cout<<"Real="<<Real<<'\t'<<"Image="<<Image<<'\n';
	}
	friend Complex operator+(const Complex &,const Complex &);
	friend Complex &operator +=(Complex &,const Complex &);     //重载复数"+="
	friend double abs(Complex &);
	friend Complex operator*(const Complex &,const Complex &);
	friend Complex operator/(const Complex &,const Complex &);
};
Complex operator+(const Complex & c1,const Complex & c2){
	return Complex(c1.Real+c2.Real,c1.Image+c2.Image);
}    //隐式说明局部对象
Complex &operator +=(Complex &c1,const Complex &c2){     //重载复数"+="
	c1.Real=c1.Real+c2.Real;
	c1.Image=c1.Image+c2.Image;
	return c1;   //返回由引用参数传递过来的变量，函数返回值可为引用
}
double abs(Complex &c){
	return sqrt(c.Real*c.Real+c.Image*c.Image);
}
Complex operator*(const Complex & c1,const Complex & c2){
	return Complex(c1.Real*c2.Real-c1.Image*c2.Image ,c1.Real*c2.Image+c2.Real*c1.Image);
}
Complex operator/(const Complex & c1,const Complex & c2){
	double d=c2.Real*c2.Real+c2.Image*c2.Image ;
	return Complex((c1.Real*c2.Real+c1.Image*c2.Image)/d , (c1.Image*c2.Real-c1.Real*c2.Image)/d) ;
}
int main(void){
	Complex c1(1.0,1.0) , c2(2.0,2.0) , c3(4.0,4.0) , c;
	double d=0.5 ;
	c1.Print();
	c=c2+c3 ;
	c.Print() ;
	c+=c2+=c1 ;
	c.Print() ;
	c=c+d ;
	c.Print() ;
	c=d+c ;
	c.Print() ;
	c=c3*c2 ;
	c.Print() ;
	c=c3/c1 ;
	c.Print() ;
	c=c3*d;
	c.Print() ;
	c=c3/d;
	c.Print() ;
	cout<<"c3的模为："<<abs(c3)<<endl ;
	return 0;
}
