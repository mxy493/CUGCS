//����3.2��˵��ʵ�κ��βζ�Ӧ��ϵ��ʾ����
#include <iostream >
#include<cmath >
using namespace std;

float power(float x,int n){				//��x��n����
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
