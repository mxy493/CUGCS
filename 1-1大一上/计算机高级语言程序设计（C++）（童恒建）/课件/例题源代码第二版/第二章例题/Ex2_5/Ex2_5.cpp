//����2.5���Ӽ�������������������������е��������

#include <iostream>
using namespace std;

int main(){
	int a, b, c, max;
	cout<<"������������:";
	cin>>a>>b>>c;
	cout<<"a="<<a<<'\t'<<"b="<<b<<'\t'<<"c="<<c<<endl;
	if(a>=b) max=a;
	else max=b;
	if(c>max) max=c;
	cout<<"�����Ϊ:"<<max;
	char ch;
	cin.get(ch);
	cin.get(ch);
	cout<<endl;
	return 0;
}
