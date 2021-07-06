//����7.9��ģ��򵥼��������ü�����ֻ��+��-��*��/ �ĸ������������Ϊ������
//���ʽ������ʹ��=�ţ����ջ��'c'�ַ���ʹ��'z'�ַ���ʾ���������
#include<iostream>
#include<cmath>
#include<cstdlib>
#include"Ex7_9.h"  //��ջģ�嶨���ļ�
using namespace std;
class Calculator{                                 //���׼�������
	Stack<int> Nstack;
	Stack<char> Ostack;
public:
	Calculator(void){};
	void Cal(void);                               //�������������
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
		case '+':Nstack.Push(Num2+Num1);break;  //���ѹջ
		case '-':Nstack.Push(Num2-Num1);break;
		case '*':Nstack.Push(Num2*Num1);break;
		case '/':Nstack.Push(Num2/Num1);break;
		case '=':cout<<Nstack.Pop()<<endl;           //������		
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
			str[k]=ch1;                           //�����ַ����봮��
		}
		else{
			if(k>=0){
				str[k+1]='\0';                       //���ִ�����
				Nstack.Push(atoi(str));				//���ִ�ת��Ϊ������ѹջ
				k=-1;
			}
			switch(ch1){
			case 'c':
				Clear();
				break;
			case '+':
			case '-':
				while(!Ostack.IsEmpty()){
					ch2=Ostack.Pop();   //�����б�'��' '��'���ȼ��͵�
					Compute(ch2);
				}
				Ostack.Push(ch1);
				break;
			case '*':
			case '/':
				while(!Ostack.IsEmpty()&&b1){
					ch2=Ostack.Pop();            //��ջ�����������
					if(ch2=='*'||ch2=='/')        //�Ƚ����ȼ�
						Compute(ch2);            //�µ����ȼ�������
					else{ 						  //�µ����ȼ���
						Ostack.Push(ch2);         //�Ȱ�ԭջ�е������ѹ��ȥ
						b1=false;
					}
				}
				Ostack.Push(ch1);             //�ٰ��µ������ѹջ
				b1=true;           //�˾䱣֤�˳������ҽ���
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
	cout<<"��������������ʽ��"<<endl;
	Calcul.Cal();
	return 0;
}
