//����2.23������һ��8λ��������������ת��Ϊʮ�����������

#include<iostream>
using namespace std;

const int n=8;
int main(){
	char bin[n];
	int x=2,a,dec,i;
	cout<<"������������У�"<<endl;
	for(i=n-1;i>=0;i--)  cin>>bin[i];      //��������Ǹ�λ��
	dec=0;	
	for(i=n-1;i>=0;i--){
	      a=bin[i]-'0';		             	//�����ַ�ת��Ϊ����
		  dec= dec*x+a;
	}
	cout<<"����������(";
	for(i=n-1;i>=0;i--)  cout<<bin[i];
	cout<<")��ֵΪ:"<<dec<<endl;
	return 0;
}
