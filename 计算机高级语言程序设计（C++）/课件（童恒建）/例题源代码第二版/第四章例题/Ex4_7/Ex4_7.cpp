//【例4.7】演示对象创建和撤消的对应关系。
#include<iostream>
using namespace std;

class complex{
  private:                                 
    double real, image;                         
  public:
    complex(){  //缺省的构造函数
		real=0.0;
		image=0.0;
		cout<<"Initializing  0   0"<<endl;
	}
	complex(double r,double i=0.0){  //带参数的构造函数
		real=r;
		image=i;
		cout<<"Initializing"<<r<<'\t'<<i<<endl;
	}
	complex(complex &com);  //拷贝的构造函数声明
	~complex(){    //析构函数
		cout <<"Destructor"<<endl;
	}
	void assign(complex com){ 
		real=com.real; //先建立临时对象com
		image=com.image;
	}
    void print(){
		cout<<real<<'+'<<image<<'i'<<endl;
	}
};
inline complex::complex(complex &com){ //拷贝的构造函数说明
	cout<<"Copy"<<com.real<<'\t'<<com.image<<endl;
	real=com.real;
	image=com.image;
}

complex fun(complex);
complex global;//全局对象首先建立 (thj: 构造1 )

int main(){
	cout <<"Entering main"<< endl;
	complex com1, com2(5.6, 7.5); // thj: 构造2; thj: 构造3
	complex com3=com1; // thj: 构造4;
	com3.print();
	global.print();
	com1=fun(com2); // thj: 析构6; // thj: 析构5;
	com1.print();
	cout<<"Exiting main"<<endl;
	return 0;  // thj: 析构4; // thj: 析构3; // thj: 析构2; // thj: 析构1;
}
complex fun(complex com){ //  thj: 构造5;
	cout<<"Entering function"<<endl;
	global.assign(com); // thj: 构造6;  // thj: 析构6;
	cout<<"Exiting function"<<endl;
return global; // thj: 构造7;  // thj: 析构7; //  thj: 析构5;
}
