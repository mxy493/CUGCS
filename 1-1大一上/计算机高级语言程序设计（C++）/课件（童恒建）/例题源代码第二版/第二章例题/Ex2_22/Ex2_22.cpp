//【例2.22】 输入一个小于1的数x，求sinx的近似值，要求误差小于0.0001。

#include<iostream>
using namespace std;

int main(){
	const double epsilon=0.0001;          //用epsilon保存误差
	double x,sinx,item;
	int n=2,sign=-1;                     //sign保存符号
	cout<<"input x:";
	cin>>x;
	sinx=x;item=x*x*x/6;                //第一项作为初值，第二项为误差项
	while(item>epsilon){
		sinx=sinx+item*sign;            //将当前项累加进结果，注意符号作为因子
		item=item*x*x/((2*n)*(2*n+1));   //推算新的误差项
		sign=-sign;                    //注意符号的变换
		n++;
	}
	cout<<"sin("<<x<<")="<<sinx<<endl;
	return 0;
}
