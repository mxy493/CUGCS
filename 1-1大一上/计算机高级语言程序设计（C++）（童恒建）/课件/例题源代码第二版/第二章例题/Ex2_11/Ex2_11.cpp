//����2.11������1+2+3+��+100��ֵ��

#include <iostream>
using namespace std;

const int n=100; //�ó����������޸ĳ���
int main(){
	int i=1,sum=0;		 //ѭ����ʼ����
	while(i<=n){
		sum+=i;
		i++;			 //�޸�ѭ������
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}
