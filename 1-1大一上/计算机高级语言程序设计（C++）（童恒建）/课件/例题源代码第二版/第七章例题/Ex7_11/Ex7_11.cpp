//����7.11��������ģ�塣
#include<iostream>
#include<cassert>
using namespace std;

template<typename T>class Queue;
template<typename T>class Node{
	T info;
	Node *link;     //����ģ��Node��ʹ��ָ��Node��ָ����Բ���<T>
public:
	Node(T data=0,Node *l=NULL);
	friend class Queue<T>;
};
template<typename T> Node<T>::Node(T data,Node *l){
	info=data;
	link=l;
}
template<typename T>class Queue{
	Node<T> *front,*rear;    //����������ָ��Node��ָ������<T>
public:
	Queue(){rear=front=NULL;}						     //����һ��������
	~Queue();
	bool IsEmpty(){ return front==NULL;}				 //�ӿշ�
	void EnQue(const T &data);						     //����
	T DeQue();									         //����
	T GetFront();						 			     //�鿴��ͷ����
	void MakeEmpty();					                 //�ÿն��У��������߼��ϲ�ͬ��������һ��
};
template<typename T>void Queue<T>::MakeEmpty(){
	Node<T> *temp;
	while(front!=NULL){
		temp=front;front=front->link;delete temp;
	}
}
template<typename T>Queue<T>::~Queue(){MakeEmpty();}
template<typename T>void Queue<T>::EnQue(const T &data){
	if(front==NULL) front=rear=new Node<T>(data,NULL);
	else rear=rear->link=new Node<T>(data,NULL);
}
template<typename T>T Queue<T>::DeQue(){
	assert(!IsEmpty());
	Node<T> *temp=front;
	T data=temp->info;                       //ȡ��ͷ����е�����
	front=front->link;                       //��ͷ����
	delete temp;                             //�ͷ��ڴ�ռ�
	return data;
}
template<typename T>T Queue<T>::GetFront(){
	assert(!IsEmpty());
	return front->info;
}

int main(){
	int i;
	Queue<char> que;                          //����һ��������
	char str1[]="abcdefghijklmnop";           //17��Ԫ�أ�������������
	for(i=0;i<17;i++) que.EnQue(str1[i]);
	for(i=0;i<17;i++) cout<<que.DeQue();           //�Ƚ��ȳ�
	cout<<endl;	
	if(que.IsEmpty()) cout<<"�ӿ�"<<endl;
	return 0;
}
