//����11.3����istream_iterator�ӱ�׼�������һ����������vector�С�
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int main(){
	istream_iterator<int> input(cin);
	istream_iterator<int> end_of_stream;
	vector<int> vec;
	copy(input,end_of_stream,inserter(vec,vec.begin()));//����^Z������
	sort(vec.begin(),vec.end(),greater<int>());//��������
	ostream_iterator<int>output(cout," ");
	unique_copy(vec.begin(),vec.end(),output);
	cout<<endl;
	return 0;
}
