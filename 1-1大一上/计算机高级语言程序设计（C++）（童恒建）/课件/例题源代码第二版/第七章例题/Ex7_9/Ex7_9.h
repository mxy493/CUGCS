//【例7.9_h】链栈的类模板，本例为头文件"Ex7_9.h"。采用无头结点链表。
#include<cassert>
using namespace std;
template<typename T>class Stack;
template<typename T>class Node{                  //链栈结点类模板
	T info;
	Node<T> *link;
public:
	Node(T data=0,Node<T> *next=NULL){
		info=data;
		link=next;
	}
	friend class Stack<T>;
};
template<typename T>class Stack{                  //链栈类模板，无头结点链表
	Node<T> *top;                              //栈顶指针
public:
	Stack(){top=NULL;}
	~Stack();
	void Push(const T &data);                      //压栈
	T Pop();                                    //弹出
	T GetTop();                                 //取栈顶元素
	void MakeEmpty();                           //清空栈
	bool IsEmpty(){return top==NULL;}
};
template<typename T> Stack<T>::~Stack(){MakeEmpty();}
template<typename T>void Stack<T>::MakeEmpty(){
	Node<T> *temp;
	while(top!=NULL){temp=top;top=top->link;delete temp;}
}
template<typename T> void Stack<T>::Push(const T &data){
	top=new Node<T>(data,top);
}
template<typename T> T Stack<T>::Pop(){
	assert(!IsEmpty());
	Node<T> *temp=top;
	T data=temp->info;
	top=top->link;                             //丢弃栈顶结点
	delete temp;                               //释放栈顶结点
	return data;                                //返回栈顶数据
}
template<typename T> T Stack<T>::GetTop(){
	assert(!IsEmpty());
	return top->info;
}
