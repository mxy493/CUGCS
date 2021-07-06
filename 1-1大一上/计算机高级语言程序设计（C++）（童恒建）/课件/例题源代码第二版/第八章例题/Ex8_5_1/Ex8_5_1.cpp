//����8.5_1�����ݸ�ֵ���ݹ�������û����ָ��ָ���������������ɸ�ָ�볷��
//�������������뽫��������˵��Ϊ�麯����ʵ�ֶ�̬�ԣ��Զ���������������������
#include<iostream>
#include<string>
using namespace std;

enum Tsex{mid,man,woman};
struct course{
	string coursename;
	int grade;
};
class Person{
	string IdPerson;			//���֤��
	string Name;				//����
	Tsex Sex;				//�Ա�
	int Birthday;				//����,��ʽ1986��8��18��д��19860818
	string HomeAddress;		//��ͥ��ַ
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
Person::~Person(){cout<<"Person��������"<<endl;}
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

class Student:public Person{//����������ѧ����
	string NoStudent;//ѧ��
	course cs[30];//30�ſγ���ɼ�
public:
	Student(string id,string name,Tsex sex,int birthday,string homeadd,string nostud);
	//ע�������๹�캯��������ʽ
	Student();
	Student(Student &Std);
	~Student();
	Student & operator=(Student &Std);
	int SetCourse(string,int);
	int GetCourse(string);
	void PrintStudentInfo();
};
Student::Student(string id,string name,Tsex sex,int birthday,string homeadd,string nostud)
             :Person(id,name,sex,birthday,homeadd){//ע��Person������������
	NoStudent=nostud;
	for(int i=0;i<30;i++){//�γ���ɼ����
		cs[i].coursename="#";
		cs[i].grade=0;
	}
}
Student::Student(){//����ȱʡ���޲������캯��������ʽ����
	NoStudent="#";
	for(int i=0;i<30;i++){//�γ���ɼ�����,�����ɼ������� 
		cs[i].coursename="#";
		cs[i].grade=0;
	}
}
Student::Student(Student &Std):Person(Std){//����ֵ���ݹ���Std��ΪPersonʵ��
	NoStudent=Std.NoStudent;
	for(int i=0;i<30;i++){
		cs[i].coursename=Std.cs[i].coursename;
		cs[i].grade=Std.cs[i].grade;
	}
}
Student::~Student(){cout<<"Student��������"<<endl;}//������������������ʽ����

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
	bool b=false;//��ʶ������Ŀγ�,���Ǹ��³ɼ�
	for(int i=0;i<30;i++){
		if(cs[i].coursename=="#"){
			//�б��Ƿ����δʹ�ò��֣����ж�Ӧɾ��Ӧ��˳���ʽ��
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
	if(i==30) return 0;//�ɼ���������0
	if(b) return 1;//�޸ĳɼ�����1
	else return 2;//�Ǽǳɼ�����2
}
int Student::GetCourse(string coursename){
	for(int i=0;i<30;i++)
		if(cs[i].coursename=="#") break;//�޴˾䣬stcpy()�����
		else if(cs[i].coursename==coursename) return cs[i].grade;
	return -1;
}//�ҵ����سɼ�,δ�ҵ�����-1
void Student::PrintStudentInfo(){
	int i;
	cout<<"ѧ��:"<<NoStudent<<'\n';
	PrintPersonInfo();
	for(i=0;i<30;i++)//��ӡ���Ƴɼ�
		if(cs[i].coursename!="#")cout<<cs[i].coursename<<'\t'<<cs[i].grade<<'\n';
		else break;
	cout<<"--------��-------- "<<endl;
}

int main(void){
	string temp;
	int i,k;
	Student stu1("320102811226161","�캣��",man,19811226,"�Ͼ��л���·1��","06000123");
	cout<<"��������Ƴɼ�:"<<'\n';//Ϊ�򵥽���һ��ѧ��Ϊ��������Ӧ����ѧ�ţ����ң��ٲ���
	while(1){//������Ƴɼ�,����"end"ֹͣ
		cin>>temp;//�����ʽ:����  80
		if(temp=="end") break;
		cin>>k;
		i=stu1.SetCourse(temp,k);
		if(i==0)cout<<"�ɼ��б�����!"<<'\n';
		else if(i==1)cout<<"�޸ĳɼ�"<<'\n';
		     else cout<<"�Ǽǳɼ�"<<'\n';
    }
	stu1.PrintStudentInfo();
	Person *pper4;
	Student	*pstu4=new Student;       //��̬��������*stu4
	*pstu4=stu1;				       //��stu1�����ݿ���*stu4
	pstu4->PrintStudentInfo();
	pper4=pstu4;
	delete pper4;				//�û���ָ�볷�������࣬��̬���ɵĶ��������ʽ����
	return 0;
}
