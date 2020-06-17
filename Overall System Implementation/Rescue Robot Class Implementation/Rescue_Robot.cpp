//
// Created by Olaniyi Alao on 14.06.20.
//

#include "Rescue_Robot.h"
#include <iostream>
#include "ultrasonic_Sensor.h"

//constructor
Rescue_Robot::Rescue_Robot(double start_Position, double end_Position) : initial_Position(start_Position), final_Position(end_Position) {}

//destructor
Rescue_Robot::~Rescue_Robot() = default;

void Rescue_Robot::drive(){
    while (system_On)
    {




        while (current_Position != drive_Path)
        {
            //std::cout<< "I am here";
            if (obstacle_Detection() == 1 && !water_Sensor)
            {
                drive_Forward();

            }else if (obstacle_Detection() == 1 && water_Sensor) {
                if (water_Sensor){
                    analyse_Obstacle();
                    if (obstacle_Type == "water" && obstacle_Depth <= 65.8){
                        std::cout<< "Driving in river mode\n";
                        drive_Forward();
                    } else{
                        std::cout<< "I can't drive in this! \nAvoiding obstacle!";
                        break;
                    }
                }

            }else if (obstacle_Detection() == -1 ){
                if (back_Obstacle_Detection() == 2){
                    rotate_360();
                    std::cout<< "Solid Obstacle  detected! Re-calculating Shortest path \n";
                    break;
                } else{
                    std::cout<< "I'm really stuck! manual override required. \n";

                    break;
                }


            }else{
                stop();

                break;
            }

            current_Position++;


        }

        if ((obstacle_Detection() == 1 && water_Sensor) || (obstacle_Detection() == -1)){
            if (obstacle_Type == "water" && obstacle_Depth <= 65.8){
                std::cout << "\nI reached my final destination!\n";
                std::cout << "Help is here!";
                system_On = 0;
            } else{
                break;
            }


        } else{
            std::cout << "I reached my final destination!\n";
            std::cout << "Help is here!";
            system_On = 0;
        }

    }
}


double Rescue_Robot::detect_Shortest_Path(double initial_Position, double final_Position){
    return 8.0;
}

void Rescue_Robot::drive_Forward(){
    printf("Driving Forward\n");

}

void Rescue_Robot::rotate_360() {
    std::cout<< "I rotated 360 degrees\n";
}

void Rescue_Robot::stop(){
    printf("The car stopped");
}

void Rescue_Robot::analyse_Obstacle(){
    if (water_Sensor == 1)
    {
        obstacle_Type = "water";
        obstacle_Depth = 64.8;

    }else
    {
        //obstacle_Type = "s";

    }


}

void Rescue_Robot::turn_System_On() {
    system_On = 1;

}


