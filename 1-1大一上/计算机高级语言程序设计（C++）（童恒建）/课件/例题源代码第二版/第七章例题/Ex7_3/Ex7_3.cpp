//����7.3����ʾ���ɴ洢�����������ͷš�
#include<iostream>
using namespace std;
class CGoods{
	string  Name;
	int  Amount;
	float Price;
	float Total_value;
public:
	CGoods(){cout<<"����ȱʡ���캯��"<<endl;};
	CGoods(string name,int amount ,float price){
		cout<<"�������������캯��"<<endl;
		Name=name; Amount=amount;
		Price=price; Total_value=price*amount;
	}
	~CGoods(){ cout<<"������������"<<endl;}
};
int main(){
	int n;
	CGoods *pc,*pc1,*pc2;
	pc=new CGoods("����2000",10,118000); //�������������캯��
	pc1=new CGoods();                      //����ȱʡ���캯��
	cout<<"������Ʒ������Ԫ����"<<endl;
	cin>>n;
	pc2=new CGoods[n];                  //��̬�������飬����ȱʡ���캯��������n��
	delete pc;
	delete pc1;
	delete []pc2;
	return 0;
}
