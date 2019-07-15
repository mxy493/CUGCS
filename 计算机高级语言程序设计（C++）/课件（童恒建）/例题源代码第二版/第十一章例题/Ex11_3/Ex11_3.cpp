//【例11.3】用istream_iterator从标准输入读入一个整数集到vector中。
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
	copy(input,end_of_stream,inserter(vec,vec.begin()));//输入^Z结束流
	sort(vec.begin(),vec.end(),greater<int>());//降序排列
	ostream_iterator<int>output(cout," ");
	unique_copy(vec.begin(),vec.end(),output);
	cout<<endl;
	return 0;
}
