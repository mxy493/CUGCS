//����3.1�� ��������ʵ����������нϴ����������������ʵ���еĽϴ����ú�����ɡ�
#include<iostream>
using namespace std;
float max(float x,float y){return(x>=y?x:y);}

int main(){
	float x,y;
	cout<<"��������ʵ����"<<endl;
	cin>>x>>y;
	cout<<x<<"��"<<y<<"�нϴ���Ϊ"<<max(x,y)<<endl;
	return 0;
}
