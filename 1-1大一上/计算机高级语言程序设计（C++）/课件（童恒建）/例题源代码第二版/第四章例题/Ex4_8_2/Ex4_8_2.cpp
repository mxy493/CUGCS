//【例4.8_2】与静态数据成员相反，为使用方便，静态函数成员多为公有的。
//在例4.8中的复数类中的函数成员print(),被说明为静态函数成员
#include <iostream>
#include <cmath>
using namespace std;

class Complex{
	double	Real,Image ;
public:
   	Complex(double r=0.0, double i=0.0){Real=r;Image=i;}//定义构造函数
    Complex(Complex &com){
		Real=com.Real ; Image=com.Image ;
	}//定义拷贝构造函数
	static void  Print(Complex & ob);
	Complex  operator+(Complex);
	Complex  operator+(double);
	Complex  operator=(Complex);
	Complex  operator+=(Complex);
	double  abs(void);
	Complex  operator*(Complex);
	Complex  operator/(Complex);
};
Complex  Complex::operator+(Complex c){
	Complex  Temp(Real+c.Real , Image+c.Image) ;		//显式说明局部对象
	  return Temp ;
}
Complex Complex::operator+(double d){    
	return Complex(Real+d , Image) ;//隐式说明局部对象
}			
Complex Complex::operator+=(Complex c){
	Complex temp;
	temp.Real=Real+c.Real;
	temp.Image=Image+c.Image;
	Real=temp.Real;
	Image=temp.Image;
	return temp;
}
Complex Complex::operator=(Complex c){
	Complex temp;
	temp.Real=c.Real;
	temp.Image=c.Image;
	Real=temp.Real;
	Image=temp.Image;
	return temp;
}
double Complex::abs(void){
	return sqrt(Real*Real+Image*Image);
}
Complex Complex::operator*(Complex c){
	return Complex(Real*c.Real-Image*c.Image , Real*c.Image+c.Real*Image);
}
Complex Complex::operator/(Complex c){
	double d=c.Real*c.Real+c.Image*c.Image ;
	return Complex((Real*c.Real+Image*c.Image)/d , (Image*c.Real-Real*c.Image)/d) ;
}
void  Complex::Print(Complex & ob){
	cout<<"Real="<<ob.Real<<'\t'<<"Image="<<ob.Image<<'\n';
}

int main(void){
	Complex c1(1.0,1.0) , c2(2.0,2.0) , c3(4.0,4.0) , c;
	double d=0.5;
	Complex::Print(c1);
	c=c2+c3;
	Complex::Print(c);
	c+=c1;
	Complex::Print(c);
	c=c+d;
	Complex::Print(c);
	c=c3*c2;
	c.Print(c);//这里c.只是表示Print属于Complex类，用c,c1,c2,c3均可，也可理解为Print可属于任一个对象
	c=c3/c1;
	c1.Print(c);
	cout<<"c3的模为："<<c3.abs()<<endl;
	return 0;
}
