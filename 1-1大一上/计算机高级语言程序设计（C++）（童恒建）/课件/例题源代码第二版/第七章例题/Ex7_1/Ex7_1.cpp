//����7.1����̬����Ľ����볷����
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	char *pc;
	cout<<"�����붯̬�����Ԫ�ظ���"<<endl;
	cin>>n;
	pc=new char[n];  //�������25���ַ�����װ12�����ֺ�һ����������Ԫ�ص��ڴ�ռ�
	strcpy(pc,"���ɴ洢���ڴ�Ķ�̬����");
	cout<<pc<<endl;
	delete []pc;           // �������ͷ�pc��ָ���n���ַ����ڴ�ռ�
	return 0;
}

