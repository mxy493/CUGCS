//����9.2_1�������������ӵĸ����������
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double fnum=31.415926535;
	cout<<"ȱʡ���Ϊ:"<<cout.width()<<"λ"<<'\n'; 
	cout<<"ȱʡ����Ϊ:"<<cout.precision()<<"λ"<<'\n';  //floatfieldΪ0x1800
	cout<<"ȱʡ��﷽ʽ:"<<fnum<<'\n';       //��ֵ��С,�Զ��������㻹�ǿ�ѧ����ʽ
	cout<<"��ѧ����﷽ʽ:"<<scientific<<fnum<<'\n';  //��Ϊ��ѧ����ʽ
	cout<<"�����﷽ʽ:"<<fixed<<fnum<<'\n';         //��Ϊ����,ȡ����ѧ����ʽ
	cout<<"9λ��ѧ����﷽ʽ"<<setprecision(9)<<scientific<<fnum<<'\n';//����9λָС�����9λ
	return 0;
}
