以下是两个进程分别启动，通过消息队列进行读写的示例：

**进程1：向消息队列发送消息**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // 生成消息队列的key
    key = ftok("/tmp", 'R');

    // 创建消息队列
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    // 设置消息类型
    message.msg_type = 1;

    // 输入消息
    printf("Enter message to send: ");
    fgets(message.msg_text, 100, stdin);

    // 向消息队列发送消息
    msgsnd(msgid, &message, sizeof(message), 0);

    printf("Data sent is : %s \n", message.msg_text);

    return 0;
}
```

**进程2：从消息队列接收消息**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // 生成消息队列的key
    key = ftok("/tmp", 'R');

    // 获取消息队列
    msgid = msgget(key, 0666 | IPC_CREAT);

    // 从消息队列接收消息
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // 输出接收到的消息
    printf("Data received is : %s \n", message.msg_text);

    // 删除消息队列
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
```

在这个示例中，进程1负责向消息队列发送消息，而进程2负责从消息队列接收消息。

进程1首先使用`ftok`函数生成一个唯一的key，并使用`msgget`函数创建或获取消息队列。然后，它设置消息的类型和内容，并使用`msgsnd`函数向消息队列发送消息。

进程2也使用相同的key来获取消息队列，然后使用`msgrcv`函数从消息队列接收消息，并输出接收到的消息。最后，它使用`msgctl`函数删除消息队列。

通过这种方式，进程1可以向消息队列发送消息，进程2则可以从消息队列接收并处理这些消息，实现了进程间的通信。



# 参数


以下是本题用到的一些函数的详细解释：

1. `ftok`函数：将一个文件名和一个整数标识符转换为一个唯一的key。

   ```c
   key_t ftok(const char *pathname, int proj_id);
   ```

   - 参数`pathname`为文件名，此文件必须存在且可读。
   - 参数`proj_id`为整数标识符，通常设置为一个非零的整数。
   - 返回一个唯一的key，可以用于创建或获取共享内存、消息队列等。

2. `shmget`函数：创建或获取共享内存段。

   ```c
   int shmget(key_t key, size_t size, int shmflg);
   ```

   - 参数`key`为共享内存段的key，通常使用`ftok`函数生成。
   - 参数`size`为共享内存段的大小，以字节为单位。
   - 参数`shmflg`为标志位，指定共享内存的权限和操作类型，如IPC_CREAT、IPC_EXCL、0666等。
   - 返回共享内存段的标识符（shmid），该标识符用于后续的共享内存操作。

3. `shmat`函数：将共享内存连接到当前进程的地址空间。

   ```c
   void *shmat(int shmid, const void *shmaddr, int shmflg);
   ```

   - 参数`shmid`为共享内存段的标识符（由`shmget`函数返回）。
   - 参数`shmaddr`为指向共享内存段的首地址，通常设置为NULL表示让系统自动分配一个地址。
   - 参数`shmflg`为标志位，通常设置为0。
   - 返回一个指向共享内存段的指针，该指针可以用于读写共享内存。

4. `shmdt`函数：将共享内存从当前进程的地址空间中分离。

   ```c
   int shmdt(const void *shmaddr);
   ```

   - 参数`shmaddr`为指向共享内存段的指针（由`shmat`函数返回）。
   - 返回0表示成功，-1表示失败。

5. `msgget`函数：创建或获取消息队列。

   ```c
   int msgget(key_t key, int msgflg);
   ```

   - 参数`key`为消息队列的key，通常使用`ftok`函数生成。
   - 参数`msgflg`为标志位，指定消息队列的权限和操作类型，如IPC_CREAT、IPC_EXCL、0666等。
   - 返回消息队列的标识符（msgid），该标识符用于后续的消息队列操作。

6. `msgsnd`函数：向消息队列发送消息。

   ```c
   int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
   ```

   - 参数`msqid`为消息队列的标识符（由`msgget`函数返回）。
   - 参数`msgp`为指向消息内容的指针，对于本题来说就是`struct msg_buffer`类型的变量。
   - 参数`msgsz`为消息内容的大小，通常为`sizeof(struct msg_buffer)`。
   - 参数`msgflg`为标志位，指定发送消息的行为，如IPC_NOWAIT等。
   - 返回0表示成功，-1表示失败。

7. `msgrcv`函数：从消息队列接收消息。

   ```c
   ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
   ```

   - 参数`msqid`为消息队列的标识符（由`msgget`函数返回）。
   - 参数`msgp`为指向消息内容的指针，对于本题来说就是`struct msg_buffer`类型的变量。
   - 参数`msgsz`为消息内容的大小，通常为`sizeof(struct msg_buffer)`。
   - 参数`msgtyp`为指定接收那个类型的消息，对于本题来说就是1。
   - 参数`msgflg`为标志位，指定接收消息的行为，如IPC_NOWAIT等。
   - 返回实际接收到的消息内容的大小，如果没有接收到消息且`msgflg`设置了IPC_NOWAIT，则返回-1。

8. `msgctl`函数：删除消息队列。

   ```c
   int msgctl(int msqid, int cmd, struct msqid_ds *buf);
   ```

   - 参数`msqid`为消息队列的标识符（由`msgget`函数返回）。
   - 参数`cmd`为命令，指定要进行的操作，如IPC_RMID表示删除消息队列。
   - 参数`buf`为消息队列的信息结构体，可以为NULL。
   - 返回0表示成功，-1表示失败。

以上函数是本题中用到的一些重要函数，更详细的使用说明可以参考操作系统相关的文档或手册。


# 阻塞

在消息队列中，通常情况下，0表示非阻塞模式，1表示阻塞模式。

具体来说，当我们调用`msgrcv`函数接收消息时，如果设置了msgflg参数为0，则表示以非阻塞模式接收消息。这种情况下，如果当前消息队列没有可以接收的消息，则立即返回，并且`msgrcv`函数的返回值为-1，并且errno被设置为ENOMSG。

而如果设置msgflg参数为1，则表示以阻塞模式接收消息。这种情况下，如果当前消息队列没有可以接收的消息，则会一直等待，直到有消息到达为止。此时`msgrcv`函数不会立即返回，而是一直阻塞在那里，直到接收到一个消息或者出现错误为止。

需要注意的是，如果设置了IPC_NOWAIT标志，则即使设置了msgflg参数为1，也不会阻塞。而是立即返回，并且`msgrcv`函数的返回值为-1，并且errno被设置为ENOMSG。


# 类型

在消息队列中，通过`msgtyp`参数来指定接收某个特定类型的消息。这个参数的取值可以是0或者正整数。

- 当`msgtyp`参数为0时，表示接收消息队列中的第一个消息。无论消息的类型是什么，都会被接收。
- 当`msgtyp`参数为正整数时，表示接收消息队列中第一个符合指定类型的消息。只有消息的类型与`msgtyp`参数相等时，才会被接收。如果没有符合条件的消息，阻塞模式下会一直等待，非阻塞模式下会立即返回。

对于这个问题，题目要求接收类型为1的消息，因此可以将`msgtyp`参数设置为1，以接收消息队列中类型为1的消息。