//【例3.7】 输入两数，将两数按从大到小的顺序保存，并输出结果。

#include<iostream>
using namespace std;

int main(){
	int a,b;					//函数内定义局部变量，具有函数域
	cout<<"输入两整数："<<endl;
	cin>>a>>b;
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
	if(b>=a){					//使a中保存大数，b中保存小数
		int t;						//块中定义局部变量，具有块作用域
		t=a; a=b; b=t;				//交换a,b的值
	}
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
	return 0;
}
