#include <stdio.h>
#include "ultra_sensor.h"

bool obstacleDetected();

int main(){
  bool systemOn = True;
  double initialPosition;
  double finalDestination;
  string rescueObjective;
  double finalDestinationReached = finalDestination;
  
  double audioSignalDistance1;
  double audioSignalDistance2;
  double audioSignalDistance3;
  double audioSignalDistance4;

  bool frontObstacle;
  bool backObstacle;

  detectShortestPath;

  while (systemOn){
    printf("help is on it's way");
    for(i=0, i < finalDestinationReached, i++){
      if(!obstacleDetected()){//obstacle not deteceted
        driveForward();
      }else{ //obstacle detected
        stopp();
        analyseObstacle();
        if(analyseObstacle() = "water"){
          riverEngine();
          tyresUp();
          driveForward();
        }else if(analyseObstacle() == "Solid"){
        avoidObstacle(); // avoid obstacle function has implementation for keeping the vehicle orientation 
        
      }

      finalDestinationReached--; 
    }
      
    stopp();
    printf("play safety instructions");
    openCompartment();
    performRescueMission(); // this function will perform the appropriate rescue mission
    returnToInitialPosition(); // this function does the calculation of how the robot returns to initial position
    
  }
  systemOn = False;


  
  return 0;
}

bool obstacleDetected(){
  if(ultrasonic_Sensor_front_middle_distance <= 300 || ultrasonic_Sensor_front_left_distance <= 300 || ultrasonic_Sensor_front_right_distance <= 300){
    frontObstacle = true;
    return frontObstacle;
  }else if(ultrasonic_Sensor_back_middle_distance <= 300 || ultrasonic_Sensor_back_left_distance <= 300 || ultrasonic_Sensor_back_right_distance <=){
    backObstacle = true;
  }else{
    return false
  }
}
