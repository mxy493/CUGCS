//����9.5���ڡ���6.10����δ�����ز��������"<<"����������Ľ���
#include<iostream>
using namespace std;

template <typename T>struct Node{
	T  key;
	// ������ʡ��
};//�ٴ�ָ���ֺŲ�����
template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	Node<T> slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	void BubbleSort();
	bool Insert(Node<T> & elem,int i);
	void print();
	// �޹س�Ա����ʡ��
};//�ٴ�ָ���ֺŲ�����
template <typename T,int size> bool Orderedlist<T,size>::Insert(Node<T> & elem ,int i){
	if (i<0||i>last+1||last==maxsize-1) return false;
	else{
		for (int j=last;j>i;j--) slist[j]=slist[j-1];
		slist[i]=elem;
		last++;
		return true;
	}
}
template <typename T,int size> void Orderedlist<T,size>::print(){
	int i;
	for(i=0;i<=last;i++){
		cout<<slist[i].key;
		if(i%5==4) cout<<endl;
	}
	cout<<endl;
}
template <typename T,int size> void Orderedlist<T,size>::BubbleSort(){
	bool noswap;
	int i,j;
	Node<T> temp;
	for (i=0;i<last;i++){//�����n-1��
		noswap=true;	//δ������־Ϊ��
		for(j=last;j>i;j--){//��������ð��
			if(slist[j].key<slist[j-1].key){
				temp=slist[j];
				slist[j]=slist[j-1];
				slist[j-1]=temp;
				noswap=false;
			}			
		}
		if(noswap) break;	//�����޽���������ֹ�㷨��
	}
}

class mystring{
	char str[20];
	int maxsize;
	int last;
public:
	mystring(){
		last=-1;
		maxsize=20;
		str[0]='\0';
	}
	mystring(char *s){//����Ϊ�˼򻯣���׳�Բ�����
		last=-1;
		maxsize=20;
		do{
			last++;
			str[last]=s[last];
		}while(s[last]!='\0');
	}
	~mystring(){}
    friend ostream & operator<<(ostream & ,const mystring &);//������Ϊ��ʽ��������������
	bool operator<(mystring &);
	mystring & operator=(char * ms);
};
bool mystring::operator<(mystring & ms){//����<�����
	int i=0,k;
	do{
		k=str[i]-ms.str[i];
		i++;
	}while(k==0&&i<last&&i<ms.last);
	if(k<0) return true;
	if(i==last&&i!=ms.last) return true;
	return false;
}
ostream & operator<<(ostream & s,const mystring & cstr){
	return s<<cstr.str<<'\t';
}
mystring & mystring::operator=(char * ms){
	last=-1;	
	do{
		last++;
		str[last]=ms[last];
	}while(ms[last]!='\0'&&last<maxsize-1);
	ms[last]='\0';
	return *this;
}

int main(){
	const int h=10;
	int i;
	Orderedlist<mystring,100> ordlist;
	char mslist[h][5]={"cat","book","car","zoo","fish","cab","dog","cap","fox","can"};
	Node<mystring> n[h];//����������
	for(i=0;i<h;i++)  n[i].key=mslist[i];// ������鸳ֵ
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //����˳���
	cout<<"δ�����"<<endl;
	ordlist.print();
	ordlist.BubbleSort();
	cout<<"�������"<<endl;
	ordlist.print();
	return 0;
}
