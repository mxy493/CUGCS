//����2.18�� ����������m���ж����Ƿ�Ϊ������

#include <iostream>
#include <cmath>
using namespace std;
		
int main(){
	 int m,i,k;
	 for(int l=0;l<3;l++){
	 cout<<"�������1��������m��"<<endl;	 
	 cin>>m;
	 if(m==2)   cout<<m<<"������"<<endl;
	 else{
		k=sqrt(m);
		for(i=2;i<=k;i++) if (m%i==0)  break;		//ֻҪ��һ���������Ϳ�ֹͣ
		if(i>k)  cout<< m<<"������"<<endl;		//ѭ����ǰ��ֹ��ʾ�Ƿ�����
		else  cout<< m<<"��������"<<endl;
	 }
	 cout<<endl;
	 }
	 char ch;
	 cin.get(ch);
	 cin.get(ch);
	 return 0;
}
