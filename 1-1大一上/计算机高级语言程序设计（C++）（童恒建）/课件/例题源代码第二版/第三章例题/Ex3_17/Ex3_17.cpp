//����3.17��ȱʡ������
#include<iostream>
using namespace std;
void delay(int loops=1000){		//��ʱ����,Ĭ����ʱ1000��ʱ�䵥λ
	for (; loops>0; loops--); 
}
int main(){
	delay(100);
	cout<<"��ʱ100��ʱ�䵥λ"<<endl;
	delay();							//��ͬ��delay(1000)
	cout<<"��ʱ1000��ʱ�䵥λ"<<endl;
	return 0;
}
