//【例7.9】模拟简单计算器，该计算器只认+、-、*、/ 四个运算符，输入为整数。
//表达式结束符使用=号，清空栈用'c'字符。使用'z'字符表示程序结束。
#include<iostream>
#include<cmath>
#include<cstdlib>
#include"Ex7_9.h"  //链栈模板定义文件
using namespace std;
class Calculator{                                 //简易计算器类
	Stack<int> Nstack;
	Stack<char> Ostack;
public:
	Calculator(void){};
	void Cal(void);                               //计算器运算程序
	void GetTwoNum(int &Num1,int &Num2);
	void Compute(char Opr);
	void Clear(void);
};
void Calculator::Clear(){
	Nstack.MakeEmpty();
	Ostack.MakeEmpty();
}
void Calculator::GetTwoNum(int &Num1,int &Num2){
	Num1=Nstack.Pop();
	Num2=Nstack.Pop();
}
void Calculator::Compute(char Opr){
	int Num1,Num2;
	if(Opr!='=') GetTwoNum(Num1,Num2);
	switch(Opr){
		case '+':Nstack.Push(Num2+Num1);break;  //结果压栈
		case '-':Nstack.Push(Num2-Num1);break;
		case '*':Nstack.Push(Num2*Num1);break;
		case '/':Nstack.Push(Num2/Num1);break;
		case '=':cout<<Nstack.Pop()<<endl;           //输出结果		
	}
}
void Calculator::Cal(){
	bool b1=true,b2=true;
	char ch1,ch2,str[50];
	int k=-1;
	while(b2){
		cin>>ch1;
		if(ch1>='0'&&ch1<='9'){
			k++;
			str[k]=ch1;                           //数字字符添入串中
		}
		else{
			if(k>=0){
				str[k+1]='\0';                       //数字串生成
				Nstack.Push(atoi(str));				//数字串转换为整数后压栈
				k=-1;
			}
			switch(ch1){
			case 'c':
				Clear();
				break;
			case '+':
			case '-':
				while(!Ostack.IsEmpty()){
					ch2=Ostack.Pop();   //不会有比'＋' '－'优先级低的
					Compute(ch2);
				}
				Ostack.Push(ch1);
				break;
			case '*':
			case '/':
				while(!Ostack.IsEmpty()&&b1){
					ch2=Ostack.Pop();            //把栈顶运算符弹出
					if(ch2=='*'||ch2=='/')        //比较优先级
						Compute(ch2);            //新的优先级并不高
					else{ 						  //新的优先级高
						Ostack.Push(ch2);         //先把原栈中的运算符压回去
						b1=false;
					}
				}
				Ostack.Push(ch1);             //再把新的运算符压栈
				b1=true;           //此句保证乘除从左倒右进行
				break;
			case '=':
				while(!Ostack.IsEmpty()){
					ch2=Ostack.Pop();
					Compute(ch2);
				}
				Compute(ch1);
				break;
			}
			if(ch1=='z') b2=false;
		}
	}
}
int main(){
	Calculator Calcul;
	cout<<"请输入四则运算式："<<endl;
	Calcul.Cal();
	return 0;
}
