//����8.2����Բ�͸߶��ؼ̳�������Բ׶��
#include<iostream>
#include<cmath>
using namespace std;

class Circle{
protected:
	float x,y,r;					//(x,y)ΪԲ��,rΪ�뾶
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
	}//��������������ֱ�ӷ���ֱ�ӻ���ı�����Ա
};

int main(){
	Cone c1(5,8,3,4);
	float a,b;
	cout<<"Բ׶���:"<<c1.GetCV()<<'\n';
	cout<<"Բ׶�����:"<<c1.GetCA()<<'\n';
	cout<<"Բ׶�����:"<<c1.GetAreaCircle()<<'\n';
	cout<<"Բ׶���ܳ�:"<<c1.GetCircumference()<<'\n';
	cout<<"Բ׶�װ뾶:"<<c1.GetR()<<'\n';
	c1.Getcoordinate(a,b);
	cout<<"Բ׶��Բ������:("<<a<<','<<b<<")\n";
	cout<<"Բ׶��:"<<c1.GetHigh()<<'\n';
	return 0;
}
