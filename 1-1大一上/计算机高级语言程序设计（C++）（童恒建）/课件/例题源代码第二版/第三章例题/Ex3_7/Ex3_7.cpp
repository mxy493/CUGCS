//����3.7�� �������������������Ӵ�С��˳�򱣴棬����������

#include<iostream>
using namespace std;

int main(){
	int a,b;					//�����ڶ���ֲ����������к�����
	cout<<"������������"<<endl;
	cin>>a>>b;
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
	if(b>=a){					//ʹa�б��������b�б���С��
		int t;						//���ж���ֲ����������п�������
		t=a; a=b; b=t;				//����a,b��ֵ
	}
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
	return 0;
}
