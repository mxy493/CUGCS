//����6.13�����η�����ֵĺ���integer()��ͨ�ú�����������һ�����Ķ����֡���ͬ�ĺ����в�ͬ�Ľ���ʽ��
//�ý���ʽ�������Ա�����ÿһ��С��������˵㴦�ĺ���ֵ������ integer()��һ��ָ������ָ��Ϊ������
//�ɸò����������󶨻��ֵĺ����������������ǻ��������ޡ�
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
	result=((*func)(a)+(*func)(b))/2;//(*func)�����func����
	step=(b-a)/100;
	for (int i=1;i<100;i++) result+=(*func)(a+i*step);//�����func
	result*=step;
	return result;
}