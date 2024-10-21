以下是一个使用sys/shm.h库提供的进程间共享内存操作函数的简单示例：

```c
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
    shmid = shmget(key, 1024, IPC_CREAT | 0666);  // 创建一个共享内存段，大小为1024字节

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // 将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, NULL, 0);
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
    shmdt(shm);

    return 0;
}
```

在这个示例中，我们首先使用ftok函数生成一个唯一的key，然后使用shmget函数创建一个共享内存段。接下来，我们使用shmat函数将共享内存连接到当前进程的地址空间，并向共享内存写入字母表。最后，我们从共享内存读取数据并输出，然后使用shmdt函数分离共享内存。

# 函数说明
在上述示例中，使用了以下几个函数：

1. `ftok`函数：用于生成一个唯一的key，作为共享内存的标识符。它接受两个参数，第一个是一个现有的路径名（通常选择一个存在的文件），第二个是一个整数值（通常是小于256的字符），用于生成唯一的key。

2. `shmget`函数：用于创建或获取共享内存段。它接受三个参数，第一个是key，第二个是共享内存的大小（以字节为单位），第三个是标志位，指定共享内存的权限和创建模式。如果共享内存已经存在，则返回共享内存的标识符；如果不存在，则根据给定的key创建新的共享内存。

3. `shmat`函数：用于将共享内存连接到当前进程的地址空间。它接受三个参数，第一个是共享内存的标识符，第二个是指定共享内存的地址（通常设置为NULL，让系统选择一个合适的地址），第三个是标志位，用于指定连接的方式。它返回一个指向共享内存段的指针。

4. `shmdt`函数：用于分离共享内存。它接受一个参数，即共享内存段的指针。调用该函数后，当前进程将不再能够访问共享内存段。

在示例中，使用`ftok`函数生成一个唯一的key，然后使用`shmget`函数创建一个大小为1024字节的共享内存段。接下来，使用`shmat`函数将共享内存连接到当前进程的地址空间，并向共享内存写入字母表。最后，使用`shmdt`函数分离共享内存。

这些函数是Linux系统提供的用于进行进程间共享内存操作的函数，通过它们可以实现进程之间的数据共享和通信。

# 两个进程读写

以下是两个进程分别启动，通过共享内存进行通信的示例：

**进程1：写入共享内存数据**

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // 创建共享内存段
    key = ftok("/tmp", 'R');
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // 将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // 写入共享内存
    s = shm;
    *s = 'H';
    s++;
    *s = 'e';
    s++;
    *s = 'l';
    s++;
    *s = 'l';
    s++;
    *s = 'o';
    s++;
    *s = '\0';

    // 分离共享内存
    shmdt(shm);

    return 0;
}
```

**进程2：读取共享内存数据**

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // 获取共享内存段
    key = ftok("/tmp", 'R');
    shmid = shmget(key, 1024, 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // 将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // 从共享内存读取数据并输出
    s = shm;
    while (*s != '\0') {
        putchar(*s);
        s++;
    }
    putchar('\n');

    // 分离共享内存
    shmdt(shm);

    // 删除共享内存段
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
```

在这个示例中，进程1负责写入数据到共享内存，进程2负责从共享内存读取数据并输出。

进程1首先使用`ftok`函数生成一个唯一的key，并使用`shmget`函数创建一个共享内存段。然后，使用`shmat`函数将共享内存连接到当前进程的地址空间，并向共享内存写入字符串"Hello"。最后，调用`shmdt`函数分离共享内存。

进程2也使用相同的key来获取共享内存段，然后使用`shmat`函数将共享内存连接到当前进程的地址空间。接下来，它从共享内存读取数据并输出，直到遇到字符串结束符'\0'。最后，它再次调用`shmdt`函数分离共享内存，并使用`shmctl`函数删除共享内存段。

通过这种方式，进程1可以将数据写入共享内存，进程2则可以读取并处理这些数据，实现了进程间的通信。