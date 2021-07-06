//����8.5_2����ֵ���ݹ������Զ���Ŀ������캯�������ö�̬������C����ַ����������
#include<iostream>
#include<cstring>
using namespace std;

enum Tsex{mid,man,woman};
struct course{
	char* coursename;
	int grade;
};
class Person{
	char IdPerson[19];			//���֤��,18λ����
	char *Name;				//����
	Tsex Sex;				//�Ա�
	int Birthday;				//����,��ʽ1986��8��18��д��19860818
	char *HomeAddress;		//��ͥ��ַ
public:
	Person(char *,char *,Tsex,int,char *);
	Person();
	Person(Person &ps);
	~Person();
	Person & operator=(const Person &);
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
}
Person::Person(){
	IdPerson[0]='\0';Name=NULL;Sex=mid;
	Birthday=0;HomeAddress=NULL;
}
Person::Person(Person &ps){
	strcpy(IdPerson,ps.IdPerson);
	if(ps.Name!=NULL){
		Name=new char[strlen(ps.Name)+1];
		strcpy(Name,ps.Name);
	}
	else Name=NULL;
	Sex=ps.Sex;
	Birthday=ps.Birthday;
	if(ps.HomeAddress!=NULL){
		HomeAddress=new char[strlen(ps.HomeAddress)+1];
		strcpy(HomeAddress,ps.HomeAddress);
	}
	else HomeAddress=NULL;
}
Person::~Person(){
	if(Name)delete[]Name;if(HomeAddress) delete [] HomeAddress;
}
Person & Person::operator=(const Person &ps){
	strcpy(IdPerson,ps.IdPerson);
	if(ps.Name!=NULL){
		delete[]Name;//��ֵҪ����ԭ������Ŀռ�
		Name=new char[strlen(ps.Name)+1];
		strcpy(Name,ps.Name);
	}
	else Name=NULL;
	Sex=ps.Sex;
	Birthday=ps.Birthday;
	if(ps.HomeAddress!=NULL){
		delete [] HomeAddress;//��ֵҪ����ԭ������Ŀռ�,�����·���
		HomeAddress=new char[strlen(ps.HomeAddress)+1];
		strcpy(HomeAddress,ps.HomeAddress);
	}
	else {
		delete [] HomeAddress;
		HomeAddress=NULL;
	}
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

class Student:public Person{//����������Q�����
	char NoStudent[10];//ѧ��
	course cs[30];//30�ſγ���ɼ�
public:
	Student(char*id,char*name,Tsex sex,int birthday,char*homeadd,char*nostud);
	//ע�������๹�캯����C���ʽ
	Student();
	Student(Student &Std);
	~Student();
	Student & operator=(const Student &Std);
	SetCourse(char *,int);
	int GetCourse(char *);
	void PrintStudentInfo();
};
Student::Student(char*id,char*name,Tsex sex,int birthday,char*homeadd,char*nostud)
             :Person(id,name,sex,birthday,homeadd){//ע��Person������������
	strcpy(NoStudent,nostud);
	for(int i=0;i<30;i++){//�N����ɼ���?�
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::Student(){//����ȱʡ���޲��}���캯������O�ʽ����
	NoStudent[10]=NULL;
	for(int i=0;i<30;i++){//�γ���ɼ�����,�����ɼ������� 
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::Student(Student &Std):Person(Std){//����ֵ���ݹ���Std��ΪPersonʵ��
	strcpy(NoStudent,Std.NoStudent);
	for(int i=0;i<30;i++){
		if(Std.cs[i].coursename!=NULL){
			cs[i].coursename=new char[strlen(Std.cs[i].coursename)+1];
			strcpy(cs[i].coursename,Std.cs[i].coursename);
		}
		else cs[i].coursename=NULL;
		cs[i].grade=Std.cs[i].grade;
	}
}
Student::~Student(){//������������������ʽ����
	for(int i=0;i<30;i++)
		if(cs[i].coursename)delete [] cs[i].coursename;
}//������γ����Ʋ�����,���Ƿ��ڶ�����
Student & Student::operator=(const Student &Std){
	this->Person::operator=(Std);
	strcpy(NoStudent,Std.NoStudent);
	for(int i=0;i<30;i++){
		if(Std.cs[i].coursename!=NULL){
			delete [] cs[i].coursename;//����Ҫ����ԭ���V��ռ�,T����·���
			cs[i].coursename=new char[strlen(Std.cs[i].coursename)+1];
			strcpy(cs[i].coursename,Std.cs[i].coursename);
		}
		else cs[i].coursename=NULL;
		cs[i].grade=Std.cs[i].grade;
	}
	return *this;
}
int Student::SetCourse(char *coursename,int grade){
	bool b=false;//��ʶ������Ŀγ�,���Ǹ��³ɼ�
	for(int i=0;i<30;i++){
		if(cs[i].coursename==NULL){
			//�б��Ƿ����δʹ�ò��֣����ж�Ӧɾ��Ӧ��˳���ʽ��
			cs[i].coursename=new char[strlen(coursename)+1];
			strcpy(cs[i].coursename,coursename);
			cs[i].grade=grade;
			b=false;
			break;
		}
		else if(!strcmp(cs[i].coursename,coursename)){
			//����Ƿ����иÿγ̼�¼�����Ȳ飬��strcmp()��׳�Ͳ��ã���NULL����
			cs[i].grade=grade;
			b=true;
			break;
		}
	}
	if(i==30) return 0;//�ɼ���������0
	if(b) return 1;//�޸ĳɼ�����1
	else return 2;//�Ǽǳɼ�����2
}
int Student::GetCourse(char *coursename){
	for(int i=0;i<30;i++)
		if(cs[i].coursename==NULL) break;//�޴˾䣬stcpy()�����
		else if(!strcmp(cs[i].coursename,coursename))return cs[i].grade;
	return -1;
}//�ҵ����سɼ�,δ�ҵ�����-1
void Student::PrintStudentInfo(){
	int i;
	cout<<"ѧ��:"<<NoStudent<<'\n';
	PrintPersonInfo();
	for(i=0;i<30;i++)//��ӡ���Ƴɼ�
		if(cs[i].coursename!=NULL)cout<<cs[i].coursename<<'\t'<<cs[i].grade<<'\n';
		else break;
	cout<<"--------��-------- "<<endl;
}

int main(void){
	char temp[30];
	int i,k;
	Person per1("320102820818161","��",man,19820818,"�Ͼ�����¥2��");
	per1.PrintPersonInfo();
	Person per2=per1,per3;//������󿽱���ʼ�������
	per2.PrintPersonInfo();
	per3=per1;//����������
	per3.PrintPersonInfo();
	Student stu1("320102811226161","�캣��",man,19811226,"�Ͼ��л���·1��","06000123");
	cout<<"��������Ƴɼ�:"<<'\n';//Ϊ�򵥽���һ��ѧ��Ϊ��������Ӧ����ѧ�ţ����ң��ٲ���
	while(1){//������Ƴɼ�,����"end"ֹͣ
		cin>>temp;//�����ʽ:����  80
		if(!strcmp(temp,"end")) break;
		cin>>k;
		i=stu1.SetCourse(temp,k);
		if(i==0)cout<<"�ɼ��б�����!"<<'\n';
		else if(i==1)cout<<"�޸ĳɼ�"<<'\n';
		     else cout<<"�Ǽǳɼ�"<<'\n';
    }
	stu1.PrintStudentInfo();
	while(1){
		cout<<"��ѯ�ɼ�"<<'\n'<<"�������Ŀ:"<<'\n';
		cin>>temp;
		if(!strcmp(temp,"end")) break;
		k=stu1.GetCourse(temp);
		if(k==-1)cout<<"δ�鵽"<<'\n';
		else cout<<k<<'\n';
	}
	Student stu2=stu1,stu3;//��������������ʼ��
	stu2.PrintStudentInfo();
	stu3=stu2;//������������
	stu3.PrintStudentInfo();
	return 0;
}
