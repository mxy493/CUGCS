/*【例2.20】 中国古代数学史上著名的"百鸡问题"：鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一。
百钱买百鸡，问鸡翁、母、雏各几何？
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int i,j,k;
	cout<<"   公鸡      母鸡      小鸡"<<endl;
	for(i=0;i<=20;i++)
		for(j=0;j<=33;j++){
			k=100-i-j;
			if((5*i+3*j+k/3==100)&&(k%3==0))			//注意(k%3==0)非常重要
			cout<<setw(6)<<i<<setw(10)<<j<<setw(10)<<k<<endl;
		}
	return 0;
}

