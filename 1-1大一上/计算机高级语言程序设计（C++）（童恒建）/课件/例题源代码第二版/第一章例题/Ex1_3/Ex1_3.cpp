//����1.3���ַ�������ַ�����������Ӧ�á�
# include <iostream>
# include <cstring>
using namespace std;

int main() {
	char s1[]="Hello C++";   //��ʼ����������s1[]��10��Ԫ��
	char s2[10], s3[20];
	s2[0]='B';s2[1]='e';s2[2]='g';s2[3]='i';s2[4]='n';
	s2[5]='\0';					 //�����������ַ�������ǳ���Ҫ
	strcpy(s3, s2);
	cout<<"The length of \""<<s1<<"\" is:"<<strlen(s1)<<'\n';
	cout<<s2<<'\t'<<s3<<'\n';  //ֻ���ַ�������������
    return 0;
}
