/*����2.16����ӡ�žű���ӡ��ʽΪ��
*      1   2   3   4   5   6   7   8   9

1      1   
2      2   4
3      3   6   9
��
9      9  18  27  36  45  54  63  72  81
*/

#include <iostream>
#include <iomanip>
using namespace std; 
int main(){
	int i,j;
	cout<<setw(3)<<'*'<<setw(4)<<' ';
	for(i=1;i<10;i++)  cout<<setw(4)<<i;	   //�����һ�б�ͷ
	cout<<endl<<endl;                              //�������
	for(i=1;i<10;i++){
		cout<<setw(3)<<i<<setw(4)<<' ';		       //����к�
		for(j=1;j<=i;j++)  cout<<setw(4)<<i*j; //�����ֵ����
		cout<<endl;						           //׼�������һ��
	}
	return 0;
}
