//【例2.8】求一元二次方程ax2+bx+c=0的根。其中系数a(a≠0)、b、c的值由键盘输入。

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float a,b,c;
	float delta,x1,x2;
	for(int i=0;i<4;i++){
	cout<<"输入三个系数a, b, c:"<<endl;
	cin>>a>>b>>c;
	if(a==0) cout<<"a can not be 0"<<endl;
	else{
		delta=b*b-4*a*c;
		if(delta==0){
			cout<<"方程有两个相同实根:";
			cout<<"x1=x2="<<-b/(2*a)<<endl;
		}
		else if(delta>0){
			delta=sqrt(delta);
			x1=(-b+delta)/(2*a);
			x2=(-b-delta)/(2*a);
			cout<<"方程有两个不同实根:";
			cout<<"x1="<<x1<<'\t'<<"x2="<<x2<<endl;
		}
		else cout<<"方程无实根!"<<endl;//delta<0
	}
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
