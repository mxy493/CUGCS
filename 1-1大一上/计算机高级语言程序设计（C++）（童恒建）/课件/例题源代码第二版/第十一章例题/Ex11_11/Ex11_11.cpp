//����11.11�����ȼ���������ʾ��ͷ�ļ���<queue>�����ȼ�������ʾ����ֵԽ�����ȼ�Խ�ߡ�
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

void main(){
	priority_queue<int> prioque;
	//ʵ�������intֵ�����ȼ����У�����deque��Ϊ�������ݽṹ
	prioque.push(7);//ѹ�����ȼ�����
	prioque.push(12);
	prioque.push(9);
	prioque.push(18);
	cout<<"�����ȼ������е���"<<endl;
	while(!prioque.empty()){
		cout<<prioque.top()<<'\t';//ȡ������ȼ�����
		prioque.pop();//����������ȼ�����
	}
	cout<<endl;
}
