//【例6.4】对半查找递归算法，算法作为有序表（ordered list）模板类的成员函数。
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
template <typename T,int size> int Orderedlist<T,size>::Binarysearch
(T & x,const int low,const int high){  // x为定值
	int mid=-1;//关键！否则找不到时出错
	if (low<=high){
		mid=(low+high)/2;
		if(slist[mid]<x) mid=Binarysearch(x,mid+1,high);
		//中间点小于定值，查找右区间，注意mid+1
		else if(x<slist[mid]) mid=Binarysearch(x,low,mid-1);
		//中间点大于定值，查找左区间，注意 mid-1
	}
	return mid;  // 找到返回下标，未找到但结束了，返回mid=-1，不加判断
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
	bool operator<(Element ele){return key<ele.key;}
	void putkey(int k){key=k;}
	void show(){cout<<key<<'\t';}
};//再次指出分号不可少
int main(){
	const int h=19;
	int i,k=37;
	Orderedlist<Element,100> ordlist;
	int a[h]={67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};//降序
	Element n[h],elem;
	for(i=0;i<h;i++)  n[i].putkey(a[i]);
	for(i=0;i<h;i++)  ordlist.Insert(n[i],0); //始终在0号元素插入，建立升序顺序表
	elem.putkey(k);
	ordlist.print();
	i=ordlist.Binarysearch(elem,0,h-1);
	cout<<"整数"<<k<<"在表中位置（下标）："<<i<<endl;
	k=33;
	elem.putkey(k);
	i=ordlist.Binarysearch(elem,0,h-1);
	cout<<"整数"<<k<<"在表中位置（下标）："<<i<<endl;
return 0;
}
