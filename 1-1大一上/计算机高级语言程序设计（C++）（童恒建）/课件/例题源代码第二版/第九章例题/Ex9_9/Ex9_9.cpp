//����9.9���ı�ʽ�����ļ��Ĵ������ȡ���ݡ�
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
	friend ostream&operator<<(ostream&dist,inventory&iv);//���ز��������
	friend istream&operator>>(istream&sour,inventory&iv);//������ȡ�����
};     //������Ϊ��ʽ��������������
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
}//д���ļ����Զ�����תΪ���ִ���д��
istream&operator>>(istream&sour,inventory&iv){
	sour>>iv.Description>>iv.No>>iv.Quantity>>iv.Cost>>iv.Retail;
	return sour;
}//���ļ��������Զ������ִ�תΪ������,��������>>���ܲ���
int main(){
	inventory car1("����2000","805637928",156,80000,105000),car2;
	inventory motor1("���125","93612575",302,10000,13000),motor2;
	ofstream distfile("d:\\Ex9_9.data");
	distfile<<car1<<motor1;//ע��ofstream��ostream��������
	distfile.close();
	cout<<car1;
	cout<<motor1;
	cout<<car2;
	cout<<motor2;
	ifstream sourfile("d:\\Ex9_9.data");//���������δ�,�ɱ�����ļ�ʱ,�����Դ�ļ�
	sourfile>>car2>>motor2;
	sourfile.close();
	cout<<car2;
	cout<<motor2;
	return 0;
}
