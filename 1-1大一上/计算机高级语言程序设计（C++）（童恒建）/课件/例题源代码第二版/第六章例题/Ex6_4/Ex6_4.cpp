//����6.4���԰���ҵݹ��㷨���㷨��Ϊ�����ordered list��ģ����ĳ�Ա������
#include<iostream>
using namespace std;

template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	T slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	int Binarysearch(T & x,const int low,const int high);
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
template <typename T,int size> int Orderedlist<T,size>::Binarysearch
(T & x,const int low,const int high){  // xΪ��ֵ
	int mid=-1;//�ؼ��������Ҳ���ʱ����
	if (low<=high){
		mid=(low+high)/2;
		if(slist[mid]<x) mid=Binarysearch(x,mid+1,high);
		//�м��С�ڶ�ֵ�����������䣬ע��mid+1
		else if(x<slist[mid]) mid=Binarysearch(x,low,mid-1);
		//�м����ڶ�ֵ�����������䣬ע�� mid-1
	}
	return mid;  // �ҵ������±꣬δ�ҵ��������ˣ�����mid=-1�������ж�
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
	bool operator<(Element ele){return key<ele.key;}
	void putkey(int k){key=k;}
	void show(){cout<<key<<'\t';}
};//�ٴ�ָ���ֺŲ�����
int main(){
	const int h=19;
	int i,k=37;
	Orderedlist<Element,100> ordlist;
	int a[h]={67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};//����
	Element n[h],elem;
	for(i=0;i<h;i++)  n[i].putkey(a[i]);
	for(i=0;i<h;i++)  ordlist.Insert(n[i],0); //ʼ����0��Ԫ�ز��룬��������˳���
	elem.putkey(k);
	ordlist.print();
	i=ordlist.Binarysearch(elem,0,h-1);
	cout<<"����"<<k<<"�ڱ���λ�ã��±꣩��"<<i<<endl;
	k=33;
	elem.putkey(k);
	i=ordlist.Binarysearch(elem,0,h-1);
	cout<<"����"<<k<<"�ڱ���λ�ã��±꣩��"<<i<<endl;
return 0;
}
