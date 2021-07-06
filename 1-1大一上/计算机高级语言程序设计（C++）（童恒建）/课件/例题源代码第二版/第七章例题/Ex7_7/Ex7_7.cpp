//����7.7��˫��������ģ��ͽ����ģ�塣
#include<iostream>
#include<string>     //������ͷ�ļ�,��ʹ�ñ�׼�ַ���
using namespace std;

template<typename T> class DblList;
template<typename T> class DblNode{
	T info;//������
	DblNode<T> *llink,*rlink;    //ǰ��������������̣�������ָ��
public:
	DblNode(T data);
	DblNode();
	T Getinfo(){return info;};
	friend class DblList<T>;
};
template<typename T> DblNode<T>::DblNode(){
	llink=rlink=NULL;
}
template<typename T> DblNode<T>::DblNode(T data){
	info=data;
	llink=NULL;
	rlink=NULL;
}
template<typename T>class DblList{
	DblNode<T> *head,*current;
public:
	DblList();
	~DblList();
	void Insert(const T & data);
	DblNode<T>* Remove(DblNode<T>* p);
	void Print();
	int Length();//����������
	DblNode<T> *Find(T data);//���������붨ֵ��ͬ�Ľ��
	void MakeEmpty();//�������
	//��������
};
template<typename T> DblList<T>::DblList(){//������ͷ���
	head=new DblNode<T>();
	head->rlink=head->llink=head;
	current=NULL;
}
template<typename T> DblList<T>::~DblList(){
	MakeEmpty();//�������
	delete head;
}
template<typename T> void DblList<T>::MakeEmpty(){
	DblNode<T> *tempP;
	while(head->rlink!=head){
		tempP=head->rlink;
		head->rlink=tempP->rlink;//��ͷ����ĵ�һ���ڵ����������
		tempP->rlink->llink=head;//������ָ��
		delete tempP;           //ɾ��(�ͷ�)���������Ľ��
	}
	current=NULL;  //currentָ��ָ�
}
template<typename T> void DblList<T>::Insert(const T & data){//�½ڵ�����β
	current=new DblNode<T>;  //thj: ������˫��ѭ������
	current->info=data;
	current->rlink=head;//ע�����
	current->llink=head->llink;
	head->llink->rlink=current;
	head->llink=current;//�����
}
template<typename T> DblNode<T>* DblList<T>::Remove(DblNode<T>* p){
	current=head->rlink;
	while(current!=head&&current!=p) current=current->rlink;
	if(current==head) current=NULL;
	else{//���ժ��
		p->llink->rlink=p->rlink;
		p->rlink->llink=p->llink;
		p->rlink=p->llink=NULL;
	}
	return current;
}

template<typename T> DblNode<T>* DblList<T>::Find(T data){
	current=head->rlink;
	while(current!=head&&current->info!=data) current=current->rlink;
	if(current==head) current=NULL;
	return current;
}
template<typename T> void DblList<T>::Print(){
	current=head->rlink;
	while(current!=head){
		cout<<current->info<<'\t';
		current=current->rlink;
	}
	cout<<endl;
}
template<typename T> int DblList<T>::Length(){
	int count=0;
	current=head->rlink;
	while(current!=head){
		count++;
		current=current->rlink;
	}
	return count;
}

int main(){
	DblList<int> Dbl1;
	DblNode<int> *tp=NULL;
	int i,a[11]={19,11,17,13,7,2,3,5,23,31,29};
	for(i=0;i<11;i++) Dbl1.Insert(a[i]);
	cout<<"˫�������ȣ�"<<Dbl1.Length()<<endl;
	Dbl1.Print();
	tp=Dbl1.Find(7);
	if(tp) cout<<"�鵽�Ľ������Ϊ��"<<tp->Getinfo()<<" ���"<<endl;
	delete Dbl1.Remove(tp);
	cout<<"˫�������ȣ�"<<Dbl1.Length()<<endl;
	Dbl1.Print();
	cout<<"�������"<<endl;
	Dbl1.MakeEmpty();
	cout<<"˫�������ȣ�"<<Dbl1.Length()<<endl;
	return 0;
}