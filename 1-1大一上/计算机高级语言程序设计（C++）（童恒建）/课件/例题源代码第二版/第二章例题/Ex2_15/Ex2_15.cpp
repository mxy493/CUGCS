//����2.15������һ��������9λ�������������䷴����������������247�����742�����

#include <iostream>
using namespace std;
int main(){
	int i,num,subscript;
	int digit[9];
	cout<<"����һ��������9λ����������"<<endl;
	cin>>num;
	cout<<"ԭ������Ϊ��"<<num<<endl;
	subscript=0;						//�����±��ֵ
	do{
		digit[subscript]=num%10;
		num=num/10;
		subscript++;					//�޸��±�
	} while (num>0);
	for(i=0;i<subscript;i++)		//�����ķ������
		num=num*10+digit[i];
	cout<<"���������Ϊ��"<<num<<endl;
	return 0;
}
