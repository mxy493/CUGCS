//【例4.6】含有成员对象的类的构造函数：
#include<iostream>
#include<cstring>
using namespace std;

class studentID{
	long value;
public:
	studentID(long id=0){
		value=id;
		cout<<"赋给学生的学号："<<value<<endl;
	}
	~studentID(){
		cout<<"删除学号："<<value<<endl;
	}
};

class student{
private:
	studentID id;
	char name[20];
public:
	student (char sname[]="no name",long sid=0):id(sid){
		cout<<"学生名："<<sname<<endl;
		strcpy(name,sname);
	}
	~student(){
		cout<<"删除学生名："<<name<<endl;
	}
};

int main(){
	student ss("朱明",82020132);
	return 0;
}
