//【例8.6】计算学分。可由本科生类派生出研究生类，但它们各自的从课程学时数折算为学分数的
//算法是不同的，本科生是16个学时一学分，而研究生是20个学时一学分。
#include<iostream>
#include<string>
using namespace std;
class Student{
	string coursename;			//课程名
	int classhour;					//学时
	int credit;						//学分,未考虑0.5学分
public:
	Student(){coursename="#";classhour=0;credit=0;}
	virtual void Calculate(){credit=classhour/16;}
	void SetCourse(string str,int hour){
		coursename=str;
		classhour=hour;
	}
	int GetHour(){return classhour;}
	void SetCredit(int cred){credit=cred;} 
	void Print(){cout<<coursename<<'\t'<<classhour<<"学时"<<'\t'<<credit<<"学分"<<endl;}
};
class GradeStudent:public Student{
public:
	GradeStudent(){};
	void Calculate(){SetCredit(GetHour()/20);}
};
int main(){
	Student s,*ps;
	GradeStudent g;
	s.SetCourse("物理",80);
	s.Calculate();
	g.SetCourse("物理",80);
	g.Calculate();
	cout<<"本科生："<<'\t';
	s.Print();
	cout<<"研究生："<<'\t';
	g.Print();
	s.SetCourse("数学",160);
	g.SetCourse("数学",160);
	ps=&s;
	ps->Calculate();
	cout<<"本科生："<<'\t';
	ps->Print();
	ps=&g;
	ps->Calculate();
	cout<<"研究生："<<'\t';
	ps->Print();
	return 0;
}
