//
// Created by Olaniyi Alao on 14.06.20.
//

#ifndef CPP_CODE_RESCUE_ROBOT_H
#define CPP_CODE_RESCUE_ROBOT_H

#include <string>


class Rescue_Robot {

    //attributes

    int system_On = 0;
    int water_Sensor = 1;


    double current_Position = 0.0;
    double initial_Position = 0.0;
    double final_Position = 10.0;
    double drive_Path = detect_Shortest_Path(initial_Position, final_Position);// equate later to shortest path()

    std::string obstacle_Type;
    float obstacle_Depth;



public:
    //constructor
    Rescue_Robot(double start_Position, double final_Position);

    //Destructor
    ~Rescue_Robot();

    //methods

    double detect_Shortest_Path(double initial_Position, double final_Position);
    void drive_Forward();
    void stop();
    void analyse_Obstacle();
    void rotate_360();
    void drive();
    void turn_System_On();

};


#endif //CPP_CODE_RESCUE_ROBOT_H
