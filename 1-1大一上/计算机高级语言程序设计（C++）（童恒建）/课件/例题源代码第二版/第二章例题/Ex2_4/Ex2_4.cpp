//����2.4������һ����ݣ��ж��Ƿ�Ϊ���ꡣ

#include <iostream>
using namespace std;

int main( ){
	int year;
	for(int i=0;i<4;i++){
	cout<<"�������:"<<endl;
	cin>>year;
	if (year%4==0&&year%100!=0||year%400==0)
		cout<<year<<"������"<<endl;
	else  cout<< year<<"�겻������"<<endl;
	cout<<endl;
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
