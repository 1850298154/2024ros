#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include "sys/sem.h"
#include "sys/msg.h"
#include "sys/shm.h"


/*
Hello, World!
Copied string: Hello
host_PC value: 12345678
host_PC value: 0x12345678
host_PC value low[0]: 0x78
Network value: 78563412
Network value: 0x78563412
Network value low[0]: 0x12
Parent process
Child process
*/

// 使用signal.h库中的signal函数注册信号处理函数
void signalHandler(int signal) {
    printf("Received signal: %d\n", signal);
}

int main() {
    // 使用stdio.h库中的printf函数打印输出
    printf("Hello, World!\n");

    // 使用stdlib.h库中的malloc函数动态分配内存
    int* numbers = (int*)malloc(5 * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 使用string.h库中的strcpy函数拷贝字符串
    char source[] = "Hello";
    char destination[10];
    strcpy(destination, source);
    printf("Copied string: %s\n", destination);

    // 使用arpa/inet.h库中的htonl函数将主机字节序转换为网络字节序
    unsigned int hostValue = 0x12345678;
    printf("host_PC value: %x\n", hostValue);
    printf("host_PC value: %#x\n", hostValue);
    printf("host_PC value low[0]: %#x\n", *(char*)(&hostValue));
    unsigned int networkValue = htonl(hostValue);
    printf("Network value: %x\n", networkValue);
    printf("Network value: %#x\n", networkValue);
    printf("Network value low[0]: %#x\n", *(char*)(&networkValue));

    // 使用unistd.h库中的fork函数创建子进程
    pid_t childPid = fork();
    if (childPid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (childPid == 0) {
        printf("Child process\n");
        // 子进程执行的代码
    } else {
        printf("Parent process\n");
        // 父进程执行的代码
    }


    signal(SIGINT, signalHandler);

    // 使用sys/sem.h库中的信号量函数进行进程间同步和互斥操作
    int semaphoreId = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semaphoreId == -1) {
        printf("Semaphore creation failed.\n");
        return 1;
    }

    // 使用sys/msg.h库中的消息队列函数进行进程间通信
    int messageQueueId = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (messageQueueId == -1) {
        printf("Message queue creation failed.\n");
        return 1;
    }

    // 使用sys/shm.h库中的共享内存函数进行进程间共享内存操作
    int sharedMemoryId = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (sharedMemoryId == -1) {
        printf("Shared memory creation failed.\n");
        return 1;
    }

    return 0;
}