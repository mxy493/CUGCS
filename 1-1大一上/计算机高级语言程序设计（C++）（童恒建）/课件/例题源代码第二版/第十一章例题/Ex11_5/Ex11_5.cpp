//����11.5��˫�˶�������ʸ����һ������һ����Ա����insert()��ע�ⲻ�ǲ������������������insert()��
//������ʾ�ú�����ʹ�ã��������ַ�������STL����ǿʹ�÷��㡣��
#include<iostream>
#include<iterator>
#include<deque>
using namespace std;

typedef deque<char> char_deque;
void print_string(char_deque);
int main(){
	char arr1[]="����ǿ",arr2[]="ʹ�÷��㡣";
	char_deque  chdeq(arr1,arr1+6);
	print_string(chdeq);
	cout<<endl;
	chdeq.insert(chdeq.begin(),'L');            //����
	chdeq.insert(chdeq.begin(),'T');
	chdeq.insert(chdeq.begin(),'S');
	print_string(chdeq);
	cout<<endl;
	chdeq.insert(chdeq.end(),arr2,arr2+10);
	print_string(chdeq);
	cout<<endl;
	return 0;
}
void print_string(char_deque  deq){
	ostream_iterator<char>output(cout);
	cout<<"���ɵ��ַ����ǣ�";
	copy(deq.begin(),deq.end(),output);
}
