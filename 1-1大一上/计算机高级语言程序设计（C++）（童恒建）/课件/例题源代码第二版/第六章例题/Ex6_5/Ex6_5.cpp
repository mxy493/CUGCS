//����6.5���԰���ҵ����㷨��
#include<iostream>
using namespace std;

template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	T slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	int Binarysearch(T & x)const;
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
template <typename T,int size> int Orderedlist<T,size>::Binarysearch(T & x)const{
	int high=last ,low=0,mid;  // last ��ǰ���������±�
	if(last==1) return -1;     //����ձ����
	while(low<=high){
		mid=(low+high)/2;
		if(x<slist[mid])  high=mid-1;  //������������
		else if(slist[mid]<x) low=mid+1;// ������������
		     else return mid;
	}
	if(slist[mid]!=x) mid=-1;
	return mid;
}
template <typename T,int size> void Orderedlist<T,size>::print(){
	int i;
	for(i=0;i<=last;i++){
		slist[i].show();
		if(i%5==4) cout<<endl;
	}
	cout<<endl;
}
class Element{
	int  key;
	// ������ʡ��
public:
	bool operator<(Element ele)const{return key<ele.key;}//ע���������const
	bool operator!=(Element ele)const{return key!=ele.key;}
	void putkey(int k){key=k;}
	void show(){cout<<key<<'\t';}
};//�ٴ�ָ���ֺŲ�����
int main(){
	const int h=19;
	int i,k=47;
	Orderedlist<Element,100> ordlist;
	int a[h]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};//����
	Element n[h],elem;
	for(i=0;i<h;i++)  n[i].putkey(a[i]);
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //�����Ա�β���룬��������˳���
	ordlist.print();
	elem.putkey(k);
	i=ordlist.Binarysearch(elem);
	cout<<"����"<<k<<"�ڱ���λ�ã��±꣩��"<<i<<endl;
	k=33;
	elem.putkey(k);
	i=ordlist.Binarysearch(elem);
	cout<<"����"<<k<<"�ڱ���λ�ã��±꣩��"<<i<<endl;
	return 0;
}
