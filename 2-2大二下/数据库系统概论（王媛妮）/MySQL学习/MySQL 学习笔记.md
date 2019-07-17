# MySQL 学习笔记

检查MySQL服务器是否启动：

```
ps -ef | grep mysqld
```

启动mysql服务

```
net start mysql
```

登录 MySQL

```
mysql -u root -p
```

退出 MySQL 

```
exit
\q
```

列出所有数据库：

```
show databases;
```

创建数据库：

```
create database 数据库名;
```

使用数据库 DB：

```
use DB;
```

创建表：

```
create table 表名;
```

列出所有的表：

```
show tables;
```

列出表 T 的所有列及其属性：

```
show columns from T;
```

输出表中数据：

```
SELECT * FROM 表名;
```

插入一行数据：

```
INSERT INTO 表名(列名1,列名2,...) VALUES(data1,data2,...);
```

显示表 T 的索引：

```
SHOW INDEX FROM T;
```

清空表中的行：

```
TRUNCATE 表名;
```

将结束号“;”临时改为“$$”，也可以改为其它符号：

```
DELIMITER $$
```

将结束符改回“;”：

```
DELIMITER ;
```

创建存储过程：

```
CREATE PROCEDURE 存储过程名([IN|OUT|INOUT] 参数名1 数据类型, IN var2 CHAR(4), ...)
```

- IN 输入参数：表示调用者向过程传入值（传入值可以是字面量或变量）
- OUT 输出参数：表示过程向调用者传出值(可以返回多个值)（传出值只能是变量）
- INOUT 输入输出参数：既表示调用者向过程传入值，又表示过程向调用者传出值（值只能是变量）

删除存储过程：

```
DROP PROCEDURE 存储过程名;
```

查看safe-updates模式：

```
show variables like 'SQL_SAFE_UPDATES';
```

打开(1)或关闭(0)safe-updates模式：

```
SET SQL_SAFE_UPDATES = 0;
```

