//����4.6�����г�Ա�������Ĺ��캯����
#include<iostream>
#include<cstring>
using namespace std;

class studentID{
	long value;
public:
	studentID(long id=0){
		value=id;
		cout<<"����ѧ����ѧ�ţ�"<<value<<endl;
	}
	~studentID(){
		cout<<"ɾ��ѧ�ţ�"<<value<<endl;
	}
};

class student{
private:
	studentID id;
	char name[20];
public:
	student (char sname[]="no name",long sid=0):id(sid){
		cout<<"ѧ������"<<sname<<endl;
		strcpy(name,sname);
	}
	~student(){
		cout<<"ɾ��ѧ������"<<name<<endl;
	}
};

int main(){
	student ss("����",82020132);
	return 0;
}
