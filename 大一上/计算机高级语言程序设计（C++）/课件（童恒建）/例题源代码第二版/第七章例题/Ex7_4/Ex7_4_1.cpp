#include <iostream>
#include <cstring>
using namespace std;
class student{
	char *pName;        
public:
	student(char *pname=0);
	student(student &s);
	~student();
};
student::student(char *pname){
	if(pname){
		if(pName=new char[strlen(pname)+1])	strcpy(pName,pname);
	}
	else pName=0;
}
student::student(student &s){
	if(s.pName){
		if(pName=new char[strlen(s.pName)+1]) strcpy(pName,s.pName);
		cout<<pName<<endl;
	}
	else pName=NULL;
}

student::~student(){     
	if(pName) delete []pName;
}

int main(void){
	student s1("·¶Ó¢Ã÷"),s2("Éò¿¡"),s3(s1);
	return 0;
}
