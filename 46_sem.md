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



# 参数
在上面的示例程序中，使用到了以下几个函数：

1. `semget`：创建或打开一个信号量集合。

   ```c
   int semget(key_t key, int nsems, int semflg);
   ```

   - 参数`key`是用于指定信号量集合的标识符。可以使用`ftok`函数生成。
   - 参数`nsems`表示信号量集合中包含的信号量数量。
   - 参数`semflg`用于指定信号量集合的属性，可以是`IPC_CREAT`（创建）或`IPC_EXCL`（如果集合已经存在则出错），还可以使用文件访问权限标志（例如`0666`）。

   函数返回值是一个整数，表示信号量集合的ID。如果出错，则返回-1。

2. `semctl`：对指定的信号量集合进行控制操作。

   ```c
   int semctl(int semid, int semnum, int cmd, union semun arg);
   ```

   - 参数`semid`是信号量集合的ID。
   - 参数`semnum`是用于指定所操作的信号量的编号。一般情况下，只有一个信号量，所以该参数为0。
   - 参数`cmd`是所需执行的命令。可以是`SETVAL`（设置信号量的值）、`GETVAL`（获取信号量的当前值）等。
   - 参数`arg`是一个联合体，用于传递命令所需的参数。具体的参数类型和含义依赖于`cmd`的取值。

   函数返回值依赖于`cmd`的取值。如果出错，则返回-1。

3. `semop`：对指定的信号量进行P/V操作（等待/释放）。

   ```c
   int semop(int semid, struct sembuf *sops, unsigned nsops);
   ```

   - 参数`semid`是信号量集合的ID。
   - 参数`sops`是一个指向信号量操作的结构体数组的指针，每个元素包含了信号量的编号、操作类型（P或V）和操作标志。一般情况下，只有一个操作，所以该数组只有一个元素。
   - 参数`nsops`是指定需要执行的操作的数量，一般情况下为1。

   函数返回值为0表示操作成功，否则表示操作失败。

4. `ftok`：生成用于创建或打开IPC对象（如信号量集合、消息队列、共享内存区域）的key值。

   ```c
   key_t ftok(const char *pathname, int proj_id);
   ```

   - 参数`pathname`是一个字符串，用于指定一个存在的文件路径。
   - 参数`proj_id`是一个整数，通常设置为0。

   函数返回值是一个key值，可以用于创建或打开IPC对象。如果出错，则返回-1。

以上是关于示例程序中使用到的主要函数的说明，还有其他的一些函数如`fork`、`printf`、`sleep`等，这里不再赘述。