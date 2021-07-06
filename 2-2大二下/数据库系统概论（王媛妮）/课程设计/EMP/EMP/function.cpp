#include "pch.h"
#include <iostream>
using namespace std;

const char *DBHOST = "localhost";	//数据库主机
const char *DBUSER = "root";		//数据库用户名
const char *DBPWD = "520493";		//数据库密码
const char *DBNAME = "EMP";			//数据库名字

MYSQL mysql;
MYSQL_RES *result;
MYSQL_ROW sql_row;
MYSQL_FIELD *fd;

void query()
{
	int func;
	cout << "===============" << endl;
	cout << "1.查询学生信息" << endl;
	cout << "2.查询课程信息" << endl;
	cout << "3.查询学生成绩" << endl;
	cout << "4.查询学生总分" << endl;
	cout << "===============" << endl;

	cout << "选择要查询的信息：";
	cin >> func;
	if (func >= 0 && func <= 4)
	{
		if (func == 1)
			queryStu();
		if (func == 2)
			queryCou();
		if (func == 3)
			queryGra();
		if (func == 4)
			queryTotalGrade();
	}
}

void queryStu()
{
	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	unsigned int num_fields;	//列数
	unsigned int num_rows;		//行数

	const char *sql = "SELECT * FROM emp.student";
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "查询失败或结果为NULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//指向查询到的数据
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "列数：" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//打印列名
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(14) << field->name;
			}
			cout << endl;

			//打印数据
			while (sql_row = mysql_fetch_row(result))
			{
				for (int i = 0; i < num_fields; i++)
				{
					cout << setw(14) << sql_row[i];
				}
				cout << endl;
			}
		}
		else  // mysql_store_result() returned nothing; should it have?
		{
			if (mysql_field_count(&mysql) == 0)
			{
				// query does not return data
				// (it was not a SELECT)
				num_rows = mysql_affected_rows(&mysql);
			}
			else // mysql_store_result() should have returned data
			{
				fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
			}
		}
	}

	if (result != NULL) mysql_free_result(result);//释放结果资源  
	mysql_close(&mysql);//关闭MySQL连接  
}

//查询课程信息
void queryCou()
{
	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	unsigned int num_fields;	//列数
	unsigned int num_rows;		//行数

	const char *sql = "SELECT * FROM emp.course";
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "查询失败或结果为NULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//指向查询到的数据
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "列数：" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//打印列名
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(20) << field->name;
			}
			cout << endl;

			//打印数据
			while (sql_row = mysql_fetch_row(result))
			{
				for (int i = 0; i < num_fields; i++)
				{
					if (sql_row[i] == NULL)
						cout << setw(20) << "NULL";
					else
						cout << setw(20) << sql_row[i];
				}
				cout << endl;
			}
		}
		else  // mysql_store_result() returned nothing; should it have?
		{
			if (mysql_field_count(&mysql) == 0)
			{
				// query does not return data
				// (it was not a SELECT)
				num_rows = mysql_affected_rows(&mysql);
			}
			else // mysql_store_result() should have returned data
			{
				fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
			}
		}
	}

	if (result != NULL) mysql_free_result(result);//释放结果资源  
	mysql_close(&mysql);//关闭MySQL连接  
}

void queryGra()
{
	int sno;
	cout << "输入要查询成绩的学生的学号：";
	cin >> sno;

	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	unsigned int num_fields;	//列数
	unsigned int num_rows;		//行数

	string strsql = "SELECT sc.Cno,Cname,Grade FROM emp.sc,emp.course WHERE (sc.Sno = " + to_string(sno) + " AND sc.Cno = course.Cno )";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "查询失败或结果为NULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//指向查询到的数据
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "列数：" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//打印列名
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(20) << field->name;
			}
			cout << endl;

			//打印数据
			while (sql_row = mysql_fetch_row(result))
			{
				for (int i = 0; i < num_fields; i++)
				{
					cout << setw(20) << sql_row[i];
				}
				cout << endl;
			}
		}
		else  // mysql_store_result() returned nothing; should it have?
		{
			if (mysql_field_count(&mysql) == 0)
			{
				// query does not return data
				// (it was not a SELECT)
				num_rows = mysql_affected_rows(&mysql);
			}
			else // mysql_store_result() should have returned data
			{
				fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
			}
		}
	}

	if (result != NULL) mysql_free_result(result);//释放结果资源  
	mysql_close(&mysql);//关闭MySQL连接
}

void queryTotalGrade()
{
	int sno;
	cout << "输入要查询总分的学生的学号：";
	cin >> sno;

	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	unsigned int num_fields;	//列数
	unsigned int num_rows;		//行数

	string strsql = "SELECT student.Sno,Sname,SUM(Grade) FROM emp.sc,emp.student WHERE (sc.Sno = " + to_string(sno) + " AND student.Sno=sc.Sno)";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "查询失败或结果为NULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//指向查询到的数据
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "列数：" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//打印列名
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(20) << field->name;
			}
			cout << endl;

			//打印数据
			while (sql_row = mysql_fetch_row(result))
			{
				for (int i = 0; i < num_fields; i++)
				{
					cout << setw(20) << sql_row[i];
				}
				cout << endl;
			}
		}
		else  // mysql_store_result() returned nothing; should it have?
		{
			if (mysql_field_count(&mysql) == 0)
			{
				// query does not return data
				// (it was not a SELECT)
				num_rows = mysql_affected_rows(&mysql);
			}
			else // mysql_store_result() should have returned data
			{
				fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
			}
		}
	}

	if (result != NULL) mysql_free_result(result);//释放结果资源  
	mysql_close(&mysql);//关闭MySQL连接
}

//插入功能二级菜单
void insert()
{
	int func;
	cout << "===============" << endl;
	cout << "1.插入学生信息" << endl;
	cout << "2.插入课程信息" << endl;
	cout << "===============" << endl;

	cout << "选择要插入的信息：";
	cin >> func;
	if (func >= 0 && func <= 4)
	{
		if (func == 1)
			insertStu();
		else if (func == 2)
			insertCou();
	}
}

void insertStu()
{
	int stuid;			//学号
	string stuname;		//姓名
	char stusex[4];		//性别
	int stuage;			//年龄
	char studept[2];	//所在系

	cout << "输入学生相关信息：" << endl;
	cout << "学号：";
	cin >> stuid;
	cout << "姓名：";
	cin >> stuname;
	cout << "性别：";
	cin >> stusex;
	cout << "年龄：";
	cin >> stuage;
	cout << "所在系：";
	cin >> studept;

	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	string strsql = "INSERT INTO emp.student (Sno, Sname, Ssex, Sage, Sdept) VALUES (" + to_string(stuid) + ",'" + stuname + "','" + stusex + "','" + to_string(stuage) + "','" + studept + "');";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "学生" << stuname << "的信息已插入" << endl;
	else
		cout << "学生" << stuname << "的信息插入失败" << endl;

	mysql_close(&mysql);
}

void insertCou()
{
	int cid;			//课程号
	string cname;		//课程名
	int cpid;			//先行课
	int ccredit;		//学分

	cout << "输入课程相关信息：" << endl;
	cout << "课程号：";
	cin >> cid;
	cout << "课程名：";
	cin >> cname;
	cout << "先行课：";
	cin >> cpid;
	cout << "学分：";
	cin >> ccredit;

	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	string strsql = "INSERT INTO emp.course (Cno,Cname,Cpno,Ccredit) VALUES (" + to_string(cid) + ",'" + cname + "'," + to_string(cpid) + "," + to_string(ccredit) + ");";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "课程" << cname << "的信息已插入" << endl;
	else
		cout << "课程" << cname << "的信息插入失败" << endl;

	mysql_close(&mysql);
}

void del()
{
	int func;
	cout << "===============" << endl;
	cout << "1.从学生表中删除" << endl;
	cout << "2.从课程表中删除" << endl;
	cout << "===============" << endl;

	cout << "选择要删除的信息：";
	cin >> func;
	if (func >= 0 && func <= 4)
	{
		if (func == 1)
			delFromStu();
		if (func == 2)
			delFromCou();
	}
}

void delFromStu()
{
	int stuid;
	cout << "输入要删除的学生的学号：";
	cin >> stuid;
	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	string strsql = "DELETE FROM emp.student WHERE (Sno = " + to_string(stuid) + ")";
	cout << "string字符串：" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*字符串：" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "学生" << stuid << "的信息已删除" << endl;
	else
		cout << "学生" << stuid << "的信息删除失败" << endl;

	mysql_close(&mysql);
}

void delFromCou()
{
	int cid;
	cout << "输入要删除课程的课程号：";
	cin >> cid;
	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	string strsql = "DELETE FROM emp.course WHERE (Cno = " + to_string(cid) + ")";
	cout << "string字符串：" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*字符串：" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "课程" << cid << "的信息已删除" << endl;
	else
		cout << "课程" << cid << "的信息删除失败" << endl;

	mysql_close(&mysql);
}

void update()
{
	int func;
	cout << "===============" << endl;
	cout << "1.更新学生信息" << endl;
	cout << "2.更新课程信息" << endl;
	cout << "===============" << endl;

	cout << "请选择要更新的信息：";
	cin >> func;
	if (func >= 0 && func <= 4)
	{
		if (func == 1)
			updateStu();
		if (func == 2)
			updateCou();
	}
}

void updateStu()
{
	int sid;
	cout << "输入要更新信息的学生的学号：";
	cin >> sid;

	string sname;		//姓名
	char ssex[4];		//性别
	int sage;			//年龄
	char sdept[2];		//所在系

	cout << "输入要更新的信息：" << endl;
	cout << "姓名：";
	cin >> sname;
	cout << "性别：";
	cin >> ssex;
	cout << "年龄：";
	cin >> sage;
	cout << "所在系：";
	cin >> sdept;

	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	string strsql = "UPDATE emp.student SET Sname = '"+sname+"',Ssex = '"+ssex+"',Sage = '"+to_string(sage)+"',Sdept = '"+sdept+"' WHERE(Sno = '"+to_string(sid)+"')";
	cout << "string字符串：" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*字符串：" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "学生" << sid << "的信息已更新" << endl;
	else
		cout << "学生" << sid << "的信息更新失败" << endl;

	mysql_close(&mysql);
}

void updateCou()
{
	int cid;
	cout << "输入要更新信息的课程的课程号：";
	cin >> cid;

	string cname;		//课程名
	int cpid;			//先行课
	int ccredit;		//学分

	cout << "输入要更新的信息：" << endl;
	cout << "课程名：";
	cin >> cname;
	cout << "先行课：";
	cin >> cpid;
	cout << "学分：";
	cin >> ccredit;

	//连接数据库
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "数据库连接失败: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "数据库已连接" << endl;

	string strsql = "UPDATE emp.course SET Cname = '" + cname + "',Cpno = '" + to_string(cpid) + "',Ccredit = '" + to_string(ccredit) + "' WHERE(Cno = '" + to_string(cid) + "')";
	cout << "string字符串：" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*字符串：" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "课程" << cid << "的信息已更新" << endl;
	else
		cout << "课程" << cid << "的信息更新失败" << endl;

	mysql_close(&mysql);
}

