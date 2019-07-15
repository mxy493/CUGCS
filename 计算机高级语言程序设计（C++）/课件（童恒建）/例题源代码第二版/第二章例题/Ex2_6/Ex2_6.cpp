//【例2.6】用嵌套if语句完成求三个整数中的最大值。

#include <iostream>
using namespace std;

int main(){
	int a, b, c, max;
	cout<<"输入三个整数:";
	cin>>a>>b>>c;
	if(a>b&&a>c)  max=a;
	else if(b>a&&b>c)  max=b;
	     else  max=c;
	cout<<"最大数为:max="<<max<<endl;
	return 0;
}
