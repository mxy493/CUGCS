/*����3.14������һ���������õݹ���㷨ʵ�ֽ��������������
�������ڵݹ���̵ĵ��Ʋ��������������㽫�����ĸ���λ���룬����ӡ������*/
#include<iostream>
using namespace std;

void backward(int);
int main(){
	int n;
	cout<<"����������"<<endl;
	cin>>n;
	cout<<"ԭ������"<<n<<endl;
	cout<<"��������";
	backward(n);
	cout<<endl;
	return 0;
}
void backward(int n){
	cout<<n%10;
	if(n<10) return; 
	else backward(n/10);
}
