//����9.4��ignore()��gcount()����ʹ�á�
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char str[255];
	int i,n;
	cout<<"�����ַ�"<<endl;        //����^Z,һ������^Zȫ���������������������ַ�
	i=cin.get();
	cout<<endl;
	n=cin.rdstate();                         //��ȡ״̬��
	cout<<"״̬��Ϊ��"<<n<<endl;             //״̬��Ϊ1,������
	cout<<"�������ַ�ʱ,ȡ�õ���:"<<i<<endl; //-1,����^Zʱ,����EOF,��-1
	if(n==0) cin.ignore(255,'\n');           //���������ַ��ͻس���
	cin.clear(0);                            // A    ʹ���ָ�����
	cout<<"�����ַ���1:"<<endl;
	cin.getline(str,255);
	cout<<endl;
	cout<<"״̬��Ϊ��"<<cin.rdstate()<<endl;
	i=cin.gcount();
	cout<<"�ַ���Ϊ:"<<str<<'\t'<<"�����ַ���Ϊ:"<<i<<'\t';
	cout<<"����Ϊ:"<<strlen(str)<<endl;
	cin.clear(0);                            // A    ʹ���ָ�����
	cout<<"�����ַ���2:"<<endl;
	cin.getline(str,255);
	cout<<endl;
	cout<<"״̬��Ϊ��"<<cin.rdstate()<<endl;
	i=cin.gcount();
	cout<<"�ַ���Ϊ:"<<str<<'\t'<<"�����ַ���Ϊ:"<<i<<'\t';
	cout<<"����Ϊ:"<<strlen(str)<<endl;
	return 0;
}
