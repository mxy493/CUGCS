//【例8.3】在采用虚基类的多重继承中，构造与析构的次序。
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
	Dclass():object(),Bclass2(),Bclass3(),Bclass1(){cout<<"派生类建立!\n";}
	~Dclass(){cout<<"派生类析构!\n";}
};

int main(){
	Dclass dd;
	cout<<"主程序运行!\n";
	return 0;
}
