//����3.4�� ���������������������������m��10<m<1000��m��m2��m3��Ϊ��������
#include<iostream>
#include<iomanip>
using namespace std;

bool palindrome(int);						//����ԭ��
int main(){
	int m;
	cout<<setw(10)<<'m'<<setw(20)<<"m*m"<<setw(20)<<"m*m*m"<<endl;
	for(m=11;m<1000;m++)
		if(palindrome(m)&&palindrome(m*m)&&palindrome(m*m*m))
			cout<<setw(10)<<m<<setw(20)<<m*m<<setw(20)<<m*m*m<<endl;
	return 0;
}
bool palindrome(int n){						//�жϻ�����
	int digit[10];
	int m=n,i=0;
	do{
		digit[i]=n%10;					    //����λ���뿪
		n/=10;
		i++;
	}while(n>0);
	for(int j=0;j<i;j++) n=n*10+digit[j];		//����װ��
	return (n==m);
}
