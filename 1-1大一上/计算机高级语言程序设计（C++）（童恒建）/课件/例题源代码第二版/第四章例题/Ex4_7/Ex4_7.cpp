//����4.7����ʾ���󴴽��ͳ����Ķ�Ӧ��ϵ��
#include<iostream>
using namespace std;

class complex{
  private:                                 
    double real, image;                         
  public:
    complex(){  //ȱʡ�Ĺ��캯��
		real=0.0;
		image=0.0;
		cout<<"Initializing  0   0"<<endl;
	}
	complex(double r,double i=0.0){  //�������Ĺ��캯��
		real=r;
		image=i;
		cout<<"Initializing"<<r<<'\t'<<i<<endl;
	}
	complex(complex &com);  //�����Ĺ��캯������
	~complex(){    //��������
		cout <<"Destructor"<<endl;
	}
	void assign(complex com){ 
		real=com.real; //�Ƚ�����ʱ����com
		image=com.image;
	}
    void print(){
		cout<<real<<'+'<<image<<'i'<<endl;
	}
};
inline complex::complex(complex &com){ //�����Ĺ��캯��˵��
	cout<<"Copy"<<com.real<<'\t'<<com.image<<endl;
	real=com.real;
	image=com.image;
}

complex fun(complex);
complex global;//ȫ�ֶ������Ƚ��� (thj: ����1 )

int main(){
	cout <<"Entering main"<< endl;
	complex com1, com2(5.6, 7.5); // thj: ����2; thj: ����3
	complex com3=com1; // thj: ����4;
	com3.print();
	global.print();
	com1=fun(com2); // thj: ����6; // thj: ����5;
	com1.print();
	cout<<"Exiting main"<<endl;
	return 0;  // thj: ����4; // thj: ����3; // thj: ����2; // thj: ����1;
}
complex fun(complex com){ //  thj: ����5;
	cout<<"Entering function"<<endl;
	global.assign(com); // thj: ����6;  // thj: ����6;
	cout<<"Exiting function"<<endl;
return global; // thj: ����7;  // thj: ����7; //  thj: ����5;
}
