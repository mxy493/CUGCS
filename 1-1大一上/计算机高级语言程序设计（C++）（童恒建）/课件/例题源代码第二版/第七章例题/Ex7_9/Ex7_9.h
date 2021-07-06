//����7.9_h����ջ����ģ�壬����Ϊͷ�ļ�"Ex7_9.h"��������ͷ�������
#include<cassert>
using namespace std;
template<typename T>class Stack;
template<typename T>class Node{                  //��ջ�����ģ��
	T info;
	Node<T> *link;
public:
	Node(T data=0,Node<T> *next=NULL){
		info=data;
		link=next;
	}
	friend class Stack<T>;
};
template<typename T>class Stack{                  //��ջ��ģ�壬��ͷ�������
	Node<T> *top;                              //ջ��ָ��
public:
	Stack(){top=NULL;}
	~Stack();
	void Push(const T &data);                      //ѹջ
	T Pop();                                    //����
	T GetTop();                                 //ȡջ��Ԫ��
	void MakeEmpty();                           //���ջ
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
	top=top->link;                             //����ջ�����
	delete temp;                               //�ͷ�ջ�����
	return data;                                //����ջ������
}
template<typename T> T Stack<T>::GetTop(){
	assert(!IsEmpty());
	return top->info;
}
