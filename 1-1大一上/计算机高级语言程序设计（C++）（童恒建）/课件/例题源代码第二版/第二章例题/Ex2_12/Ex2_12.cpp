//����2.12���õ�������a��ƽ�����Ľ���ֵ��Ҫ��ǰ������������֮��С��10-5��

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float x0,x1,a;
	cout<<"����һ��������"<<endl;
	cin>>a;
	if(a<0)  cout<<a<<"���ܿ�ƽ��!"<<endl;
	else {										//��ʵ��������
		x1=a/2;									//x1����������
		do {
			x0=x1;
			x1=(x0+a/x0)/2;
		} while (fabs(x1-x0)>=1e-5);
		cout<< a<<"��ƽ����Ϊ��"<<x1<<endl;
	}
	return 0;
}
