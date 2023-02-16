cmake_minimum_required(VERSION 3.5)
project(action_bridge)

#set(CMAKE_PREFIX_PATH "/opt/ros/noetic:/root/nav2_ws/install/dwb_msgs:/root/nav2_ws/install/nav_2d_msgs:/root/nav2_ws/install/nav2_voxel_grid:/root/nav2_ws/install/nav2_msgs:/root/nav2_ws/install/nav2_common:/root/ros2_humble/install/rosbag2:/root/ros2_humble/install/rosbag2_compression_zstd:/root/ros2_humble/install/zstd_vendor:/root/ros2_humble/install/rviz_visual_testing_framework:/root/ros2_humble/install/rviz2:/root/ros2_humble/install/rviz_default_plugins:/root/ros2_humble/install/rviz_common:/root/ros2_humble/install/rosbag2_py:/root/ros2_humble/install/rosbag2_transport:/root/ros2_humble/install/rosbag2_performance_benchmarking:/root/ros2_humble/install/rosbag2_compression:/root/ros2_humble/install/rosbag2_cpp:/root/ros2_humble/install/rosbag2_storage_default_plugins:/root/ros2_humble/install/rosbag2_storage:/root/ros2_humble/install/image_common:/root/ros2_humble/install/camera_info_manager:/root/ros2_humble/install/camera_calibration_parsers:/root/ros2_humble/install/yaml_cpp_vendor:/root/ros2_humble/install/ros1_bridge:/root/ros2_humble/install/interactive_markers:/root/ros2_humble/install/common_interfaces:/root/ros2_humble/install/visualization_msgs:/root/ros2_humble/install/dummy_robot_bringup:/root/ros2_humble/install/robot_state_publisher:/root/ros2_humble/install/kdl_parser:/root/ros2_humble/install/urdf:/root/ros2_humble/install/urdfdom:/root/ros2_humble/install/urdf_parser_plugin:/root/ros2_humble/install/urdfdom_headers:/root/ros2_humble/install/turtlesim:/root/ros2_humble/install/geometry2:/root/ros2_humble/install/tf2_sensor_msgs:/root/ros2_humble/install/test_tf2:/root/ros2_humble/install/tf2_kdl:/root/ros2_humble/install/tf2_geometry_msgs:/root/ros2_humble/install/tf2_eigen:/root/ros2_humble/install/tf2_bullet:/root/ros2_humble/install/tf2_ros:/root/ros2_humble/install/tf2_py:/root/ros2_humble/install/tf2_msgs:/root/ros2_humble/install/test_msgs:/root/ros2_humble/install/sros2_cmake:/root/ros2_humble/install/ros2cli_common_extensions:/root/ros2_humble/install/rqt_py_common:/root/ros2_humble/install/ros_testing:/root/ros2_humble/install/ros2cli_test_interfaces:/root/ros2_humble/install/quality_of_service_demo_cpp:/root/ros2_humble/install/image_transport:/root/ros2_humble/install/message_filters:/root/ros2_humble/install/demo_nodes_cpp:/root/ros2_humble/install/composition:/root/ros2_humble/install/laser_geometry:/root/ros2_humble/install/rclpy:/root/ros2_humble/install/examples_rclcpp_minimal_action_server:/root/ros2_humble/install/examples_rclcpp_minimal_action_client:/root/ros2_humble/install/action_tutorials_cpp:/root/ros2_humble/install/rclcpp_action:/root/ros2_humble/install/rcl_action:/root/ros2_humble/install/examples_rclcpp_wait_set:/root/ros2_humble/install/examples_rclcpp_minimal_service:/root/ros2_humble/install/examples_rclcpp_minimal_client:/root/ros2_humble/install/examples_rclcpp_async_client:/root/ros2_humble/install/example_interfaces:/root/ros2_humble/install/action_tutorials_interfaces:/root/ros2_humble/install/action_msgs:/root/ros2_humble/install/unique_identifier_msgs:/root/ros2_humble/install/ament_lint_common:/root/ros2_humble/install/ament_cmake_uncrustify:/root/ros2_humble/install/uncrustify_vendor:/root/ros2_humble/install/trajectory_msgs:/root/ros2_humble/install/topic_statistics_demo:/root/ros2_humble/install/pendulum_control:/root/ros2_humble/install/tlsf_cpp:/root/ros2_humble/install/test_tracetools:/root/ros2_humble/install/rqt_gui_cpp:/root/ros2_humble/install/rosbag2_test_common:/root/ros2_humble/install/ros2lifecycle_test_fixtures:/root/ros2_humble/install/lifecycle:/root/ros2_humble/install/rclcpp_lifecycle:/root/ros2_humble/install/logging_demo:/root/ros2_humble/install/image_tools:/root/ros2_humble/install/examples_rclcpp_minimal_subscriber:/root/ros2_humble/install/examples_rclcpp_minimal_composition:/root/ros2_humble/install/demo_nodes_cpp_native:/root/ros2_humble/install/rclcpp_components:/root/ros2_humble/install/intra_process_demo:/root/ros2_humble/install/examples_rclcpp_multithreaded_executor:/root/ros2_humble/install/examples_rclcpp_minimal_timer:/root/ros2_humble/install/examples_rclcpp_minimal_publisher:/root/ros2_humble/install/examples_rclcpp_cbg_executor:/root/ros2_humble/install/dummy_sensors:/root/ros2_humble/install/dummy_map_server:/root/ros2_humble/install/rclcpp:/root/ros2_humble/install/rcl_lifecycle:/root/ros2_humble/install/libstatistics_collector:/root/ros2_humble/install/rcl:/root/ros2_humble/install/rmw_implementation:/root/ros2_humble/install/rmw_fastrtps_dynamic_cpp:/root/ros2_humble/install/rmw_fastrtps_cpp:/root/ros2_humble/install/rmw_fastrtps_shared_cpp:/root/ros2_humble/install/rmw_cyclonedds_cpp:/root/ros2_humble/install/tracetools:/root/ros2_humble/install/tlsf:/root/ros2_humble/install/tinyxml_vendor:/root/ros2_humble/install/qt_gui_core:/root/ros2_humble/install/qt_gui_cpp:/root/ros2_humble/install/pluginlib:/root/ros2_humble/install/tinyxml2_vendor:/root/ros2_humble/install/tf2_eigen_kdl:/root/ros2_humble/install/tf2:/root/ros2_humble/install/test_security:/root/ros2_humble/install/test_rmw_implementation:/root/ros2_humble/install/test_rclcpp:/root/ros2_humble/install/test_quality_of_service:/root/ros2_humble/install/test_launch_testing:/root/ros2_humble/install/test_interface_files:/root/ros2_humble/install/test_communication:/root/ros2_humble/install/test_cli_remapping:/root/ros2_humble/install/test_cli:/root/ros2_humble/install/qt_gui_app:/root/ros2_humble/install/qt_gui:/root/ros2_humble/install/tango_icons_vendor:/root/ros2_humble/install/stereo_msgs:/root/ros2_humble/install/std_srvs:/root/ros2_humble/install/shape_msgs:/root/ros2_humble/install/map_msgs:/root/ros2_humble/install/sensor_msgs:/root/ros2_humble/install/nav_msgs:/root/ros2_humble/install/diagnostic_msgs:/root/ros2_humble/install/geometry_msgs:/root/ros2_humble/install/actionlib_msgs:/root/ros2_humble/install/std_msgs:/root/ros2_humble/install/statistics_msgs:/root/ros2_humble/install/sqlite3_vendor:/root/ros2_humble/install/rcl_logging_spdlog:/root/ros2_humble/install/spdlog_vendor:/root/ros2_humble/install/shared_queues_vendor:/root/ros2_humble/install/rviz_rendering_tests:/root/ros2_humble/install/rviz_rendering:/root/ros2_humble/install/rviz_ogre_vendor:/root/ros2_humble/install/rviz_assimp_vendor:/root/ros2_humble/install/rttest:/root/ros2_humble/install/rmw_connextddsmicro:/root/ros2_humble/install/rmw_connextdds:/root/ros2_humble/install/rmw_connextdds_common:/root/ros2_humble/install/rti_connext_dds_cmake_module:/root/ros2_humble/install/rosgraph_msgs:/root/ros2_humble/install/rosbag2_interfaces:/root/ros2_humble/install/rmw_dds_common:/root/ros2_humble/install/composition_interfaces:/root/ros2_humble/install/rcl_interfaces:/root/ros2_humble/install/pendulum_msgs:/root/ros2_humble/install/lifecycle_msgs:/root/ros2_humble/install/builtin_interfaces:/root/ros2_humble/install/rosidl_default_runtime:/root/ros2_humble/install/rosidl_default_generators:/root/ros2_humble/install/rosidl_generator_py:/root/ros2_humble/install/rosidl_typesupport_introspection_tests:/root/ros2_humble/install/rosidl_typesupport_cpp:/root/ros2_humble/install/rosidl_typesupport_introspection_cpp:/root/ros2_humble/install/rosidl_typesupport_c:/root/ros2_humble/install/rosidl_typesupport_introspection_c:/root/ros2_humble/install/rosidl_typesupport_fastrtps_c:/root/ros2_humble/install/rosidl_typesupport_fastrtps_cpp:/root/ros2_humble/install/rosidl_generator_cpp:/root/ros2_humble/install/rosidl_runtime_cpp:/root/ros2_humble/install/rcl_yaml_param_parser:/root/ros2_humble/install/rmw:/root/ros2_humble/install/rosidl_runtime_c:/root/ros2_humble/install/rosidl_generator_c:/root/ros2_humble/install/rosidl_typesupport_interface:/root/ros2_humble/install/rosidl_generator_dds_idl:/root/ros2_humble/install/rosidl_cmake:/root/ros2_humble/install/rosidl_parser:/root/ros2_humble/install/rosidl_adapter:/root/ros2_humble/install/rosbag2_tests:/root/ros2_humble/install/ros_environment:/root/ros2_humble/install/rmw_implementation_cmake:/root/ros2_humble/install/resource_retriever:/root/ros2_humble/install/class_loader:/root/ros2_humble/install/rcpputils:/root/ros2_humble/install/rcl_logging_noop:/root/ros2_humble/install/rcl_logging_interface:/root/ros2_humble/install/rcutils:/root/ros2_humble/install/qt_gui_py_common:/root/ros2_humble/install/qt_dotgraph:/root/ros2_humble/install/python_qt_binding:/root/ros2_humble/install/python_orocos_kdl_vendor:/root/ros2_humble/install/launch_testing_ament_cmake:/root/ros2_humble/install/python_cmake_module:/root/ros2_humble/install/pybind11_vendor:/root/ros2_humble/install/performance_test_fixture:/root/ros2_humble/install/osrf_testing_tools_cpp:/root/ros2_humble/install/orocos_kdl_vendor:/root/ros2_humble/install/mimick_vendor:/root/ros2_humble/install/libyaml_vendor:/root/ros2_humble/install/libcurl_vendor:/root/ros2_humble/install/keyboard_handler:/root/ros2_humble/install/cyclonedds:/root/ros2_humble/install/iceoryx_posh:/root/ros2_humble/install/iceoryx_hoofs:/root/ros2_humble/install/iceoryx_binding_c:/root/ros2_humble/install/ament_cmake_ros:/root/ros2_humble/install/ament_cmake_gmock:/root/ros2_humble/install/gmock_vendor:/root/ros2_humble/install/ament_cmake_auto:/root/ros2_humble/install/ament_cmake_gtest:/root/ros2_humble/install/gtest_vendor:/root/ros2_humble/install/ament_cmake_google_benchmark:/root/ros2_humble/install/google_benchmark_vendor:/root/ros2_humble/install/fastrtps:/root/ros2_humble/install/foonathan_memory_vendor:/root/ros2_humble/install/fastrtps_cmake_module:/root/ros2_humble/install/fastcdr:/root/ros2_humble/install/eigen3_cmake_module:/root/ros2_humble/install/console_bridge_vendor:/root/ros2_humble/install/ament_cmake_xmllint:/root/ros2_humble/install/ament_cmake_pyflakes:/root/ros2_humble/install/ament_cmake_pycodestyle:/root/ros2_humble/install/ament_cmake_pep257:/root/ros2_humble/install/ament_cmake_pclint:/root/ros2_humble/install/ament_lint_auto:/root/ros2_humble/install/ament_cmake:/root/ros2_humble/install/ament_cmake_version:/root/ros2_humble/install/ament_cmake_pytest:/root/ros2_humble/install/ament_cmake_nose:/root/ros2_humble/install/ament_cmake_mypy:/root/ros2_humble/install/ament_cmake_lint_cmake:/root/ros2_humble/install/ament_cmake_flake8:/root/ros2_humble/install/ament_cmake_cpplint:/root/ros2_humble/install/ament_cmake_cppcheck:/root/ros2_humble/install/ament_cmake_copyright:/root/ros2_humble/install/ament_cmake_clang_tidy:/root/ros2_humble/install/ament_cmake_clang_format:/root/ros2_humble/install/ament_cmake_test:/root/ros2_humble/install/ament_cmake_target_dependencies:/root/ros2_humble/install/ament_cmake_python:/root/ros2_humble/install/ament_cmake_export_dependencies:/root/ros2_humble/install/ament_cmake_libraries:/root/ros2_humble/install/ament_cmake_include_directories:/root/ros2_humble/install/ament_cmake_gen_version_h:/root/ros2_humble/install/ament_cmake_export_targets:/root/ros2_humble/install/ament_cmake_export_link_flags:/root/ros2_humble/install/ament_cmake_export_interfaces:/root/ros2_humble/install/ament_cmake_export_libraries:/root/ros2_humble/install/ament_cmake_export_include_directories:/root/ros2_humble/install/ament_cmake_export_definitions:/root/ros2_humble/install/ament_cmake_core:/root/ros2_humble/install/ament_index_cpp")
#message("CMAKE_PREFIX_PATH is :" ${CMAKE_PREFIX_PATH})

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

#if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#  add_compile_options(-Wall -Wextra -Wpedantic)
#endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(nav2_msgs REQUIRED)

find_package(action_tutorials_interfaces REQUIRED)
find_package(control_msgs REQUIRED)

# find ROS 1 packages
include(cmake/find_ros1_package.cmake)

find_package(PkgConfig REQUIRED)

find_ros1_package(roscpp REQUIRED)
find_ros1_package(actionlib REQUIRED)
find_package(move_base_msgs REQUIRED)

find_ros1_package(actionlib_tutorials REQUIRED)
find_ros1_package(control_msgs REQUIRED)


ament_export_include_directories(include)

include_directories(include)

#add_executable(action_bridge_follow_joint_trajectory_1_2
#    "src/action_bridge_follow_joint_trajectory_1_2.cpp"
#)

#add_executable(action_bridge_follow_joint_trajectory_2_1
#    "src/action_bridge_follow_joint_trajectory_2_1.cpp"
#)


add_executable(action_bridge_fibonacci_1_2
    "src/action_bridge_fibonacci_1_2.cpp"
)
ament_target_dependencies(action_bridge_fibonacci_1_2
    "ros1_roscpp" "ros1_actionlib" "ros1_actionlib_tutorials"
    "rclcpp" "rclcpp_action" "action_tutorials_interfaces"
)

add_executable(action_bridge_fibonacci_2_1
    "src/action_bridge_fibonacci_2_1.cpp"
)
ament_target_dependencies(action_bridge_fibonacci_2_1
    "ros1_roscpp" "ros1_actionlib" "ros1_actionlib_tutorials"
    "rclcpp" "rclcpp_action" "action_tutorials_interfaces"
)


add_executable(action_bridge_nav_2_1
        "src/action_bridge_nav_2_1.cpp"
        )
ament_target_dependencies(action_bridge_nav_2_1
        "ros1_roscpp" "ros1_actionlib"
        "rclcpp" "rclcpp_action" "nav2_msgs" move_base_msgs
        )


install(TARGETS action_bridge_fibonacci_1_2 action_bridge_fibonacci_2_1 action_bridge_nav_2_1
    DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
    DESTINATION include/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # remove the line when a copyright and license is present in all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # remove the line when this package is a git repo
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()



ament_package()
