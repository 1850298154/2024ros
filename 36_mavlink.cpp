#include <math.h>
#include <thread>
#include <mutex>
// #include "mav_inc/mavlink_types.h"
#include "/opt/ros/noetic/include/mavlink/v2.0/mavlink_types.h"
// /opt/ros/noetic/include/mavlink/v2.0/mavlink_helpers.h
#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
#define MAVLINK_SEND_UART_BYTES(a, b, c) send(a, b, c, 0)
mavlink_system_t mavlink_system = {1, 1};
// #include "mav_inc/common/mavlink.h"
#include "/opt/ros/noetic/include/mavlink/v2.0/common/mavlink.h"
int main(void)
{
    Socket sock;
    sock.Create();
    while (sock.Connect((char *)"127.0.0.1", 1244) != 0)
    {
        printf("connect error.waiting for 1 second...\n");
        usleep(1000000);
    }
    while (1)
    {
        mavlink_message_t msg;
        mavlink_status_t status;
        uint8_t buf[1024];
        int recv_len = sock.Receive((char *)buf, 1024);
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