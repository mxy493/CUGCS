//【例2.19】 用筛选法求100之内的所有素数，并将这些素数输出，每行输出10个数据。

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int n=100;
int main(){
	int a[n];
	int i,j;
	for(i=0;i<n;i++) a[i]=1+i;			//用数组保存整数1-100
	a[0]=0;							//1不是素数，置0
	for(i=1;i<n;i++){
		if(a[i]==0)  continue;			//该数已经置0,判断下一个数
		for(j=i+1;j<n;j++)	if(a[j]%a[i]==0)  a[j]=0;	//是a[i]倍数的元素置0；
	}
	int count=0;
	cout<<"1-" <<n<<"之间的素数："<<endl;
	for(i=0;i<n;i++)						//输出所有素数
		if(a[i]!=0){                       //非0元素即为素数
			cout<<setw(6)<<a[i];
			count++;
			if(count%10==0)  cout<<endl;	//每行10个数据
		}
	cout<<endl;
	return 0;
}
