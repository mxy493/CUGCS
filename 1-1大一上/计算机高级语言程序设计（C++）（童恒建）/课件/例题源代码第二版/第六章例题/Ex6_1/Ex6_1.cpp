//����6.1��������Ԫ�������ֵ�ĺ���ģ�塣
#include <iostream>
#include <string>
using namespace std; 
template <typename Groap>Groap max(const Groap *r_array,int size){
//����const����λ�ñ�ʾָ����ָ�Ķ��󲻿ɸı䣬�ɷ�ֹ�����ʵ��
	Groap max_val=r_array[0];
	for (int i=1;i<size; ++i)
		if(r_array[i]>max_val) max_val=r_array[i];
	return  max_val;
}
int ia[5]={10,7,14,3,25};
double da[6]={10.2,7.1,14.5,3.2,25.6,16.8};
string sa[5]={"�Ϻ�","����","����","����","�人"};
int main() {
	int  i=max(ia,5);
	cout <<"�������ֵΪ��"<<i<<endl;
	double  d=max(da,6);
	cout <<"ʵ�����ֵΪ��"<<d<<endl;
	string  s=max(sa,5);
	cout <<"�ֵ��������Ϊ��"<<s<<endl;
	return 0;
}
