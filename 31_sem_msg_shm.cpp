#include <stdio.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>

#include <unistd.h>

#include <sys/wait.h>


/*
Child process reads from shared memory: Hello from parent process!
Child process receives message: Hello from parent process!
*/

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
        char* sharedMemory = (char*)shmat(sharedMemoryId, NULL, 0);
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
        // 父进程 pid >0 为 子进程的 pid

        // 写入共享内存
        char* sharedMemory = (char*)shmat(sharedMemoryId, NULL, 0);
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