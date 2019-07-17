//【例8.7】计算学分。
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

void Calfun(Student &ps,string str,int hour){
	ps.SetCourse(str,hour);
	ps.Calculate();
	ps.Print();
}
int main(){
	Student s;
	GradeStudent g;
	cout<<"本科生:";
	Calfun(s,"物理",80);
	cout<<"研究生:";
	Calfun(g,"物理",80);//派生类对象初始化基类的引用,只有calculate()为虚函数才能实现动态的多态性
	return 0;
}
