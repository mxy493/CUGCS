#include<iostream>
using namespace std;
//首先看结点组织,采用结点类加数据类
class Object{//数据类为抽象类
public:
	Object(){}
	virtual bool operator>(Object &)=0;//纯虚函数,参数必须为引用或指针
	virtual bool operator!=(Object &)=0;//纯虚函数,参数必须为引用或指针
	virtual void Print()=0;//纯虚函数
	virtual ~Object(){} //析构函数可为虚函数，构造函数不行
};
class Node{
	Object* info;     //数据域用指针指向数据类对象
	Node* link;     //指针域
public:
	Node();           //生成头结点的构造函数
	~Node();
	void InsertAfter(Node* P);                 //在当前结点后插入一个结点
	Node* RemoveAfter();	//删除当前结点的后继结点，返回该结点备用
	void Linkinfo(Object* obj);
	friend class List;
	//以List为友元类，List可直接访问Node的私有函数，与结构一样方便，但更安全
};
Node::Node(){info=NULL;link=NULL;}
Node::~Node(){
	cout<<"删除结点类"<<'\t';
	delete info; //释放数据域,自动调用数据域类析构函数,而数据域类对象是在main()中建立
}
void Node::InsertAfter(Node* p){
	p->link=link;
	link=p;
}
Node* Node::RemoveAfter(){
	Node* tempP=link;
	if(link==NULL) tempP=NULL;                 //已在链尾,后面无结点
	else link=tempP->link;
	return tempP;
}
void Node::Linkinfo(Object * obj){info=obj;}

//再定义链表类，选择常用操作：包括建立有序链表、搜索遍历、插入、删除、取数据等
class List{
	Node *head,*tail;//链表头指针和尾指针
public:
	List();             //构造函数，生成头结点(空链表)
	~List();                                   //析构函数
	void MakeEmpty();                              //清空一个链表，只余表头结点
	Node* Find(Object & obj);           //搜索数据域与定值相同的结点，返回该结点的地址
	int Length();                                //计算单链表长度
	void PrintList();                    //打印链表的数据域
    void InsertFront(Node* p);      //可用来向前生成链表，在表头插入一个结点
	void InsertRear(Node* p);       //可用来向后生成链表，在表尾添加一个结点
	void InsertOrder(Node* p);  //按升序生成链表
	Node* CreatNode();//创建一个结点(孤立结点)
	Node* DeleteNode(Node* p);        //删除指定结点
};
List::List(){
	head=tail=new Node();
}
List::~List(){
	MakeEmpty();
	cout<<"删除头结点"<<'\t';
	delete head;//自动调用结点类析构函数,因指针域空不再调数据域类析构函数
}
void List::MakeEmpty(){
	Node *tempP;
	while(head->link!=NULL){
		tempP=head->link;
		head->link=tempP->link;  //把头结点后的第一个节点从链中脱离
		delete tempP; //删除(释放)该结点,自动调用结点类析构函数,进一步自动调用数据域类析构函数
	}                 //千万不可在前面加 delete tempP->info; 来释放数据域类
	tail=head;  //表头指针与表尾指针均指向表头结点，表示空链
}
Node* List::Find(Object & obj){//对抽象类只能用“引用”
	Node* tempP=head->link;
	while(tempP!=NULL&&*tempP->info!=obj) tempP=tempP->link;
	return tempP;        //搜索成功返回该结点地址，不成功返回NULL
}
int List::Length(){
	Node* tempP=head->link;
	int count=0;
	while(tempP!=NULL){
		tempP=tempP->link;
		count++;
	}
	return count;
}
void List::PrintList(){
	Node* tempP=head->link;
	while(tempP!=NULL){
		tempP->info->Print();
		tempP=tempP->link;
	}
	cout<<endl;
}
void List::InsertFront(Node *p){
	p->link=head->link;
	head->link=p;
	if(tail==head) tail=p;
}
void List::InsertRear(Node *p){
	p->link=tail->link;
	tail->link=p;
	tail=p;
}
void List::InsertOrder(Node* p){
	Node *tempP=head->link,*tempQ=head;        //tempQ指向tempP前面的一个节点
	while(tempP!=NULL){
		if(*tempP->info>*p->info)break; //找第一个比插入结点大的结点，由tempP指向
		tempQ=tempP;
		tempP=tempP->link;
	}
	tempQ->InsertAfter(p);	//插在tempP指向结点之前，tempQ之后
	if(tail==tempQ) tail=tempQ->link;
}
Node* List::CreatNode(){//建立新节点
	Node*tempP=new Node();
	return tempP;
}
Node* List::DeleteNode(Node* p){
	Node* tempP=head;
	while(tempP->link!=NULL&&tempP->link!=p) tempP=tempP->link;
	if(tempP->link==tail) tail=tempP;
	return tempP->RemoveAfter();       //本函数所用方法可省一个工作指针，与InsertOrder比较
}
