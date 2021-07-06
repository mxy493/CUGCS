//����8.4��������ڶ����ؼ̳��е�Ӧ��--��ְ�о����ඨ�塣
#include<iostream>
#include<string>
using namespace std;
enum Tsex{mid,man,woman};
//Ϊ��,��������ѧ����ʱ�γ�ʡ��,��ȫ����string�ַ���
class Person{
	string IdPerson;			    //���֤��
	string Name;				    //����
	Tsex Sex;				        //�Ա�
	int Birthday;				    //����,��ʽ1986��8��18��д��19860818
	string HomeAddress;		    //��ͥ��ַ
public:
	Person(string, string,Tsex,int, string);
	Person();
	~Person();
	void PrintPersonInfo();
	//�����ӿں���
};
Person::Person(string id, string name,Tsex sex,int birthday, string homeadd){
	cout<<"����Person"<<endl;
	IdPerson=id;
	Name=name;
	Sex=sex;
	Birthday=birthday;
	HomeAddress=homeadd;
}
Person::Person(){
	cout<<"����Person"<<endl;
	IdPerson='\0';Name='\0';Sex=mid;
	Birthday=0;HomeAddress='\0';
}
Person::~Person(){
	cout<<"����Person"<<endl;
} // IdPerson, Name, HomeAddress����ʱ�Զ����������Լ��������������ͷ��ڴ�ռ�
void Person::PrintPersonInfo(){
	int i;
	cout<<"���֤��:"<<IdPerson<<'\n'<<"����:"<<Name<<'\n'<<"�Ա�:";
	if(Sex==man)cout<<"��"<<'\n';
	else if(Sex==woman)cout<<"Ů"<<'\n';
	     else cout<<" "<<'\n';
	cout<<"����������:";
	i=Birthday;
	cout<<i/10000<<"��";
	i=i%10000;
	cout<<i/100<<"��"<<i%100<<"��"<<'\n'<<"��ͥסַ:"<<HomeAddress<<'\n';
}
class Student:public virtual Person{           //������ඨ�幫��������ѧ����
	string NoStudent;                   //ѧ��
	//30�ſγ���ɼ���
public:
	Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud);
	//ע�������๹�캯��������ʽ
	Student();
    ~Student(){cout<<"����Student"<<endl;}
	void PrintStudentInfo();
};
Student::Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud)
:Person(id,name,sex,birthday,homeadd){      //ע��Person������������
	cout<<"����Student"<<endl;
	NoStudent=nostud;
}
Student::Student(){                        //����ȱʡ���޲������캯��������ʽ����
	cout<<"����Student"<<endl;
}
void Student::PrintStudentInfo(){
	cout<<"ѧ��:"<<NoStudent<<'\n';
	PrintPersonInfo();
}
class GStudent:public Student{                   //������ඨ�幫���������о�����
	string NoGStudent;                      //�о�����
	//������
public:
	GStudent(string id, string name,Tsex sex,int birthday, string homeadd, string nostud,
			string nogstudent);	                    //ע�������๹�캯��������ʽ
	GStudent();
	~GStudent(){cout<<"����GStudent"<<endl;};
	void PrintGStudentInfo();
};
GStudent::GStudent(string id, string name,Tsex sex,	int birthday, string homeadd,
 string nostud, string nogstud)
:Student(id,name,sex,birthday,homeadd,nostud),Person(id,name,sex,birthday,homeadd){
	//��Person�������,���ܲ���ֱ�ӻ���,�綨��GStudent����Person������֡�
	//���������ɲ����֣�Ϊͨ��Ӧ���֡��粻������࣬�����Ǵ����
	cout<<"����GStudent"<<endl;
	NoGStudent=nogstud;
}
GStudent::GStudent(){                      //����ȱʡ���޲������캯��������ʽ����
	cout<<"����GStudent"<<endl;
}
void GStudent::PrintGStudentInfo(){
	cout<<"�о�����:"<<NoGStudent<<'\n';
	PrintStudentInfo();
}
class Employee:public virtual Person{          //������ඨ�幫�������Ľ�ְ����
	string NoEmployee;                  //��ְ����
	//������
public:
	Employee(string id, string name,Tsex sex,int birthday, string homeadd, string noempl);
	//ע�������๹�캯��������ʽ
	Employee();
	~Employee(){cout<<"����Employee"<<endl;}
	void PrintEmployeeInfo();
	void PrintEmployeeInfo1();   //���ؼ̳�ʱ�����ظ���ӡ�����Person����Ϣ
};
Employee::Employee(string id, string name,Tsex sex,int birthday, string homeadd, string noempl)
:Person(id,name,sex,birthday,homeadd){    //ע��Person������ɲ�������
	cout<<"����Employee"<<endl;
	NoEmployee=noempl;
}
Employee::Employee(){                    //����ȱʡ���޲������캯��������ʽ����
	cout<<"����Employee"<<endl;
}
void Employee::PrintEmployeeInfo(){
	cout<<"��ְ����:"<<NoEmployee<<'\n';
	PrintPersonInfo();
}
void Employee::PrintEmployeeInfo1(){cout<<"��ְ����:"<<NoEmployee<<'\n';}
class EGStudent:public Employee,public GStudent{ //������ඨ�幫����������ְ�о�����
	string NoEGStudent;                          //��ְѧϰ��
	//������
public:
	EGStudent(string id, string name,Tsex sex,int birthday, string homeadd, string nostud,
		string nogstud, string noempl, string noegstud);
	//ע�������๹�캯��������ʽ
	EGStudent();
	~EGStudent(){cout<<"����EGStudent"<<endl;};
	void PrintEGStudentInfo();
};
EGStudent::EGStudent(string id, string name,Tsex sex,int birthday, string homeadd,
	string nostud, string nogstud, string noempl, string noegstud)
	:GStudent(id,name,sex,birthday,homeadd,nostud,nogstud),
	Employee(id,name,sex,birthday,homeadd,noempl),
	Person(id,name,sex,birthday,homeadd){ //ע��Ҫ����EGStudent����Person�������
	cout<<"����EGStudent"<<endl;
	NoEGStudent=noegstud;
}
EGStudent::EGStudent(){                 //����ȱʡ���޲������캯��������ʽ����
	cout<<"����EGStudent"<<endl;
}
void EGStudent::PrintEGStudentInfo(){
	cout<<"��ְѧϰ��:"<<NoEGStudent<<'\n';
	PrintEmployeeInfo1();   //���ؼ̳�ʱ�����ظ���ӡ�����Person����Ϣ
	PrintGStudentInfo();    // �����Person����Ϣ����GStudent�д�ӡ
}
int main(void){
	EGStudent egstu1("320102811226161","�캣��",man,19811226,"�Ͼ��л���·1��",
		"06000123",	"034189","06283","030217");
	egstu1.PrintEGStudentInfo();
	GStudent gstu1("320102820818161","��",man,19820818,"�Ͼ�����¥2��",
		"08000312","058362");
	gstu1.PrintGStudentInfo();
	return 0;
}
