//【例9.13】将商店的货物，定义为一个货物数组类。数组对象动态建立，初始为2个元素，
//不够用时扩充一倍。用文本数据文件建立数组元素对象，要求放在构造函数中，而数据的
//保存和文件的关闭放在析构函数中。第一次运行时，建立空的数据文件，由键盘输入建立
//数组元素对象，并写入文件，程序退出时，关闭文件；下一次运行由该文件构造对象，恢
//复前一次做过的工作。
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class inventory{
	string Description;//商品名称
	string No;//货号
	int Quantity;//数量
	double Cost;//价格
	double Retail;//零售
public:
	inventory(string ="#",string="#",int =0,double =0,double =0);
	friend ostream&operator<<(ostream&dist,inventory&iv);//重载插入运算符
	friend istream&operator>>(istream&sour,inventory&iv);//重载提取运算符
	bool operator==(inventory &);//货号为关键字
	bool operator<=(inventory &);
};
inventory::inventory(string des,string no,int quan,double cost,double ret){
	Description=des;
	No=no;
	Quantity=quan;
	Cost=cost;
	Retail=ret;
}
ostream &operator<<(ostream&dist,inventory&iv){
	dist<<left<<setw(20)<<iv.Description<<setw(10)<<iv.No;
	dist<<right<<setw(10)<<iv.Quantity<<setw(10)<<iv.Cost<<setw(10)<<iv.Retail<<endl;
	return dist;
}
istream&operator>>(istream&sour,inventory&iv){     //文件流类作为形式参数必须是引用
	if(sour==cin){
		cout<<"请输入货物名称："<<endl;
		sour>>iv.Description;
		cout<<"请输入货号："<<endl;
		sour>>iv.No;
		cout<<"请输入货物数量："<<endl;
		sour>>iv.Quantity;
		cout<<"请输入货物价格："<<endl;
		sour>>iv.Cost;
		cout<<"请输入货物零售价格："<<endl;
		sour>>iv.Retail;
	}
	else sour>>iv.Description>>iv.No>>iv.Quantity>>iv.Cost>>iv.Retail;
	return sour;
}
bool inventory::operator==(inventory & inven){
	return No==inven.No;
}
bool inventory::operator<=(inventory & inven){//为按货号排序重载关系运算符
	return No<=inven.No;
}
template <typename T>class Array{
	T *elements;
	int Subscript;           //已用最大下标值
	int maxSize;
	fstream datafile;
public:
	Array(int=2);           //为了便于检验,缺省元素数暂为2
	~Array();
	bool IsFull() const{return Subscript==maxSize-1;}
	void renews();         //内存扩大一倍
	void show(){
		cout<<"已用最大下标值"<<Subscript<<'\t'<<"可用元素数"<<maxSize<<endl;
	}
	void ordinsert(T&);    //输入时以货号为关键字排序
	friend ostream&operator<<(ostream&dist,Array&ar);//重载插入运算符
};
template <typename T> Array<T>::Array(int maxs){
	maxSize=maxs;
	Subscript=-1;//私有数据不容许直接赋初值,必须在构造函数中赋初值
	T temp;
	elements=new T[maxSize];
	datafile.open("mydatafile.txt",ios::in);          //如文件不存在，打开失败
	if(!datafile==0){
		while(!datafile.eof()){
			datafile>>temp;
			if(datafile.eof()==0){//读到无数据可读后,即读入不成功,eofbit为1
				ordinsert(temp);//即使原文件未排序，读出也是排好序的，退出时按排好序的重存
			}
		}
		datafile.close();//必须放此处，打开成功才能关闭
	}
	datafile.clear(0);//采用标准库不可少，前面曾经读到文件结束或文件打开失败，流无法恢复
}
template <typename T> Array<T>::~Array(){
	int i;
	datafile.open("mydatafile.txt",ios::out);
	for(i=0;i<=Subscript;i++) datafile<<elements[i];
	datafile.close();
	delete[]elements;
}
template <typename T> void Array<T>::renews(){
	int i;	
	T *temp=elements;
	maxSize*=2;
	elements=new T[maxSize];
	for(i=0;i<=Subscript;i++) elements[i]=temp[i];
	delete[]temp;
}
template <typename T> void Array<T>::ordinsert(T & elem){//输入时以货号为关键字排序
	int i,j;
	if(IsFull()) renews();
	for(i=0;i<=Subscript;i++) if(elem<=elements[i]) break;
	if(!(elem==elements[i])){
		for(j=Subscript;j>=i;j--) elements[j+1]=elements[j];
		Subscript++;
	}
	elements[i]=elem;
	show();
}
template <typename T> ostream&operator<<(ostream&dist,Array<T>&ar){
	int i;
	for(i=0;i<=ar.Subscript;i++) cout<<ar.elements[i];
	return dist;
}

int main(){
	Array<inventory> mylist;
	inventory temp;
	char ch;
	cout<<"是否输入新商品？Y or N"<<endl;
	cin>>ch;
	while(ch=='Y'||ch=='y'){
		cin.get();//吸收回车
		cin>>temp;
		mylist.ordinsert(temp);		
		cout<<"是否继续输入？Y or N"<<endl;
		cin>>ch;
	}
	cout<<mylist;
	return 0;
}