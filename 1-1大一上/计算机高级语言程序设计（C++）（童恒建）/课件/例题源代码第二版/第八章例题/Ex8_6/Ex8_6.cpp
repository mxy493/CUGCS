//����8.6������ѧ�֡����ɱ��������������о����࣬�����Ǹ��ԵĴӿγ�ѧʱ������Ϊѧ������
//�㷨�ǲ�ͬ�ģ���������16��ѧʱһѧ�֣����о�����20��ѧʱһѧ�֡�
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
int main(){
	Student s,*ps;
	GradeStudent g;
	s.SetCourse("����",80);
	s.Calculate();
	g.SetCourse("����",80);
	g.Calculate();
	cout<<"��������"<<'\t';
	s.Print();
	cout<<"�о�����"<<'\t';
	g.Print();
	s.SetCourse("��ѧ",160);
	g.SetCourse("��ѧ",160);
	ps=&s;
	ps->Calculate();
	cout<<"��������"<<'\t';
	ps->Print();
	ps=&g;
	ps->Calculate();
	cout<<"�о�����"<<'\t';
	ps->Print();
	return 0;
}
