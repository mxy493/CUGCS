//����4.2�������ࡣҪȷ��һ�����Σ��ı߶���ˮƽ��ֱ���򣬲�����б����ֻҪȷ�������ϽǺ����½ǵ�
//x��y���꼴�ɣ����Ӧ�����ĸ����ݳ�Ա��left,right,top,bottom�������������ĸ��߽�ֵ���ɹ��캯����
//���ݳ�Ա��ֵ����ֵ�������δ��ʼ���ľ��θ�ֵ��Ҳ�����޸ĸ����ݳ�Ա�����ö��ļ�ʵ�֡�
#include <iostream>
#include "rect.h"
using namespace std;

int main(){
	Rectangle rect; 
	cout<<"��ȱʡ�Ĺ��캯�����ɵ�rect��"<<endl;
	rect.Show();
	rect.Assign(100,200,300,400);
	cout<<"�ɸ�ֵ����������rect��"<<endl;
	rect.Show();
	Rectangle rect1(0,0,200,200);
	cout<<"�ɹ��캯�����ɵ�rect1��"<<endl;
	rect1.Show();
	return 0;
}
