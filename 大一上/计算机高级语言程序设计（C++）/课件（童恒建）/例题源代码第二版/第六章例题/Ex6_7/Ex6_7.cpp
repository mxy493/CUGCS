//【例6. 7】升序对半插入排序算法，亦作为Orderedlist<T,size >类的成员函数。
//在顺序表已排好序的部分查找后一元素插入位置时，采用对半查找方法。
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
		while (low<=high){//请注意与对半查找的不同之处
			mid=(low+high)/2;
			if(temp<slist[mid])  high=mid-1;
			else  low=mid+1;
		}//稳定排序
		for(j=i-1;j>=low;j--) slist[j+1]=slist[j];
		slist[low]=temp;
	}
}

class Element{
	string  key;
	// 其他域省略
public:
	bool operator<(Element ele){return key<ele.key;}
	void putkey(string k){key=k;}
	void show(){cout<<key<<'\t';}
};//再次指出分号不可少
int main(){
	const int h=10;
	int i;
	Orderedlist<Element,100> ordlist;
	string mslist[h]={"cat","book","car","zoo","fish","cab","dog","cap","fox","can"};
	Element n[h];
	for(i=0;i<h;i++)  n[i].putkey(mslist[i]);
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //建立顺序表
	cout<<"未排序表："<<endl;
	ordlist.print();
	ordlist.BinaryInsertSort();
	cout<<"已排序表："<<endl;
	ordlist.print();
	return 0;
}

