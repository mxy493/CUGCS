//����3.5�� �������ʹ��ȫ�ֱ��������ӡ�
#include<iostream>
using namespace std; 
int n=100;

void func(){
	 n*=2;
}
int main(){
	n*=2;
	cout<<n<<endl;
	func();
	cout<<n<<endl;
	return 0;
}
