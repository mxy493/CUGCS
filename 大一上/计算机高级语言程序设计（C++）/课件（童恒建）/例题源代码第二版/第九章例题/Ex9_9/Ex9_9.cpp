//【例9.9】文本式数据文件的创建与读取数据。
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class inventory{
	string Description;
	string No;
	int Quantity;
	double Cost;
	double Retail;
public:
	inventory(string="#",string="0",int=0,double=0,double=0);
	friend ostream&operator<<(ostream&dist,inventory&iv);//重载插入运算符
	friend istream&operator>>(istream&sour,inventory&iv);//重载提取运算符
};     //流类作为形式参数必须是引用
inventory::inventory(string des,string no,int quan,double cost,double ret){
	Description=des;
	No=no;
	Quantity=quan;
	Cost=cost;
	Retail=ret;
}
ostream &operator<<(ostream&dist,inventory&iv){
	dist<<left<<setw(20)<<iv.Description<<setw(10)<<iv.No;
	dist<<right<<setw(10)<<iv.Quantity<<setw(10)<<iv.Cost<<setw(10)<<iv.Retail<<endl;
	return dist;
}//写入文件是自动把数转为数字串后写入
istream&operator>>(istream&sour,inventory&iv){
	sour>>iv.Description>>iv.No>>iv.Quantity>>iv.Cost>>iv.Retail;
	return sour;
}//从文件读出是自动把数字串转为数读出,函数体内>>功能不变
int main(){
	inventory car1("夏利2000","805637928",156,80000,105000),car2;
	inventory motor1("金城125","93612575",302,10000,13000),motor2;
	ofstream distfile("d:\\Ex9_9.data");
	distfile<<car1<<motor1;//注意ofstream是ostream的派生类
	distfile.close();
	cout<<car1;
	cout<<motor1;
	cout<<car2;
	cout<<motor2;
	ifstream sourfile("d:\\Ex9_9.data");//这样分两次打开,可避免读文件时,误改了源文件
	sourfile>>car2>>motor2;
	sourfile.close();
	cout<<car2;
	cout<<motor2;
	return 0;
}
