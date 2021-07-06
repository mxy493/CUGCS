//【例9.4】ignore()和gcount()函数使用。
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char str[255];
	int i,n;
	cout<<"输入字符"<<endl;        //输入^Z,一旦输入^Z全部结束，不能输入其它字符
	i=cin.get();
	cout<<endl;
	n=cin.rdstate();                         //读取状态字
	cout<<"状态字为："<<n<<endl;             //状态字为1,流结束
	cout<<"当输入字符时,取得的是:"<<i<<endl; //-1,输入^Z时,返回EOF,即-1
	if(n==0) cin.ignore(255,'\n');           //清除多余的字符和回车符
	cin.clear(0);                            // A    使流恢复正常
	cout<<"输入字符串1:"<<endl;
	cin.getline(str,255);
	cout<<endl;
	cout<<"状态字为："<<cin.rdstate()<<endl;
	i=cin.gcount();
	cout<<"字符串为:"<<str<<'\t'<<"读入字符数为:"<<i<<'\t';
	cout<<"串长为:"<<strlen(str)<<endl;
	cin.clear(0);                            // A    使流恢复正常
	cout<<"输入字符串2:"<<endl;
	cin.getline(str,255);
	cout<<endl;
	cout<<"状态字为："<<cin.rdstate()<<endl;
	i=cin.gcount();
	cout<<"字符串为:"<<str<<'\t'<<"读入字符数为:"<<i<<'\t';
	cout<<"串长为:"<<strlen(str)<<endl;
	return 0;
}
