//����7.15���������������Һ������ݹ�����������������Ĳ����㷨��
#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T>class BinaryTree;
template<typename T>class Node{
	Node<T> *lchild,*rchild;
	T info;
public:
	Node(){lchild=NULL;rchild=NULL;}
	Node(T data,Node<T> *left=NULL,Node<T> *right=NULL){
		info=data;
		lchild=left;
		rchild=right;
	}
	friend class BinaryTree<T>;
};
template<typename T>class BinaryTree{
	Node<T> *root;                  //�������ĸ�ָ��
	void InOrder(Node<T> *Current);                //�������
	void Insert(const T &data,Node<T> * &b); //�����㣬�ڶ�����Ϊ���ã�
	void Destory(Node<T> * Current);         //ɾ����
	Node<T>* Find(const T &data,Node<T> *b);//����
public:
	BinaryTree(){root=NULL;}						//�������캯��
	~BinaryTree(){Destory(root);}						//��������
	void Creat(T* data,int n);                    //���������򣩶�����
	void InOrder(){InOrder(root);}                //������������к���Ϊ�ӿ�
	void Find(const T &data){//����
		Node<T>* temp=Find(data,root) ;
		if(temp==NULL) cout<<"�޴�����"<<'\t';
		else cout<<temp->info<<'\t';
	}
};
template<typename T> void BinaryTree<T>::Destory(Node<T> *Current){
	if(Current!=NULL){
		Destory(Current->lchild);
		Destory(Current->rchild);
		delete Current;  						//�����ͷŸ����
	}
}
template<typename T>void BinaryTree<T>::Insert(const T &data,Node<T> * &b){
	if(b==NULL){								//�ѵ�����,����
		b=new Node<T>(data);
		if(b==NULL){
			cout<<"�ռ䲻��"<<endl;
			exit(1);
		}
	}
	else if(data<b->info) Insert(data,b->lchild);			//С��,��������ȥ��
	     else Insert(data,b->rchild);	//���ڵ���,��������ȥ��
}
template<typename T>void BinaryTree<T>::Creat(T* data,int n){		//����һ�ö���������
	for(int i=0;i<n;i++) Insert(data[i],root);
}
template<typename T>Node<T> *BinaryTree<T>::Find(const T &data,Node<T> *b){//����
	if(b!=NULL){
		Node<T> *temp=b;
		while(temp!=NULL){
			if(temp->info==data)return temp;
			if(temp->info<data)temp=temp->rchild;
				else temp=temp->lchild;
		}	
	}
	return NULL;
}
template<typename T>void BinaryTree<T>::InOrder(Node<T> *Current){
	if(Current!=NULL){							//�ݹ���ֹ����
		InOrder(Current->lchild);					//�������������
		cout<<Current->info<<'\t';					//���ʸ���㣬ע������λ��
		InOrder(Current->rchild);					//�������������
	}
}

int main(){
	const int n=15;
	int i,a[n]={10,5,15,8,3,18,13,12,14,16,20,1,4,6,9};
	BinaryTree<int> btree;
	btree.Creat(a,n);
	cout<<"�������ݣ�"<<endl;
	for(i=0;i<n;i++) cout<<a[i]<<'\t';
	cout<<endl<<"����"<<endl;
	btree.InOrder();    //��������������
	cout<<endl<<"���ң�"<<endl;
	btree.Find(a[13]);
	btree.Find(a[2]);
	btree.Find(2);
	cout<<endl;
	return 0;
}