//【例7.6】以学生类作为链表的数据类，完成学生档案的管理。
#include<string>
using namespace std;
#include "Ex7_6.h"
class  student{
	int   id ;           //学号
	string name;         // 姓名
	char  sex;          // 性别
	int   age;          // 年龄
	string  address;      //家庭地址
	float  eng, phy, math, electron;     //英语，物理，数学和电子学成绩
public:
	student(int=0,string="",char='\0',int=0,string="",float=0.0,float=0.0,float=0.0,float=0.0);
//	bool operator<(student ele){return id<ele.id;}
	bool operator<(student ele){return electron<ele.electron;} //thj 
	bool operator!=(student ele){return id!=ele.id;}
	void show(){cout<<id<<'\t'<<name<<'\t'<<sex<<'\t'<<age<<'\t'<<address<<'\t'
		<<eng<<'\t'<<phy<<'\t'<<math<<'\t'<<electron<<endl;}
};
student::student(int i,string n,char s,int a,string add,float en,float ph,float ma,float ele){
	id=i;           //学号
	name=n;         // 姓名
	sex=s;          // 性别
	age=a;          // 年龄
	address=add;      //家庭地址
	eng=en; phy=ph; math=ma, electron=ele;     //英语，物理，数学和电子学成绩
}
int main(){
	const int h=4;
	int i,j;
	Node<student> * P1;
	List<student> list1,list2;
	student n[h]={student(6004327,"张菲",'m',19,"北京路58号",80,85,90,78),
		student(6004121,"关雨",'w',19,"天津路64号",88,75,91,68),
		student(6004118,"刘蓓",'w',18,"上海路37号",78,95,81,88),
		student(6004219,"赵昀",'m',18,"重庆路95号",78,95,81,85), //thj: 88 --> 85
	};
	for(i=0;i<h;i++){
		P1=list1.CreatNode(n[i]);
		list1.InsertFront(P1);//向前生成list1
		P1=list2.CreatNode(n[i]);
		list2.InsertRear(P1);                        //向后生成list2
	}
	list1.PrintList();
	cout<<"list1长度："<<list1.Length()<<endl;
	list2.PrintList();
	cout<<"请输入一个要求删除的学生学号"<<endl;
	cin>>j;
	P1=list1.Find(j);   //学号由构造函数转换为学生类
	if(P1!=NULL){
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
		cout<<"list1长度："<<list1.Length()<<endl; 
	}
	else cout<<"未找到"<<endl;
	list1.MakeEmpty();    //清空list1
 	for(i=0;i<h;i++){
		P1=list1.CreatNode(n[i]);
		list1.InsertOrder(P1);//升序创建list1
	}
	list1.PrintList();
	return 0;
}