//����2.22�� ����һ��С��1����x����sinx�Ľ���ֵ��Ҫ�����С��0.0001��

#include<iostream>
using namespace std;

int main(){
	const double epsilon=0.0001;          //��epsilon�������
	double x,sinx,item;
	int n=2,sign=-1;                     //sign�������
	cout<<"input x:";
	cin>>x;
	sinx=x;item=x*x*x/6;                //��һ����Ϊ��ֵ���ڶ���Ϊ�����
	while(item>epsilon){
		sinx=sinx+item*sign;            //����ǰ���ۼӽ������ע�������Ϊ����
		item=item*x*x/((2*n)*(2*n+1));   //�����µ������
		sign=-sign;                    //ע����ŵı任
		n++;
	}
	cout<<"sin("<<x<<")="<<sinx<<endl;
	return 0;
}
