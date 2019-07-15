//【例3.3】设计函数，根据三角形的三边长求面积。如果不能构成三角形，给出提示信息。
#include<iostream>
#include<cmath>
using namespace std;

float TriangleArea(float a, float b, float c){
	if ((a+b<=c)||(a+c<=b)||(b+c<=a)) return -1;
	float s;
	s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){
	 float a,b,c,area;
	 cout<<"输入三角形三边a,b,c:"<<endl;
	 cin>>a>>b>>c;
	 area=TriangleArea(a,b,c);
	 if(area==-1)
		cout<<'('<<a<<','<<b<<','<<c<<')'<<"不能构成三角形！"<<endl;
	 else
		cout<<"三角形("<<a<<','<<b<<','<<c<<")面积为："<<area<<endl;
	 return 0;
}
