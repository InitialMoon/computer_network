#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h> // 定以了系统编程中用到的一些数据类型
#include <sys/wait.h>
#include <my_daemon.h>

void parent_task() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("%d+%d+1120213081+main\n", pid, ppid);
    sleep(5);
}

void child_task() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = getpid();
        pid_t ppid = getppid();
        printf("%d+%d+1120213081+sub\n", pid, ppid);
        sleep(25);
    }
}

int main() {
    my_daemon();
    pid_t pid = -1;
    for (int i = 0; i < 10; i++) {
        pid = fork();
        if (pid == -1) {
            perror("fork failed");
            return 1;
        }
        if (pid == 0) {
            child_task();
            return 0;
        }
        sleep(3);
    }
    if (pid > 0) {
        while (1) {
            int status;
            pid_t child_pid = waitpid(-1, &status, WNOHANG); // -1 means wait for any child
            if (child_pid > 0) {
                // Child process has finished
                if (WIFEXITED(status)) {
                    printf("Child process %ld exited normally\n", (long)child_pid);
                } else if (WIFSIGNALED(status)) {
                    printf("Child process %ld was terminated by a signal\n",
                    (long)child_pid);
                } else if (WIFSTOPPED(status)) {
                    printf("Child process %ld was stopped\n", (long)child_pid);
                }
            }
            parent_task();
        }
    }
}
