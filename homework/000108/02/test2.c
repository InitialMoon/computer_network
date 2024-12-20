// 02/test2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "common/my_daemon.h"  // 引入 my_daemon 函数

int main() {
    // 将进程转为守护进程
    my_daemon();

    // 模拟学号和姓名
    const char *student_id = "2023123456";
    const char *name = "张三";

    // 每 5 秒打印一次学号和姓名
    while (1) {
        sleep(5);
        printf("学号: %s 姓名: %s\n", student_id, name);
    }

    return 0;
}
