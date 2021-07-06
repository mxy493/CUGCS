//【例8.4】虚基类在多层多重继承中的应用--在职研究生类定义。
#include<iostream>
#include<string>
using namespace std;
enum Tsex{mid,man,woman};
//为简化,本例定义学生类时课程省略,并全部用string字符串
class Person{
	string IdPerson;			    //身份证号
	string Name;				    //姓名
	Tsex Sex;				        //性别
	int Birthday;				    //生日,格式1986年8月18日写作19860818
	string HomeAddress;		    //家庭地址
public:
	Person(string, string,Tsex,int, string);
	Person();
	~Person();
	void PrintPersonInfo();
	//其他接口函数
};
Person::Person(string id, string name,Tsex sex,int birthday, string homeadd){
	cout<<"构造Person"<<endl;
	IdPerson=id;
	Name=name;
	Sex=sex;
	Birthday=birthday;
	HomeAddress=homeadd;
}
Person::Person(){
	cout<<"构造Person"<<endl;
	IdPerson='\0';Name='\0';Sex=mid;
	Birthday=0;HomeAddress='\0';
}
Person::~Person(){
	cout<<"析构Person"<<endl;
} // IdPerson, Name, HomeAddress析构时自动调用它们自己的析构函数来释放内存空间
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
class Student:public virtual Person{           //以虚基类定义公有派生的学生类
	string NoStudent;                   //学号
	//30门课程与成绩略
public:
	Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud);
	//注意派生类构造函数声明方式
	Student();
    ~Student(){cout<<"析构Student"<<endl;}
	void PrintStudentInfo();
};
Student::Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud)
:Person(id,name,sex,birthday,homeadd){      //注意Person参数表不用类型
	cout<<"构造Student"<<endl;
	NoStudent=nostud;
}
Student::Student(){                        //基类缺省的无参数构造函数不必显式给出
	cout<<"构造Student"<<endl;
}
void Student::PrintStudentInfo(){
	cout<<"学号:"<<NoStudent<<'\n';
	PrintPersonInfo();
}
class GStudent:public Student{                   //以虚基类定义公有派生的研究生类
	string NoGStudent;                      //研究生号
	//其他略
public:
	GStudent(string id, string name,Tsex sex,int birthday, string homeadd, string nostud,
			string nogstudent);	                    //注意派生类构造函数声明方式
	GStudent();
	~GStudent(){cout<<"析构GStudent"<<endl;};
	void PrintGStudentInfo();
};
GStudent::GStudent(string id, string name,Tsex sex,	int birthday, string homeadd,
 string nostud, string nogstud)
:Student(id,name,sex,birthday,homeadd,nostud),Person(id,name,sex,birthday,homeadd){
	//因Person是虚基类,尽管不是直接基类,如定义GStudent对象，Person必须出现。
	//不定义对象可不出现，为通用应出现。如不是虚基类，出现是错误的
	cout<<"构造GStudent"<<endl;
	NoGStudent=nogstud;
}
GStudent::GStudent(){                      //基类缺省的无参数构造函数不必显式给出
	cout<<"构造GStudent"<<endl;
}
void GStudent::PrintGStudentInfo(){
	cout<<"研究生号:"<<NoGStudent<<'\n';
	PrintStudentInfo();
}
class Employee:public virtual Person{          //以虚基类定义公有派生的教职工类
	string NoEmployee;                  //教职工号
	//其他略
public:
	Employee(string id, string name,Tsex sex,int birthday, string homeadd, string noempl);
	//注意派生类构造函数声明方式
	Employee();
	~Employee(){cout<<"析构Employee"<<endl;}
	void PrintEmployeeInfo();
	void PrintEmployeeInfo1();   //多重继承时避免重复打印虚基类Person的信息
};
Employee::Employee(string id, string name,Tsex sex,int birthday, string homeadd, string noempl)
:Person(id,name,sex,birthday,homeadd){    //注意Person参数表可不用类型
	cout<<"构造Employee"<<endl;
	NoEmployee=noempl;
}
Employee::Employee(){                    //基类缺省的无参数构造函数不必显式给出
	cout<<"构造Employee"<<endl;
}
void Employee::PrintEmployeeInfo(){
	cout<<"教职工号:"<<NoEmployee<<'\n';
	PrintPersonInfo();
}
void Employee::PrintEmployeeInfo1(){cout<<"教职工号:"<<NoEmployee<<'\n';}
class EGStudent:public Employee,public GStudent{ //以虚基类定义公有派生的在职研究生类
	string NoEGStudent;                          //在职学习号
	//其他略
public:
	EGStudent(string id, string name,Tsex sex,int birthday, string homeadd, string nostud,
		string nogstud, string noempl, string noegstud);
	//注意派生类构造函数声明方式
	EGStudent();
	~EGStudent(){cout<<"析构EGStudent"<<endl;};
	void PrintEGStudentInfo();
};
EGStudent::EGStudent(string id, string name,Tsex sex,int birthday, string homeadd,
	string nostud, string nogstud, string noempl, string noegstud)
	:GStudent(id,name,sex,birthday,homeadd,nostud,nogstud),
	Employee(id,name,sex,birthday,homeadd,noempl),
	Person(id,name,sex,birthday,homeadd){ //注意要定义EGStudent对象，Person必须出现
	cout<<"构造EGStudent"<<endl;
	NoEGStudent=noegstud;
}
EGStudent::EGStudent(){                 //基类缺省的无参数构造函数不必显式给出
	cout<<"构造EGStudent"<<endl;
}
void EGStudent::PrintEGStudentInfo(){
	cout<<"在职学习号:"<<NoEGStudent<<'\n';
	PrintEmployeeInfo1();   //多重继承时避免重复打印虚基类Person的信息
	PrintGStudentInfo();    // 虚基类Person的信息仅在GStudent中打印
}
int main(void){
	EGStudent egstu1("320102811226161","朱海鹏",man,19811226,"南京市黄浦路1号",
		"06000123",	"034189","06283","030217");
	egstu1.PrintEGStudentInfo();
	GStudent gstu1("320102820818161","沈俊",man,19820818,"南京四牌楼2号",
		"08000312","058362");
	gstu1.PrintGStudentInfo();
	return 0;
}
