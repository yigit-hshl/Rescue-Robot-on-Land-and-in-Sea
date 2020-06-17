cmake_minimum_required(VERSION 3.16)
project(Rescue_Object)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rescue_Object main.cpp Rescue_Robot.cpp Rescue_Robot.h utrasonic_Sensor.cpp ultrasonic_Sensor.h)