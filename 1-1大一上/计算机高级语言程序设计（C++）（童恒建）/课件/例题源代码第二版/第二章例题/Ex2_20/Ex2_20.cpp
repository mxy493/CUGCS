/*����2.20�� �й��Ŵ���ѧʷ��������"�ټ�����"������һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ��
��Ǯ��ټ����ʼ��̡�ĸ���������Σ�
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int i,j,k;
	cout<<"   ����      ĸ��      С��"<<endl;
	for(i=0;i<=20;i++)
		for(j=0;j<=33;j++){
			k=100-i-j;
			if((5*i+3*j+k/3==100)&&(k%3==0))			//ע��(k%3==0)�ǳ���Ҫ
			cout<<setw(6)<<i<<setw(10)<<j<<setw(10)<<k<<endl;
		}
	return 0;
}

