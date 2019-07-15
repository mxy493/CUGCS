//【例7.7】双向链表类模板和结点类模板。
#include<iostream>
#include<string>     //保留此头文件,可使用标准字符串
using namespace std;

template<typename T> class DblList;
template<typename T> class DblNode{
	T info;//数据域
	DblNode<T> *llink,*rlink;    //前驱（左链）、后继（右链）指针
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
	int Length();//计算链表长度
	DblNode<T> *Find(T data);//搜索数据与定值相同的结点
	void MakeEmpty();//清空链表
	//其它操作
};
template<typename T> DblList<T>::DblList(){//建立表头结点
	head=new DblNode<T>();
	head->rlink=head->llink=head;
	current=NULL;
}
template<typename T> DblList<T>::~DblList(){
	MakeEmpty();//清空链表
	delete head;
}
template<typename T> void DblList<T>::MakeEmpty(){
	DblNode<T> *tempP;
	while(head->rlink!=head){
		tempP=head->rlink;
		head->rlink=tempP->rlink;//把头结点后的第一个节点从链中脱离
		tempP->rlink->llink=head;//处理左指针
		delete tempP;           //删除(释放)脱离下来的结点
	}
	current=NULL;  //current指针恢复
}
template<typename T> void DblList<T>::Insert(const T & data){//新节点在链尾
	current=new DblNode<T>;  //thj: 构成了双向循环链表
	current->info=data;
	current->rlink=head;//注意次序
	current->llink=head->llink;
	head->llink->rlink=current;
	head->llink=current;//最后做
}
template<typename T> DblNode<T>* DblList<T>::Remove(DblNode<T>* p){
	current=head->rlink;
	while(current!=head&&current!=p) current=current->rlink;
	if(current==head) current=NULL;
	else{//结点摘下
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
	cout<<"双向链表长度："<<Dbl1.Length()<<endl;
	Dbl1.Print();
	tp=Dbl1.Find(7);
	if(tp) cout<<"查到的结点数据为："<<tp->Getinfo()<<" 清除"<<endl;
	delete Dbl1.Remove(tp);
	cout<<"双向链表长度："<<Dbl1.Length()<<endl;
	Dbl1.Print();
	cout<<"清空链表"<<endl;
	Dbl1.MakeEmpty();
	cout<<"双向链表长度："<<Dbl1.Length()<<endl;
	return 0;
}