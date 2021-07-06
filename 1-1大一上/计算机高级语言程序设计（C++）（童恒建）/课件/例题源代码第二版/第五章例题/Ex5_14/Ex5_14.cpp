//【例5.14】先用指向二维数组基本元素的指针变量，再用指向组成二维数组的
//一维数组的指针变量输出二维数组全部基本元素。
#include< iostream>
using namespace std;
int main( ){
	int a[3][6]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
	int  * ptr,i,j;
	ptr=&a[0][0] ;       //或 ptr = *a; 而不能ptr = a;
	for(i=0;i<18;i++){
		cout<<*(ptr+i)<<'\t';
		if(i%6==5) cout<<endl;
	}
	cout<<endl;
	int  (* ptr1)[6];       //注意 ptr1是指向包含6个整型元素的一维数组的指针
	ptr1=a; 
	for(i=0;i<3;i++){
		for(j=0;j<6;j++) cout<<*(*(ptr1+i)+j)<<'\t';
		cout<<endl;
	}
	return 0;
}

