//ǿ����������ļ����ļ���λָ��ֻ��һ����������������ô˶�λָ�롣
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//����˵��ֻ��һ���ļ���λָ��
class inventory{
	string Description;
	string No;
	int Quantity;
	double Cost;
	double Retail;
public:
	inventory(string="#",string="0",int =0,double =0,double =0);
	friend ostream &operator<<(ostream&,inventory&);
	void Bdatatofile(fstream&dist);     //�ļ�������Ϊ��ʽ��������������
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
	dist.write(Description.c_str(),20); //��string���c_str()����תΪchar*
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
}//�ɴ˿ɼ�����д����ȫ�ԳƵĹ���,��������ܴ�

int main(){
	inventory car1("����2000","805637928",156,80000,105000),car2;
	inventory motor1("���125","93612575",302,10000,13000),motor2;
	cout<<"����car1:"<<endl;
	cout<<car1;
	cout<<"����motor1:"<<endl;
	cout<<motor1;
	cout<<"����car2:"<<endl;
	cout<<car2;
	cout<<"����motor2:"<<endl;
	cout<<motor2;
	fstream datafile("d:\\Ex9_11_1.data",ios::in|ios::out|ios::binary);
	if(!datafile){
		datafile.clear(0);
		datafile.open("d:\\Ex9_11_1.data",ios::out); //��������ļ�
		datafile.close();
		datafile.open("d:\\Ex9_11_1.data",ios::in|ios::out|ios::binary); //��Ϊ��������ļ�
	}
	car1.Bdatatofile(datafile);//��car1
	datafile.seekp(0,ios::beg);//�ض�λ����seekp()��ȫһ��
	car2.Bdatafromfile(datafile);//��дcar2
	cout<<"����car2:"<<endl;
	cout<<car2;
	datafile.seekg(0,ios::end);//�ض�λ����seekg()��ȫһ��
	motor1.Bdatatofile(datafile);//��motor1
	datafile.seekp(50,ios::beg);//�ض�λ����seekp()��ȫһ��
	motor2.Bdatafromfile(datafile);//��дmotor2
	cout<<"����motor2:"<<endl;
	cout<<motor2;
	datafile.close();
	return 0;
}
