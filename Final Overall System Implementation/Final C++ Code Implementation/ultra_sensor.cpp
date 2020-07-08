//
// Created by Olaniyi Alao on 12.06.20.
//

#include "ultra_sensor.h"
//#include <string>



// ultrasonic_Sensor_front
double ultrasonic_Sensor_front_distance ;


// ultrasonic_Sensor_back
double ultrasonic_Sensor_back_distance;




double ultrasonic_Sensor_front(){
    // Clears the trigPin
// Read the echoPin, returns the sound wave travel time in microseconds
// Calculate the distance
    ultrasonic_Sensor_front_distance = 400.00;

    return ultrasonic_Sensor_front_distance;
}





// Calculating the distance for the back side

double ultrasonic_Sensor_back(){
    // Clears the trigPin
// Reads the echoPin, returns the sound wave travel time in microseconds
// Calculating the distance
    ultrasonic_Sensor_back_distance = 0.20;

    return ultrasonic_Sensor_back_distance;
}



std::string obstacle_Detection(){
    if ( ultrasonic_Sensor_front() >= 300.02 ){
        return "Obstacle free in front";
    } else{
        return "Obstacle detected in front";
    }

}

std::string back_Obstacle_Detection(){
    if(ultrasonic_Sensor_back() >= 300.02 ){
        return "Obstacle free at the back";

    } else{
        return "Obstacle detected at the back";
    }

}
