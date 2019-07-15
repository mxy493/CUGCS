//强调输入输出文件中文件定位指针只有一个，输入输出都是用此定位指针。
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//本例说明只有一个文件定位指针
class inventory{
	string Description;
	string No;
	int Quantity;
	double Cost;
	double Retail;
public:
	inventory(string="#",string="0",int =0,double =0,double =0);
	friend ostream &operator<<(ostream&,inventory&);
	void Bdatatofile(fstream&dist);     //文件流类作为形式参数必须是引用
	void Bdatafromfile(fstream&sour);
};
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
}
void inventory::Bdatatofile(fstream&dist){
	dist.write(Description.c_str(),20); //由string类的c_str()函数转为char*
	dist.write(No.c_str(),10);
	dist.write((char*)&Quantity,sizeof(int));
	dist.write((char*)&Cost,sizeof(double));
	dist.write((char*)&Retail,sizeof(double));
}
void inventory::Bdatafromfile(fstream&sour){
	char k[20];
	sour.read(k,20);
	Description=k;
	sour.read(k,10);
	No=k;
	sour.read((char*)&Quantity,sizeof(int));
	sour.read((char*)&Cost,sizeof(double));
	sour.read((char*)&Retail,sizeof(double));
}//由此可见读和写是完全对称的过程,次序决不能错

int main(){
	inventory car1("夏利2000","805637928",156,80000,105000),car2;
	inventory motor1("金城125","93612575",302,10000,13000),motor2;
	cout<<"对象car1:"<<endl;
	cout<<car1;
	cout<<"对象motor1:"<<endl;
	cout<<motor1;
	cout<<"对象car2:"<<endl;
	cout<<car2;
	cout<<"对象motor2:"<<endl;
	cout<<motor2;
	fstream datafile("d:\\Ex9_11_1.data",ios::in|ios::out|ios::binary);
	if(!datafile){
		datafile.clear(0);
		datafile.open("d:\\Ex9_11_1.data",ios::out); //建立输出文件
		datafile.close();
		datafile.open("d:\\Ex9_11_1.data",ios::in|ios::out|ios::binary); //改为输入输出文件
	}
	car1.Bdatatofile(datafile);//存car1
	datafile.seekp(0,ios::beg);//重定位，用seekp()完全一样
	car2.Bdatafromfile(datafile);//重写car2
	cout<<"对象car2:"<<endl;
	cout<<car2;
	datafile.seekg(0,ios::end);//重定位，用seekg()完全一样
	motor1.Bdatatofile(datafile);//存motor1
	datafile.seekp(50,ios::beg);//重定位，用seekp()完全一样
	motor2.Bdatafromfile(datafile);//重写motor2
	cout<<"对象motor2:"<<endl;
	cout<<motor2;
	datafile.close();
	return 0;
}
