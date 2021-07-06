#!/bin/sh

function f1(){
        echo "至少输入2个参数"
        cat $1
}
function f2(){
        echo "缺少第3个参数，输出到mydoc.txt"
        cat $1 $2 > mydoc.txt
        cat mydoc.txt
}

function Usage(){
        echo "Usage:$0 <arg1> <arg2> [arg3]"
}

if [ $# -eq 0 ]; then
        Usage
elif [ $# -eq 1 ]; then
        f1 $1
elif [ $# -eq 2 ]; then
        f2 $1 $2
elif [ $# -eq 3 ]; then
        cat $1 $2 > $3
        cat $3
fi

exit 0