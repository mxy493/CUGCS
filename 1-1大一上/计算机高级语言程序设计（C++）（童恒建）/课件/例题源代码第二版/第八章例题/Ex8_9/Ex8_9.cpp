//����8.9�����麯����ʵ���������������Ķ����֡������η�������ֱ��������
//�������ε����ߣ����������������������������棬�������Ϊż��n��������䡣
#include<iostream>
#include<cmath>
using namespace std;

class Simpson{
	double Intevalue,a,b;//Intevalue����ֵ��a�������ޣ�b��������
public:
	virtual double fun(double x)=0;//������������Ϊ���麯��
	Simpson(double ra=0,double rb=0){
		a=ra;
		b=rb;
		Intevalue=0;
	}
	void Integrate(){
		double dx;
		int i;
		dx=(b-a)/2000;
		Intevalue=fun(a)+fun(b);
		for(i=1;i<2000;i+=2)Intevalue+=4*fun(a+dx*i);
		for(i=2;i<2000;i+=2)Intevalue+=2*fun(a+dx*i);
		Intevalue*=dx/3;
	}
	void Print(){cout<<"����ֵ="<<Intevalue<<endl;}
};
class A:public Simpson{
public:
	A(double ra,double rb):Simpson(ra,rb){};
	double fun(double x){return sin(x);}
};
class B:public Simpson{//BҲ����˵��Ϊ��A������������˵����̬��̬��
public:
	B(double ra,double rb):Simpson(ra,rb){};
	double fun(double x){return exp(x);}
};
int main(){
	A a1(0.0,3.1415926535/2.0);
	Simpson *s=&a1;
	s->Integrate();//��̬
	B b1(0.0,1.0);
	b1.Integrate();//��̬
	s->Print();
	b1.Print();
	return 0;
}
