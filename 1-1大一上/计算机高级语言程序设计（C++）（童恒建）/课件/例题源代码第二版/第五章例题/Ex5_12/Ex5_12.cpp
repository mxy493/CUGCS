//����5.12���ж��û�������ַ����Ƿ�Ϊ���ġ�������ָ˳���ͷ�����һ���Ĵ������ﲻ�ִ�Сд��
//����ȥ���з���ĸ�ַ����磺Madam,I'm Adam.��Golf,No Sir,prefer prison flog!���ǻ��ġ�
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void swap(char&,char&);           //���������ַ�
string reverse(const string&);     //���ط�ת���ַ���
string remove_punct(const string&,const string&);
  //����һ���ַ���������������ڶ����ַ�������ͬ���ַ�ɾȥ
string make_lower(const string&);  //���д�д��ΪСд
bool is_pal(const string&);        //�ж��Ƿ����

int main(){
	string str;
	cout<<"���������ж��Ƿ�Ϊ���ĵ��ַ������Իس�������\n";
	getline(cin,str);
	if(is_pal(str)) cout<<str<<"�ǻ��ġ�\n";
	else  cout<<str<<"���ǻ��ġ�\n";
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
	string no_punct;                     //���ô������ַ���
	int i,s_length=s.length(),p_length=punct.length();
	for(i=0;i<s_length;i++){
		string a_ch=s.substr(i,1);       //���ַ�string
		int location=punct.find(a_ch,0); //��ͷ����a_ch��punct�г��ֵ�λ��
		if(location<0||location>=p_length)
			no_punct=no_punct+a_ch;//punct����a_ch,a_ch�����´�
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
	string punct(",;:.?'\" ");           //�����ո��
	string str(make_lower(s));
	str=remove_punct(str,punct);
	return str==reverse(str);
}
