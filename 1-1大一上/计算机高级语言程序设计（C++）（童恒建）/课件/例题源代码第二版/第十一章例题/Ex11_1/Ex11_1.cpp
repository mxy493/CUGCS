//����11.1��Ѱ������Ԫ�ء�
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
	int search_value,ia[9]={47,29,37,23,11,7,5,31,41};
	cout<<"������������������"<<endl;
	cin>>search_value;
	int* presult=find(&ia[0],&ia[9],search_value);
	cout<<"��ֵ"<<search_value<<(presult==&ia[9] ?"������":"����")<<endl;
	return 0;
}
