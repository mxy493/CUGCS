//【例3.1】 输入两个实数，输出其中较大的数。其中求两个实数中的较大数用函数完成。
#include<iostream>
using namespace std;
float max(float x,float y){return(x>=y?x:y);}

int main(){
	float x,y;
	cout<<"输入两个实数："<<endl;
	cin>>x>>y;
	cout<<x<<"和"<<y<<"中较大数为"<<max(x,y)<<endl;
	return 0;
}
