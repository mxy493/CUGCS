//����8.3���ڲ��������Ķ��ؼ̳��У������������Ĵ���
#include<iostream>
using namespace std;

class Object{
public:
	Object(){cout<<"constructor Object\n";}
	~Object(){cout<<"deconstructor Object\n";}
};
class Bclass1{
public:
	Bclass1(){cout<<"constructor Bclass1\n";}
	~Bclass1(){cout<<"deconstructor Bclass1\n";}
};
class Bclass2{
public:
	Bclass2(){cout<<"constructor Bclass2\n";}
	~Bclass2(){cout<<"deconstructor Bclass2\n";}
};
class Bclass3{
public:
	Bclass3(){cout<<"constructor Bclass3\n";}
	~Bclass3(){cout<<"deconstructor Bclass3\n";}
};
class Dclass:public Bclass1,virtual Bclass3,virtual Bclass2{
	Object object;
public:
	Dclass():object(),Bclass2(),Bclass3(),Bclass1(){cout<<"�����ཨ��!\n";}
	~Dclass(){cout<<"����������!\n";}
};

int main(){
	Dclass dd;
	cout<<"����������!\n";
	return 0;
}
