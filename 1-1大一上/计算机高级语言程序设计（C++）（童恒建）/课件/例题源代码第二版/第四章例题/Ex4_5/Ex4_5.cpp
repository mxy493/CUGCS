//����4.5��ͳ��ѧ���ɼ���������80�����ϵ�ΪA�࣬60�����ϣ�80�����µ�ΪB�࣬60������ΪC�ࡣ
#include<iostream>
using namespace std;
int& level(int grade , int& typeA , int& typeB , int& typeC);   //��������ֵΪ����������
int main( ){
	int typeA=0,typeB=0,typeC=0 ;
	int student=9 ;
	int array[9]={90 , 75 , 83 , 66 , 58 , 40 , 80 , 85 , 71} ;
	for (int i=0 ; i<student ; i++)
		level(array[i], typeA, typeB, typeC)++ ;       //��������ֵ�����++
	cout<<"A��ѧ������"<<typeA<<endl ;
	cout<<"B��ѧ������"<<typeB<<endl ;
	cout<<"C��ѧ������"<<typeC<<endl ;
	return 0;
}
int& level(int grade ,int& typeA ,int& typeB ,int& typeC){ 
	if(grade>=80) return typeA ; 
	else if(grade>=60) return typeB; 
	else return typeC;      //��������ֵΪmain( )�ж����3������֮һ,��������ʱ����
}
