//����3.8����ƺ�����������������������������в��ԣ����Ƿ�ɹ���
#include<iostream>
using namespace std;

void swap(int,int);	
int main(){
	int a,b;						      //main()�ж����a,b��������Ϊmain()
	cout<<"������������"<<endl;
	cin>>a>>b;
	cout<<"����ǰ��ʵ��a="<<a<<','<<"b="<<b<<endl;
	swap(a,b);
	cout<<"���ú�ʵ��a="<<a<<','<<"b="<<b<<endl; //���ֽ���ʧ��
	return 0;
}	
void swap(int a,int b){				     //swap()�ж����a,b��������Ϊswap()
	cout<<"�����С�"<<endl;
	cout<<"����ǰ���β�a="<<a<<','<<"b="<<b<<endl;
	int t;
	t=a; a=b; b=t;						 //����a,b��ֵ
	cout<<"�������β�a="<<a<<','<<"b="<<b<<endl;
}								
