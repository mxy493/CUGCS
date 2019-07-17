//【例4.1】商品类对象应用实例。
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class CGoods{
private :
	char 	Name[21] ;
	int  	Amount ;
	float 	Price ;
	float	Total_value ;
public :
	void 	RegisterGoods(char[],int,float) ;
	void 	CountTotal(void) ;
	void 	GetName(char[]) ;
	int 	GetAmount(void) ;
	float 	GetPrice(void) ;
	float 	GetTotal_value(void) ;
};
void CGoods::RegisterGoods(char name[] , int amount , float price){
	strcpy(Name , name) ; Amount=amount ; Price=price ;
}
void CGoods::CountTotal(void){
	Total_value = Price*Amount;
}
void CGoods::GetName(char name[]){
	strcpy(name , Name);
}
int  CGoods::GetAmount(void){
	return(Amount) ;
}
float CGoods::GetPrice(void){
	return(Price) ;
}
float CGoods::GetTotal_value(void){
	return(Total_value) ;
}

int main( ){
	CGoods	 car ;
	char  str[21] ;
	int	number ;
	float  pr ;
	cout<<"请输入汽车型号：" ;
	cin.getline(str , 20) ;              //输入串长必须小于20
	cout<<"请依次输入汽车数量与单价：" ;
	cin>>number>>pr ;
	car.RegisterGoods(str , number , pr) ;
	car.CountTotal() ;
	str[0]='\0' ;                        //字符串str清零
	car.GetName(str) ;                   //string赋值car.Name
	cout<<setw(20)<<str<<setw(5)<<car.GetAmount() ;                     //A
	cout<<setw(10)<<car.GetPrice()<<setw(20)<<car.GetTotal_value()<<endl ; //B
	return 0;
}
