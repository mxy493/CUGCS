#include<iostream>
using namespace std;
//����ģ��
template<typename T>class pushOnFull{
	T _value;
public:
	pushOnFull(T i){_value=i;}
	T value(){return _value;}
	void print(){cerr<<"ջ����"<<value()<<"δѹ��ջ"<<endl;}
};
template<typename T>class popOnEmpty{
public:
	void print(){cerr<<"ջ�ѿգ��޷���ջ"<<endl;}
};

template<typename T>class Stack{
	int top;                                    //ջ��ָ�루�±꣩
	T *elements;                               //��̬��������ֵ
	int maxSize;                               //ջ������ɵ�Ԫ�ظ���
public:
	Stack(int=20);                              //ջ�粻ָ����С����Ϊ20Ԫ��
	~Stack(){delete[] elements;}
	void Push(const T &data) ;        //ѹջ
	T Pop();                            //������top-- 
	T GetElem(int i){return elements[i];}                 //����ָ��Ԫ�أ�top����
	void MakeEmpty(){top= -1;}                            //���ջ
	bool IsEmpty() const{return top== -1;}                //��ջ��
	bool IsFull() const{return top==maxSize-1;}           //��ջ��
	void PrintStack();                                    //���ջ����������
};
template<typename T> Stack<T>::Stack(int maxs){
	maxSize=maxs;
	top=-1;
	elements=new T [maxSize];                     //����ջ�ռ�
}
template<typename T> void Stack<T>::PrintStack(){
	for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
	cout<<endl;
}
template<typename T> void Stack<T>::Push(const T &data) {
	if(IsFull())  throw pushOnFull<T>(data);                   //ջ�����׳��쳣
	elements[++top]=data;          //ջ��ָ���ȼ�1��Ԫ���ٽ�ջ��top��ָ��ջ��Ԫ��
}
template<typename T>T Stack<T>::Pop() {
	if(IsEmpty())  throw popOnEmpty<T>();          //ջ�ѿ�������ջ���׳��쳣
	return elements[top--];				           //����ջ��Ԫ�أ�ͬʱջ��ָ����1
}

int main()try{
	int a[9]={1,2,3,4,5,6,7,8,9}, b[9]={0},i;
	Stack<int> istack(8);
	for(i=0;i<9;i++)  istack.Push(a[i]);     //��a[8]ʱջ��,�쳣
	istack.PrintStack();
	for(i=0;i<9;i++) b[i]=istack.Pop();
	for(i=0;i<9;i++) cout<<b[i]<<'\t';       //�����쳣�󲻻�ִ��
	cout<<endl;
	return 0;
}
catch(pushOnFull<int> & eObj){
	eObj.print();
	return 1;
}
catch(popOnEmpty<int> & eObj){
	eObj.print();
	return 2;
}

