//����9.8�����и����ı��ļ���
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	char filename[256],buf[100];
	fstream sfile,dfile;
	cout<<"����Դ�ļ�·����:"<<endl;
	cin>>filename;//��·����������Կո����޹ؽ�Ҫ��,����Ҫ��getline()�ȳ�Ա����
	sfile.open(filename,ios::in);//��һ���Ѵ��ڵ��ļ�
	while(!sfile){
		cout<<"Դ�ļ��Ҳ���,����������·����:"<<endl;
		sfile.clear(0);//��״̬��
		cin>>filename;
		sfile.open(filename,ios::in);
	}
	cout<<"����Ŀ���ļ�·����:"<<endl;
	cin>>filename; //ֻ�ܴ����ļ������ܽ�����Ŀ¼����·����������ʧ��
	dfile.open(filename,ios::out);
	if(!dfile){
		cout<<"Ŀ���ļ�����ʧ��"<<endl;
		return -1;
	}
	while(sfile.getline(buf,100)){//���п���  A��
		if(sfile.gcount()<100) dfile<<buf<<'\n';//��س���δ�͵�  B��
		else dfile<<buf;//���д���99���ַ�,��δ�����س����з�,���Բ���'\n'
	} 
	sfile.close();
	dfile.close();
	return 0;
}
