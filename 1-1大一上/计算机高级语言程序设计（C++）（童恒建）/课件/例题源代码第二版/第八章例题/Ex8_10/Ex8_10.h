#include<iostream>
using namespace std;
//���ȿ������֯,���ý�����������
class Object{//������Ϊ������
public:
	Object(){}
	virtual bool operator>(Object &)=0;//���麯��,��������Ϊ���û�ָ��
	virtual bool operator!=(Object &)=0;//���麯��,��������Ϊ���û�ָ��
	virtual void Print()=0;//���麯��
	virtual ~Object(){} //����������Ϊ�麯�������캯������
};
class Node{
	Object* info;     //��������ָ��ָ�����������
	Node* link;     //ָ����
public:
	Node();           //����ͷ���Ĺ��캯��
	~Node();
	void InsertAfter(Node* P);                 //�ڵ�ǰ�������һ�����
	Node* RemoveAfter();	//ɾ����ǰ���ĺ�̽�㣬���ظý�㱸��
	void Linkinfo(Object* obj);
	friend class List;
	//��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�к�������ṹһ�����㣬������ȫ
};
Node::Node(){info=NULL;link=NULL;}
Node::~Node(){
	cout<<"ɾ�������"<<'\t';
	delete info; //�ͷ�������,�Զ���������������������,�����������������main()�н���
}
void Node::InsertAfter(Node* p){
	p->link=link;
	link=p;
}
Node* Node::RemoveAfter(){
	Node* tempP=link;
	if(link==NULL) tempP=NULL;                 //������β,�����޽��
	else link=tempP->link;
	return tempP;
}
void Node::Linkinfo(Object * obj){info=obj;}

//�ٶ��������࣬ѡ���ò����������������������������������롢ɾ����ȡ���ݵ�
class List{
	Node *head,*tail;//����ͷָ���βָ��
public:
	List();             //���캯��������ͷ���(������)
	~List();                                   //��������
	void MakeEmpty();                              //���һ������ֻ���ͷ���
	Node* Find(Object & obj);           //�����������붨ֵ��ͬ�Ľ�㣬���ظý��ĵ�ַ
	int Length();                                //���㵥������
	void PrintList();                    //��ӡ�����������
    void InsertFront(Node* p);      //��������ǰ���������ڱ�ͷ����һ�����
	void InsertRear(Node* p);       //������������������ڱ�β���һ�����
	void InsertOrder(Node* p);  //��������������
	Node* CreatNode();//����һ�����(�������)
	Node* DeleteNode(Node* p);        //ɾ��ָ�����
};
List::List(){
	head=tail=new Node();
}
List::~List(){
	MakeEmpty();
	cout<<"ɾ��ͷ���"<<'\t';
	delete head;//�Զ����ý������������,��ָ����ղ��ٵ�����������������
}
void List::MakeEmpty(){
	Node *tempP;
	while(head->link!=NULL){
		tempP=head->link;
		head->link=tempP->link;  //��ͷ����ĵ�һ���ڵ����������
		delete tempP; //ɾ��(�ͷ�)�ý��,�Զ����ý������������,��һ���Զ���������������������
	}                 //ǧ�򲻿���ǰ��� delete tempP->info; ���ͷ���������
	tail=head;  //��ͷָ�����βָ���ָ���ͷ��㣬��ʾ����
}
Node* List::Find(Object & obj){//�Գ�����ֻ���á����á�
	Node* tempP=head->link;
	while(tempP!=NULL&&*tempP->info!=obj) tempP=tempP->link;
	return tempP;        //�����ɹ����ظý���ַ�����ɹ�����NULL
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
	Node *tempP=head->link,*tempQ=head;        //tempQָ��tempPǰ���һ���ڵ�
	while(tempP!=NULL){
		if(*tempP->info>*p->info)break; //�ҵ�һ���Ȳ������Ľ�㣬��tempPָ��
		tempQ=tempP;
		tempP=tempP->link;
	}
	tempQ->InsertAfter(p);	//����tempPָ����֮ǰ��tempQ֮��
	if(tail==tempQ) tail=tempQ->link;
}
Node* List::CreatNode(){//�����½ڵ�
	Node*tempP=new Node();
	return tempP;
}
Node* List::DeleteNode(Node* p){
	Node* tempP=head;
	while(tempP->link!=NULL&&tempP->link!=p) tempP=tempP->link;
	if(tempP->link==tail) tail=tempP;
	return tempP->RemoveAfter();       //���������÷�����ʡһ������ָ�룬��InsertOrder�Ƚ�
}
