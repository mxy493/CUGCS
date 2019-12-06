//【例9.7】复制文件。
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	char ch;
	ifstream sfile("d:\\Ex9_6\\Ex9_6.cpp");
	ofstream dfile("e:\\Ex9_6.cpp");  //只能创建文件，不能建立子目录，如路径不存在则失败
	if(!sfile){
		cout<<"不能打开源文件:"<<"d:\\Ex9_6\\Ex9_6.cpp"<<endl;
		return -1;
	}
	if(!dfile){
		cout<<"不能打开目标文件:"<<"e:\\Ex9_6.cpp"<<endl;
		return -1;
	}
	sfile.unsetf(ios::skipws);      //关键!把跳过空格控制位置0,即不跳过空格,否则空格全部未拷贝
	while(sfile>>ch)dfile<<ch;
	sfile.close();                  //如没有这两个关闭函数,析构函数也可关闭
	dfile.close();
	return 0;
}
