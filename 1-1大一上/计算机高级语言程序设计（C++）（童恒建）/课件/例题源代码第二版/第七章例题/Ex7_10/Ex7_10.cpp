//����7.10��˳��洢��ʽ��ѭ��������ģ�塣
#include<cassert>
#include<iostream>
using namespace std;

template<typename T>class Queue{
	int rear,front;									//��β���ͷ
	T *elements;									//��Ŷ���Ԫ�ص�����
	int maxSize;                     				//������������Ԫ�ظ���+1
public:
	Queue(int ms=18);
	~Queue(){delete[] elements;}
	bool IsEmpty() const {return front==rear;}			 //�жӿ�
	bool IsFull() const {return (rear+1)%maxSize==front;} //�ж���
	int Length() const {return  (rear-front+maxSize)%maxSize;}   
			//�����Ԫ������ע�������㷨
	void EnQue(const T &data);						 //����
	T DeQue();									 //����
	T GetFront();									 //ȡ��ͷ����
	void MakeEmpty(){front=rear=0;}				 //���ÿգ���ʼ̬��
};
template<typename T> Queue<T>::Queue(int ms){
	maxSize=ms;
	elements=new T[maxSize];
	rear=front=0;
	assert(elements!=NULL);						 //���ԣ�����ɹ�
}
template<typename T> void Queue<T>::EnQue(const T &data){  //����
	assert(!IsFull());								 //���ԣ����в������������ܽ���
	rear=(rear+1)%maxSize;							 //��βָ���1
	elements[rear]=data;
}
template<typename T>T Queue<T>::DeQue(){
	assert(!IsEmpty());
	front=(front+1)%maxSize;						 //��ͷָ���1
	return elements[front];  					//ע��frontָ�����ڶ�ͷ��ǰһλ��
}
template<typename T>T Queue<T>::GetFront(){
	assert(!IsEmpty());
	return elements[(front+1)%maxSize];				 //ע���1���ܷ��ض�ͷ����
}

int main(){
	int i;
	Queue<char> que;                             //ȱʡΪ18Ԫ�ض��У�����17
	char str1[]="abcdefghijklmnop";//17��Ԫ�أ�������������
	que.MakeEmpty();
	for(i=0;i<17;i++) que.EnQue(str1[i]);
	if(que.IsFull()) cout<<"����";
	cout<<"����Ԫ�أ�"<<que.Length()<<endl;
	for(i=0;i<17;i++) cout<<que.DeQue();           //�Ƚ��ȳ�
	cout<<endl;	
	if(que.IsEmpty()) cout<<"�ӿ�";
	cout<<"����Ԫ�أ�"<<que.Length()<<endl;
	return 0;
}