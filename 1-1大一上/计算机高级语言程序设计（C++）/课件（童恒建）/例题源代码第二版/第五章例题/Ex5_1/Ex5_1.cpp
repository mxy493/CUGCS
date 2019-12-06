//【例 5.1】找出一个整型数组各数组元素中的最大数和最小数，数组中的数由随机数发生函数 rand()产生。
#include <iostream>
#include <cstdlib>
using namespace std;

const SIZE=15;

int main(){
    int arr[SIZE];
    int i,high,low;
    for (i=0;i<SIZE;i++) arr[i]=rand()%100;
    cout << "Here are the " <<SIZE<<"  roundom numbers :"<<endl;
    for (i=0;i<SIZE;i++)  cout<<arr[i]<<'\t';
	cout<<endl;
    high=arr[0];             //初始化时认为最大和最小值均为数组的第一个元素
    low=arr[0];
    for(i=1;i<SIZE;i++){
		if(arr[i]>high)   high=arr[i];
		if(arr[i]<low)   low=arr[i];
    }
    cout<<"highest value is "<<high<<endl;
    cout<<"lowest value is "<<low<<endl;
    return 0;
}
