//����2.25�����ټ���������������ļ���

#include<fstream>
#include<iomanip>
using namespace std;
int main(){
	int i,j,k;
	ofstream ofile;               //��������ļ�
	ofile.open("d:\\myfile.txt");     //��Ϊ����ļ���
	ofile<<"   ����      ĸ��      С��"<<endl;   //����д���ļ�
	for(i=0;i<=20;i++)
		for(j=0;j<=33;j++){
			k=100-i-j;
			if((5*i+3*j+k/3==100)&&(k%3==0))			//ע��(k%3==0)�ǳ���Ҫ
			ofile<<setw(6)<<i<<setw(10)<<j<<setw(10)<<k<<endl;   //����д���ļ�
		}
	ofile.close();                //�ر��ļ�
	return 0;
}
