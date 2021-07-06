/*【例2.17】打印如下图形。
* * * * * * * * * * *
  * * * * * * * * * * *
    * * * * * * * * * * *
      * * * * * * * * * * *
        * * * * * * * * * * *
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i,j;
	for(i=1;i<=5;i++){
		for(j=1;j<=5-i;j++)  cout<<"  " ;		  //输出若干空格
		for(j=1;j<=11;j++)  cout<<"* ";           //输出若干*
		cout<<endl;						      //准备输出下一行
	}
	return 0;
}
