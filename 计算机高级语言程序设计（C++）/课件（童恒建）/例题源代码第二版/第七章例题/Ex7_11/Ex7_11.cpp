//【例7.11】链队类模板。
#include<iostream>
#include<cassert>
using namespace std;

template<typename T>class Queue;
template<typename T>class Node{
	T info;
	Node *link;     //在类模板Node中使用指向Node的指针可以不加<T>
public:
	Node(T data=0,Node *l=NULL);
	friend class Queue<T>;
};
template<typename T> Node<T>::Node(T data,Node *l){
	info=data;
	link=l;
}
template<typename T>class Queue{
	Node<T> *front,*rear;    //在其他类中指向Node的指针必须加<T>
public:
	Queue(){rear=front=NULL;}						     //构造一个空链队
	~Queue();
	bool IsEmpty(){ return front==NULL;}				 //队空否？
	void EnQue(const T &data);						     //进队
	T DeQue();									         //出队
	T GetFront();						 			     //查看队头数据
	void MakeEmpty();					                 //置空队列，与析构逻辑上不同，物理上一样
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
	T data=temp->info;                       //取队头结点中的数据
	front=front->link;                       //队头出队
	delete temp;                             //释放内存空间
	return data;
}
template<typename T>T Queue<T>::GetFront(){
	assert(!IsEmpty());
	return front->info;
}

int main(){
	int i;
	Queue<char> que;                          //构造一个空链队
	char str1[]="abcdefghijklmnop";           //17个元素，包括串结束符
	for(i=0;i<17;i++) que.EnQue(str1[i]);
	for(i=0;i<17;i++) cout<<que.DeQue();           //先进先出
	cout<<endl;	
	if(que.IsEmpty()) cout<<"队空"<<endl;
	return 0;
}
