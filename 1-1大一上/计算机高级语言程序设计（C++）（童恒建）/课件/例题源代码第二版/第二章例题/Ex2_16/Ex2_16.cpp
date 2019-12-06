/*【例2.16】打印九九表。打印格式为：
*      1   2   3   4   5   6   7   8   9

1      1   
2      2   4
3      3   6   9
…
9      9  18  27  36  45  54  63  72  81
*/

#include <iostream>
#include <iomanip>
using namespace std; 
int main(){
	int i,j;
	cout<<setw(3)<<'*'<<setw(4)<<' ';
	for(i=1;i<10;i++)  cout<<setw(4)<<i;	   //输出第一行表头
	cout<<endl<<endl;                              //输出空行
	for(i=1;i<10;i++){
		cout<<setw(3)<<i<<setw(4)<<' ';		       //输出行号
		for(j=1;j<=i;j++)  cout<<setw(4)<<i*j; //输出表值数据
		cout<<endl;						           //准备输出下一行
	}
	return 0;
}
