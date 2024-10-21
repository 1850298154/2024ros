
这段代码使用了MavLink库来实现与无人机通信的功能。主要包括以下几个步骤：
1. 引入相关的MavLink头文件，包括mavlink.h、mavlink_msg_local_position_ned.h和mavlink_msg_sys_status.h。
2. 定义了一个BUFFER_LENGTH常量，用于设置接收缓冲区的大小。
3. 在main函数中，首先初始化了一个mavlink_system_t结构体，设置了系统ID和组件ID。
4. 声明了一个字符数组target_ip，用于存储目标IP地址。
5. 声明了一个长度为6的float数组position，用于存储位置信息。
6. 声明了一个长度为BUFFER_LENGTH的uint8_t数组buf，用作接收缓冲区。
7. 调用mavlink_msg_local_position_ned_pack函数将位置信息打包成mavlink_message_t类型的消息，并将其存储在msg2变量中。
8. 调用mavlink_msg_to_send_buffer函数将消息转换成字节流，并将字节流存储在buf数组中。然后通过循环遍历打印出buf数组中的字节数据。
9. 在for循环中，通过调用mavlink_parse_char函数解析接收到的字节数据，如果成功解析出一个完整的消息，则打印出消息的相关信息。
10. 如果解析出的消息类型是32（mavlink_msg_local_position_ned），则通过调用mavlink_msg_local_position_ned_decode函数解码出位置信息，并将其打印出来。
这段代码的主要作用是将位置信息通过MavLink协议打包发送给无人机，然后接收无人机返回的消息并解析出位置信息进行处理。

NED是"North-East-Down"的缩写，表示一种坐标系。在飞行领域中，NED坐标系通常用于表示无人机的位置和姿态信息。
NED坐标系以无人机起飞点为参考点，定义了三个轴：北轴（North），东轴（East）和下轴（Down）。北轴指向地理北方，东轴指向地理东方，下轴指向地面。无人机的位置可以通过这三个轴的数值来确定。例如，NED坐标系中的一个位置可以表示为(x, y, z)，其中x表示相对于北轴的位置，y表示相对于东轴的位置，z表示相对于下轴的位置。
通过使用NED坐标系，可以方便地描述无人机在空间中的位置和运动状态，为飞行控制和导航提供了基础。

```cpp
#include "MavLinkLibrary/common/mavlink.h"
#include "MavLinkLibrary/common/mavlink_msg_local_position_ned.h"
#include "MavLinkLibrary/common/mavlink_msg_sys_status.h"
#include<iostream>
using namespace std;
#define BUFFER_LENGTH                                                          \
  2041 // minimum buffer size that can be used with qnx (I don't know why)
 
int main(int argc, char *argv[]) {
 
  mavlink_system_t mavlink_system = {
      1, // System ID (1-255)
      1  // Component ID (a MAV_COMPONENT value)
  };
  char help[] = "--help";
 
  char target_ip[100];
 
  float position[6] = {};
 
  uint8_t buf[BUFFER_LENGTH];
  ssize_t recsize;
  // socklen_t fromlen = sizeof(gcAddr);
  int bytes_sent;
  mavlink_message_t msg2;
 
  // mavlink_message_t msg;
  mavlink_status_t status;
 
  uint16_t len;
  int i = 0;
  unsigned int temp = 0;
  {
    mavlink_msg_local_position_ned_pack(1, 200, &msg2, 123, 2, 33, 35, 43, 52,
                                        62);
    len = mavlink_msg_to_send_buffer(buf, &msg2);
    if(len){
        std::cout<<"message send success!"<<endl;
    }
    for (i = 0; i < len; i++)
      printf("%x ", buf[i]);
    printf("\n--------------------------------------------------------\n");
    mavlink_message_t msg;
    for (i = 0; i < len; i++) {
      temp = buf[i];
      printf("%02x ", (unsigned char)temp);
      if (mavlink_parse_char(12, buf[i], &msg, &status)) {
        // Packet received
        printf("\nReceived --packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n",
               msg.sysid, msg.compid, msg.len, msg.msgid);
        if (msg.msgid == 32) {
          mavlink_local_position_ned_t local_position_ned;
          mavlink_msg_local_position_ned_decode(&msg, &local_position_ned);
          printf("ned x %f, y%f, z%f\nned vx %f, vy%f, vz%f\n",
                 local_position_ned.x, local_position_ned.y,
                 local_position_ned.z, local_position_ned.vx,
                 local_position_ned.vy, local_position_ned.vz);
        }
      }
    }
 
  }
}

```


```cpp
#include <math.h>
#include <thread>
#include <mutex>
#include "mav_inc/mavlink_types.h"
#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
#define MAVLINK_SEND_UART_BYTES(a, b, c) send(a, b, c, 0)
mavlink_system_t mavlink_system = { 1,1 };
#include "mav_inc/common/mavlink.h"
int main(void){
        Socket sock;
        sock.Create();
        while (sock.Connect((char*)"127.0.0.1", 1244) != 0) 
       { 
               printf("connect error.waiting for 1 second...\n");
                usleep(1000000);
        } 
        while (1)
        { 
               mavlink_message_t msg; 
               mavlink_status_t status;
                uint8_t buf[1024]; 
               int recv_len = sock.Receive((char*)buf, 1024); 
               for (int i = 0; i < recv_len; i++) 
               { 
                       if (mavlink_parse_char(0, buf[i], &msg, &status))
                        { 
                               switch (msg.msgid)  
                              {  
                              case MAVLINK_MSG_ID_ATTITUDE: 
                                       mavlink_attitude_t attitude; 
                                       mavlink_msg_attitude_decode(&msg, &attitude);
                                        printf("rpy=%f,%f,%f\n", attitude.roll, attitude.pitch, attitude.yaw);  
                                      break; 
                               case MAVLINK_MSG_ID_HEARTBEAT: 
                                       mavlink_heartbeat_t heart; 
                                       mavlink_msg_heartbeat_decode(&msg, &heart);
                                        if (heart.base_mode) 
                                       {  
                                              bool armed = (heart.base_mode & MAV_MODE_FLAG_SAFETY_ARMED); 
                                               bool guided = (heart.base_mode & MAV_MODE_FLAG_GUIDED_ENABLED); 
                                               printf("armed=%d,guided=%d\n", armed, guided); 
                                       }  
                                      break; 
                               default: 
                                       break; 
                               } 
                       }
                } 
       }
         return 0;
}
```