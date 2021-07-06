//����8.1�����ڲ���Ա�๫������ѧ���ࡣ
#include<iostream>
#include<string>
using namespace std;
enum Tsex{mid,man,woman};
struct course{
	string coursename;
	int grade;
};
class Person{
	string IdPerson;			//���֤��,18λ����
	string Name;				//����
	Tsex Sex;				    //�Ա�
	int Birthday;				//����,��ʽ1986��8��18��д��19860818
	string HomeAddress;		//��ͥ��ַ
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
}//��Ϊһ���������,������캯�����ޱ�Ҫ,��Ϊ����������������ġ���Ϊ˵���﷨���ڡ�
Person::Person(){
	IdPerson="#";Name="#";Sex=mid;
	Birthday=0;HomeAddress="#";
}
Person::~Person(){}  //string�ڲ���̬������ͷţ���string�Դ��������������
void Person::SetName(string name){
	Name=name;                    //����������
}
void Person::SetHomeAdd(string homeadd){
	HomeAddress=homeadd;
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
class Student:public Person{                     //����������ѧ����
	string NoStudent;                        //ѧ��
	course cs[30];                             //30�ſγ���ɼ�
public:
	Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud);
	//ע�������๹�캯��������ʽ
	Student();
	~Student();
	int SetCourse(string,int);
	int GetCourse(string);
	void PrintStudentInfo();
};
Student::Student(string id, string name,Tsex sex,int birthday, string homeadd, string nostud)
             :Person(id,name,sex,birthday,homeadd){    //ע��Person������������
	int i;
	NoStudent=nostud;
	for(i=0;i<30;i++){                            //�γ���ɼ����
		cs[i].coursename="#";
		cs[i].grade=0;
	}
}
Student::Student(){                     //����ȱʡ���޲������캯��������ʽ����
	int i;
	NoStudent="";
	for(i=0;i<30;i++){               //�γ���ɼ�����,�����ɼ������� 
		cs[i].coursename="";
		cs[i].grade=0;
	}
}
Student::~Student(){}   //�������������Լ���Ա�������������Զ�����
int Student::SetCourse(string coursename,int grade){
	int i;
	bool b=false;                        //��ʶ������Ŀγ�,���Ǹ��³ɼ�
	for(i=0;i<30;i++){
		if(cs[i].coursename=="#"){
			//�б��Ƿ����δʹ�ò��֣����ж�Ӧɾ��,Ӧ��˳���ʽ��
			cs[i].coursename=coursename;
			cs[i].grade=grade;
			b=false;
			break;
		}
		else if(cs[i].coursename==coursename){
			//�Ƿ����иÿγ̼�¼
			cs[i].grade=grade;
			b=true;
			break;
		}
	}
	if(i==30) return 0;      //�ɼ���������0
	if(b) return 1;          //�޸ĳɼ�����1
	else return 2;          //�Ǽǳɼ�����2
}
int Student::GetCourse(string coursename){
	for(int i=0;i<30;i++) if(cs[i].coursename==coursename) return cs[i].grade;
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
	char temp[30];
	int i,k;
	Person per1("320102820818161","��",man,19820818,"�Ͼ�����¥2��");
	Person per2;
	per2.SetName("����");
	per2.SetSex(woman);
	per2.SetBirth(19780528);
	per2.SetId("320102780528162");
	per2.SetHomeAdd("�Ͼ��г��ͽ�9��");
	per1.PrintPersonInfo();
	per2.PrintPersonInfo();
	Student stu1("320102811226161","�캣��",man,19811226,"�Ͼ��л���·1��",
		"06000123");
	cout<<"��������Ƴɼ�:"<<'\n';         //�����ĳ���Ӧ����ѧ��,����,�ٲ���
	while(1){                            //������Ƴɼ�,����"end"ֹͣ
		cin>>temp;                       //�����ʽ:����  80
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
	return 0;
}
