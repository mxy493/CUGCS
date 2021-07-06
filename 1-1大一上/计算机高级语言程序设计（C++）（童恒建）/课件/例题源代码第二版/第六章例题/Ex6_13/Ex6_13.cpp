//【例6.13】梯形法求积分的函数integer()是通用函数，可求任一函数的定积分。不同的函数有不同的解析式，
//该解析式决定了自变量在每一个小积分区间端点处的函数值。函数 integer()以一个指向函数的指针为参数，
//由该参数调用欲求定积分的函数，另两个参数是积分上下限。
#include <iostream>                                                    
#include <iomanip>
using namespace std;
                                                     
double f1(double x){
	return (1+x+2*x*x);
}
double f2(double x){
	return (1+x+2*x*x+3*x*x*x);
}
double f3(double x){
	return (1+x+2*x*x+3*x*x*x+4*x*x*x*x);
}
double integer (double (*func)(double),float, float);
int main(){
	double fixint1, fixint2, fixint3;
	fixint1=integer(f1,0.0,3.0);
	fixint2=integer(f2,0.0,3.0);
	fixint3=integer(f3,0.0,3.0);
	cout<<fixint1<<'\n'<<fixint2<<'\n'<<fixint3<<'\n';
	return 0;
}
double integer (double (*func)(double),float a,float b){
	double result,step;
	result=((*func)(a)+(*func)(b))/2;//(*func)亦可用func代替
	step=(b-a)/100;
	for (int i=1;i<100;i++) result+=(*func)(a+i*step);//亦可用func
	result*=step;
	return result;
}