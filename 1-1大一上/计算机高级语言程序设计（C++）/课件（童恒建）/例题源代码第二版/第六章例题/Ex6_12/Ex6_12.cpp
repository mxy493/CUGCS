//【例6.12】设计梯形法求积分的函数模板，梯形法求积分的函数为独立的非成员函数。该方法更简洁。
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

template<typename T>double integer (T cf,float a, float b,int n){
	double result,step;
	result=(cf.fun(a)+cf.fun(b))/2;
	step=(b-a)/n;
	for (int i=1;i<n;i++) result+=cf.fun(a+i*step);
	result*=step;
	return result;
}

int main(){
	F1 f1;F2 f2;F3 f3;
	double fixint1, fixint2, fixint3;
	int n=1000;
	fixint1=integer(f1,0.0,3.0,n);
	fixint2=integer(f2,0.0,3.0,n);
	fixint3=integer(f3,0.0,3.0,n);
	cout<<fixint1<<'\n'<<fixint2<<'\n'<<fixint3<<'\n';
	return 0;
}
