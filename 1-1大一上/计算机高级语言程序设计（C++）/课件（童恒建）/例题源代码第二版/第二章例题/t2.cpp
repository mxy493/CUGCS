/*【例3.13】汉诺塔问题。有A、B、C三根柱子，A柱上有n个大小不等的盘子，大盘在下，小盘在上。
要求将所有盘子由A柱搬动到C柱上，每次只能搬动一个盘子，搬动过程中可以借助任何一根柱子，但
必须满足大盘在下，小盘在上的条件。打印出搬动的步骤。
*/
#include <iostream>
using namespace std;

void move(char,char);
void hanoi(int,char,char,char);
int main(){
	int n;
	cout<<"输入盘子数："<<endl;
	cin>>n;
	hanoi(n,'A','B','C');
	cout<<endl;
	return 0;
}
void hanoi(int n,char source,char temp,char target){
	if(n==1)  move(source,target);
	else{
		hanoi(n-1,source,target,temp);				//将n-1个盘子搬到中间柱
		move (source,target);					//将最后一个盘子搬到目标柱
		hanoi(n-1,temp,source,target);				//将n-1个盘子搬到目标柱
	}
}
void move(char source,char target){
	cout<<source<<"->"<<target<<'\t';
}
