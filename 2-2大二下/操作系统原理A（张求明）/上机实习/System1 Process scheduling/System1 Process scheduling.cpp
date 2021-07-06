#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct LinkNode {        //定义链表结点
	string name;         //进程名
	int need;            //需运行时间
	int turn;            //周转时间
	LinkNode* link;

	LinkNode() {};
	LinkNode(string na, int ne, int tu)
	{
		name = na;
		need = ne;
		turn = tu;
		link = NULL;
	}
};

LinkNode* RQ1, * RQ2;

int main() {
	int i = 0, j = 0;
	string A[3][5];
	string B[3][5];
	LinkNode* p, * q, * s = new LinkNode;
	int clock = 0;                 //时钟
	int pie = 7;                   //时间片

	ifstream ifile;

	ifile.open("RQ1.data");
	string sline;
	string out;
	string s1, s2, s3, s4, s5;
	while (getline(ifile, sline))
	{
		istringstream sin(sline);
		sin >> s1 >> s2 >> s3 >> s4 >> s5;
		A[i][0] = s1; A[i][1] = s2; A[i][2] = s3; A[i][3] = s4; A[i][4] = s5;
		i++;
	}
	ifile.close();

	ifile.open("RQ2.data");
	while (getline(ifile, sline))
	{
		istringstream sin(sline);
		sin >> s1 >> s2 >> s3 >> s4 >> s5;
		B[j][0] = s1; B[j][1] = s2; B[j][2] = s3; B[j][3] = s4; B[j][4] = s5;
		j++;
	}

	RQ1 = (LinkNode*)malloc(sizeof(LinkNode));          //建立RQ1链表
	if (RQ1)
	{
		string name1 = A[0][0];
		int need1 = atoi(A[1][0].c_str());
		int turn1 = atoi(A[2][0].c_str());
		RQ1 = new LinkNode(name1, need1, turn1);
		p = RQ1;
		for (int j = 1; j < 5; j++) {
			name1 = A[0][j];
			need1 = atoi(A[1][j].c_str());
			turn1 = atoi(A[2][j].c_str());
			p->link = new LinkNode(name1, need1, turn1);
			p = p->link;
		}
	}
	
	RQ2 = (LinkNode*)malloc(sizeof(LinkNode));           //建立RQ2链表
	if (RQ2)
	{
		string name2 = B[0][0];
		int need2 = atoi(B[1][0].c_str());
		int turn2 = atoi(B[2][0].c_str());
		RQ2 = new LinkNode(name2, need2, turn2);
		p = RQ2;
		for (int j = 1; j < 5; j++) {
			name2 = B[0][j];
			need2 = atoi(B[1][j].c_str());
			turn2 = atoi(B[2][j].c_str());
			p->link = new LinkNode(name2, need2, turn2);
			p = p->link;
		}
	}

	p = RQ1;
	int a = 0;
	while (p != NULL) {
		while (p != NULL && p->need > 0) {
			q = p;
			while (q->link != NULL)q = q->link;
			if (p->need > pie) {
				clock += pie;
				p->need -= pie;
				if (s != NULL) s->link = p->link;
				q->link = p;
				p = p->link;
				q->link->link = NULL;
			}
			else {
				a++;
				clock += p->need;
				p->need = 0;
				p->turn += clock;
				if (a == 1) RQ1 = p;
				s = p;
				p = p->link;
			}
		}
		while (p != NULL && p->need == 0) {
			p = p->link;
		}
	}
	for (int b = 0; b < 5; b++) {
		q = RQ2;
		p = (LinkNode*)malloc(sizeof(LinkNode));
		if (p)
		{
			p->need = 1000;
			p->link = NULL;
			while (q != NULL) {
				if (q->need != 0 && q->need < p->need) p = q;
				q = q->link;
			}
			clock += p->need;
			p->turn += clock;
			p->need = 0;
		}
	}

	p = RQ1;
	cout << "RQ1各进程运行时间" << endl;
	while (p != NULL) {
		cout << p->name << ":" << p->turn << endl;
		p = p->link;
	}
	cout << endl;
	q = RQ2;
	cout << "RQ2各进程运行时间" << endl;
	while (q != NULL) {
		cout << q->name << ":" << q->turn << endl;
		q = q->link;
	}
	return 0;
}
