//����5.7��ͨ���ṹָ�������ʽṹ��Ա��
#include<iostream>
#include<cstring>
using namespace std;

struct student{
	char name[20];
	char id[10];//ѧ��������ַ�������ѧ����0��ͷ�������ᶪʧ0������Ϊ�ǰ˽���
	int age;
	float score;
	char address[30];
};

int main(){
	student st1,*prst;
	prst=&st1;
	cout<<"������ѧ����������"<<endl;
	cin.getline(st1.name,20);//cin.getline������ո�
	cout<<"������ѧ�š��������ѧ�ɼ���"<<endl;
	cin>>st1.id>>st1.age>>st1.score;
	cin.get();//���յ����лس���
	cout<<"�������ͥסַ��"<<endl;
	cin.getline(st1.address,30);
	cout<<"����"<<'\t'<<prst->name<<'\n';
	cout<<"ѧ��"<<'\t'<<prst->id<<'\n';
	cout<<"����"<<'\t'<<prst->age<<'\n';
	cout<<"��ѧ�ɼ�"<<'\t'<<prst->score<<'\n';
	cout<<"��ͥסַ"<<'\t'<<prst->address<<endl;
	return 0;
}
