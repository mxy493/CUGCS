//【例4.5】统计学生成绩，分数在80分以上的为A类，60分以上，80分以下的为B类，60分以下为C类。
#include<iostream>
using namespace std;
int& level(int grade , int& typeA , int& typeB , int& typeC);   //函数返回值为变量的引用
int main( ){
	int typeA=0,typeB=0,typeC=0 ;
	int student=9 ;
	int array[9]={90 , 75 , 83 , 66 , 58 , 40 , 80 , 85 , 71} ;
	for (int i=0 ; i<student ; i++)
		level(array[i], typeA, typeB, typeC)++ ;       //函数返回值本身后++
	cout<<"A类学生数："<<typeA<<endl ;
	cout<<"B类学生数："<<typeB<<endl ;
	cout<<"C类学生数："<<typeC<<endl ;
	return 0;
}
int& level(int grade ,int& typeA ,int& typeB ,int& typeC){ 
	if(grade>=80) return typeA ; 
	else if(grade>=60) return typeB; 
	else return typeC;      //函数返回值为main( )中定义的3个变量之一,而不是临时变量
}
