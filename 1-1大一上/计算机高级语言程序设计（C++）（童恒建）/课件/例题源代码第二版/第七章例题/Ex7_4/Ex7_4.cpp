//����7.4���ຬ�ж�̬���ɵ����ݳ�Ա�������Զ��������������ͷŶ�̬������ڴ棬�Զ���
//�������캯����Copy Structor���Ϳ�����ֵ��������Copy Assignment Operator��ʵ�������
#include <iostream>
#include <cstring>
using namespace std;
class student{
	char *pName;          //Ϊ����ʾ���������string��
public:
	student();
	student(char *pname);
	student(student &s);
//explicit student(student &s); //thj: student s4=s1; //������˹ؼ���explicit������ʽת�����캯��: ���벻��ͨ��//thj
	~student();
	student & operator=(student &s);
};
student::student(){
	cout<<"Constructor";
	pName=NULL;
	cout<<"ȱʡ"<<endl;
}
student::student(char *pname){
	cout<<"Constructor";
	if(pName=new char[strlen(pname)+1]) strcpy(pName,pname);
	//��һ�����٣����򴮽���������������Ϣ�����������
	cout<<pName<<endl;
}
student::student(student &s){
	cout<<"Copy Constructor";
	if(s.pName){
		if(pName=new char[strlen(s.pName)+1]) strcpy(pName,s.pName);
		cout<<pName<<endl;
	}
	else pName=NULL;
}
student::~student(){     //���ж�̬���ɵ����Ա����������������ȱʡ����������
	cout<<"Destructor";
	if(pName) cout<<pName<<endl;
	delete pName;
}
student & student::operator=(student &s){
	cout<<"Copy Assign operator";
	delete[] pName; 
	if(s.pName){
		if(pName=new char[strlen(s.pName)+1]) strcpy(pName,s.pName);
		cout<<pName<<endl;
	}
	else pName=NULL;
	return *this;
}
int main(void){
	student s1("��Ӣ��"),s2("��"),s3;
	student s4=s1; //��ʽת�����캯�� //thj
//	student s4(s1);  //thj
	s3=s2;
	return 0;
}
