//����9.2�������������
#include<iostream>
using namespace std;

int main(){
	double fnum=31.415926535;
	cout<<"ȱʡ���Ϊ:"<<cout.width()<<"λ"<<'\n'; 
	cout<<"ȱʡ����Ϊ:"<<cout.precision()<<"λ"<<'\n';  //floatfieldΪ0x1800
	cout<<"ȱʡ��﷽ʽ:"<<fnum<<'\n';       //��ֵ��С,�Զ��������㻹�ǿ�ѧ����ʽ
	cout.setf(ios::scientific,ios::floatfield);        //floatfieldΪ0x1800
	cout<<"��ѧ����﷽ʽ:"<<fnum<<'\n';
	cout.setf(ios::fixed,ios::floatfield);            //��Ϊ����,ȡ����ѧ����ʽ
	cout<<"�����﷽ʽ:"<<fnum<<'\n';
	cout.precision(9);                                //����Ϊ9λ��С�����9λ
	cout.setf(ios::scientific,ios::floatfield); 
	cout<<"9λ��ѧ����﷽ʽ"<<fnum<<'\n';
	return 0;
}
