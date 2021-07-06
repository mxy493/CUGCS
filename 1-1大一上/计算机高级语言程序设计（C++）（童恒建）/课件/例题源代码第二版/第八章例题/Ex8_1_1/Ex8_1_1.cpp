//����8.1�����ڲ���Ա�๫������ѧ���ࡣʹ���˶�̬���ɵ�C����ַ���.
#include<iostream.h>
#include<string.h>

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
}//��Ϊһ���������,������캯�����ޱ�Ҫ,��Ϊ����������������ġ���Ϊ˵���﷨���ڡ�
Person::Person(){
	IdPerson[0]='\0';Name=NULL;Sex=mid;
	Birthday=0;HomeAddress=NULL;
}
Person::~Person(){
	if(Name)delete [] Name;if(HomeAddress) delete [] HomeAddress;
}
void Person::SetName(char *name){
	if(Name) delete [] Name;//ɾȥԭ��������
	Name=new char[strlen(name)+1];//���·����ڴ�
	strcpy(Name,name);//����������
}
void Person::SetHomeAdd(char *homeadd){
	if(HomeAddress) delete [] HomeAddress;
	HomeAddress=new char[strlen(homeadd)+1];
	strcpy(HomeAddress,homeadd);
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
	char NoStudent[10];//ѧ��
	course cs[30];//30�ſγ���ɼ�
public:
	Student(char *id,char *name,Tsex sex,int birthday,char *homeadd,char* nostud);
	//ע�������๹�캯��������ʽ
	Student();
	~Student();
	SetCourse(char *,int);
	int GetCourse(char *);
	void PrintStudentInfo();
};
Student::Student(char*id,char*name,Tsex sex,int birthday,char*homeadd,char*nostud)
             :Person(id,name,sex,birthday,homeadd){//ע��Person������������
	strcpy(NoStudent,nostud);
	for(int i=0;i<30;i++){//�γ���ɼ����
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::Student(){//����ȱʡ���޲������캯��������ʽ����
	NoStudent[0]='\0';
	for(int i=0;i<30;i++){//�γ���ɼ�����,�����ɼ������� 
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::~Student(){//������������������ʽ����
	for(int i=0;i<30;i++)
		if(cs[i].coursename)delete [] cs[i].coursename;
}//������γ����Ʋ�����,���Ƿ��ڶ�����
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
	Person per2;
	per2.SetName("����");
	per2.SetSex(woman);
	per2.SetBirth(19780528);
	per2.SetId("320102780528162");
	per2.SetHomeAdd("�Ͼ��г��ͽ�9��");
	per1.PrintPersonInfo();
	per2.PrintPersonInfo();
	Student stu1("320102811226161","�캣��",man,19811226,"�Ͼ��л���·1��","06000123");
	cout<<"��������Ƴɼ�:"<<'\n';
	//Ϊ�򵥽���һ��ѧ��Ϊ��������Ӧ����ѧ�ţ����ң��ٲ���
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
	return 0;
}
