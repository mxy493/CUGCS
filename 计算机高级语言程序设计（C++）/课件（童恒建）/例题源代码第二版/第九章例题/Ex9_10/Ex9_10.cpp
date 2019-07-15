//【例9.10】创建二进制数据文件，以及数据文件的读取。这两项操作设计为成员函数。
//为与【例9.9】对比，采用同名的类，并有同样的数据成员。
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
	inventory(string="#",string="0",int =0,double =0,double =0);
	friend ostream &operator<<(ostream&,inventory&);
	void Bdatatofile(ofstream&dist);     //文件流类作为形式参数必须是引用
	void Bdatafromfile(ifstream&sour);
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
void inventory::Bdatatofile(ofstream&dist){
	dist.write(Description.c_str(),20); //由string类的c_str()函数转为char*
	dist.write(No.c_str(),10);
	dist.write((char*)&Quantity,sizeof(int));
	dist.write((char*)&Cost,sizeof(double));
	dist.write((char*)&Retail,sizeof(double));
}
void inventory::Bdatafromfile(ifstream&sour){
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
	ofstream ddatafile("d:\\Ex9_10.data",ios::out|ios::binary);
	car1.Bdatatofile(ddatafile);
	motor1.Bdatatofile(ddatafile);
	cout<<"对象car1:"<<endl;
	cout<<car1;
	cout<<"对象motor1:"<<endl;
	cout<<motor1;
	cout<<"对象car2:"<<endl;
	cout<<car2;
	cout<<"对象motor2:"<<endl;
	cout<<motor2;
	ddatafile.close();
	ifstream sdatafile("d:\\Ex9_10.data",ios::in|ios::binary);//重新打开文件,从头读取数据
	car2.Bdatafromfile(sdatafile);                         //从文件读取数据拷贝到对象car2
	if(sdatafile.eof()==0) cout<<"读文件成功"<<endl; 
	cout<<"对象car2:"<<endl;
	cout<<car2;
	motor2.Bdatafromfile(sdatafile);                 //继续从文件读取数据拷贝到对象motor2
	if(sdatafile.eof()==0) cout<<"读文件成功"<<endl;
	cout<<"对象motor2:"<<endl;
	cout<<motor2;
	sdatafile.close();
	return 0;
}
