//����9.12���ַ���
#include<strstream>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int i;
	char str[36]="This is a book.";
	char ch;
	istrstream input(str,36);          //�Դ���Ϊ��ϢԴ
	ostrstream output(str,36);
	cout<<"�ַ������ȣ�"<<strlen(str)<<endl;
	for(i=0;i<36;i++){
		input>>ch;             //�������豸(��)����һ���ַ�,���пհ��ַ�ȫ����
		cout<<ch;                     //����ַ�
	}
	cout<<endl;
	int inum1=93,inum2;
	double fnum1=89.5,fnum2;
	output<<inum1<<' '<<fnum1<<'\0';  //�ӿո�ָ�����
	cout<<"�ַ������ȣ�"<<strlen(str)<<endl;
	istrstream input1(str,0);      //�ڶ�����Ϊ0ʱ,��ʾ���ӵ��Դ��������ս�Ĵ�
	input1>>inum2>>fnum2;
	cout<<"������"<<inum2<<'\t'<<"��������"<<fnum2<<endl; //�����������93 ��������89.5
	cout<<"�ַ������ȣ�"<<strlen(str)<<endl;
	return 0;
}
