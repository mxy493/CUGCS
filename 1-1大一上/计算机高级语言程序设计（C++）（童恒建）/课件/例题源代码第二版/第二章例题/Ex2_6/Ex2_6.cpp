//����2.6����Ƕ��if�����������������е����ֵ��

#include <iostream>
using namespace std;

int main(){
	int a, b, c, max;
	cout<<"������������:";
	cin>>a>>b>>c;
	if(a>b&&a>c)  max=a;
	else if(b>a&&b>c)  max=b;
	     else  max=c;
	cout<<"�����Ϊ:max="<<max<<endl;
	return 0;
}
