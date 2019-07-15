//【例9.5】在【例6.10】中未能重载插入运算符"<<"，本例给予改进。
#include<iostream>
using namespace std;

template <typename T>struct Node{
	T  key;
	// 其他域省略
};//再次指出分号不可少
template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	Node<T> slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	void BubbleSort();
	bool Insert(Node<T> & elem,int i);
	void print();
	// 无关成员函数省略
};//再次指出分号不可少
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
	for (i=0;i<last;i++){//最多做n-1趟
		noswap=true;	//未交换标志为真
		for(j=last;j>i;j--){//从下往上冒泡
			if(slist[j].key<slist[j-1].key){
				temp=slist[j];
				slist[j]=slist[j-1];
				slist[j-1]=temp;
				noswap=false;
			}			
		}
		if(noswap) break;	//本趟无交换，则终止算法。
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
	mystring(char *s){//本例为了简化，健壮性并不好
		last=-1;
		maxsize=20;
		do{
			last++;
			str[last]=s[last];
		}while(s[last]!='\0');
	}
	~mystring(){}
    friend ostream & operator<<(ostream & ,const mystring &);//流类作为形式参数必须是引用
	bool operator<(mystring &);
	mystring & operator=(char * ms);
};
bool mystring::operator<(mystring & ms){//重载<运算符
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
	Node<mystring> n[h];//定义结点数组
	for(i=0;i<h;i++)  n[i].key=mslist[i];// 结点数组赋值
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //建立顺序表
	cout<<"未排序表："<<endl;
	ordlist.print();
	ordlist.BubbleSort();
	cout<<"已排序表："<<endl;
	ordlist.print();
	return 0;
}
