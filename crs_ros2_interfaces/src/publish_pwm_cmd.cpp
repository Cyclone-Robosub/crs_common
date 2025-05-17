#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "crs_ros2_interfaces/msg/pwm_cmd.hpp"

using namespace std::chrono_literals;

class PwmCmdPublisher : public rclcpp::Node
{
public:
  PwmCmdPublisher()
  : Node("pwm_cmd_publisher")
  {
    pwm_cmd_publisher_ =
      this->create_publisher<crs_ros2_interfaces::msg::PwmCmd>("pwm_cmd", 10);

    auto publish_msg = [this]() -> void {
        auto message =crs_ros2_interfaces::msg::PwmCmd();

        message.pwm_flt = 1;
        message.pwm_frt = 2;
        message.pwm_rlt = 3;
        message.pwm_rrt = 4;
        message.pwm_flb = 11;
        message.pwm_frb = 12;
        message.pwm_rlb = 13;
        message.pwm_rrb = 14;

        message.is_timed = true;

        message.duration = msg_count++;

        message.is_overriding = true;

        std::cout << "Publishing PwmCmd to /pwm_cmd:" << 
          "\n  pwm_flt: " << message.pwm_flt <<
          "\n  pwm_frt: " << message.pwm_frt << 
          "\n  pwm_rlt: " << message.pwm_rlt << 
          "\n  pwm_rrt: " << message.pwm_rrt << 
          "\n  pwm_flb: " << message.pwm_flb << 
          "\n  pwm_frb: " << message.pwm_frb << 
          "\n  pwm_rlb: " << message.pwm_rlb << 
          "\n  pwm_rrb: " << message.pwm_rrb << 
          "\n  is_timed " << message.is_timed << 
          "\n  duration: " << message.duration << 
          "\n  is_overriding: " << message.is_overriding << std::endl;


        this->pwm_cmd_publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(1s, publish_msg);
  }

private:
  rclcpp::Publisher<crs_ros2_interfaces::msg::PwmCmd>::SharedPtr pwm_cmd_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  int64_t msg_count = 0;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PwmCmdPublisher>());
  rclcpp::shutdown();

  return 0;
}