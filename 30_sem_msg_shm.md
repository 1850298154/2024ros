以下是父子进程之间使用信号量、消息队列和共享内存进行读写的示例代码：

```c
#include <stdio.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>

// 信号量操作结构体
struct sembuf semOperation;

int main() {
    // 创建信号量
    int semaphoreId = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semaphoreId == -1) {
        printf("Semaphore creation failed.\n");
        return 1;
    }

    // 创建消息队列
    int messageQueueId = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (messageQueueId == -1) {
        printf("Message queue creation failed.\n");
        return 1;
    }

    // 创建共享内存
    int sharedMemoryId = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (sharedMemoryId == -1) {
        printf("Shared memory creation failed.\n");
        return 1;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // 子进程

        // 读取共享内存中的数据
        char* sharedMemory = shmat(sharedMemoryId, NULL, 0);
        printf("Child process reads from shared memory: %s\n", sharedMemory);

        // 从消息队列接收消息
        struct {
            long messageType;
            char messageText[256];
        } message;
        msgrcv(messageQueueId, &message, sizeof(message.messageText), 1, 0);
        printf("Child process receives message: %s\n", message.messageText);

        // 释放共享内存
        shmdt(sharedMemory);

        // 删除信号量和消息队列
        semctl(semaphoreId, 0, IPC_RMID);
        msgctl(messageQueueId, IPC_RMID, NULL);

    } else {
        // 父进程

        // 写入共享内存
        char* sharedMemory = shmat(sharedMemoryId, NULL, 0);
        sprintf(sharedMemory, "Hello from parent process!");

        // 发送消息到消息队列
        struct {
            long messageType;
            char messageText[256];
        } message;
        message.messageType = 1;
        sprintf(message.messageText, "Hello from parent process!");
        msgsnd(messageQueueId, &message, sizeof(message.messageText), 0);

        // 等待子进程结束
        wait(NULL);

        // 释放共享内存
        shmdt(sharedMemory);

        // 删除共享内存
        shmctl(sharedMemoryId, IPC_RMID, NULL);
    }

    return 0;
}
```

以上代码演示了父子进程之间使用信号量、消息队列和共享内存进行通信的基本原理。请注意，这只是一个简单的示例，实际应用中可能需要更复杂的逻辑和错误处理。


# 参数

以下是信号量、消息队列和共享内存的基本读写函数以及其参数的说明：

1. 信号量：
   - `semget(key_t key, int nsems, int semflg)`：创建或获取一个信号量集。
     - `key`：用于标识信号量集的键值。
     - `nsems`：信号量集中的信号量数量。
     - `semflg`：标志位，用于指定信号量的权限和操作方式。
   - `semop(int semid, struct sembuf *sops, size_t nsops)`：对信号量集进行操作（如加锁、解锁）。
     - `semid`：信号量集的标识符。
     - `sops`：执行的操作数组，包含一个或多个 `struct sembuf` 结构体。
     - `nsops`：执行操作的数量。

2. 消息队列：
   - `msgget(key_t key, int msgflg)`：创建或获取一个消息队列。
     - `key`：用于标识消息队列的键值。
     - `msgflg`：标志位，用于指定消息队列的权限和操作方式。
   - `msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)`：将消息发送到消息队列。
     - `msqid`：消息队列的标识符。
     - `msgp`：指向消息缓冲区的指针。
     - `msgsz`：消息的大小。
     - `msgflg`：消息发送的标志位。
   - `msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)`：从消息队列接收消息。
     - `msqid`：消息队列的标识符。
     - `msgp`：指向消息缓冲区的指针。
     - `msgsz`：消息缓冲区的大小。
     - `msgtyp`：期望接收的消息类型。
     - `msgflg`：消息接收的标志位。

3. 共享内存：
   - `shmget(key_t key, size_t size, int shmflg)`：创建或获取一个共享内存段。
     - `key`：用于标识共享内存的键值。
     - `size`：共享内存段的大小。
     - `shmflg`：标志位，用于指定共享内存的权限和操作方式。
   - `shmat(int shmid, const void *shmaddr, int shmflg)`：将共享内存连接到进程的地址空间中。
     - `shmid`：共享内存段的标识符。
     - `shmaddr`：共享内存分配的地址。通常设置为 `NULL`，由系统自动分配。
     - `shmflg`：标志位，用于指定共享内存的连接方式。
   - `shmdt(const void *shmaddr)`：将共享内存从进程的地址空间中分离。
     - `shmaddr`：共享内存连接的地址。
   - `shmctl(int shmid, int cmd, struct shmid_ds *buf)`：对共享内存进行控制操作。
     - `shmid`：共享内存段的标识符。
     - `cmd`：控制命令，用于指定要执行的操作。
     - `buf`：`struct shmid_ds` 结构体指针，用于获取或设置共享内存的信息。

请注意，这些函数的参数还可以根据具体的需求进行进一步设置和调整。以上只是基本的参数说明，详细的使用方法和更多参数选项可以参考相关的系统调用文档或资料。


#  消息队列  ： 类型、标志
在消息队列中，每个消息都有一个类型和一个数据部分。类型是一个长整型数值，通常用来标识不同种类的消息。标记位则用来指定消息发送或接收的一些选项，如是否阻塞等。

在发送消息时，可以通过 `msgsnd` 函数的第四个参数 `msgflg` 来设置标记位。常用的标记位包括：
- `IPC_NOWAIT`：若消息队列已满则立即返回，而不是阻塞等待。
- `MSG_NOERROR`：若消息长度大于消息队列的最大容量，则截断消息而不是报错。
- `MSG_EXCEPT`：接收除指定类型以外的所有消息。

在接收消息时，也可以通过 `msgrcv` 函数的第五个参数 `msgflg` 来设置标记位。常用的标记位包括：
- `IPC_NOWAIT`：若消息队列为空则立即返回，而不是阻塞等待。
- `MSG_NOERROR`：若消息长度小于接收缓冲区的大小，则截断消息而不是报错。
- `MSG_EXCEPT`：接收除指定类型以外的所有消息。

需要注意的是，在使用标记位时应仔细考虑其影响，避免出现不可预期的后果。

# 全局系统级的id ： 
创建管道、消息队列和共享内存时返回的 ID 是全局系统级的，可以被不同进程访问。

对于管道（Pipe）来说，  *父子进程或兄弟进程*   可以通过文件描述符进行读写操作，因为它们共享同一个管道。当父进程创建一个管道时，会返回  *两个文件描述符*  ，一个用于读取，一个用于写入，这两个文件描述符都可以被父进程和子进程使用。

对于消息队列（Message Queue）来说，   *不同进程*  可以通过共享的消息队列 ID 进行消息的发送和接收。进程可以通过指定消息队列 ID 来访问同一个消息队列。消息队列 ID 是在创建消息队列时由系统生成的，并且是全局唯一的。

对于共享内存（Shared Memory）来说，  *不同进程*   可以通过共享内存的标识符（通常是由 `shmget` 函数返回的标识符）来访问同一块共享内存。多个进程可以通过该标识符将共享内存映射到各自的虚拟地址空间中进行读写操作。共享内存的标识符也是全局唯一的。

综上所述，管道、消息队列和共享内存创建时返回的 ID 是全局系统级的，可以被不同进程访问。它们提供了一种跨进程的通信方式，不仅限于亲属进程之间的通信。