#include <iostream>
#include <cstring>
#include <stdio.h>
#include <malloc.h>

#define max 10000
using namespace std;

typedef struct tag_pcb
{
	char name[8];
	int need;
	int turn;
	int wait;
	struct tag_pcb *next;
} PCB;			//进程控制块

PCB *RQ1, *RQ2;
int mclock = 0;

int main()
{
	PCB *p, *q, *s = NULL;
	int timeslice = 7;		//时间片
	int n, m = 0;
	char RQ1name[99][99] = {"p1", "p2", "p3", "p4", "p5"};
	char RQ2name[99][99] = {"p6", "p7", "p8", "p9", "p10"};
	int RQ1need[] = {16, 11, 14, 13, 15};			//RQ1运行时间
	int RQ1wait[] = {6, 5, 4, 3, 2};				//RQ1已等待时间
	int RQ2need[] = {21, 18, 10, 7, 14};			//RQ2运行时间
	int RQ2wait[] = {1, 2, 3, 4, 5};				//RQ2已等待时间
	RQ1 = (PCB *)malloc(sizeof(PCB));				//申请一块连续的指定大小的内存块区域
	strcpy(RQ1->name, RQ1name[0]);
	RQ1->next = NULL;
	p = RQ1;
	int i;
	RQ1->need = RQ1need[0];
	RQ1->turn = RQ1wait[0];
	for (i = 1; i < 5; i++)
	{
		q = (PCB *)malloc(sizeof(PCB));
		strcpy(q->name, RQ1name[i]);
		q->need = RQ1need[i];
		q->turn = RQ1wait[i];
		p->next = q;
		q->next = NULL;
		p = p->next;
	}
	RQ2 = (PCB *)malloc(sizeof(PCB));
	strcpy(RQ2->name, RQ2name[0]);
	RQ2->need = RQ2need[0];
	RQ2->turn = RQ2wait[0];
	RQ2->next = NULL;
	p = RQ2;
	for (i = 1; i < 5; i++)
	{
		q = (PCB *)malloc(sizeof(PCB));
		strcpy(q->name, RQ2name[i]);
		q->need = RQ2need[i];
		q->turn = RQ2wait[i];
		p->next = q;
		q->next = NULL;
		p = p->next;
	}
	p = RQ1;
	int x = 0;
	while (p != NULL)
	{
		while (p != NULL)
		{
			q = p;
			while (q->next != NULL)
				q = q->next;
			if (p->need > timeslice)
			{
				mclock = mclock + timeslice;
				p->need -= timeslice;
				if (s != NULL)
					s->next = p->next;
				q->next = p;
				p = p->next;
				q->next->next = NULL;
			}
			else
			{
				x++;
				mclock = mclock + p->need;
				p->need = 0;
				p->turn = p->turn + mclock;
				if (x == 1)
					RQ1 = p;
				s = p;
				p = p->next;
			}
		}
		while (p != NULL && p->need == 0)
			p = p->next;
	}
	for (i = 0; i < 5; i++)
	{
		q = RQ2;
		p = (PCB *)malloc(sizeof(PCB));
		p->need = max;
		p->next = NULL;
		while (q != NULL)
		{
			if (q->need != 0 && q->need < p->need)
				p = q;
			q = q->next;
		}
		mclock = mclock + p->need;
		p->turn = p->turn + mclock;
		p->need = 0;
	}
	q = RQ1;
	cout << "RQ1:" << endl;
	while (q != NULL)
	{
		cout << q->name << "=" << q->turn << " ,";
		q = q->next;
	}
	cout << endl;
	q = RQ2;
	cout << "RQ2:" << endl;
	while (q != NULL)
	{
		cout << q->name << "=" << q->turn << " ,";
		q = q->next;
	}
}