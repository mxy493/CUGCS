#include<iostream>
using namespace std;

template<typename T>class pushOnFull{
	T _value;
public:
	pushOnFull(T i){_value=i;}
	T value(){return _value;}
	void print(){cerr<<"栈满，"<<value()<<"未压入栈"<<endl;}
};
template<typename T>class popOnEmpty{
public:
	void print(){cerr<<"栈已空，无法出栈"<<endl;}
};

template<typename T>class Stack{
	int top;                                    //栈顶指针（下标）
	T *elements;                               //动态建立的数值
	int maxSize;                               //栈最大允纳的元素个数
public:
	Stack(int=20);                              //栈如不指定大小，设为20元素
	~Stack(){delete[] elements;}
	void Push(const T &data) ;        //压栈
	T Pop();                            //弹出，top-- 
	T GetElem(int i){return elements[i];}                 //返回指定元素，top不变
	void MakeEmpty(){top= -1;}                            //清空栈
	bool IsEmpty() const{return top== -1;}                //判栈空
	bool IsFull() const{return top==maxSize-1;}           //判栈满
	void PrintStack();                                    //输出栈内所有数据
};
template<typename T> Stack<T>::Stack(int maxs){
	maxSize=maxs;
	top=-1;
	elements=new T [maxSize];                     //建立栈空间
}
template<typename T> void Stack<T>::PrintStack(){
	for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
	cout<<endl;
}
template<typename T> void Stack<T>::Push(const T &data) {
	if(IsFull())  throw pushOnFull<T>(data);                   //栈满则抛出异常
	elements[++top]=data;          //栈顶指针先加1，元素再进栈，top是指向栈顶元素
}
template<typename T>T Stack<T>::Pop() {
	if(IsEmpty())  throw popOnEmpty<T>();          //栈已空则不能退栈，抛出异常
	return elements[top--];				           //返回栈顶元素，同时栈顶指针退1
}

int main(){
	int a[9]={1,2,3,4,5,6,7,8,9}, b[9]={0},i;
	Stack<int>istack(8);
	try{
		for(i=0;i<9;i++)  istack.Push(a[i]);//到a[8]时栈满,异常
		istack.PrintStack();
	}
	catch(pushOnFull<int>&eObj){eObj.print();}
	try{for(i=0;i<9;i++) b[i]=istack.Pop();}
	catch(popOnEmpty<int>&eObj){ eObj.print();}
	cout<<"出栈次序为：";
	for(i=0;i<9;i++) cout<<b[i]<<'\t';
	cout<<endl;
	return 0;
}

