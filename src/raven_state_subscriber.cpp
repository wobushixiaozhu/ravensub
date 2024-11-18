#include "ros/ros.h"
#include "raven_2/raven_state.h" // 确保包含raven_state的消息头文件

// 回调函数，用于处理接收到的raven_state消息
void ravenStateCallback(const raven_2::raven_state::ConstPtr& msg)
{
    ROS_INFO("Received raven state:");
    ROS_INFO("Runlevel: %d", msg->runlevel);
    ROS_INFO("Sublevel: %d", msg->sublevel);
    ROS_INFO("Last Sequence: %d", msg->last_seq);

    // 打印位置数据
    ROS_INFO("Position: [%d, %d, %d, %d, %d, %d]",
             msg->pos[0], msg->pos[1], msg->pos[2],
             msg->pos[3], msg->pos[4], msg->pos[5]);


    
    // 根据需要打印其他数据
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "raven_state_listener");
    ros::NodeHandle nh;

    // 订阅"/ravenstate"话题
    ros::Subscriber sub = nh.subscribe("/ravenstate", 100, ravenStateCallback);

    // 进入回调循环
    ros::spin();

    return 0;
}

