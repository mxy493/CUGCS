//【例2.12】用迭代法求a的平方根的近似值，要求前后两个迭代根之差小于10-5。

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float x0,x1,a;
	cout<<"输入一个正数："<<endl;
	cin>>a;
	if(a<0)  cout<<a<<"不能开平方!"<<endl;
	else {										//有实数解的情况
		x1=a/2;									//x1用作保存结果
		do {
			x0=x1;
			x1=(x0+a/x0)/2;
		} while (fabs(x1-x0)>=1e-5);
		cout<< a<<"的平方根为："<<x1<<endl;
	}
	return 0;
}
