//【例3.2】说明实参和形参对应关系的示例。
#include <iostream >
#include<cmath >
using namespace std;

float power(float x,int n){				//求x的n次幂
	float pow=1;
	while(n--)
		pow*=x;
	return pow;
}
int main(){
	int n=3;
	float x=4.6;
	char c='a';
	cout<<"power ("<<x<<','<<n<<")="<<power(x,n)<<endl;
	cout<<"power ("<<c<<','<<n<<")="<<power(c,n)<<endl;		//A
	cout<<"power ("<<n<<','<<x<<")="<<power(n,x)<<endl;		//B
	return 0;
}
