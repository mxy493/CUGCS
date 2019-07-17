//【例9.12】字符流
#include<strstream>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int i;
	char str[36]="This is a book.";
	char ch;
	istrstream input(str,36);          //以串流为信息源
	ostrstream output(str,36);
	cout<<"字符串长度："<<strlen(str)<<endl;
	for(i=0;i<36;i++){
		input>>ch;             //从输入设备(串)读入一个字符,所有空白字符全跳过
		cout<<ch;                     //输出字符
	}
	cout<<endl;
	int inum1=93,inum2;
	double fnum1=89.5,fnum2;
	output<<inum1<<' '<<fnum1<<'\0';  //加空格分隔数字
	cout<<"字符串长度："<<strlen(str)<<endl;
	istrstream input1(str,0);      //第二参数为0时,表示连接到以串结束符终结的串
	input1>>inum2>>fnum2;
	cout<<"整数："<<inum2<<'\t'<<"浮点数："<<fnum2<<endl; //输出：整数：93 浮点数：89.5
	cout<<"字符串长度："<<strlen(str)<<endl;
	return 0;
}
