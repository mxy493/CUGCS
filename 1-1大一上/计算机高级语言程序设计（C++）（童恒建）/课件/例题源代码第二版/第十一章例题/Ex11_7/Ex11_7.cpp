//����11.7�����Ͷ��ؼ��Ϲ������������ʾ�� 
#include<iostream>
#include<set>						        //��������ͷ�ļ�
#include<algorithm>					        //�����㷨ͷ�ļ�
using namespace std;                        //C++��׼�����ֿռ���
typedef multiset<int> INTMS;        //����ȡ��INTMS�����Ͷ��ؼ��ϰ���������

int main(){
	const int size=16;
	int a[size]={17,11,29,89,73,53,61,37,41,29,3,47,31,59,5,2};
	INTMS intMultiset(a,a+size);				//��a����ʼ��INTMS����ʵ��
	ostream_iterator<int> output(cout," ");
		              //�������������output����ͨ��cout���һ���ÿո�ָ�������
	cout<<"����ԭ����"<<intMultiset.count(17)<<"����ֵ17"<<endl;//�����м����ؼ���17
	intMultiset.insert(17);                                    //����һ���ظ�����17
	cout<<"�����������"<<intMultiset.count(17)<<"����ֵ17"<<endl;
	INTMS::const_iterator result;	//const_iteratorʹ������Զ�ȡINTMS��Ԫ�أ�
	                        //�����ó����޸�����Ԫ�أ�resultΪINTMS�ĵ�����
	result=intMultiset.find(18);//�ҵ��򷵻�����λ�ã����ҵ��������end()���ص�ͬ��ֵ
	if(result==intMultiset.end()) cout<<"û�ҵ�ֵ18"<<endl;
	else cout<<"�ҵ�ֵ18"<<endl;
	cout<<"intMultiset��������"<<endl;
	copy(intMultiset.begin(),intMultiset.end(),output);        //���������ȫ��Ԫ��
	cout<<endl;
	return 0;
}