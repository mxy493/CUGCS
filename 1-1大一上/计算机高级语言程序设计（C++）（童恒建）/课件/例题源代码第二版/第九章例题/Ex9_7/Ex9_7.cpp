//����9.7�������ļ���
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	char ch;
	ifstream sfile("d:\\Ex9_6\\Ex9_6.cpp");
	ofstream dfile("e:\\Ex9_6.cpp");  //ֻ�ܴ����ļ������ܽ�����Ŀ¼����·����������ʧ��
	if(!sfile){
		cout<<"���ܴ�Դ�ļ�:"<<"d:\\Ex9_6\\Ex9_6.cpp"<<endl;
		return -1;
	}
	if(!dfile){
		cout<<"���ܴ�Ŀ���ļ�:"<<"e:\\Ex9_6.cpp"<<endl;
		return -1;
	}
	sfile.unsetf(ios::skipws);      //�ؼ�!�������ո����λ��0,���������ո�,����ո�ȫ��δ����
	while(sfile>>ch)dfile<<ch;
	sfile.close();                  //��û���������رպ���,��������Ҳ�ɹر�
	dfile.close();
	return 0;
}
