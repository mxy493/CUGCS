//¡¾Àı8.5_2¡¿¸³Öµ¼æÈİ¹æÔòÓë×Ô¶¨ÒåµÄ¿½±´¹¹Ôìº¯Êı¡£²ÉÓÃ¶¯Ì¬½¨Á¢µÄC·ç¸ñ×Ö·û´®£¬Éî¿½±´¡£
#include<iostream>
#include<cstring>
using namespace std;

enum Tsex{mid,man,woman};
struct course{
	char* coursename;
	int grade;
};
class Person{
	char IdPerson[19];			//Éí·İÖ¤ºÅ,18Î»Êı×Ö
	char *Name;				//ĞÕÃû
	Tsex Sex;				//ĞÔ±ğ
	int Birthday;				//ÉúÈÕ,¸ñÊ½1986Äê8ÔÂ18ÈÕĞ´×÷19860818
	char *HomeAddress;		//¼ÒÍ¥µØÖ·
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
		delete[]Name;//¸³ÖµÒªÏÈÇåÔ­À´·ÖÅäµÄ¿Õ¼ä
		Name=new char[strlen(ps.Name)+1];
		strcpy(Name,ps.Name);
	}
	else Name=NULL;
	Sex=ps.Sex;
	Birthday=ps.Birthday;
	if(ps.HomeAddress!=NULL){
		delete [] HomeAddress;//¸³ÖµÒªÏÈÇåÔ­À´·ÖÅäµÄ¿Õ¼ä,ÔÙÖØĞÂ·ÖÅä
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
	cout<<"Éí·İÖ¤ºÅ:"<<IdPerson<<'\n'<<"ĞÕÃû:"<<Name<<'\n'<<"ĞÔ±ğ:";
	if(Sex==man)cout<<"ÄĞ"<<'\n';
	else if(Sex==woman)cout<<"Å®"<<'\n';
	     else cout<<" "<<'\n';
	cout<<"³öÉúÄêÔÂÈÕ:";
	i=Birthday;
	cout<<i/10000<<"Äê";
	i=i%10000;
	cout<<i/100<<"ÔÂ"<<i%100<<"ÈÕ"<<'\n'<<"¼ÒÍ¥×¡Ö·:"<<HomeAddress<<'\n';
}

class Student:public Person{//¶¨ÒåÅÉÉúµÄQ§ÉúÀà
	char NoStudent[10];//Ñ§ºÅ
	course cs[30];//30ÃÅ¿Î³ÌÓë³É¼¨
public:
	Student(char*id,char*name,Tsex sex,int birthday,char*homeadd,char*nostud);
	//×¢ÒâÅÉÉúÀà¹¹Ôìº¯ÊıÉùC÷·½Ê½
	Student();
	Student(Student &Std);
	~Student();
	Student & operator=(const Student &Std);
	SetCourse(char *,int);
	int GetCourse(char *);
	void PrintStudentInfo();
};
Student::Student(char*id,char*name,Tsex sex,int birthday,char*homeadd,char*nostud)
             :Person(id,name,sex,birthday,homeadd){//×¢ÒâPerson²ÎÊı±í²»ÓÃÀàĞÍ
	strcpy(NoStudent,nostud);
	for(int i=0;i<30;i++){//¿N³ÌÓë³É¼¨Çå?Õ
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::Student(){//»ùÀàÈ±Ê¡µÄÎŞ²ÎÊ}¹¹Ôìº¯Êı²»±ØOÔÊ½¸ø³ö
	NoStudent[10]=NULL;
	for(int i=0;i<30;i++){//¿Î³ÌÓë³É¼¨ÇåÁã,½«À´ÓÉ¼üÅÌÊäÈë 
		cs[i].coursename=NULL;
		cs[i].grade=0;
	}
}
Student::Student(Student &Std):Person(Std){//°´¸³Öµ¼æÈİ¹æÔòStd¿ÉÎªPersonÊµ²Î
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
Student::~Student(){//»ùÀàÎö¹¹º¯Êı²»±ØÏÔÊ½¸ø³ö
	for(int i=0;i<30;i++)
		if(cs[i].coursename)delete [] cs[i].coursename;
}//Çå³ı¸÷¿Î³ÌÃû³Æ²»¿ÉÉÙ,ËüÃÇ·ÅÔÚ¶ÑÇøÖĞ
Student & Student::operator=(const Student &Std){
	this->Person::operator=(Std);
	strcpy(NoStudent,Std.NoStudent);
	for(int i=0;i<30;i++){
		if(Std.cs[i].coursename!=NULL){
			delete [] cs[i].coursename;//¿½±´ÒªÏÈÇåÔ­À´·VÅä¿Õ¼ä,TÙÖØĞÂ·ÖÅä
			cs[i].coursename=new char[strlen(Std.cs[i].coursename)+1];
			strcpy(cs[i].coursename,Std.cs[i].coursename);
		}
		else cs[i].coursename=NULL;
		cs[i].grade=Std.cs[i].grade;
	}
	return *this;
}
int Student::SetCourse(char *coursename,int grade){
	bool b=false;//±êÊ¶ĞÂÊäÈëµÄ¿Î³Ì,»¹ÊÇ¸üĞÂ³É¼¨
	for(int i=0;i<30;i++){
		if(cs[i].coursename==NULL){
			//ÅĞ±íÊÇ·ñ½øÈëÎ´Ê¹ÓÃ²¿·Ö£¨ÈçÓĞ¶ÔÓ¦É¾³ıÓ¦°´Ë³Ğò±í·½Ê½£©
			cs[i].coursename=new char[strlen(coursename)+1];
			strcpy(cs[i].coursename,coursename);
			cs[i].grade=grade;
			b=false;
			break;
		}
		else if(!strcmp(cs[i].coursename,coursename)){
			//ºó²éÊÇ·ñÒÑÓĞ¸Ã¿Î³Ì¼ÇÂ¼¡£ÈçÏÈ²é£¬Òòstrcmp()½¡×³ĞÍ²»ºÃ£¬ÓöNULL³ö´í
			cs[i].grade=grade;
			b=true;
			break;
		}
	}
	if(i==30) return 0;//³É¼¨±íÂú·µ»Ø0
	if(b) return 1;//ĞŞ¸Ä³É¼¨·µ»Ø1
	else return 2;//µÇ¼Ç³É¼¨·µ»Ø2
}
int Student::GetCourse(char *coursename){
	for(int i=0;i<30;i++)
		if(cs[i].coursename==NULL) break;//ÎŞ´Ë¾ä£¬stcpy()»á³ö´í
		else if(!strcmp(cs[i].coursename,coursename))return cs[i].grade;
	return -1;
}//ÕÒµ½·µ»Ø³É¼¨,Î´ÕÒµ½·µ»Ø-1
void Student::PrintStudentInfo(){
	int i;
	cout<<"Ñ§ºÅ:"<<NoStudent<<'\n';
	PrintPersonInfo();
	for(i=0;i<30;i++)//´òÓ¡¸÷¿Æ³É¼¨
		if(cs[i].coursename!=NULL)cout<<cs[i].coursename<<'\t'<<cs[i].grade<<'\n';
		else break;
	cout<<"--------Íê-------- "<<endl;
}

int main(void){
	char temp[30];
	int i,k;
	Person per1("320102820818161","Éò¿¡",man,19820818,"ÄÏ¾©ËÄÅÆÂ¥2ºÅ");
	per1.PrintPersonInfo();
	Person per2=per1,per3;//»ùÀà¶ÔÏó¿½±´³õÊ¼»¯£¬Éî¿½±´
	per2.PrintPersonInfo();
	per3=per1;//»ùÀà¶ÔÏóÉî¿½±´
	per3.PrintPersonInfo();
	Student stu1("320102811226161","Öìº£Åô",man,19811226,"ÄÏ¾©ÊĞ»ÆÆÖÂ·1ºÅ","06000123");
	cout<<"ÇëÊäÈë¸÷¿Æ³É¼¨:"<<'\n';//Îª¼òµ¥½öÒÔÒ»¸öÑ§ÉúÎªÀı¡£ÍêÕûÓ¦ÊäÈëÑ§ºÅ£¬²éÕÒ£¬ÔÙ²Ù×÷
	while(1){//ÊäÈë¸÷¿Æ³É¼¨,ÊäÈë"end"Í£Ö¹
		cin>>temp;//ÊäÈë¸ñÊ½:ÎïÀí  80
		if(!strcmp(temp,"end")) break;
		cin>>k;
		i=stu1.SetCourse(temp,k);
		if(i==0)cout<<"³É¼¨ÁĞ±íÒÑÂú!"<<'\n';
		else if(i==1)cout<<"ĞŞ¸Ä³É¼¨"<<'\n';
		     else cout<<"µÇ¼Ç³É¼¨"<<'\n';
    }
	stu1.PrintStudentInfo();
	while(1){
		cout<<"²éÑ¯³É¼¨"<<'\n'<<"ÇëÊäÈë¿ÆÄ¿:"<<'\n';
		cin>>temp;
		if(!strcmp(temp,"end")) break;
		k=stu1.GetCourse(temp);
		if(k==-1)cout<<"Î´²éµ½"<<'\n';
		else cout<<k<<'\n';
	}
	Student stu2=stu1,stu3;//ÅÉÉúÀà¶ÔÏóÉî¿½±´³õÊ¼»¯
	stu2.PrintStudentInfo();
	stu3=stu2;//ÅÉÉúÀà¶ÔÏóÉî¿½±´
	stu3.PrintStudentInfo();
	return 0;
}
