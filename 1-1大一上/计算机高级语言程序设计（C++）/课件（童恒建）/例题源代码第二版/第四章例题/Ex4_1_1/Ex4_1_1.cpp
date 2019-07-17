//【例4.1_1】完整商品类对象应用实例。
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class CGoods{
private :
	char 	Name[21] ;
	int  	Amount ;
	float 	Price ;
	float	    Total_value ;
public :
	CGoods();
	CGoods(char [],int,float);
	CGoods(char [],float);
	void 	RegisterGoods(char[],int,float) ;
	void 	CountTotal(void) ;
	void 	GetName(char[]) ;
	int 		GetAmount(void) ;
	float 	GetPrice(void) ;
	float 	GetTotal_value(void) ;
};
CGoods::CGoods(){
	Name[0]='\0' ; Price=0.0 ;
	Amount=0 ; Total_value=0.0 ;
}
CGoods::CGoods(char name[] , int amount , float price){
	strcpy(Name,name) ;	Price=price ;
	Amount=amount ;	Total_value=price*amount ;
}
CGoods::CGoods(char name[] , float price){
	strcpy(Name,name) ;	Price=price ;
	Amount=0 ;	Total_value=0.0 ;
}
void CGoods::RegisterGoods(char name[] , int amount , float price){
	strcpy(Name , name) ;//字符串拷贝函数
	Amount=amount ; Price=price ;
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
	char string[21]={'\0'};
	CGoods Car1("夏利2000",30,98000.0);
	CGoods Car2("桑塔那2000",164000.0);
	Car1.GetName(string); //string赋值car.Name
	cout<<setw(20)<<string<<setw(5)<< Car1.GetAmount();
	cout<<setw(10)<<Car1.GetPrice()<<setw(20)<< Car1.GetTotal_value()<<endl;
	Car2.GetName(string); //string赋值car.Name
	cout<<setw(20)<<string<<setw(5)<< Car2.GetAmount();
	cout<<setw(10)<<Car2.GetPrice()<<setw(20)<< Car2.GetTotal_value()<<endl;
	return 0;
}
