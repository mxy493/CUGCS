//【例7.5_h】单链表类模板，本例作为一个头文件。单链表的结点采用类，与结点有关的基本
//操作都作为结点类的成员函数。对链表整体的操作则作为链表类的成员函数，包括清空链表、
//查找数据、计算单链表长度、打印链表数据、前生成链表、向后生成链表、按升序生成链表等等。
#include<iostream>
using namespace std;
//首先看结点组织，采用结点类，凡与结点数据和指针操作有关函数作为成员函数
template<typename T>class List;
template<typename T>class Node{
	T info;                                     //数据域
	Node<T> *link;                             //指针域
public:
	Node();                                   //生成头结点的构造函数
	Node(const T & data);//生成一般结点的构造函数
	void InsertAfter(Node<T>* P);                 //在当前结点后插入一个结点
	Node<T>* RemoveAfter();           //删除当前结点的后继结点，返回该结点备用
	friend class List<T>;
	//以List为友元类，List可直接访问Node的私有成员，与结构一样方便，但更安全
};
template <typename T> Node<T>::Node(){link=NULL;}
template <typename T> Node<T>::Node(const T & data){
	info=data;
	link=NULL;
}
template<typename T>void Node<T>::InsertAfter(Node<T>* p){
	p->link=link;  //thj: link denotes the current node
	link=p;
}
template<typename T>Node<T>* Node<T>::RemoveAfter(){
	Node<T>* tempP=link;
	if(link==NULL) tempP=NULL;                 //已在链尾,后面无结点
	else link=tempP->link;
	return tempP;
}
//再定义链表类，选择常用操作：包括建立有序链表、搜索遍历、插入、删除、取数据等
template<typename T>class List{
	Node<T> *head,*tail;//链表头指针和尾指针
public:
	List();             //构造函数，生成头结点(空链表)
	~List();                                   //析构函数
	void MakeEmpty();                              //清空一个链表，只余表头结点
	Node<T>* Find(T data);           //搜索数据域与data相同的结点，返回该结点的地址
	int Length();                                //计算单链表长度
	void PrintList();                    //打印链表的数据域
    void InsertFront(Node<T>* p);      //可用来向前生成链表，在表头插入一个结点
	void InsertRear(Node<T>* p);       //可用来向后生成链表，在表尾添加一个结点
	void InsertOrder(Node<T> *p);  //按升序生成链表
	Node<T>*CreatNode(T data);             //创建一个结点(孤立结点)
	Node<T>*DeleteNode(Node<T>* p);        //删除指定结点
};
template<typename T>List<T>::List(){
	head=tail=new Node<T>();
}
template<typename T>List<T>::~List(){
	MakeEmpty();
	delete head;
}
template<typename T>void List<T>::MakeEmpty(){
	Node<T> *tempP;
	while(head->link!=NULL){
		tempP=head->link;
		head->link=tempP->link;  //把头结点后的第一个节点从链中脱离
		delete tempP;            //删除(释放)脱离下来的结点
	}
	tail=head;  //表头指针与表尾指针均指向表头结点，表示空链
}
template<typename T> Node<T>* List<T>::Find(T data){
	Node<T> *tempP=head->link;
	while(tempP!=NULL&&tempP->info!=data) tempP=tempP->link;
	return tempP;        //搜索成功返回该结点地址，不成功返回NULL
}
template<typename T>int List<T>::Length(){
	Node<T>* tempP=head->link;
	int count=0;
	while(tempP!=NULL){
		tempP=tempP->link;
		count++;
	}
	return count;
}
template<typename T>void List<T>::PrintList(){
	Node<T>* tempP=head->link;
	while(tempP!=NULL){
		cout<<tempP->info<<'\t';
		tempP=tempP->link;
	}
	cout<<endl;
}
template<typename T>void List<T>::InsertFront(Node<T> *p){
	p->link=head->link;
	head->link=p;
	if(tail==head) tail=p;
}
template<typename T>void List<T>::InsertRear(Node<T> *p){
	p->link=tail->link;
	tail->link=p;
	tail=p;
}
template<typename T>void List<T>::InsertOrder(Node<T> *p){
	Node<T> *tempP=head->link,*tempQ=head;        //tempQ指向tempP前面的一个节点
	while(tempP!=NULL){
		if(p->info<tempP->info)break; //找第一个比插入结点大的结点，由tempP指向
		tempQ=tempP;
		tempP=tempP->link;
	}
	tempQ->InsertAfter(p);	//插在tempP指向结点之前，tempQ之后
	if(tail==tempQ) tail=tempQ->link;
}
template<typename T>Node<T>* List<T>::CreatNode(T data){//建立新节点
	Node<T>*tempP=new Node<T>(data);
	return tempP;
}
template<typename T>Node<T>* List<T>::DeleteNode(Node<T>* p){
	Node<T>* tempP=head;
	while(tempP->link!=NULL&&tempP->link!=p) tempP=tempP->link;
	if(tempP->link==tail) tail=tempP;
	return tempP->RemoveAfter();       //本函数所用方法可省一个工作指针，与InsertOrder比较
}
