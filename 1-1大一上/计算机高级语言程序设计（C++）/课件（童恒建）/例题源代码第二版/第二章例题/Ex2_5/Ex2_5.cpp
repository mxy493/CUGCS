//【例2.5】从键盘上输入三个整数，输出其中的最大数。

#include <iostream>
using namespace std;

int main(){
	int a, b, c, max;
	cout<<"输入三个整数:";
	cin>>a>>b>>c;
	cout<<"a="<<a<<'\t'<<"b="<<b<<'\t'<<"c="<<c<<endl;
	if(a>=b) max=a;
	else max=b;
	if(c>max) max=c;
	cout<<"最大数为:"<<max;
	char ch;
	cin.get(ch);
	cin.get(ch);
	cout<<endl;
	return 0;
}
