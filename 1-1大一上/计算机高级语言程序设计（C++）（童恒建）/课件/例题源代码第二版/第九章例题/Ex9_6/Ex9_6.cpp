//����9.6���û�����ĸ�������Complex�������������
#include<iostream>
using namespace std;

class Complex{
	double Real,Image;
public:
	Complex(double r=0.0, double i=0.0):Real(r),Image(i){}//���幹�캯��
	//������4.7��,����ʡ��,�Խ�Լƪ��
	friend ostream&operator<<(ostream&s,const Complex&z);
	friend istream&operator>>(istream&s,Complex&a);
};
ostream&operator<<(ostream&s,const Complex &z){     //������Ϊ��ʽ��������������
	return s<<'('<<z.Real<<','<<z.Image<<')';
}
istream&operator>>(istream&s,Complex &a){//��ʽΪd,(d),(d,d)
	double re=0,im=0;
	char c=0;
	s>>c;//�Ƿ������ſ�ʼ
	if(c=='('){
		s>>re>>c;//ʵ��
		if(c==',')s>>im>>c;//�鲿
		if(c!=')')s.clear(ios::failbit);//©�����Ÿ�һ������ʧ�ܱ�־
	}
	else{
		s.putback(c);//�����ţ�����һ���ַ������뻺����
		s>>re;//ʵ��
	}
	if(s)a=Complex(re,im);
	return s;
}
int main(){
	Complex a,b,c;
	cout<<"����һ��ʵ��"<<endl;
	cin>>a;
	cout<<"����һ����������������ʵ��"<<endl;
	cin>>b;
	cout<<"����һ������������������"<<endl;
	cin>>c;
	cout<<"a="<<a<<'\t'<<"b="<<b<<'\t'<< "c="<<c<<'\n';
	return 0;
}
