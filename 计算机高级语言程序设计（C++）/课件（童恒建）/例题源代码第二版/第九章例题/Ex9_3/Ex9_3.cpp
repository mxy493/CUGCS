//【例9.3】提高输入的健壮性。输入时需要故意输错，以测试健壮性。
#include<iostream>
using namespace std;
int main(){
	char str[256];
	int i;
	cout<<"请输入整数:"<<endl;//强制清空缓冲区,保证输出,不会等缓冲区溢出再输出
	cin>>i;//可故意输入若干非数字字符,下次再输入若干字符加数字串加若干非数字字符进行检测
	while(cin.fail()){
		cout<<"状态字为："<<cin.rdstate()<<endl;
		cin.clear(0);
		cin.getline(str,255);//读空缓冲区
		cout<<"输入错误,请重新输入整数"<<endl;
		cin>>i;
	}
	cin.getline(str,256);//读空缓冲区
	cout<<"请输入字符串"<<endl;
	cin.getline(str,255);//B行
	cout<<"输入整数为:"<<i<<endl;
	cout<<"输入字符串为:"<<str<<endl;
	return 0;
}
