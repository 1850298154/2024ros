#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // 创建共享内存段
    key = ftok("/tmp", 'R');  // 生成一个唯一的key
    shmid = shmget(key, 1024, IPC_CREAT | 0666);  // 创建一个共享内存段，大小为1024字节 //<sys/shm.h>

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // 将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, NULL, 0);  //<sys/shm.h>
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // 写入共享内存
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = 0;

    // 从共享内存读取数据并输出
    s = shm;
    while (*s != 0) {
        putchar(*s++);
    }
    putchar('\n');

    // 分离共享内存
    shmdt(shm); //<sys/shm.h>

    return 0;
}
