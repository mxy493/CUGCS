#include<iostream>
using namespace std;

class Excp{                                   //为了简化，本例未用模板
public:
	virtual void print(){cerr<<"发生异常"<<endl;}
};
class stackExcp:public Excp{
public:
	virtual void print(){cerr<<"栈发生异常"<<endl;}
};
class pushOnFull:public stackExcp{
public:
	virtual void print(){cerr<<"栈满,不能压栈"<<endl;}
};
class popOnEmpty:public stackExcp{
public:
	void print(){cerr<<"栈已空，无法出栈"<<endl;}
};

class Stack{
	int top;                                     //栈顶指针（下标）
	int *elements;                               //动态建立的数值
	int maxSize;                                 //栈最大允纳的元素个数
public:
	Stack(int=20);                               //栈如不指定大小，设为20元素
	~Stack(){delete[] elements;}
	void Push(const int &data);                  //压栈
	int Pop();                                   //弹出，top--
	int GetElem(int i){return elements[i];}      //返回栈顶元素，top不变
	void MakeEmpty(){top= -1;}                   //清空栈
	bool IsEmpty() const{return top== -1;}       //判栈空
	bool IsFull() const{return top==maxSize-1;}  //判栈满
	void PrintStack();                           //输出栈内所有数据
};
Stack::Stack(int maxs){
	maxSize=maxs;
	top=-1;
	elements=new int [maxSize];                     //建立栈空间
}
void Stack::PrintStack(){
	for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
	cout<<endl;
}
void Stack::Push(const int &data){
	if(IsFull())  throw pushOnFull();             //栈满则抛出异常
	elements[++top]=data;                         //栈顶指针先加1，元素再进栈，top是指向栈顶元素
}
int Stack::Pop(){
	if(IsEmpty())  throw popOnEmpty();            //栈已空则不能退栈，抛出异常
	return elements[top--];				          //返回栈顶元素，同时栈顶指针退1
}

int main(){
	int a[9]={1,2,3,4,5,6,7,8,9}, b[9]={0},i;
	Stack istack(8);
	try{
		for(i=0;i<9;i++)  istack.Push(a[i]);      //到a[8]时栈满,异常
		istack.PrintStack();
	}
	catch(Excp&eObj){
		eObj.print();                             //调用虚函数pushOnFull::print()
	}
	try{for(i=0;i<9;i++) b[i]=istack.Pop();}
	catch(Excp&eObj){
		eObj.print();                             //调用虚函数popOnEmpty::print()
	}
	for(i=0;i<9;i++) cout<<b[i]<<'\t';
	cout<<endl;
	return 0;
}

