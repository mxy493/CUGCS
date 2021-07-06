//����8.8��ѧУ���ڲ���Ա���н�����������ҵ���֣�����ҵ���ֵļ��㷽��ֻ�ܶԾ�����
//Ա���У���ѧ������ʦ��������Ա�����ˣ��㷨����ͬ�����Կ��Խ��ڲ���Ա����Ϊһ����
//���࣬ҵ�����㷽����Ϊһ�����麯����
#include<iostream>
#include<string>
using namespace std;

class Person{
	int MarkAchieve;
	string Name;
public:
	Person(string name){
		Name=name;
		MarkAchieve=0;}
	void SetMark(int mark){MarkAchieve=mark;};
	virtual void CalMark()=0;//CalMark()Ϊ�麯��,PersonΪ������
	void Print(){cout<<Name<<"��ҵ����Ϊ:"<<MarkAchieve<<endl;}	
};
class Student:public Person{
	int credit,grade;//ѧ���ͳɼ�
public:
	Student(string name,int cred,int grad):Person(name){
		credit=cred;
		grade=grad;
	}
	void CalMark(){SetMark(credit*grade);}
};
class Teacher:public Person{
	int classhour,studnum;//�ڿ�ѧʱ��ѧ������
public:
	Teacher(string name,int ch,int sn):Person(name){
		classhour=ch;
		studnum=sn;
	}
	void CalMark(){
		int K=(studnum+15)/30;//������ϵ��,30��Ϊһ��,15�����²�����
		switch(K){
		case 1: SetMark(classhour*studnum);break;
		case 2: SetMark(classhour*(30+(studnum-30)*8/10));break;
		case 3: SetMark(classhour*(30+24+(studnum-60)*6/10));break;
		case 4: SetMark(classhour*(30+24+18+(studnum-90)*4/10));break;
		case 5: SetMark(classhour*(30+24+12+(studnum-120)*2/10));break;
		default:SetMark(classhour*(30+24+12+6+(studnum-150)*1/10));break;
		}
	}
};
int main(){
	Person *pp;
	Student s1("�ų�",20,80);
	Teacher t1("��Ӣ��",64,125),t2("�",80,85);
	pp=&s1;
	pp->CalMark();
	pp->Print();
	pp=&t1;
	pp->CalMark();
	pp->Print();
	pp=&t2;
	pp->CalMark();
	pp->Print();
	return 0;
}
