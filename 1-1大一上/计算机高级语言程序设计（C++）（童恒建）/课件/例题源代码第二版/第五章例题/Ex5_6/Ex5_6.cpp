//����5.6��ָ�븳ֵʵ����
#include <iostream>
using namespace std;

int main(){
	int age1=18,age2=20,*p_age;
	p_age=&age1;    //���1����ͼ5.5
	cout<<"age1�ĵ�ַ�ǣ�"<<p_age<<endl;
	cout<<"age of wang ping is "<<*p_age<<endl;
	p_age=&age2;  //���2��ָ���ָ��һ��������ͼ5.5
	cout<<"age2�ĵ�ַ�ǣ�"<<p_age<<endl;
	cout<<"age of zhang ling is "<<*p_age<<endl;
	return 0;
}
