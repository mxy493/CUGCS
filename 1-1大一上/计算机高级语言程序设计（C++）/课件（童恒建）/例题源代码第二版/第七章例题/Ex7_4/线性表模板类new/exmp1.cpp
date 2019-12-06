#include<iostream>

#include"tmp.h"
#include<string>
using namespace std;
class Student{
	string name;
//	int eng,math,c;
//	double ave;
public:
	Student(string n=0){
		name=n;
	}
	Student(Student &s){
		name=s.name;
	}
	int operator>(Student s){return name>s.name;}
	int operator<(Student s){return name<s.name;}
	int operator==(Student s){return name==s.name;}
	void print(){cout<<name<<endl;}
	void Input(){
		cout<<"input student data"<<endl;
		cin>>name;
	}
};


void main(){
	seqlist<int> list1,list2;
	cout<<"input data to create a list"<<endl;
	for(int i=0;i<5;i++){
		int x;
		cin>>x;
		list1.Insert(x,i);
		list2.Insert(x);
	}
	list1.print();
	list2.print();
	seqlist<int> list3(list1);
	list3.print();
}
