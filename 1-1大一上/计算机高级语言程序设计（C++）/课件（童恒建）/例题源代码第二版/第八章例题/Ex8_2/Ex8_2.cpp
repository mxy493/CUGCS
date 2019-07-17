//【例8.2】由圆和高多重继承派生出圆锥。
#include<iostream>
#include<cmath>
using namespace std;

class Circle{
protected:
	float x,y,r;					//(x,y)为圆心,r为半径
public:
	Circle(float a=0,float b=0,float R=0){x=a;y=b;r=R;}
	void Setcoordinate(float a,float b){x=a;y=b;}
	void Getcoordinate(float &a,float &b){a=x;b=y;}
	void SetR(float R){r=R;}
	float GetR(){return r;}
	float GetAreaCircle(){return float(r*r*3.14159);}
	float GetCircumference(){return float(2*r*3.14159);}
};
class Line{
protected:
	float High;
public:
	Line(float a=0){High=a;}
	void SetHigh(float a){High=a;}
	float GetHigh(){return High;}
};
class Cone:public Circle,public Line{
public:
	Cone(float a,float b,float R,float d):Circle(a,b,R),Line(d){}
	float GetCV(){return float(GetAreaCircle()*High/3);}
	float GetCA(){
		return float(GetAreaCircle()+r*3.14159*sqrt(r*r+High*High));
	}//共有派生类中能直接访问直接基类的保护成员
};

int main(){
	Cone c1(5,8,3,4);
	float a,b;
	cout<<"圆锥体积:"<<c1.GetCV()<<'\n';
	cout<<"圆锥表面积:"<<c1.GetCA()<<'\n';
	cout<<"圆锥底面积:"<<c1.GetAreaCircle()<<'\n';
	cout<<"圆锥底周长:"<<c1.GetCircumference()<<'\n';
	cout<<"圆锥底半径:"<<c1.GetR()<<'\n';
	c1.Getcoordinate(a,b);
	cout<<"圆锥底圆心坐标:("<<a<<','<<b<<")\n";
	cout<<"圆锥高:"<<c1.GetHigh()<<'\n';
	return 0;
}
