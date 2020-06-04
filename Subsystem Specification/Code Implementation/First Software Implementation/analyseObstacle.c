#include "analyseObstacle.h"


string analyseObstacle(){
  int sendSignal = 1;
  string receiveSignal;
  int receiveDepthSignal;
  string obstacleType = "";
  
  if(receiveSignal == "water"){
    if(receiveDepthSignal <=65.8){
      obstacleType = "water";
      return obstacleType;
    }
  }else{
    obstacleType = "solid";
    return obstacleType;
  }
}
