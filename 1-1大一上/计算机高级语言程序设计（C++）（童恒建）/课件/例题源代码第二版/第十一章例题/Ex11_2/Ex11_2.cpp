//����11.2��Ѱ��vector����Ԫ�ء�
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	int i,search_value,ia[9]={47,29,37,23,11,7,5,31,41};
	vector<int> vec(ia,ia+9);                                       //��������vector
	vector<int>::iterator iter;      //iter��vector�õĵ����ӣ��Զ���Ϊ������ʵ�����
	for(i=0;i<vec.size();i++)  cout<<vec[i]<<'\t';       //��Ա����size()����Ԫ������
	cout<<endl;
    vec.push_back(13);                     //����ĩβ������Ԫ�أ�vectorֻ����β������
	for(iter=vec.begin();iter!=vec.end();iter++)  cout<<*iter<<'\t';   //��׼�������
	cout<<"\n������������������"<<endl;
	cin>>search_value;
	iter=find(vec.begin(),vec.end(),search_value);   //ʹ��vector��Ա�����������ӳ�ֵ
	cout<<"��ֵ"<<search_value<<( iter==vec.end() ?"������":"����")<<endl;
	return 0;
}

