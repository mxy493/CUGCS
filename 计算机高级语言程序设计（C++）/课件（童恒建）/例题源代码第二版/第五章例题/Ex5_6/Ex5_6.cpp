//【例5.6】指针赋值实例：
#include <iostream>
using namespace std;

int main(){
	int age1=18,age2=20,*p_age;
	p_age=&age1;    //情况1，见图5.5
	cout<<"age1的地址是："<<p_age<<endl;
	cout<<"age of wang ping is "<<*p_age<<endl;
	p_age=&age2;  //情况2，指针改指另一变量，见图5.5
	cout<<"age2的地址是："<<p_age<<endl;
	cout<<"age of zhang ling is "<<*p_age<<endl;
	return 0;
}
