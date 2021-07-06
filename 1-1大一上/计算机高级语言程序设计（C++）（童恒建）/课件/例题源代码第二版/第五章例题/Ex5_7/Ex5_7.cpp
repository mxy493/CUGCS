//【例5.7】通过结构指针来访问结构成员。
#include<iostream>
#include<cstring>
using namespace std;

struct student{
	char name[20];
	char id[10];//学号最好用字符串，当学号以0开头，整数会丢失0甚至认为是八进制
	int age;
	float score;
	char address[30];
};

int main(){
	student st1,*prst;
	prst=&st1;
	cout<<"请输入学生的姓名："<<endl;
	cin.getline(st1.name,20);//cin.getline可输入空格
	cout<<"请输入学号、年龄和入学成绩："<<endl;
	cin>>st1.id>>st1.age>>st1.score;
	cin.get();//吸收掉换行回车符
	cout<<"请输入家庭住址："<<endl;
	cin.getline(st1.address,30);
	cout<<"姓名"<<'\t'<<prst->name<<'\n';
	cout<<"学号"<<'\t'<<prst->id<<'\n';
	cout<<"年龄"<<'\t'<<prst->age<<'\n';
	cout<<"入学成绩"<<'\t'<<prst->score<<'\n';
	cout<<"家庭住址"<<'\t'<<prst->address<<endl;
	return 0;
}
