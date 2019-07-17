//【例8.9】用虚函数来实现辛普生法求函数的定积分。在梯形法中是用直线来代替
//曲边梯形的曲边，在辛普生法中是用抛物线来代替，区间必须为偶数n个相等区间。
#include<iostream>
#include<cmath>
using namespace std;

class Simpson{
	double Intevalue,a,b;//Intevalue积分值，a积分下限，b积分上限
public:
	virtual double fun(double x)=0;//被积函数声明为纯虚函数
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
	void Print(){cout<<"积分值="<<Intevalue<<endl;}
};
class A:public Simpson{
public:
	A(double ra,double rb):Simpson(ra,rb){};
	double fun(double x){return sin(x);}
};
class B:public Simpson{//B也可以说明为由A派生，更利于说明动态多态性
public:
	B(double ra,double rb):Simpson(ra,rb){};
	double fun(double x){return exp(x);}
};
int main(){
	A a1(0.0,3.1415926535/2.0);
	Simpson *s=&a1;
	s->Integrate();//动态
	B b1(0.0,1.0);
	b1.Integrate();//静态
	s->Print();
	b1.Print();
	return 0;
}
