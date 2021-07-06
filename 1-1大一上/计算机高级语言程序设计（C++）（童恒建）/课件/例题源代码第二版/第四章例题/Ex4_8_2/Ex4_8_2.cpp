//����4.8_2���뾲̬���ݳ�Ա�෴��Ϊʹ�÷��㣬��̬������Ա��Ϊ���еġ�
//����4.8�еĸ������еĺ�����Աprint(),��˵��Ϊ��̬������Ա
#include <iostream>
#include <cmath>
using namespace std;

class Complex{
	double	Real,Image ;
public:
   	Complex(double r=0.0, double i=0.0){Real=r;Image=i;}//���幹�캯��
    Complex(Complex &com){
		Real=com.Real ; Image=com.Image ;
	}//���忽�����캯��
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
	Complex  Temp(Real+c.Real , Image+c.Image) ;		//��ʽ˵���ֲ�����
	  return Temp ;
}
Complex Complex::operator+(double d){    
	return Complex(Real+d , Image) ;//��ʽ˵���ֲ�����
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
	c.Print(c);//����c.ֻ�Ǳ�ʾPrint����Complex�࣬��c,c1,c2,c3���ɣ�Ҳ�����ΪPrint��������һ������
	c=c3/c1;
	c1.Print(c);
	cout<<"c3��ģΪ��"<<c3.abs()<<endl;
	return 0;
}
