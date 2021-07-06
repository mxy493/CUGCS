#include<iostream>
using namespace std;

class Excp{                                   //Ϊ�˼򻯣�����δ��ģ��
public:
	virtual void print(){cerr<<"�����쳣"<<endl;}
};
class stackExcp:public Excp{
public:
	virtual void print(){cerr<<"ջ�����쳣"<<endl;}
};
class pushOnFull:public stackExcp{
public:
	virtual void print(){cerr<<"ջ��,����ѹջ"<<endl;}
};
class popOnEmpty:public stackExcp{
public:
	void print(){cerr<<"ջ�ѿգ��޷���ջ"<<endl;}
};

class Stack{
	int top;                                     //ջ��ָ�루�±꣩
	int *elements;                               //��̬��������ֵ
	int maxSize;                                 //ջ������ɵ�Ԫ�ظ���
public:
	Stack(int=20);                               //ջ�粻ָ����С����Ϊ20Ԫ��
	~Stack(){delete[] elements;}
	void Push(const int &data);                  //ѹջ
	int Pop();                                   //������top--
	int GetElem(int i){return elements[i];}      //����ջ��Ԫ�أ�top����
	void MakeEmpty(){top= -1;}                   //���ջ
	bool IsEmpty() const{return top== -1;}       //��ջ��
	bool IsFull() const{return top==maxSize-1;}  //��ջ��
	void PrintStack();                           //���ջ����������
};
Stack::Stack(int maxs){
	maxSize=maxs;
	top=-1;
	elements=new int [maxSize];                     //����ջ�ռ�
}
void Stack::PrintStack(){
	for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
	cout<<endl;
}
void Stack::Push(const int &data){
	if(IsFull())  throw pushOnFull();             //ջ�����׳��쳣
	elements[++top]=data;                         //ջ��ָ���ȼ�1��Ԫ���ٽ�ջ��top��ָ��ջ��Ԫ��
}
int Stack::Pop(){
	if(IsEmpty())  throw popOnEmpty();            //ջ�ѿ�������ջ���׳��쳣
	return elements[top--];				          //����ջ��Ԫ�أ�ͬʱջ��ָ����1
}

int main(){
	int a[9]={1,2,3,4,5,6,7,8,9}, b[9]={0},i;
	Stack istack(8);
	try{
		for(i=0;i<9;i++)  istack.Push(a[i]);      //��a[8]ʱջ��,�쳣
		istack.PrintStack();
	}
	catch(Excp&eObj){
		eObj.print();                             //�����麯��pushOnFull::print()
	}
	try{for(i=0;i<9;i++) b[i]=istack.Pop();}
	catch(Excp&eObj){
		eObj.print();                             //�����麯��popOnEmpty::print()
	}
	for(i=0;i<9;i++) cout<<b[i]<<'\t';
	cout<<endl;
	return 0;
}

