//����3.6�� ʹ�þֲ����������ӡ�
#include<iostream>
using namespace std;

void fun(){
	auto int t=5;					// fun()�еľֲ�������auto��ʡ��
	cout<<"fun()�е�t="<<t<<endl;
}
int main(){
	float t=3.5;					//main()�����еľֲ�����
	cout<<"main()�е�t="<<t<<endl;
	fun();
	cout<<"main()�е�t="<<t<<endl;
	return 0;
}
