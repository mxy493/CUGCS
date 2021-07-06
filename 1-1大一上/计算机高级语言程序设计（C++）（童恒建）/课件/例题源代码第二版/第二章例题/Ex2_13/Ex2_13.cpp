/*【例2.13】输入一段文本，统计文本的行数、单词数及字符数。假定单词之间以空格或跳格或换行符间隔，
假定文本没有空行。
*/

#include<iostream>
using namespace std;

int main(){
	char ch;
	int nline=0,nword=0,nch=0;                    //字符包括标点
	int isword=0;
	cout<<"输入一段文本（无空行）："<<endl;
	do{
		ch=cin.get();
		if(ch=='\n')  nline++;						//遇换行符行数+1
		if(ch!=' '&& ch!='\t'&&ch!='\n'&&ch!=EOF){  //读到非间隔符
			if(!isword)  nword++;					//在单词的起始处给单词数+1
			nch++;								//字符数加+1
			isword=1;
		}
		else  isword=0;							//读到间隔符
	} while(ch!=EOF);							//读到文本结束符为止
	cout<<"行数："<<nline<<endl;		
	cout<<"单词数："<<nword<<endl;
	cout<<"字符数："<<nch<<endl;
	return 0;
}
