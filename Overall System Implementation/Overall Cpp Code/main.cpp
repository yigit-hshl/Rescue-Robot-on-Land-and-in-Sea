#include <iostream>
#include <string>
#include "ultra_sensor.h"


void drive_Forward();
void stop();
void analyse_Obstacle();
void rotate_360();
void drive();
double detect_Shortest_Path(double initial_Position, double final_Position);


int system_On = 1;
int water_Sensor = 1;


double current_Position = 0.0;
double initial_Position = 0.0;
double final_Position = 10.0; // equate later to shortest path()
double drive_Path = detect_Shortest_Path(initial_Position, final_Position);

std::string obstacle_Type;
float obstacle_Depth;


int main() {
    drive();


    return 0;
}


void drive(){
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




void drive_Forward(){
    printf("Driving Forward\n");

}

void   rotate_360(){
    std::cout<< "I rotated 360 degrees\n";
}

void stop(){
    printf("The car stopped");
}

void analyse_Obstacle(){
    if (water_Sensor == 1)
    {
        obstacle_Type = "water";
        obstacle_Depth = 98;

    }else
    {
        //obstacle_Type = "s";

    }


}

double detect_Shortest_Path(double initial_Position, double final_Position){
    return 8.0;
}