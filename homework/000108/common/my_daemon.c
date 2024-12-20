// common/my_daemon.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void redirect() {
    // 将标准输出重定向到 output.txt 文件（追加模式）
    FILE *file = freopen("output.txt", "a", stdout);
    if (file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // 将标准错误输出重定向到同一个文件
    file = freopen("output.txt", "a", stderr);
    if (file == NULL) {
        perror("Error opening error file");
        exit(1);
    }

    // 现在，stdout 和 stderr 都会输出到 output.txt 文件
    printf("This is standard output\n");
    fprintf(stderr, "This is an error message\n");
}


void my_daemon() {
    pid_t pid;

    // 创建一个子进程
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    // 如果是父进程，则退出
    if (pid > 0) {
        exit(0);
    }

    // 创建一个新的会话
    if (setsid() < 0) {
        perror("setsid failed");
        exit(1);
    }

    // 设置文件权限掩码
    umask(0);

    // 改变工作目录，防止守护进程占用目录
    if (chdir("/") < 0) {
        perror("chdir failed");
        exit(1);
    }

    redirect();
}
