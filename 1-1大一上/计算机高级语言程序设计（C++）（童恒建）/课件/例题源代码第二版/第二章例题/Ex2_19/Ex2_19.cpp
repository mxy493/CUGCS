//����2.19�� ��ɸѡ����100֮�ڵ�����������������Щ���������ÿ�����10�����ݡ�

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int n=100;
int main(){
	int a[n];
	int i,j;
	for(i=0;i<n;i++) a[i]=1+i;			//�����鱣������1-100
	a[0]=0;							//1������������0
	for(i=1;i<n;i++){
		if(a[i]==0)  continue;			//�����Ѿ���0,�ж���һ����
		for(j=i+1;j<n;j++)	if(a[j]%a[i]==0)  a[j]=0;	//��a[i]������Ԫ����0��
	}
	int count=0;
	cout<<"1-" <<n<<"֮���������"<<endl;
	for(i=0;i<n;i++)						//�����������
		if(a[i]!=0){                       //��0Ԫ�ؼ�Ϊ����
			cout<<setw(6)<<a[i];
			count++;
			if(count%10==0)  cout<<endl;	//ÿ��10������
		}
	cout<<endl;
	return 0;
}
