### 文件结构说明

文件夹p1-p6为六个题目的源码，各文件夹内 p.cpp 文件为源码，文件 p 为可执行文件，其余 file_name.txt 为数据文件。

### 使用说明

程序编译：

确保Linux已安装g++，执行以下命令，第一步由 source.cpp 生成 obj.o，第二步由 obj.o 生成 可执行程序 exec_name。

```bash
g++ -c source.cpp -o obj.o
g++ obg.o -o exec_name
```

程序运行：

在可执行文件所在文件夹对应路径下执行如下命令。

```bash
./exec_name
```

