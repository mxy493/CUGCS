/*����2.17����ӡ����ͼ�Ρ�
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
		for(j=1;j<=5-i;j++)  cout<<"  " ;		  //������ɿո�
		for(j=1;j<=11;j++)  cout<<"* ";           //�������*
		cout<<endl;						      //׼�������һ��
	}
	return 0;
}
