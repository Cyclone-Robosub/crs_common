# pwm of each thruster on the robot
# In left to right:
# f = front / r = rear
# l = left  / r = right
# t = top   / b = bottom
int32 pwm_flt
int32 pwm_frt
int32 pwm_rlt
int32 pwm_rrt
int32 pwm_flb
int32 pwm_frb
int32 pwm_rlb
int32 pwm_rrb

# Does PWM command have duration or runs indefinitely.
# 1 means run for duration.
# 0 means run indefinitely
bool is_timed

# Duration of the PWM command
int64 duration

# Should this command override existing PWM commands
# 1 means any existing PWM commands should be removed before adding this one
# 0 means this command should be added to the queue
bool is_overriding