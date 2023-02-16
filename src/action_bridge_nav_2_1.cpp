// Copyright 2019 Fraunhofer IPA
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <action_bridge/action_bridge_2_1.hpp>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#endif
#include <move_base_msgs/MoveBaseAction.h>
#include <move_base_msgs/MoveBaseActionResult.h>
//#include <move_base_msgs/action/MoveBaseAction.h>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

// include ROS 2
#include <nav2_msgs/action/navigate_to_pose.hpp>
#include <nav2_msgs/action/compute_path_to_pose.hpp>
#include <actionlib_tutorials/FibonacciAction.h>

using NavActionBridge = ActionBridge_2_1<move_base_msgs::MoveBaseAction,
        nav2_msgs::action::NavigateToPose>;

template <>
void NavActionBridge::translate_goal_2_to_1(const ROS2Goal &goal2, ROS1Goal &goal1)
{
    goal1.target_pose.header.stamp.sec = goal2.pose.header.stamp.sec;
    goal1.target_pose.header.stamp.nsec = goal2.pose.header.stamp.nanosec;
    goal1.target_pose.header.frame_id = goal2.pose.header.frame_id;

    goal1.target_pose.pose.position.x = goal2.pose.pose.position.x;
    goal1.target_pose.pose.position.y = goal2.pose.pose.position.y;
    goal1.target_pose.pose.position.z = goal2.pose.pose.position.z;

    goal1.target_pose.pose.orientation.w = goal2.pose.pose.orientation.w;
    goal1.target_pose.pose.orientation.x = goal2.pose.pose.orientation.x;
    goal1.target_pose.pose.orientation.y = goal2.pose.pose.orientation.y;
    goal1.target_pose.pose.orientation.z = goal2.pose.pose.orientation.z;

    // unused: goal2.behavior_tree;

}

template <>
void NavActionBridge::translate_result_1_to_2(
    ROS2Result &result2,
    const ROS1Result &result1)
{
    // for some reason ROS 2 uses a std_msgs/Empty and error code for its result while ROS 1 uses move_base_msgs/MoveBaseActionResult

//if (result1.status != move_base_msgs::MoveBaseActionResult::SUCCEEDED){
//    result2.error_code = nav2_msgs::action::ComputePathToPose::UNKNOWN;
//} else{
    result2.error_code = nav2_msgs::action::ComputePathToPose::Goal::NONE;
//}

}

template <>
void NavActionBridge::translate_feedback_1_to_2(
    ROS2Feedback &feedback2,
    const ROS1Feedback &feedback1)
{
    feedback2.current_pose.header.stamp.sec = feedback1.base_position.header.stamp.sec;
    feedback2.current_pose.header.stamp.nanosec = feedback1.base_position.header.stamp.nsec;
    feedback2.current_pose.header.frame_id = feedback1.base_position.header.frame_id;

    feedback2.current_pose.pose.position.x = feedback1.base_position.pose.position.x;
    feedback2.current_pose.pose.position.y = feedback1.base_position.pose.position.y;
    feedback2.current_pose.pose.position.z = feedback1.base_position.pose.position.z;

    feedback2.current_pose.pose.orientation.w = feedback1.base_position.pose.orientation.w;
    feedback2.current_pose.pose.orientation.x = feedback1.base_position.pose.orientation.x;
    feedback2.current_pose.pose.orientation.y = feedback1.base_position.pose.orientation.y;
    feedback2.current_pose.pose.orientation.z = feedback1.base_position.pose.orientation.z;

}

int main(int argc, char *argv[])
{
  return NavActionBridge::main("move_base", argc, argv);
}
