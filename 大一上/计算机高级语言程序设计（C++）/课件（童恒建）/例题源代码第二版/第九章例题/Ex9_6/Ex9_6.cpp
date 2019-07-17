//【例9.6】用户定义的复数类型Complex的输入与输出。
#include<iostream>
using namespace std;

class Complex{
	double Real,Image;
public:
	Complex(double r=0.0, double i=0.0):Real(r),Image(i){}//定义构造函数
	//见【例4.7】,这里省略,以节约篇幅
	friend ostream&operator<<(ostream&s,const Complex&z);
	friend istream&operator>>(istream&s,Complex&a);
};
ostream&operator<<(ostream&s,const Complex &z){     //流类作为形式参数必须是引用
	return s<<'('<<z.Real<<','<<z.Image<<')';
}
istream&operator>>(istream&s,Complex &a){//格式为d,(d),(d,d)
	double re=0,im=0;
	char c=0;
	s>>c;//是否由括号开始
	if(c=='('){
		s>>re>>c;//实部
		if(c==',')s>>im>>c;//虚部
		if(c!=')')s.clear(ios::failbit);//漏了括号给一个操作失败标志
	}
	else{
		s.putback(c);//无括号，返回一个字符到输入缓冲区
		s>>re;//实数
	}
	if(s)a=Complex(re,im);
	return s;
}
int main(){
	Complex a,b,c;
	cout<<"输入一个实数"<<endl;
	cin>>a;
	cout<<"输入一个用括号括起来的实数"<<endl;
	cin>>b;
	cout<<"输入一个用括号括起来复数"<<endl;
	cin>>c;
	cout<<"a="<<a<<'\t'<<"b="<<b<<'\t'<< "c="<<c<<'\n';
	return 0;
}
