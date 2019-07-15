//【例8.1】由在册人员类公有派生学生类。使用了动态生成的C风格字符串.
#include<iostream.h>
#include<string.h>

enum Tsex{mid,man,woman};
struct course{
	char* coursename;
	int grade;
};
class Person{
	char IdPerson[19];			//身份证号,18位数字
	char *Name;				//姓名
	Tsex Sex;				//性别
	int Birthday;				//生日,格式1986年8月18日写作19860818
	char *HomeAddress;		//家庭地址
public:
	Person(char *,char *,Tsex,int,char *);
	Person();
	~Person();
	void SetName(char *);
	char *GetName(){return Name;}
	void SetSex(Tsex sex){Sex=sex;}
	Tsex GetSex(){return Sex;}
	void SetId(char *id){strcpy(IdPerson,id);}
	char *GetId(){return IdPerson;}
	void SetBirth(int birthday){Birthday=birthday;}
	int GetBirth(){return Birthday;}
	void SetHomeAdd(char *);
	char *GetHomeAdd(){return HomeAddress;}
	void PrintPersonInfo();
};
Person::Person(char *id,char *name,Tsex sex,int birthday,char *homeadd){
	strcpy(IdPerson,id);
	Name=new char[strlen(name)+1];
	strcpy(Name,name);
	Sex=sex;
	Birthday=birthday;
	HomeAddress=new char[strlen(homeadd)+1];
	strcpy(HomeAddress,homeadd);
}//作为一个管理程序,这个构造函数并无必要,因为数据总是另外输入的。仅为说明语法存在。
Person::Person(){
	IdPerson[0]='\0';Name=NULL;Sex=mid;
	Birthday=0;HomeAddress=NULL;
}
Person::~Person(){
	if(Name)delete [] Name;if(HomeAddress) delete [] HomeAddress;
}
void Person::SetName(char *name){
	if(Name) delete [] Name;//删去原来的姓名
	Name=new char[strlen(name)+1];//重新分配内存
	strcpy(Name,name);//拷入新姓名
}
void Person::SetHomeAdd(char *homeadd){
	if(HomeAddress) delete [] HomeAddress;
	HomeAddress=new char[strlen(homeadd)+1];
	strcpy(HomeAddress,homeadd);
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
	char NoStudent[10];//学号
	course cs[30];//30门课程与成绩
public:
	Student(char *id,char *name,Tsex sex,int birthday,char *homeadd,char* nostud);
	//注意派生类构造函数声明方式
	Student();
	~Student();
	SetCourse(char *,int);
	int GetCourse(char *);
	void PrintStudentInfo();
};
Student::Student(char*id,char*name,Tsex sex,int birthday,char*homeadd,char*nostud)
             :Person(id,name,sex,birthday,homeadd){//注意Person参数表不用类型
	strcpy(NoStudent,nostud);
	for(int i=0;i<30;i++){//课程与成绩清空
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::Student(){//基类缺省的无参数构造函数不必显式给出
	NoStudent[0]='\0';
	for(int i=0;i<30;i++){//课程与成绩清零,将来由键盘输入 
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::~Student(){//基类析构函数不必显式给出
	for(int i=0;i<30;i++)
		if(cs[i].coursename)delete [] cs[i].coursename;
}//清除各课程名称不可少,它们放在堆区中
int Student::SetCourse(char *coursename,int grade){
	bool b=false;//标识新输入的课程,还是更新成绩
	for(int i=0;i<30;i++){
		if(cs[i].coursename==NULL){
			//判表是否进入未使用部分（如有对应删除应按顺序表方式）
			cs[i].coursename=new char[strlen(coursename)+1];
			strcpy(cs[i].coursename,coursename);
			cs[i].grade=grade;
			b=false;
			break;
		}
		else if(!strcmp(cs[i].coursename,coursename)){
			//后查是否已有该课程记录。如先查，因strcmp()健壮型不好，遇NULL出错
			cs[i].grade=grade;
			b=true;
			break;
		}
	}
	if(i==30) return 0;//成绩表满返回0
	if(b) return 1;//修改成绩返回1
	else return 2;//登记成绩返回2
}
int Student::GetCourse(char *coursename){
	for(int i=0;i<30;i++)
		if(cs[i].coursename==NULL) break;//无此句，stcpy()会出错
		else if(!strcmp(cs[i].coursename,coursename))return cs[i].grade;
	return -1;
}//找到返回成绩,未找到返回-1
void Student::PrintStudentInfo(){
	int i;
	cout<<"学号:"<<NoStudent<<'\n';
	PrintPersonInfo();
	for(i=0;i<30;i++)//打印各科成绩
		if(cs[i].coursename!=NULL)cout<<cs[i].coursename<<'\t'<<cs[i].grade<<'\n';
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
	Student stu1("320102811226161","朱海鹏",man,19811226,"南京市黄浦路1号","06000123");
	cout<<"请输入各科成绩:"<<'\n';
	//为简单仅以一个学生为例。完整应输入学号，查找，再操作
	while(1){//输入各科成绩,输入"end"停止
		cin>>temp;//输入格式:物理  80
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
