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