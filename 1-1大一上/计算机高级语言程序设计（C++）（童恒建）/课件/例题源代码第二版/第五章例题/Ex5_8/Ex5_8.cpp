//����5.8��ָ����������ص�����:
#include <iostream>
using namespace std;

int main(){
	int i,fibon[10]={0,1,1,2,3,5,8,13,21,34},*pfib1,*pfib2;
	pfib1=pfib2=fibon;                         //Ҳ������pfib1=pfib2=&fibon[0]
	cout<<"ʹ��������ʾ쳲���������"<<endl;
	for(i=0;i<10;i++)
		cout<<fibon[i]<<'\t'<<pfib1[i]<<endl;
	cout<<"ʹ��ָ����ʾ쳲���������"<<endl;
	for(i=0;i<10;i++)
		cout<<*(fibon+i)<<'\t'<<*pfib2++<<endl;   //ע�⣺fibon++�Ǵ���ģ���pfib2++����ȷ��
	cout<<"��ʾָ�����,ӦΪ���鳤��:";
	cout<<pfib2-pfib1<<endl;                  //pfib2��ָ������ĩβ
	return 0;
}
