//【例7.3】演示自由存储区对象分配和释放。
#include<iostream>
using namespace std;
class CGoods{
	string  Name;
	int  Amount;
	float Price;
	float Total_value;
public:
	CGoods(){cout<<"调用缺省构造函数"<<endl;};
	CGoods(string name,int amount ,float price){
		cout<<"调用三参数构造函数"<<endl;
		Name=name; Amount=amount;
		Price=price; Total_value=price*amount;
	}
	~CGoods(){ cout<<"调用析构函数"<<endl;}
};
int main(){
	int n;
	CGoods *pc,*pc1,*pc2;
	pc=new CGoods("夏利2000",10,118000); //调用三参数构造函数
	pc1=new CGoods();                      //调用缺省构造函数
	cout<<"输入商品类数组元素数"<<endl;
	cin>>n;
	pc2=new CGoods[n];                  //动态建立数组，调用缺省构造函数，共调n次
	delete pc;
	delete pc1;
	delete []pc2;
	return 0;
}
