//����2.8����һԪ���η���ax2+bx+c=0�ĸ�������ϵ��a(a��0)��b��c��ֵ�ɼ������롣

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float a,b,c;
	float delta,x1,x2;
	for(int i=0;i<4;i++){
	cout<<"��������ϵ��a, b, c:"<<endl;
	cin>>a>>b>>c;
	if(a==0) cout<<"a can not be 0"<<endl;
	else{
		delta=b*b-4*a*c;
		if(delta==0){
			cout<<"������������ͬʵ��:";
			cout<<"x1=x2="<<-b/(2*a)<<endl;
		}
		else if(delta>0){
			delta=sqrt(delta);
			x1=(-b+delta)/(2*a);
			x2=(-b-delta)/(2*a);
			cout<<"������������ͬʵ��:";
			cout<<"x1="<<x1<<'\t'<<"x2="<<x2<<endl;
		}
		else cout<<"������ʵ��!"<<endl;//delta<0
	}
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
