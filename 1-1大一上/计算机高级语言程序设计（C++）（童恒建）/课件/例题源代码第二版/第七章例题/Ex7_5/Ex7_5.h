//����7.5_h����������ģ�壬������Ϊһ��ͷ�ļ���������Ľ������࣬�����йصĻ���
//��������Ϊ�����ĳ�Ա����������������Ĳ�������Ϊ������ĳ�Ա�����������������
//�������ݡ����㵥�����ȡ���ӡ�������ݡ�ǰ���������������������������������ȵȡ�
#include<iostream>
using namespace std;
//���ȿ������֯�����ý���࣬���������ݺ�ָ������йغ�����Ϊ��Ա����
template<typename T>class List;
template<typename T>class Node{
	T info;                                     //������
	Node<T> *link;                             //ָ����
public:
	Node();                                   //����ͷ���Ĺ��캯��
	Node(const T & data);//����һ����Ĺ��캯��
	void InsertAfter(Node<T>* P);                 //�ڵ�ǰ�������һ�����
	Node<T>* RemoveAfter();           //ɾ����ǰ���ĺ�̽�㣬���ظý�㱸��
	friend class List<T>;
	//��ListΪ��Ԫ�࣬List��ֱ�ӷ���Node��˽�г�Ա����ṹһ�����㣬������ȫ
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
	if(link==NULL) tempP=NULL;                 //������β,�����޽��
	else link=tempP->link;
	return tempP;
}
//�ٶ��������࣬ѡ���ò����������������������������������롢ɾ����ȡ���ݵ�
template<typename T>class List{
	Node<T> *head,*tail;//����ͷָ���βָ��
public:
	List();             //���캯��������ͷ���(������)
	~List();                                   //��������
	void MakeEmpty();                              //���һ������ֻ���ͷ���
	Node<T>* Find(T data);           //������������data��ͬ�Ľ�㣬���ظý��ĵ�ַ
	int Length();                                //���㵥������
	void PrintList();                    //��ӡ�����������
    void InsertFront(Node<T>* p);      //��������ǰ���������ڱ�ͷ����һ�����
	void InsertRear(Node<T>* p);       //������������������ڱ�β���һ�����
	void InsertOrder(Node<T> *p);  //��������������
	Node<T>*CreatNode(T data);             //����һ�����(�������)
	Node<T>*DeleteNode(Node<T>* p);        //ɾ��ָ�����
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
		head->link=tempP->link;  //��ͷ����ĵ�һ���ڵ����������
		delete tempP;            //ɾ��(�ͷ�)���������Ľ��
	}
	tail=head;  //��ͷָ�����βָ���ָ���ͷ��㣬��ʾ����
}
template<typename T> Node<T>* List<T>::Find(T data){
	Node<T> *tempP=head->link;
	while(tempP!=NULL&&tempP->info!=data) tempP=tempP->link;
	return tempP;        //�����ɹ����ظý���ַ�����ɹ�����NULL
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
	Node<T> *tempP=head->link,*tempQ=head;        //tempQָ��tempPǰ���һ���ڵ�
	while(tempP!=NULL){
		if(p->info<tempP->info)break; //�ҵ�һ���Ȳ������Ľ�㣬��tempPָ��
		tempQ=tempP;
		tempP=tempP->link;
	}
	tempQ->InsertAfter(p);	//����tempPָ����֮ǰ��tempQ֮��
	if(tail==tempQ) tail=tempQ->link;
}
template<typename T>Node<T>* List<T>::CreatNode(T data){//�����½ڵ�
	Node<T>*tempP=new Node<T>(data);
	return tempP;
}
template<typename T>Node<T>* List<T>::DeleteNode(Node<T>* p){
	Node<T>* tempP=head;
	while(tempP->link!=NULL&&tempP->link!=p) tempP=tempP->link;
	if(tempP->link==tail) tail=tempP;
	return tempP->RemoveAfter();       //���������÷�����ʡһ������ָ�룬��InsertOrder�Ƚ�
}
