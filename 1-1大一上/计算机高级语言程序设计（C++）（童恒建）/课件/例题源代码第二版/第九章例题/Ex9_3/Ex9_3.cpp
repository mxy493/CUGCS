//����9.3���������Ľ�׳�ԡ�����ʱ��Ҫ��������Բ��Խ�׳�ԡ�
#include<iostream>
using namespace std;
int main(){
	char str[256];
	int i;
	cout<<"����������:"<<endl;//ǿ����ջ�����,��֤���,����Ȼ�������������
	cin>>i;//�ɹ����������ɷ������ַ�,�´������������ַ������ִ������ɷ������ַ����м��
	while(cin.fail()){
		cout<<"״̬��Ϊ��"<<cin.rdstate()<<endl;
		cin.clear(0);
		cin.getline(str,255);//���ջ�����
		cout<<"�������,��������������"<<endl;
		cin>>i;
	}
	cin.getline(str,256);//���ջ�����
	cout<<"�������ַ���"<<endl;
	cin.getline(str,255);//B��
	cout<<"��������Ϊ:"<<i<<endl;
	cout<<"�����ַ���Ϊ:"<<str<<endl;
	return 0;
}
