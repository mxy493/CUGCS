//����5.2���ַ��������ַ����������ӡ�
#include <iostream>
using namespace std;

void strcat(char s[],char ct[]){
	int i=0,j=0;
	while (s[i]!=0) i++;
	while (ct[j]!=0)  s[i++]=ct[j++];
	s[i]='\0';
}
int main (void){
	char a[40]="����";
	char b[20]="�Ƕ��ϴ�ѧѧ��";
	cout<<a<<endl;
	cout<<b<<endl;
	strcat(a,b);
	cout<<"�ַ������Ӻ�"<<endl;
	cout<<a<<endl;                  //��ӡ�ַ�����a
	return 0;
}
