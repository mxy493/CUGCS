//����8.7������ѧ�֡�
#include<iostream>
#include<string>
using namespace std;

class Student{
	string coursename;			//�γ���
	int classhour;					//ѧʱ
	int credit;						//ѧ��,δ����0.5ѧ��
public:
	Student(){coursename="#";classhour=0;credit=0;}
	virtual void Calculate(){credit=classhour/16;}
	void SetCourse(string str,int hour){
		coursename=str;
		classhour=hour;
	}
	int GetHour(){return classhour;}
	void SetCredit(int cred){credit=cred;} 
	void Print(){cout<<coursename<<'\t'<<classhour<<"ѧʱ"<<'\t'<<credit<<"ѧ��"<<endl;}
};
class GradeStudent:public Student{
public:
	GradeStudent(){};
	void Calculate(){SetCredit(GetHour()/20);}
};

void Calfun(Student &ps,string str,int hour){
	ps.SetCourse(str,hour);
	ps.Calculate();
	ps.Print();
}
int main(){
	Student s;
	GradeStudent g;
	cout<<"������:";
	Calfun(s,"����",80);
	cout<<"�о���:";
	Calfun(g,"����",80);//����������ʼ�����������,ֻ��calculate()Ϊ�麯������ʵ�ֶ�̬�Ķ�̬��
	return 0;
}
