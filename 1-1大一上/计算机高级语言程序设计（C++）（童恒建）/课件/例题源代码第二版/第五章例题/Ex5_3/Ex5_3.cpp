//����5.3���˻ʺ����⣺��8��8�Ĺ������������ϰ��Ű˸��ʺ�Ϊ��������֮���໥������
//Ҫ��û���κ������ʺ������̵�ͬһ�С�ͬһ�м���ͬһ�Խ����ϡ�
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int queen[8];
	int total = 0;      //��������
	int i, j, k;
	for (i=0;i<8;i++)  queen[i] = 0;           //�˻ʺ�ȫ���ڵ�0��
	for (i=1;;){                               //���Ȱ��ŵ�0�лʺ�
		if(queen[i]<8){                          //�ʺ󻹿ɵ���
			k=0;                                   //������k���ʺ��Ƿ��๥��
			while(k<i&&(queen[k]-queen[i])&&(abs(queen[k]-queen[i])-abs(k-i)))  k++;
			if (k<=i-1){                           //���k���ʺ��๥��
				queen[i]++;                          //��i���ʺ�����һ�У��ز�
				continue;
			}
			i++;                                   //�޳�ͻ��������һ�лʺ�
			if(i<8) continue;
			for(j=0;j<8;j++) cout<<queen[j];       //����ɣ�������
			cout<<"  ";
			total++;                               //��������1
			if(total%5==0) cout<<endl;
			queen[7]++;                            // ����7���ʺ�����һ�У�ǰ7������
			i=7;                           //�˴���������ᣬ�粻�ɹ�����ݣ��ؼ�һ��
		}
		else                                     //��ǰ�лʺ��޷����ã�����
		{
			queen[i]=0;                            //��ǰ�лʺ�ع�0��
			i--;                                   //���ݵ�ǰһ�лʺ�
			if(i<0){                               //���ݵ�����0��֮ǰ������
				cout<<" ����:"<<total<<endl;
				return 0;
			}
			else queen[i]++;             //ǰһ�лʺ�����һ��
		}
	}
}
