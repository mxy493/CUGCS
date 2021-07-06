//【例6.5】对半查找迭代算法。
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
	// 无关成员函数省略
};//再次指出分号不可少
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
	int high=last ,low=0,mid;  // last 当前有序表最大下标
	if(last==1) return -1;     //避免空表出错
	while(low<=high){
		mid=(low+high)/2;
		if(x<slist[mid])  high=mid-1;  //左缩查找区间
		else if(slist[mid]<x) low=mid+1;// 右缩查找区间
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
	// 其他域省略
public:
	bool operator<(Element ele)const{return key<ele.key;}//注意这里加了const
	bool operator!=(Element ele)const{return key!=ele.key;}
	void putkey(int k){key=k;}
	void show(){cout<<key<<'\t';}
};//再次指出分号不可少
int main(){
	const int h=19;
	int i,k=47;
	Orderedlist<Element,100> ordlist;
	int a[h]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};//升序
	Element n[h],elem;
	for(i=0;i<h;i++)  n[i].putkey(a[i]);
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //在线性表尾插入，建立升序顺序表
	ordlist.print();
	elem.putkey(k);
	i=ordlist.Binarysearch(elem);
	cout<<"整数"<<k<<"在表中位置（下标）："<<i<<endl;
	k=33;
	elem.putkey(k);
	i=ordlist.Binarysearch(elem);
	cout<<"整数"<<k<<"在表中位置（下标）："<<i<<endl;
	return 0;
}
