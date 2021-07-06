//【例2.4】输入一个年份，判断是否为闰年。

#include <iostream>
using namespace std;

int main( ){
	int year;
	for(int i=0;i<4;i++){
	cout<<"输入年份:"<<endl;
	cin>>year;
	if (year%4==0&&year%100!=0||year%400==0)
		cout<<year<<"是闰年"<<endl;
	else  cout<< year<<"年不是闰年"<<endl;
	cout<<endl;
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
