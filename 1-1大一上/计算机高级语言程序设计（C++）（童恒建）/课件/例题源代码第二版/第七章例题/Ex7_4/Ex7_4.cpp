//【例7.4】类含有动态生成的数据成员，必须自定义析构函数以释放动态分配的内存，自定义
//拷贝构造函数（Copy Structor）和拷贝赋值操作符（Copy Assignment Operator）实现深拷贝。
#include <iostream>
#include <cstring>
using namespace std;
class student{
	char *pName;          //为了演示深拷贝，不用string类
public:
	student();
	student(char *pname);
	student(student &s);
//explicit student(student &s); //thj: student s4=s1; //如果用了关键字explicit：则隐式转换构造函数: 编译不会通过//thj
	~student();
	student & operator=(student &s);
};
student::student(){
	cout<<"Constructor";
	pName=NULL;
	cout<<"缺省"<<endl;
}
student::student(char *pname){
	cout<<"Constructor";
	if(pName=new char[strlen(pname)+1]) strcpy(pName,pname);
	//加一不可少，否则串结束符冲了其他信息，析构会出错！
	cout<<pName<<endl;
}
student::student(student &s){
	cout<<"Copy Constructor";
	if(s.pName){
		if(pName=new char[strlen(s.pName)+1]) strcpy(pName,s.pName);
		cout<<pName<<endl;
	}
	else pName=NULL;
}
student::~student(){     //因有动态生成的类成员，析构函数不可用缺省的析构函数
	cout<<"Destructor";
	if(pName) cout<<pName<<endl;
	delete pName;
}
student & student::operator=(student &s){
	cout<<"Copy Assign operator";
	delete[] pName; 
	if(s.pName){
		if(pName=new char[strlen(s.pName)+1]) strcpy(pName,s.pName);
		cout<<pName<<endl;
	}
	else pName=NULL;
	return *this;
}
int main(void){
	student s1("范英明"),s2("沈俊"),s3;
	student s4=s1; //隐式转换构造函数 //thj
//	student s4(s1);  //thj
	s3=s2;
	return 0;
}
