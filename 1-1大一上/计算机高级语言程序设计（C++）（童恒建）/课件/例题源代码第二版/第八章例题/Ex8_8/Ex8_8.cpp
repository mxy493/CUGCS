//【例8.8】学校对在册人员进行奖励，依据是业绩分，但是业绩分的计算方法只能对具体人
//员进行，如学生，教师，行政人员，工人，算法都不同，所以可以将在册人员类作为一个抽
//象类，业绩计算方法作为一个纯虚函数。
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
	virtual void CalMark()=0;//CalMark()为虚函数,Person为抽象类
	void Print(){cout<<Name<<"的业绩分为:"<<MarkAchieve<<endl;}	
};
class Student:public Person{
	int credit,grade;//学历和成绩
public:
	Student(string name,int cred,int grad):Person(name){
		credit=cred;
		grade=grad;
	}
	void CalMark(){SetMark(credit*grade);}
};
class Teacher:public Person{
	int classhour,studnum;//授课学时和学生人数
public:
	Teacher(string name,int ch,int sn):Person(name){
		classhour=ch;
		studnum=sn;
	}
	void CalMark(){
		int K=(studnum+15)/30;//工作量系数,30人为一班,15人以下不开课
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
	Student s1("张成",20,80);
	Teacher t1("范英明",64,125),t2("李凯",80,85);
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
