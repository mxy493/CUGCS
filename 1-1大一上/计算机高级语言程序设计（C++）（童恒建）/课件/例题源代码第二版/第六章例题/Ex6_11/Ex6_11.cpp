//【例6.11】设计梯形法求积分的类模板，梯形法求积分的函数为成员函数，
//可求任一函数的定积分。以积分类的模板参数T来引入被积函数。
#include <iostream>                                                    
#include <iomanip>
using namespace std;

class F1 {
public:
	double fun(double x){return (1+x+2*x*x);}
};
class F2 {
public:
	double fun(double x){return (1+x+2*x*x+3*x*x*x);}
};
class F3 {
public:
	double fun(double x){return (1+x+2*x*x+3*x*x*x+4*x*x*x*x);}
};
template<typename T>class Integer{
	double a,b,step,result;
	int n;//分区数量
	T cf;//被积函数
public:
	Integer(double aa=0, double bb=0, int nn=100){
		a=aa;	b=bb;	n=nn;
		integerate();
	}
	void putlimits(double aa=0, double bb=0, int nn=100){//修改积分上下限和分区数
		a=aa;	b=bb;	n=nn;
	}
	void integerate();
	void print(){cout<<"定积分值为："<<result<<endl;}
};
template<typename T>void Integer<T>::integerate(){
	step=(b-a)/n;
	result=(cf.fun(a)+cf.fun(b))/2;
	for (int i=1;i<n;i++) result+=cf.fun(a+i*step);
	result*=step;
}

int main(){
	Integer<F1> integer1(0.0,3.0,1000);
	integer1.print();
	Integer<F2> integer2(0.0,3.0,1000);
	integer2.print();
	Integer<F3> integer3(0.0,3.0,1000);
	integer3.print();
	return 0;
}
