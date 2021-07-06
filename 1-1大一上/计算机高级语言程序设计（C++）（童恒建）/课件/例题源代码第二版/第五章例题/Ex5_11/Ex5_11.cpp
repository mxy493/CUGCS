//【例5.11】通常用输出数组名得到的是数组地址，但字符型数组（串）不同，
//输出的是数组内容。本例将字符指针强制转换为泛型指针输出字符串地址。
#include<iostream>
using namespace std;

int main(){
  char *string1="欢迎学习C++程序设计课程！";
  cout<<"串值是："<<string1<<"\n串地址是："<<(void*)string1<<endl;
  return 0;
}
