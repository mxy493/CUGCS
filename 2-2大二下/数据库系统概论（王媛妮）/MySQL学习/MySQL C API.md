mysql_real_connect()

```
MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag)
```

mysql_options()

```
int mysql_options(MYSQL *mysql, enum mysql_option option, const void *arg)
```

* Call [`mysql_options()`](https://dev.mysql.com/doc/refman/8.0/en/mysql-options.html) after [`mysql_init()`](https://dev.mysql.com/doc/refman/8.0/en/mysql-init.html) and before [`mysql_connect()`](https://dev.mysql.com/doc/refman/8.0/en/mysql-connect.html) or [`mysql_real_connect()`](https://dev.mysql.com/doc/refman/8.0/en/mysql-real-connect.html).

mysql_close()

```
void mysql_close(MYSQL *mysql)
```

