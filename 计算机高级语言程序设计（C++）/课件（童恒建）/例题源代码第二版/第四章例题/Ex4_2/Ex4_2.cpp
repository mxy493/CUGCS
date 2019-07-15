//【例4.2】矩形类。要确定一个矩形（四边都是水平或垂直方向，不能倾斜），只要确定其左上角和右下角的
//x和y坐标即可，因此应包括四个数据成员，left,right,top,bottom，即左右上下四个边界值。由构造函数对
//数据成员赋值。赋值函数完成未初始化的矩形赋值，也可以修改各数据成员。并用多文件实现。
#include <iostream>
#include "rect.h"
using namespace std;

int main(){
	Rectangle rect; 
	cout<<"由缺省的构造函数生成的rect："<<endl;
	rect.Show();
	rect.Assign(100,200,300,400);
	cout<<"由赋值函数处理后的rect："<<endl;
	rect.Show();
	Rectangle rect1(0,0,200,200);
	cout<<"由构造函数生成的rect1："<<endl;
	rect1.Show();
	return 0;
}
