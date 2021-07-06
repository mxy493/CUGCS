//【例8.5_1】根据赋值兼容规则可以用基类的指针指向派生类对象，如果由该指针撤销
//派生类对象，则必须将析构函数说明为虚函数，实现多态性，自动调用派生类析构函数。
#include<iostream>
#include<string>
using namespace std;

enum Tsex{mid,man,woman};
struct course{
	string coursename;
	int grade;
};
class Person{
	string IdPerson;			//身份证号
	string Name;				//姓名
	Tsex Sex;				//性别
	int Birthday;				//生日,格式1986年8月18日写作19860818
	string HomeAddress;		//家庭地址
public:
	Person(string,string,Tsex,int,string);
	Person();
	Person(Person &ps);
	virtual ~Person();
	Person & operator=(Person &);
	void PrintPersonInfo();
};
Person::Person(string id,string name,Tsex sex,int birthday,string homeadd){
	IdPerson=id;
	Name=name;
	Sex=sex;
	Birthday=birthday;
	HomeAddress=homeadd;
}
Person::Person(){
	IdPerson="#";Name="#";Sex=mid;
	Birthday=0;HomeAddress="#";
}
Person::Person(Person &ps){
	IdPerson=ps.IdPerson;
	Name=ps.Name;
	Sex=ps.Sex;
	Birthday=ps.Birthday;
	HomeAddress=ps.HomeAddress;
}
Person::~Person(){cout<<"Person析构函数"<<endl;}
Person & Person::operator=(Person &ps){
	IdPerson=ps.IdPerson;
	Name=ps.Name;
	Sex=ps.Sex;
	Birthday=ps.Birthday;
	HomeAddress=ps.HomeAddress;
	return *this;
}
void Person::PrintPersonInfo(){
	int i;
	cout<<"身份证号:"<<IdPerson<<'\n'<<"姓名:"<<Name<<'\n'<<"性别:";
	if(Sex==man)cout<<"男"<<'\n';
	else if(Sex==woman)cout<<"女"<<'\n';
	     else cout<<" "<<'\n';
	cout<<"出生年月日:";
	i=Birthday;
	cout<<i/10000<<"年";
	i=i%10000;
	cout<<i/100<<"月"<<i%100<<"日"<<'\n'<<"家庭住址:"<<HomeAddress<<'\n';
}

class Student:public Person{//定义派生的学生类
	string NoStudent;//学号
	course cs[30];//30门课程与成绩
public:
	Student(string id,string name,Tsex sex,int birthday,string homeadd,string nostud);
	//注意派生类构造函数声明方式
	Student();
	Student(Student &Std);
	~Student();
	Student & operator=(Student &Std);
	int SetCourse(string,int);
	int GetCourse(string);
	void PrintStudentInfo();
};
Student::Student(string id,string name,Tsex sex,int birthday,string homeadd,string nostud)
             :Person(id,name,sex,birthday,homeadd){//注意Person参数表不用类型
	NoStudent=nostud;
	for(int i=0;i<30;i++){//课程与成绩清空
		cs[i].coursename="#";
		cs[i].grade=0;
	}
}
Student::Student(){//基类缺省的无参数构造函数不必显式给出
	NoStudent="#";
	for(int i=0;i<30;i++){//课程与成绩清零,将来由键盘输入 
		cs[i].coursename="#";
		cs[i].grade=0;
	}
}
Student::Student(Student &Std):Person(Std){//按赋值兼容规则Std可为Person实参
	NoStudent=Std.NoStudent;
	for(int i=0;i<30;i++){
		cs[i].coursename=Std.cs[i].coursename;
		cs[i].grade=Std.cs[i].grade;
	}
}
Student::~Student(){cout<<"Student析构函数"<<endl;}//基类析构函数不必显式给出

Student & Student::operator=(Student &Std){
	this->Person::operator=(Std);
	NoStudent=Std.NoStudent;
	for(int i=0;i<30;i++){
		cs[i].coursename=Std.cs[i].coursename;
		cs[i].grade=Std.cs[i].grade;
	}
	return *this;
}
int Student::SetCourse(string coursename,int grade){
	bool b=false;//标识新输入的课程,还是更新成绩
	for(int i=0;i<30;i++){
		if(cs[i].coursename=="#"){
			//判表是否进入未使用部分（如有对应删除应按顺序表方式）
			cs[i].coursename=coursename;
			cs[i].grade=grade;
			b=false;
			break;
		}
		else if(cs[i].coursename==coursename){
			cs[i].grade=grade;
			b=true;
			break;
		}
	}
	if(i==30) return 0;//成绩表满返回0
	if(b) return 1;//修改成绩返回1
	else return 2;//登记成绩返回2
}
int Student::GetCourse(string coursename){
	for(int i=0;i<30;i++)
		if(cs[i].coursename=="#") break;//无此句，stcpy()会出错
		else if(cs[i].coursename==coursename) return cs[i].grade;
	return -1;
}//找到返回成绩,未找到返回-1
void Student::PrintStudentInfo(){
	int i;
	cout<<"学号:"<<NoStudent<<'\n';
	PrintPersonInfo();
	for(i=0;i<30;i++)//打印各科成绩
		if(cs[i].coursename!="#")cout<<cs[i].coursename<<'\t'<<cs[i].grade<<'\n';
		else break;
	cout<<"--------完-------- "<<endl;
}

int main(void){
	string temp;
	int i,k;
	Student stu1("320102811226161","朱海鹏",man,19811226,"南京市黄浦路1号","06000123");
	cout<<"请输入各科成绩:"<<'\n';//为简单仅以一个学生为例。完整应输入学号，查找，再操作
	while(1){//输入各科成绩,输入"end"停止
		cin>>temp;//输入格式:物理  80
		if(temp=="end") break;
		cin>>k;
		i=stu1.SetCourse(temp,k);
		if(i==0)cout<<"成绩列表已满!"<<'\n';
		else if(i==1)cout<<"修改成绩"<<'\n';
		     else cout<<"登记成绩"<<'\n';
    }
	stu1.PrintStudentInfo();
	Person *pper4;
	Student	*pstu4=new Student;       //动态建立对象*stu4
	*pstu4=stu1;				       //把stu1的数据拷入*stu4
	pstu4->PrintStudentInfo();
	pper4=pstu4;
	delete pper4;				//用基类指针撤销派生类，动态生成的对象必须显式撤销
	return 0;
}
