//【例3.8】设计函数完成两数交换，并用主函数进行测试，看是否成功。
#include<iostream>
using namespace std;

void swap(int,int);	
int main(){
	int a,b;						      //main()中定义的a,b，作用域为main()
	cout<<"输入两整数："<<endl;
	cin>>a>>b;
	cout<<"调用前：实参a="<<a<<','<<"b="<<b<<endl;
	swap(a,b);
	cout<<"调用后：实参a="<<a<<','<<"b="<<b<<endl; //发现交换失败
	return 0;
}	
void swap(int a,int b){				     //swap()中定义的a,b，作用域为swap()
	cout<<"调用中…"<<endl;
	cout<<"交换前：形参a="<<a<<','<<"b="<<b<<endl;
	int t;
	t=a; a=b; b=t;						 //交换a,b的值
	cout<<"交换后：形参a="<<a<<','<<"b="<<b<<endl;
}								
