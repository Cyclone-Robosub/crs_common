# CRS ROS2 Interfaces
This ros package defines the interfaces used by ros topics, services, and actions.

To use these interfaces:

A Python package:
* Add the following to your `package.xml`
  ```xml
  <exec_depend>crs_ros2_interfaces</exec_depend>
  ```
* Import the specific messages in the python files using them like so:
  ```python
  from crs_ros2_interfaces.msg import PwmCmd
  ```

For a C++ package:
* Add the following to your `package.xml`
  ```xml
  <depend>crs_ros2_interfaces</depend>
  ```
* Add the following lines to your `CMakeLists.txt`, replacing `YOUR_TARGET` with the name of your CMake target.
  ```CMake
  find_package(crs_ros2_interfaces REQUIRED)
  ament_target_dependencies(YOUR_TARGET rclcpp crs_ros2_interfaces)
  ```
* Include the generated headers in files where you use the message, like so:
  ```cpp
  #include "crs_ros2_interfaces/msg/pwm_cmd.hpp"
  ```