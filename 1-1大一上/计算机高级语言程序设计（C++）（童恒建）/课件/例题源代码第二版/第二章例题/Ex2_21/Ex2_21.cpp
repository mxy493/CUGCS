/*����2.21����ŷ������㷨��Ҳ��շת�������������������Լ����
�ٶ����������ֱ�Ϊnum1��num2�����Լ��Ӧ���ǲ��������н�С����һ��������
շת����˼���ǣ���num1����num2���������resd�����resd==0����ǰnum2�������Լ����
����resd!=0����num1=num2, num2=resd, �ظ����Ϲ��̣�ֱ��resd==0Ϊֹ��
*/
#include<iostream>
using namespace std;

int main(){
	 int num1,num2,resd;
	 cout<<"��������������"<<endl;
	 cin>>num1>>num2;
	 cout<<num1<<"��"<<num2<<"�����Լ��Ϊ��";
	 for(;;){
		resd=num1%num2;
		if(resd==0)  break;
		num1=num2;  num2=resd;
	 }
	 cout<<num2<<endl;
	 return 0;
}
