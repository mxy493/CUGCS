//【例2.18】 给定正整数m，判定其是否为素数。

#include <iostream>
#include <cmath>
using namespace std;
		
int main(){
	 int m,i,k;
	 for(int l=0;l<3;l++){
	 cout<<"输入大于1的正整数m："<<endl;	 
	 cin>>m;
	 if(m==2)   cout<<m<<"是素数"<<endl;
	 else{
		k=sqrt(m);
		for(i=2;i<=k;i++) if (m%i==0)  break;		//只要有一个整除，就可停止
		if(i>k)  cout<< m<<"是素数"<<endl;		//循环提前终止表示是非素数
		else  cout<< m<<"不是素数"<<endl;
	 }
	 cout<<endl;
	 }
	 char ch;
	 cin.get(ch);
	 cin.get(ch);
	 return 0;
}
