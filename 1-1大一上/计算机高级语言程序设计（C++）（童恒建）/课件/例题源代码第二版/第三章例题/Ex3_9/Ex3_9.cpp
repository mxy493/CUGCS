//����3.9����ʾͬ�������ɼ��Ե����ӡ�
#include<iostream>
using namespace std;
int n=100;

int main(){
	 int i=200,j=300;
	 cout<< n<<'\t'<<i<<'\t'<<j<<endl;{		//���ȫ�ֱ���n�����ֲ�����i,j
		 int i=500,j=600,n;              //�ڲ��
		 n=i+j;
		 cout<< n<<'\t'<<i<<'\t'<<j<< endl;		//����ڲ�ֲ�����n��i,j
		 cout<<::n<<endl;					//���ȫ�ֱ���n
	 }
	 n=i+j;								//�޸�ȫ�ֱ���
	 cout<< n<<'\t'<<i<<'\t'<<j<< endl;		//���ȫ�ֱ���n�����ֲ�����i,j
	 return 0;
}
