#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <std_msgs/String.h>

void callback1(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Received message from topic 1: %s", msg->data.c_str());
}

void callback2(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Received message from topic 2: %s", msg->data.c_str());
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "callback_queue_example");
    ros::NodeHandle nh;

    // 创建两个回调队列，分别用于处理消息主题1和主题2的回调函数
    ros::CallbackQueue queue1;
    ros::CallbackQueue queue2;

    // 创建两个订阅者，分别订阅消息主题1和主题2，并将它们的回调函数添加到对应的回调队列中
    ros::Subscriber sub1 = nh.subscribe<std_msgs::String>("topic1", 10, boost::bind(&callback1, _1), ros::VoidConstPtr(), &queue1);
    ros::Subscriber sub2 = nh.subscribe<std_msgs::String>("topic2", 10, boost::bind(&callback2, _1), ros::VoidConstPtr(), &queue2);

    // 循环处理回调队列，直到所有回调函数都被执行完毕
    while (ros::ok())
    {
        // 处理回调队列1中的回调函数，直到队列为空
        queue1.callAvailable();

        // 处理回调队列2中的回调函数，直到队列为空
        queue2.callAvailable();

        // 暂停一段时间，避免过度消耗 CPU 周期
        ros::Duration(0.1).sleep();
    }

    return 0;
}
