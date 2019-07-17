//【例1.3】字符数组和字符串处理函数的应用。
# include <iostream>
# include <cstring>
using namespace std;

int main() {
	char s1[]="Hello C++";   //初始化决定数组s1[]有10个元素
	char s2[10], s3[20];
	s2[0]='B';s2[1]='e';s2[2]='g';s2[3]='i';s2[4]='n';
	s2[5]='\0';					 //串结束符对字符串处理非常重要
	strcpy(s3, s2);
	cout<<"The length of \""<<s1<<"\" is:"<<strlen(s1)<<'\n';
	cout<<s2<<'\t'<<s3<<'\n';  //只有字符数组可整体输出
    return 0;
}
