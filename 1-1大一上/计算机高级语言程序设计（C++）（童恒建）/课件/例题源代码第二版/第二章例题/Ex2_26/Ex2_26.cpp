//����2.26��������Űټ�������������ļ���

#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	char a[28];
	ifstream ifile;               //���������ļ�
	ifile.open("d:\\myfile.txt");     //��Ϊ�����ļ���
	int i=0,j,k;
	while(ifile.get(a[i])){      //������,��Ա�cin.get(),������>>,�����ܶ����ַ�
		if(a[i]=='\n') break;
		i++;
	}
	a[i]='\0';
	cout<<a<<endl;
	while(1){
		ifile>>i>>j>>k;                                 //���ļ���������
		if(ifile.eof()!=0) break;            //�������ļ�����ʱ��ifile.eof()Ϊ��
		cout<<setw(6)<<i<<setw(10)<<j<<setw(10)<<k<<endl;     //��Ļ��ʾ	    
	}
	ifile.close();                 //�ر��ļ�
	return 0;
}
