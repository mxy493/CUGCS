//【例8.10】通用单链表派生类。首先改造【例7.4】的头文件，不采用模板类，
//而采用虚函数实现多态性，达到通用的目的。
#include "Ex8_10.h"
#include<string>
using namespace std;

class StringObject:public Object{
	string sptr;
public:
	StringObject();
	StringObject(string);
	~StringObject();
	bool operator>(Object &);
	bool operator!=(Object &);
	void Print();
};
StringObject::StringObject(){sptr="";}
StringObject::StringObject(string s){sptr=s;}
StringObject::~StringObject(){cout<<"数据类析构"<<endl;} //自动进一步调用string析构函数
bool StringObject::operator>(Object & obj){//虚函数
	StringObject & temp=(StringObject &)obj;//必须转换
	return sptr>temp.sptr;
}
bool StringObject::operator!=(Object & obj){//虚函数
	StringObject & temp=(StringObject &)obj;//必须转换
	return sptr!=temp.sptr;
}
void StringObject::Print(){cout<<sptr<<'\t';}//虚函数

int main(){
	Node * P1;
	StringObject* p;
	List list1,list2,list3;
	char *a[5]={"dog","cat","bear","sheep","ox"},*sp="cat";
	int i;
	for(i=0;i<5;i++){
		p=new StringObject(a[i]);              //建立数据对象
		P1=list1.CreatNode();                  //建立结点
		P1->Linkinfo(p);                       //数据对象连接到结点
		list1.InsertFront(P1);                 //向前生成list1
		p=new StringObject(a[i]);              //将在Node的析构函数中释放
		P1=list2.CreatNode();
		P1->Linkinfo(p);
		list2.InsertRear(P1);                  //向后生成list2
	}
	list1.PrintList();
	cout<<"list1长度："<<list1.Length()<<endl;
	list2.PrintList();
	cout<<"要求删除的字符串\"cat\""<<endl;
	p=new StringObject(sp);                    //为了程序的通用性只能多一次转换
	P1=list1.Find(*p);
	delete p;
	if(P1!=NULL){
		cout<<"删除cat"<<endl;
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
		cout<<"list1长度："<<list1.Length()<<endl; 
	}
	else cout<<"未找到"<<endl;
	cout<<"清空list1"<<endl;
	list1.MakeEmpty();                         //清空list1
	list1.PrintList();
	for(i=0;i<5;i++){
		p=new StringObject(a[i]);
		P1=list3.CreatNode();
		P1->Linkinfo(p);
		list3.InsertOrder(P1);//升序创建list3
	}
	list3.PrintList();
	cout<<"程序结束"<<endl;
	return 0;
}
