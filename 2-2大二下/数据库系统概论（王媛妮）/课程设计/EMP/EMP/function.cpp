#include "pch.h"
#include <iostream>
using namespace std;

const char *DBHOST = "localhost";	//���ݿ�����
const char *DBUSER = "root";		//���ݿ��û���
const char *DBPWD = "520493";		//���ݿ�����
const char *DBNAME = "EMP";			//���ݿ�����

MYSQL mysql;
MYSQL_RES *result;
MYSQL_ROW sql_row;
MYSQL_FIELD *fd;

void query()
{
	int func;
	cout << "===============" << endl;
	cout << "1.��ѯѧ����Ϣ" << endl;
	cout << "2.��ѯ�γ���Ϣ" << endl;
	cout << "3.��ѯѧ���ɼ�" << endl;
	cout << "4.��ѯѧ���ܷ�" << endl;
	cout << "===============" << endl;

	cout << "ѡ��Ҫ��ѯ����Ϣ��";
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
	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	unsigned int num_fields;	//����
	unsigned int num_rows;		//����

	const char *sql = "SELECT * FROM emp.student";
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "��ѯʧ�ܻ���ΪNULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//ָ���ѯ��������
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "������" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//��ӡ����
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(14) << field->name;
			}
			cout << endl;

			//��ӡ����
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

	if (result != NULL) mysql_free_result(result);//�ͷŽ����Դ  
	mysql_close(&mysql);//�ر�MySQL����  
}

//��ѯ�γ���Ϣ
void queryCou()
{
	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	unsigned int num_fields;	//����
	unsigned int num_rows;		//����

	const char *sql = "SELECT * FROM emp.course";
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "��ѯʧ�ܻ���ΪNULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//ָ���ѯ��������
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "������" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//��ӡ����
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(20) << field->name;
			}
			cout << endl;

			//��ӡ����
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

	if (result != NULL) mysql_free_result(result);//�ͷŽ����Դ  
	mysql_close(&mysql);//�ر�MySQL����  
}

void queryGra()
{
	int sno;
	cout << "����Ҫ��ѯ�ɼ���ѧ����ѧ�ţ�";
	cin >> sno;

	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	unsigned int num_fields;	//����
	unsigned int num_rows;		//����

	string strsql = "SELECT sc.Cno,Cname,Grade FROM emp.sc,emp.course WHERE (sc.Sno = " + to_string(sno) + " AND sc.Cno = course.Cno )";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "��ѯʧ�ܻ���ΪNULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//ָ���ѯ��������
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "������" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//��ӡ����
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(20) << field->name;
			}
			cout << endl;

			//��ӡ����
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

	if (result != NULL) mysql_free_result(result);//�ͷŽ����Դ  
	mysql_close(&mysql);//�ر�MySQL����
}

void queryTotalGrade()
{
	int sno;
	cout << "����Ҫ��ѯ�ֵܷ�ѧ����ѧ�ţ�";
	cin >> sno;

	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n",
			mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	unsigned int num_fields;	//����
	unsigned int num_rows;		//����

	string strsql = "SELECT student.Sno,Sname,SUM(Grade) FROM emp.sc,emp.student WHERE (sc.Sno = " + to_string(sno) + " AND student.Sno=sc.Sno)";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;

	if (mysql_query(&mysql, sql))
	{
		// error
		cout << "��ѯʧ�ܻ���ΪNULL" << endl;
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(&mysql);	//ָ���ѯ��������
		if (result)  // there are rows
		{
			num_fields = mysql_field_count(&mysql);
			cout << "������" << num_fields << endl;
			// retrieve rows, then call mysql_free_result(result)

			//��ӡ����
			MYSQL_FIELD *field;
			while ((field = mysql_fetch_field(result)))
			{
				//printf("field name %s\n", );
				cout << std::left;
				cout << setw(20) << field->name;
			}
			cout << endl;

			//��ӡ����
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

	if (result != NULL) mysql_free_result(result);//�ͷŽ����Դ  
	mysql_close(&mysql);//�ر�MySQL����
}

//���빦�ܶ����˵�
void insert()
{
	int func;
	cout << "===============" << endl;
	cout << "1.����ѧ����Ϣ" << endl;
	cout << "2.����γ���Ϣ" << endl;
	cout << "===============" << endl;

	cout << "ѡ��Ҫ�������Ϣ��";
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
	int stuid;			//ѧ��
	string stuname;		//����
	char stusex[4];		//�Ա�
	int stuage;			//����
	char studept[2];	//����ϵ

	cout << "����ѧ�������Ϣ��" << endl;
	cout << "ѧ�ţ�";
	cin >> stuid;
	cout << "������";
	cin >> stuname;
	cout << "�Ա�";
	cin >> stusex;
	cout << "���䣺";
	cin >> stuage;
	cout << "����ϵ��";
	cin >> studept;

	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	string strsql = "INSERT INTO emp.student (Sno, Sname, Ssex, Sage, Sdept) VALUES (" + to_string(stuid) + ",'" + stuname + "','" + stusex + "','" + to_string(stuage) + "','" + studept + "');";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "ѧ��" << stuname << "����Ϣ�Ѳ���" << endl;
	else
		cout << "ѧ��" << stuname << "����Ϣ����ʧ��" << endl;

	mysql_close(&mysql);
}

void insertCou()
{
	int cid;			//�γ̺�
	string cname;		//�γ���
	int cpid;			//���п�
	int ccredit;		//ѧ��

	cout << "����γ������Ϣ��" << endl;
	cout << "�γ̺ţ�";
	cin >> cid;
	cout << "�γ�����";
	cin >> cname;
	cout << "���пΣ�";
	cin >> cpid;
	cout << "ѧ�֣�";
	cin >> ccredit;

	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	string strsql = "INSERT INTO emp.course (Cno,Cname,Cpno,Ccredit) VALUES (" + to_string(cid) + ",'" + cname + "'," + to_string(cpid) + "," + to_string(ccredit) + ");";
	cout << strsql << endl;
	const char *sql = strsql.c_str();
	cout << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "�γ�" << cname << "����Ϣ�Ѳ���" << endl;
	else
		cout << "�γ�" << cname << "����Ϣ����ʧ��" << endl;

	mysql_close(&mysql);
}

void del()
{
	int func;
	cout << "===============" << endl;
	cout << "1.��ѧ������ɾ��" << endl;
	cout << "2.�ӿγ̱���ɾ��" << endl;
	cout << "===============" << endl;

	cout << "ѡ��Ҫɾ������Ϣ��";
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
	cout << "����Ҫɾ����ѧ����ѧ�ţ�";
	cin >> stuid;
	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	string strsql = "DELETE FROM emp.student WHERE (Sno = " + to_string(stuid) + ")";
	cout << "string�ַ�����" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*�ַ�����" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "ѧ��" << stuid << "����Ϣ��ɾ��" << endl;
	else
		cout << "ѧ��" << stuid << "����Ϣɾ��ʧ��" << endl;

	mysql_close(&mysql);
}

void delFromCou()
{
	int cid;
	cout << "����Ҫɾ���γ̵Ŀγ̺ţ�";
	cin >> cid;
	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	string strsql = "DELETE FROM emp.course WHERE (Cno = " + to_string(cid) + ")";
	cout << "string�ַ�����" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*�ַ�����" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "�γ�" << cid << "����Ϣ��ɾ��" << endl;
	else
		cout << "�γ�" << cid << "����Ϣɾ��ʧ��" << endl;

	mysql_close(&mysql);
}

void update()
{
	int func;
	cout << "===============" << endl;
	cout << "1.����ѧ����Ϣ" << endl;
	cout << "2.���¿γ���Ϣ" << endl;
	cout << "===============" << endl;

	cout << "��ѡ��Ҫ���µ���Ϣ��";
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
	cout << "����Ҫ������Ϣ��ѧ����ѧ�ţ�";
	cin >> sid;

	string sname;		//����
	char ssex[4];		//�Ա�
	int sage;			//����
	char sdept[2];		//����ϵ

	cout << "����Ҫ���µ���Ϣ��" << endl;
	cout << "������";
	cin >> sname;
	cout << "�Ա�";
	cin >> ssex;
	cout << "���䣺";
	cin >> sage;
	cout << "����ϵ��";
	cin >> sdept;

	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	string strsql = "UPDATE emp.student SET Sname = '"+sname+"',Ssex = '"+ssex+"',Sage = '"+to_string(sage)+"',Sdept = '"+sdept+"' WHERE(Sno = '"+to_string(sid)+"')";
	cout << "string�ַ�����" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*�ַ�����" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "ѧ��" << sid << "����Ϣ�Ѹ���" << endl;
	else
		cout << "ѧ��" << sid << "����Ϣ����ʧ��" << endl;

	mysql_close(&mysql);
}

void updateCou()
{
	int cid;
	cout << "����Ҫ������Ϣ�Ŀγ̵Ŀγ̺ţ�";
	cin >> cid;

	string cname;		//�γ���
	int cpid;			//���п�
	int ccredit;		//ѧ��

	cout << "����Ҫ���µ���Ϣ��" << endl;
	cout << "�γ�����";
	cin >> cname;
	cout << "���пΣ�";
	cin >> cpid;
	cout << "ѧ�֣�";
	cin >> ccredit;

	//�������ݿ�
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, DBHOST, DBUSER, DBPWD, DBNAME, 0, NULL, 0))
	{
		fprintf(stderr, "���ݿ�����ʧ��: Error: %s\n", mysql_error(&mysql));
	}
	else
		cout << "���ݿ�������" << endl;

	string strsql = "UPDATE emp.course SET Cname = '" + cname + "',Cpno = '" + to_string(cpid) + "',Ccredit = '" + to_string(ccredit) + "' WHERE(Cno = '" + to_string(cid) + "')";
	cout << "string�ַ�����" << strsql << endl;
	const char *sql = strsql.c_str();
	cout << "const char*�ַ�����" << sql << endl;
	int res = mysql_query(&mysql, sql);

	my_ulonglong affected_row = mysql_affected_rows(&mysql);
	printf("%d rows affected.\n", (int)affected_row);

	if (!res)
		cout << "�γ�" << cid << "����Ϣ�Ѹ���" << endl;
	else
		cout << "�γ�" << cid << "����Ϣ����ʧ��" << endl;

	mysql_close(&mysql);
}

