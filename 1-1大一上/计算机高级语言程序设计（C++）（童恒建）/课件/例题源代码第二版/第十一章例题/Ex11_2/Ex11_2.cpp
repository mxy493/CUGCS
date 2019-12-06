//【例11.2】寻找vector容器元素。
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main(){
	int i,search_value,ia[9]={47,29,37,23,11,7,5,31,41};
	vector<int> vec(ia,ia+9);                                       //数据填入vector
	vector<int>::iterator iter;      //iter是vector用的迭代子，自动建为随机访问迭代子
	for(i=0;i<vec.size();i++)  cout<<vec[i]<<'\t';       //成员函数size()返回元素数量
	cout<<endl;
    vec.push_back(13);                     //容器末尾插入新元素，vector只能在尾部处理
	for(iter=vec.begin();iter!=vec.end();iter++)  cout<<*iter<<'\t';   //标准输出方法
	cout<<"\n请输入需搜索的数："<<endl;
	cin>>search_value;
	iter=find(vec.begin(),vec.end(),search_value);   //使用vector成员函数赋迭代子初值
	cout<<"数值"<<search_value<<( iter==vec.end() ?"不存在":"存在")<<endl;
	return 0;
}

