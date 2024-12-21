#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)  
{  
    pid_t pid;  
    pid = fork();  
    if (pid == 0) {  
            printf("I am child, my parent= %d, going to sleep 3s\n", getppid());  
            sleep(3);  
            printf("-------------child die--------------\n");  
    } else if (pid > 0) {  
            printf("I am parent, pid = %d, myson = %d, going to sleep 5s\n", getpid(), pid);  
            sleep(5);  
            system("ps -o pid,ppid,state,tty,command");  
    } else {  
        perror("fork");  
        return 1;  
    }  

    return 0;  
}  

// int main() {
//     pid_t pid = fork();
//     if (pid < 0) {
//         printf("fork fail\n");
//         return 1;
//     }
//     if (pid == 0) {
//         sleep(1);
//         printf("pid = 0 fork return %d\n", pid);
//         // 返回值是0的pid进入了子进程的部分执行
//     }
//     else {
//         sleep(2);
//         printf("pid > 0 fork return %d\n", pid);
//     }
// }
