//【例9.8】按行复制文本文件。
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	char filename[256],buf[100];
	fstream sfile,dfile;
	cout<<"输入源文件路径名:"<<endl;
	cin>>filename;//对路径各方面而言空格是无关紧要的,否则要用getline()等成员函数
	sfile.open(filename,ios::in);//打开一个已存在的文件
	while(!sfile){
		cout<<"源文件找不到,请重新输入路径名:"<<endl;
		sfile.clear(0);//清状态字
		cin>>filename;
		sfile.open(filename,ios::in);
	}
	cout<<"输入目标文件路径名:"<<endl;
	cin>>filename; //只能创建文件，不能建立子目录，如路径不存在则失败
	dfile.open(filename,ios::out);
	if(!dfile){
		cout<<"目标文件创建失败"<<endl;
		return -1;
	}
	while(sfile.getline(buf,100)){//按行拷贝  A行
		if(sfile.gcount()<100) dfile<<buf<<'\n';//因回车符未送到  B行
		else dfile<<buf;//本行大于99个字符,还未读到回车换行符,所以不加'\n'
	} 
	sfile.close();
	dfile.close();
	return 0;
}
