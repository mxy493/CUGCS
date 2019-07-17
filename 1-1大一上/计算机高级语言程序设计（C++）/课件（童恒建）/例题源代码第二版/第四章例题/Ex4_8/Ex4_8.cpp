//【例4.8】定义复数类，可完成复数基本运算，并应用它进行复数运算。
#include <iostream>
#include <cmath>
using namespace std;

class Complex{
	double	Real,Image ;
public:
   	Complex(double r=0.0, double i=0.0)
	{
	Real=r;
	Image=i;
	}//定义构造函数
    Complex(Complex &com){
		Real=com.Real ; 
		Image=com.Image ;
	}//定义拷贝构造函数
	void  Print(){
		cout<<"Real="<<Real<<'\t'<<"Image="<<Image<<'\n';
	}
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
	Complex temp;//定义temp为了可以返回Complex类型的值，使+=可以连续使用
	temp.Real=Real+c.Real;
	temp.Image=Image+c.Image;
	Real=temp.Real;
	Image=temp.Image;
	return temp;
}
Complex Complex::operator=(Complex c){
	Complex temp;//定义temp为了可以返回Complex类型的值，使=可以连续使用
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

int main(void){
	Complex c1(1.0,1.0) , c2(2.0,2.0) , c3(4.0,4.0) , c;
	double d=0.5 ;
	c1.Print();
	c=c2+c3;
	c.Print();
	c+=c1;
	c.Print();
	c=c+d;
	c.Print();
	c=c3*c2;
	c.Print();
	c=c3/c1;
	c.Print();
	cout<<"c3的模为："<<c3.abs()<<endl;
	c=c3=c2=c1;
	c.Print();
	c+=c3+=c2+=c1;
	c.Print();
	return 0;
}
