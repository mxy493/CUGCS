//【例7.8】顺序栈的类模板。操作包括元素压栈、弹出、取元素、清空栈元素、
//判断栈是否空或满。为了安全，栈满不可再压栈，栈空不可再弹出。
#include<cassert>
#include<iostream>
using namespace std;

template<typename T>class Stack{
	int top;                                    //栈顶指针（下标）
	T *elements;                               //动态建立的栈
	int maxSize;                               //栈最大容纳的元素个数
public:
	Stack(int=20);                              //栈如不指定大小，设为20元素
	~Stack(){delete[] elements;}
	void Push(const T &data);                    //压栈
	T Pop();                            //弹出，top--
	T GetElem(int i);                   //取数据，top不变
	void MakeEmpty(){top= -1;}                  //清空栈
	bool IsEmpty() const{return top== -1;}          //判栈空
	bool IsFull() const{return top==maxSize-1;}      //判栈满
	void PrintStack();                            //输出栈内所有数据
};
template<typename T> Stack<T>::Stack(int maxs){
	maxSize=maxs;
	top=-1;
	elements=new T [maxSize];                     //建立栈空间
	assert(elements!=0);                           //分配不成功结束程序
}
template<typename T> void Stack<T>::PrintStack(){
	for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
	cout<<endl;
}
template<typename T> void Stack<T>::Push(const T &data){
	assert(!IsFull());                             //栈满则退出程序
	elements[++top]=data;                //栈顶指针先加1，元素再进栈，top是指向栈顶元素
}
template<typename T> T Stack<T>::Pop(){
	assert(!IsEmpty());                           //栈已空则不能退栈，退出程序
	return elements[top--];                        //返回栈顶元素，同时栈顶指针退1
}
template<typename T> T Stack<T>::GetElem(int I){
	assert(i<=top&&i>=0);                        //超出栈有效数据则错，退出程序
	return elements[i];                            //返回指定元素，top不变
}

int main(){
	int i,a[10]={0,1,2,3,4,5,6,7,8,9},b[10];
	Stack<int> istack(10);
	for(i=0;i<10;i++) istack.Push(a[i]);
	if(istack.IsFull()) cout<<"栈满"<<endl;
	istack.PrintStack();
	for(i=0;i<10;i++) b[i]=istack.Pop();
	if(istack.IsEmpty()) cout<<"栈空"<<endl;
	for(i=0;i<10;i++) cout<<b[i]<<'\t';//注意先进后出
	cout<<endl;
	istack.Pop();                          //下溢出
	return 0;
}
