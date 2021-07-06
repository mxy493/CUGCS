//【例5.12】判断用户输入的字符串是否为回文。回文是指顺读和反读都一样的串，这里不分大小写，
//并滤去所有非字母字符，如：Madam,I'm Adam.和Golf,No Sir,prefer prison flog!都是回文。
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void swap(char&,char&);           //交换两个字符
string reverse(const string&);     //返回反转的字符串
string remove_punct(const string&,const string&);
  //将第一个字符串中所包含的与第二个字符串中相同的字符删去
string make_lower(const string&);  //所有大写改为小写
bool is_pal(const string&);        //判断是否回文

int main(){
	string str;
	cout<<"请输入需判断是否为回文的字符串，以回车结束。\n";
	getline(cin,str);
	if(is_pal(str)) cout<<str<<"是回文。\n";
	else  cout<<str<<"不是回文。\n";
	return 0;
}

void swap(char& ch1,char& ch2){
	char temp=ch1;
	ch1=ch2;
	ch2=temp;
}
string reverse(const string& s){
	int start=0,end=s.length();
	string temp(s);
	while(start<end){
		end--;
		swap(temp[start],temp[end]);
		start++;
	}
	return temp;
}
string remove_punct(const string& s,const string& punct){
	string no_punct;                     //放置处理后的字符串
	int i,s_length=s.length(),p_length=punct.length();
	for(i=0;i<s_length;i++){
		string a_ch=s.substr(i,1);       //单字符string
		int location=punct.find(a_ch,0); //从头查找a_ch在punct中出现的位置
		if(location<0||location>=p_length)
			no_punct=no_punct+a_ch;//punct中无a_ch,a_ch拷入新串
	}
	return  no_punct;
}
string make_lower(const string& s){
	string temp(s);
	int i,s_length=s.length();
	for(i=0;i<s_length;i++) temp[i]=tolower(s[i]);
	return temp;
}
bool is_pal(const string& s){
	string punct(",;:.?'\" ");           //包括空格符
	string str(make_lower(s));
	str=remove_punct(str,punct);
	return str==reverse(str);
}
