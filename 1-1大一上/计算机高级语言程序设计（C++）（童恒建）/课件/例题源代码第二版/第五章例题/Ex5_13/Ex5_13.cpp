//【例5.13】多级指针示例。
#include<iostream>
using namespace std;

int main(){
	int val=66;
	int *pval = &val;
	int **ppval = &pval;
	cout<<"val="<<val<<'\n'<<"**ppval="<<**ppval<<'\n';
	**ppval=18;
	cout<<"val="<<val<<'\n'<<"**ppval="<<**ppval<<endl;
	return 0;
}
