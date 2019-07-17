//【例5.2】字符数组与字符数组相连接。
#include <iostream>
using namespace std;

void strcat(char s[],char ct[]){
	int i=0,j=0;
	while (s[i]!=0) i++;
	while (ct[j]!=0)  s[i++]=ct[j++];
	s[i]='\0';
}
int main (void){
	char a[40]="李明";
	char b[20]="是东南大学学生";
	cout<<a<<endl;
	cout<<b<<endl;
	strcat(a,b);
	cout<<"字符串连接后："<<endl;
	cout<<a<<endl;                  //打印字符数组a
	return 0;
}
