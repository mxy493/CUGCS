//【例11.7】整型多重集合关联容器类的演示。 
#include<iostream>
#include<set>						        //包含集合头文件
#include<algorithm>					        //包含算法头文件
using namespace std;                        //C++标准库名字空间域
typedef multiset<int> INTMS;        //特例取名INTMS，整型多重集合按升序排列

int main(){
	const int size=16;
	int a[size]={17,11,29,89,73,53,61,37,41,29,3,47,31,59,5,2};
	INTMS intMultiset(a,a+size);				//用a来初始化INTMS容器实例
	ostream_iterator<int> output(cout," ");
		              //整型输出迭代子output，可通过cout输出一个用空格分隔的整数
	cout<<"这里原来有"<<intMultiset.count(17)<<"个数值17"<<endl;//查找有几个关键字17
	intMultiset.insert(17);                                    //插入一个重复的数17
	cout<<"输入后这里有"<<intMultiset.count(17)<<"个数值17"<<endl;
	INTMS::const_iterator result;	//const_iterator使程序可以读取INTMS的元素，
	                        //但不让程序修改它的元素，result为INTMS的迭代子
	result=intMultiset.find(18);//找到则返回所在位置，设找到返回与调end()返回的同样值
	if(result==intMultiset.end()) cout<<"没找到值18"<<endl;
	else cout<<"找到值18"<<endl;
	cout<<"intMultiset容器中有"<<endl;
	copy(intMultiset.begin(),intMultiset.end(),output);        //输出容器中全部元素
	cout<<endl;
	return 0;
}