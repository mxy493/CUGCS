//【例6.9】直接选择排序，作为Orderedlist<T,size>类的成员函数。
#include<iostream>
#include<string>
using namespace std;

template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	T slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	void SelectSort();
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
template <typename T,int size> void Orderedlist<T,size>::SelectSort(){
	int i,j,k;
	T temp;
	for(i=0;i<last;i++){
		k=i;
		temp=slist[i];
		for(j=i;j<=last;j++)
			if(slist[j]<temp){
				k=j;
				temp=slist[j];
			}
		if(k!=i){
			temp=slist[i];
			slist[i]=slist[k];
			slist[k]=temp;
		}
	}
}
class  student{
	int   id ;           //学号
	string name;         // 姓名
	char  sex;          // 性别
	int   age;          // 年龄
	string  address;      //家庭地址
	float  eng, phy, math, electron;     //英语，物理，数学和电子学成绩
public:
	student(){}
	student(int,string,char,int,string,float,float,float,float);
	bool operator<(student ele){return id<ele.id;}
	void show(){cout<<id<<'\t'<<name<<'\t'<<sex<<'\t'<<age<<'\t'
		<<eng<<'\t'<<phy<<'\t'<<math<<'\t'<<electron<<endl;}
};
student::student(int i,string n,char s,int a,string add,float en,float ph,float ma,float ele){
	id=i;           //学号
	name=n;         // 姓名
	sex=s;          // 性别
	age=a;          // 年龄
	address=add;      //家庭地址
	eng=en; phy=ph; math=ma, electron=ele;     //英语，物理，数学和电子学成绩

}

int main(){
	const int h=4;
	int i;
	Orderedlist<student,100> ordlist;
	student n[h]={student(6004327,"张菲",'m',19,"北京路58号",80,85,90,78),
		student(6004121,"关雨",'w',19,"天津路64号",88,75,91,68),
		student(6004118,"刘蓓",'w',18,"上海路37号",78,95,81,88),
		student(6004219,"赵昀",'m',18,"重庆路95号",78,95,81,88),
	};
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //建立顺序表
	cout<<"未排序表："<<endl;
	ordlist.print();
	ordlist.SelectSort();
	cout<<"已排序表："<<endl;
	ordlist.print();
	return 0;
}


