//����6. 7������԰���������㷨������ΪOrderedlist<T,size >��ĳ�Ա������
//��˳������ź���Ĳ��ֲ��Һ�һԪ�ز���λ��ʱ�����ö԰���ҷ�����
#include<iostream>
#include<string>
using namespace std;

template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	T slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	void BinaryInsertSort();
	bool Insert(T & elem,int i);
	void print();
	// �޹س�Ա����ʡ��
};//�ٴ�ָ���ֺŲ�����
template <typename T,int size> bool Orderedlist<T,size>::Insert(T & elem ,int i){
	int j;
	if (i<0||i>last+1||last==maxsize-1) return false;
	else{
		last++;
		for (j=last;j>i;j--) slist[j]=slist[j-1];
		slist[i]=elem;
		return true;
	}
}
template <typename T,int size> void Orderedlist<T,size>::print(){
	int i;
	for(i=0;i<=last;i++){
		slist[i].show();
		if(i%5==4) cout<<endl;
	}
	cout<<endl;
}
template <typename T,int size> void Orderedlist<T,size>::BinaryInsertSort(){
	T temp;
	int low,high,mid,i,j;
	for (i=1;i<=last;i++){
		temp=slist[i];
		low=0;
		high=i-1;
		while (low<=high){//��ע����԰���ҵĲ�֮ͬ��
			mid=(low+high)/2;
			if(temp<slist[mid])  high=mid-1;
			else  low=mid+1;
		}//�ȶ�����
		for(j=i-1;j>=low;j--) slist[j+1]=slist[j];
		slist[low]=temp;
	}
}

class Element{
	string  key;
	// ������ʡ��
public:
	bool operator<(Element ele){return key<ele.key;}
	void putkey(string k){key=k;}
	void show(){cout<<key<<'\t';}
};//�ٴ�ָ���ֺŲ�����
int main(){
	const int h=10;
	int i;
	Orderedlist<Element,100> ordlist;
	string mslist[h]={"cat","book","car","zoo","fish","cab","dog","cap","fox","can"};
	Element n[h];
	for(i=0;i<h;i++)  n[i].putkey(mslist[i]);
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //����˳���
	cout<<"δ�����"<<endl;
	ordlist.print();
	ordlist.BinaryInsertSort();
	cout<<"�������"<<endl;
	ordlist.print();
	return 0;
}

