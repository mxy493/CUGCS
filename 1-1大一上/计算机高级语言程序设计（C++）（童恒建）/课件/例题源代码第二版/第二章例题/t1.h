/*����3.13����ŵ�����⡣��A��B��C�������ӣ�A������n����С���ȵ����ӣ��������£�С�����ϡ�
Ҫ������������A���ᶯ��C���ϣ�ÿ��ֻ�ܰᶯһ�����ӣ��ᶯ�����п��Խ����κ�һ�����ӣ���
��������������£�С�����ϵ���������ӡ���ᶯ�Ĳ��衣
*/
#include <iostream>
using namespace std;

void move(char,char);
void hanoi(int,char,char,char);
int main(){
	int n;
	cout<<"������������"<<endl;
	cin>>n;
	hanoi(n,'A','B','C');
	cout<<endl;
	return 0;
}
void hanoi(int n,char source,char temp,char target){
	if(n==1)  move(source,target);
	else{
		hanoi(n-1,source,target,temp);				//��n-1�����Ӱᵽ�м���
		move (source,target);					//�����һ�����ӰᵽĿ����
		hanoi(n-1,temp,source,target);				//��n-1�����ӰᵽĿ����
	}
}
void move(char source,char target){
	cout<<source<<"->"<<target<<'\t';
}
