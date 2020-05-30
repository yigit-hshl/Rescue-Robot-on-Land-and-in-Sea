#include <stdio.h>
#include "ultra_sensor.h"

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

  detectShortestPath;

  while (systemOn){
    for(i=0, i < finalDestinationReached, i++){
      if(!obstacleDetected()){//obstacle not deteceted
        driveForward();
      }else{ //obstacle detected
        stopp();
        analysisObstacle();
        if(obstacleType == "water" && obstacleDepth <= river){
          riverEngine();
          driveForward();
        }else if(obstacleType == "water" && obstacleDepth > river){
          avoidObstacle(); // this function will break the while loop to recalculate the shortest path
        }else if(obstacleType == "Solid){
        avoidObstacle(); // avoid obstacle function has implementation for keeping the vehicle orientation 
        
      }

      finalDestinationReached--; 
    }
      
    stopp();
    openCompartment();
    performRescueMission(); // this function will perform the appropriate rescue mission
    returnToInitialPosition(); // this function does the calculation of how the robot returns to initial position
    systemOn = False;
  }
  

  detectShortestPath();


  
  return 0;
}
