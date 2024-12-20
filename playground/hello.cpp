#include <stdio.h>
#include <unistd.h>
// #include <sys/type.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("fork fail\n");
        return 1;
    }
    if (pid == 0) {
        sleep(1);
        printf("pid = 0 fork return %d\n", pid);
        // 返回值是0的pid进入了子进程的部分执行
    }
    else {
        sleep(2);
        printf("pid > 0 fork return %d\n", pid);
    }
}
