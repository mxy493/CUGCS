/*【例2.7】商场优惠活动规定，某商品一次购买5件以上（包含5件）10件以下（不包含10件）打9折，
一次购买10件以上（包含10件）打8折。设计程序根据单价和客户的购买量计算总价。
*/
#include <iostream>
using namespace std;

int main(){
	float price,discount,amount;			//单价、折扣、总价
	int count;						  	//购买件数
	cout<<"输入单价:"<<endl;
	cin>>price;
	cout<<"输入购买件数:"<<endl;
	cin>>count;
	if(count<5)  discount=1;
	else if(count<10)  discount=0.9;
	     else  discount=0.8;
	amount=price*count*discount;
	cout<<"单价："<< price<<endl;
	cout<<"购买件数："<<count<<"\t\t"<<"折扣："<<discount<<endl;
	cout<<"总价："<<amount<<endl;
	return 0;
}
