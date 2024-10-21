以下是一个示例，演示了如何使用`sys/sem.h`库在两个进程之间进行同步和互斥操作：

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sem.h>

// 定义信号量的初始值
#define SEM_INIT_VALUE 1

int main() {
    // 创建一个信号量集合
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // 设置信号量的初始值
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;
    arg.val = SEM_INIT_VALUE;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");
        exit(1);
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // 子进程
        printf("Child process is running.\n");

        // 对信号量进行P操作（等待）
        struct sembuf sb;
        sb.sem_num = 0;
        sb.sem_op = -1;
        sb.sem_flg = 0;
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        // 在临界区内进行操作
        printf("Child process is in the critical section.\n");
        sleep(2);  // 模拟操作

        // 对信号量进行V操作（释放）
        sb.sem_op = 1;
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        printf("Child process exits.\n");
    } else {
        // 父进程
        printf("Parent process is running.\n");

        // 对信号量进行P操作（等待）
        struct sembuf sb;
        sb.sem_num = 0;
        sb.sem_op = -1;
        sb.sem_flg = 0;
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        // 在临界区内进行操作
        printf("Parent process is in the critical section.\n");
        sleep(2);  // 模拟操作

        // 对信号量进行V操作（释放）
        sb.sem_op = 1;
        if (semop(semid, &sb, 1) == -1) {
            perror("semop");
            exit(1);
        }

        printf("Parent process exits.\n");
    }

    // 删除信号量集合
    if (semctl(semid, 0, IPC_RMID, arg) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}
```

在这个示例中，首先创建了一个信号量集合，并初始化为初始值`SEM_INIT_VALUE`。然后创建了一个子进程，父进程和子进程分别执行不同的操作。在进入临界区前，每个进程都进行了P操作（等待）。在临界区内进行操作时，由于信号量的值为1，所以两个进程可以顺序地进入临界区。最后，在临界区操作完成后，每个进程都进行了V操作（释放）。最后，删除了信号量集合。

需要注意的是，这只是一个示例，实际应用中，可能需要根据具体的需求进行相应的修改和扩展。