// EMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int func;
	do
	{
		cout << endl;
		cout << "======EMP======" << endl;
		cout << "     1.查询" << endl;
		cout << "     2.插入" << endl;
		cout << "     3.删除" << endl;
		cout << "     4.修改" << endl;
		cout << "     0.退出" << endl;
		cout << "===============" << endl;
		cout << "请选择要执行的功能：";
	label:cin >> func;
		if (func >= 0 && func <= 4)
		{
			if (func == 1)
				query();
			if (func == 2)
				insert();
			if (func == 3)
				del();
			if (func == 4)
				update();
		}
		else
		{
			cout << "输入有误，请重新输入：";
			goto label;
		}
	} while (func);
	return 0;
}
