//【例8.1】由在册人员类公有派生学生类。
#include<iostream>
#include<string>
using namespace std;
enum Tsex{mid,man,woman};
struct course{
	string coursename;
	int grade;
};
class Person{
	string IdPerson;			//身份证号,18位数字
	string Name;				//姓名
	Tsex Sex;				    //性别
	int Birthday;				//生日,格式1986年8月18日写作19860818
	string HomeAddress;		//家庭地址
public:
	Person(string, string,Tsex,int, string);
	Person();
	~Person();
	void SetName(string);
	string GetName(){return Name;}
	void SetSex(Tsex sex){Sex=sex;}
	Tsex GetSex(){return Sex;}
	void SetId(string id){IdPerson=id;}
	string GetId(){return IdPerson;}
	void SetBirth(int birthday){Birthday=birthday;}
	int GetBirth(){return Birthday;}
	void SetHomeAdd(string );
	string GetHomeAdd(){return HomeAddress;}
	void PrintPersonInfo();
};
Person::Person(string id, string name,Tsex sex,int birthday, string homeadd){
	IdPerson=id;
	Name=name;
	Sex=sex;
	Birthday=birthday;
	HomeAddress=homeadd;
}//作为一个管理程序,这个构造函数并无必要,因为数据总是另外输入的。仅为说明语法存在。
Person::Person(){
	IdPerson="#";Name="#";Sex=mid;
	Birthday=0;HomeAddress="#";
}
Person::~Person(){}  //string内部动态数组的释放，由string自带的析构函数完成
void Person::SetName(string name){
	Name=name;                    //拷入新姓名
}
void Person::SetHomeAdd(string homeadd){
	HomeAddress=homeadd;
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
class Student:public Person{                     //定义派生的学生类
	string NoStudent;                        //学号
	course cs[30];                             //30门课程与成绩
public:
	Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud);
	//注意派生类构造函数声明方式
	Student();
	~Student();
	int SetCourse(string,int);
	int GetCourse(string);
	void PrintStudentInfo();
};
Student::Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud)
             :Person(id,name,sex,birthday,homeadd){    //注意Person参数表不用类型
	int i;
	NoStudent=nostud;
	for(i=0;i<30;i++){                            //课程与成绩清空
		cs[i].coursename="#";
		cs[i].grade=0;
	}
}
Student::Student(){                     //基类缺省的无参数构造函数不必显式给出
	int i;
	NoStudent="";
	for(i=0;i<30;i++){               //课程与成绩清零,将来由键盘输入 
		cs[i].coursename="";
		cs[i].grade=0;
	}
}
Student::~Student(){}   //基类析构函数以及成员对象析构函数自动调用
int Student::SetCourse(string coursename,int grade){
	int i;
	bool b=false;                        //标识新输入的课程,还是更新成绩
	for(i=0;i<30;i++){
		if(cs[i].coursename=="#"){
			//判表是否进入未使用部分（如有对应删除,应按顺序表方式）
			cs[i].coursename=coursename;
			cs[i].grade=grade;
			b=false;
			break;
		}
		else if(cs[i].coursename==coursename){
			//是否已有该课程记录
			cs[i].grade=grade;
			b=true;
			break;
		}
	}
	if(i==30) return 0;      //成绩表满返回0
	if(b) return 1;          //修改成绩返回1
	else return 2;          //登记成绩返回2
}
int Student::GetCourse(string coursename){
	for(int i=0;i<30;i++) if(cs[i].coursename==coursename) return cs[i].grade;
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
	char temp[30];
	int i,k;
	Person per1("320102820818161","沈俊",man,19820818,"南京四牌楼2号");
	Person per2;
	per2.SetName("朱明");
	per2.SetSex(woman);
	per2.SetBirth(19780528);
	per2.SetId("320102780528162");
	per2.SetHomeAdd("南京市成贤街9号");
	per1.PrintPersonInfo();
	per2.PrintPersonInfo();
	Student stu1("320102811226161","朱海鹏",man,19811226,"南京市黄浦路1号",
		"06000123");
	cout<<"请输入各科成绩:"<<'\n';         //完整的程序应输入学号,查找,再操作
	while(1){                            //输入各科成绩,输入"end"停止
		cin>>temp;                       //输入格式:物理  80
		if(!strcmp(temp,"end")) break;
		cin>>k;
		i=stu1.SetCourse(temp,k);
		if(i==0)cout<<"成绩列表已满!"<<'\n';
		else if(i==1)cout<<"修改成绩"<<'\n';
		     else cout<<"登记成绩"<<'\n';
    }
	stu1.PrintStudentInfo();
	while(1){
		cout<<"查询成绩"<<'\n'<<"请输入科目:"<<'\n';
		cin>>temp;
		if(!strcmp(temp,"end")) break;
		k=stu1.GetCourse(temp);
		if(k==-1)cout<<"未查到"<<'\n';
		else cout<<k<<'\n';
	}
	return 0;
}
