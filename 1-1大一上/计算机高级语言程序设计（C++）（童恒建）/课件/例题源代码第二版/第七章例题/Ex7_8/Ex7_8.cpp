//����7.8��˳��ջ����ģ�塣��������Ԫ��ѹջ��������ȡԪ�ء����ջԪ�ء�
//�ж�ջ�Ƿ�ջ�����Ϊ�˰�ȫ��ջ��������ѹջ��ջ�ղ����ٵ�����
#include<cassert>
#include<iostream>
using namespace std;

template<typename T>class Stack{
	int top;                                    //ջ��ָ�루�±꣩
	T *elements;                               //��̬������ջ
	int maxSize;                               //ջ������ɵ�Ԫ�ظ���
public:
	Stack(int=20);                              //ջ�粻ָ����С����Ϊ20Ԫ��
	~Stack(){delete[] elements;}
	void Push(const T &data);                    //ѹջ
	T Pop();                            //������top--
	T GetElem(int i);                   //ȡ���ݣ�top����
	void MakeEmpty(){top= -1;}                  //���ջ
	bool IsEmpty() const{return top== -1;}          //��ջ��
	bool IsFull() const{return top==maxSize-1;}      //��ջ��
	void PrintStack();                            //���ջ����������
};
template<typename T> Stack<T>::Stack(int maxs){
	maxSize=maxs;
	top=-1;
	elements=new T [maxSize];                     //����ջ�ռ�
	assert(elements!=0);                           //���䲻�ɹ���������
}
template<typename T> void Stack<T>::PrintStack(){
	for(int i=0;i<=top;i++) cout<<elements[i]<<'\t';
	cout<<endl;
}
template<typename T> void Stack<T>::Push(const T &data){
	assert(!IsFull());                             //ջ�����˳�����
	elements[++top]=data;                //ջ��ָ���ȼ�1��Ԫ���ٽ�ջ��top��ָ��ջ��Ԫ��
}
template<typename T> T Stack<T>::Pop(){
	assert(!IsEmpty());                           //ջ�ѿ�������ջ���˳�����
	return elements[top--];                        //����ջ��Ԫ�أ�ͬʱջ��ָ����1
}
template<typename T> T Stack<T>::GetElem(int I){
	assert(i<=top&&i>=0);                        //����ջ��Ч��������˳�����
	return elements[i];                            //����ָ��Ԫ�أ�top����
}

int main(){
	int i,a[10]={0,1,2,3,4,5,6,7,8,9},b[10];
	Stack<int> istack(10);
	for(i=0;i<10;i++) istack.Push(a[i]);
	if(istack.IsFull()) cout<<"ջ��"<<endl;
	istack.PrintStack();
	for(i=0;i<10;i++) b[i]=istack.Pop();
	if(istack.IsEmpty()) cout<<"ջ��"<<endl;
	for(i=0;i<10;i++) cout<<b[i]<<'\t';//ע���Ƚ����
	cout<<endl;
	istack.Pop();                          //�����
	return 0;
}
