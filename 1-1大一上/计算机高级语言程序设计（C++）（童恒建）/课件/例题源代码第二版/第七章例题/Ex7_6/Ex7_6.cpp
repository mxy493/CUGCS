//����7.6����ѧ������Ϊ����������࣬���ѧ�������Ĺ���
#include<string>
using namespace std;
#include "Ex7_6.h"
class  student{
	int   id ;           //ѧ��
	string name;         // ����
	char  sex;          // �Ա�
	int   age;          // ����
	string  address;      //��ͥ��ַ
	float  eng, phy, math, electron;     //Ӣ�������ѧ�͵���ѧ�ɼ�
public:
	student(int=0,string="",char='\0',int=0,string="",float=0.0,float=0.0,float=0.0,float=0.0);
//	bool operator<(student ele){return id<ele.id;}
	bool operator<(student ele){return electron<ele.electron;} //thj 
	bool operator!=(student ele){return id!=ele.id;}
	void show(){cout<<id<<'\t'<<name<<'\t'<<sex<<'\t'<<age<<'\t'<<address<<'\t'
		<<eng<<'\t'<<phy<<'\t'<<math<<'\t'<<electron<<endl;}
};
student::student(int i,string n,char s,int a,string add,float en,float ph,float ma,float ele){
	id=i;           //ѧ��
	name=n;         // ����
	sex=s;          // �Ա�
	age=a;          // ����
	address=add;      //��ͥ��ַ
	eng=en; phy=ph; math=ma, electron=ele;     //Ӣ�������ѧ�͵���ѧ�ɼ�
}
int main(){
	const int h=4;
	int i,j;
	Node<student> * P1;
	List<student> list1,list2;
	student n[h]={student(6004327,"�ŷ�",'m',19,"����·58��",80,85,90,78),
		student(6004121,"����",'w',19,"���·64��",88,75,91,68),
		student(6004118,"����",'w',18,"�Ϻ�·37��",78,95,81,88),
		student(6004219,"����",'m',18,"����·95��",78,95,81,85), //thj: 88 --> 85
	};
	for(i=0;i<h;i++){
		P1=list1.CreatNode(n[i]);
		list1.InsertFront(P1);//��ǰ����list1
		P1=list2.CreatNode(n[i]);
		list2.InsertRear(P1);                        //�������list2
	}
	list1.PrintList();
	cout<<"list1���ȣ�"<<list1.Length()<<endl;
	list2.PrintList();
	cout<<"������һ��Ҫ��ɾ����ѧ��ѧ��"<<endl;
	cin>>j;
	P1=list1.Find(j);   //ѧ���ɹ��캯��ת��Ϊѧ����
	if(P1!=NULL){
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
		cout<<"list1���ȣ�"<<list1.Length()<<endl; 
	}
	else cout<<"δ�ҵ�"<<endl;
	list1.MakeEmpty();    //���list1
 	for(i=0;i<h;i++){
		P1=list1.CreatNode(n[i]);
		list1.InsertOrder(P1);//���򴴽�list1
	}
	list1.PrintList();
	return 0;
}