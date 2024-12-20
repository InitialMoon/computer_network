#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h> // define some data type used in system program e.g. pid_t
#include <my_daemon.h>

void parent_task() {
    while(1) {
        pid_t pid = getpid();
        pid_t ppid = getppid();
        printf("%d+%d+1120213039+main\n", pid, ppid);
        sleep(5);
    }
}

void child_task() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = getpid();
        pid_t ppid = getppid();
        printf("%d+%d+1120213039+sub\n", pid, ppid);
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
            break;
        }
        sleep(3);
    }
    if (pid > 0) {
        parent_task();
    }
}
