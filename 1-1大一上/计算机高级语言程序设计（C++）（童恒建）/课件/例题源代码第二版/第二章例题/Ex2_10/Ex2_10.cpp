//����2.10�����һ������������ʵ�ּӡ������ˡ������㡣

#include <iostream>
using namespace std;

int main(){
	float num1,num2;
	char op;
	for(int i=0;i<2;i++){
	cout<<"���������1���������������2��"<<endl;
	cin>>num1>>op>>num2;
	switch(op){
	  case '+':  cout<<num1<<op<<num2<<"="<<num1+num2<<endl; break;
	  case '-':  cout<<num1<<op<<num2<<"="<<num1-num2<<endl; break;
	  case '*':  cout<<num1<<op<<num2<<"="<<num1*num2<<endl; break;
	  case '/':  cout<<num1<<op<<num2<<"="<<num1/num2<<endl; break;
	  default :  cout<<op<<"����Ч�����!";
	}
	cout<<endl;
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
