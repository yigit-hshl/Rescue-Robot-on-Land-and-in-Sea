//
// Created by Olaniyi Alao on 12.06.20.
//

#include "ultrasonic_Sensor.h"



// ultrasonic_Sensor_front
double ultrasonic_Sensor_front_distance ;


// ultrasonic_Sensor_back
double ultrasonic_Sensor_back_distance;




double ultrasonic_Sensor_front(){
    // Clears the trigPin
// Read the echoPin, returns the sound wave travel time in microseconds
// Calculate the distance
    ultrasonic_Sensor_front_distance = 400;

    return ultrasonic_Sensor_front_distance;
}





// Calculating the distance for the back side

double ultrasonic_Sensor_back(){
    // Clears the trigPin
// Reads the echoPin, returns the sound wave travel time in microseconds
// Calculating the distance
    ultrasonic_Sensor_back_distance = 300;

    return ultrasonic_Sensor_back_distance;
}



int obstacle_Detection(){
    if ( ultrasonic_Sensor_front() >= 300.02 ){
        return 1; // 1 = obstacle free in front
    } else{
        return -1; // -1 = obstacle detected in front
    }

}

int back_Obstacle_Detection(){
    if(ultrasonic_Sensor_back() >= 300.02 ){
        return 2; // 2 = obstacle free in the back

    } else{
        return -2; // -2 = obstacle detected in the back
    }

}
