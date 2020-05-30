#include "ultra_sensor.h"

// ultrasonic_Sensor_front_middle
int ultrasonic_Sensor_front_middle_trig;
int ultrasonic_Sensor_front_middle_echo;
int ultrasonic_Sensor_front_middle_distance;
long ultrasonic_Sensor_front_middle_duration;

  // ultrasonic_Sensor_front_left
int ultrasonic_Sensor_front_left_trig;
int ultrasonic_Sensor_front_left_echo;
int ultrasonic_Sensor_front_left_distance;
long ultrasonic_Sensor_front_left_duration;

  // ultrasonic_Sensor_front_right
int ultrasonic_Sensor_front_right_trig;
int ultrasonic_Sensor_front_right_echo;
int ultrasonic_Sensor_front_right_distance;
long ultrasonic_Sensor_front_right_duration;


// ultrasonic_Sensor_back_middle
int ultrasonic_Sensor_back_middle_trig;
int ultrasonic_Sensor_back_middle_echo;
int ultrasonic_Sensor_back_middle_distance;
long ultrasonic_Sensor_back_middle_duration;

  // ultrasonic_Sensor_back_left
int ultrasonic_Sensor_back_left_trig;
int ultrasonic_Sensor_back_left_echo;
int ultrasonic_Sensor_back_left_distance;
long ultrasonic_Sensor_back_left_duration;

  // ultrasonic_Sensor_back_right
int ultrasonic_Sensor_back_right_trig;
int ultrasonic_Sensor_back_right_echo;
int ultrasonic_Sensor_back_right_distance;
long ultrasonic_Sensor_back_right_duration;


void ultrasonic_Sensor_front_middle(){
  // Clears the trigPin
  
  digitalWrite(ultrasonic_Sensor_front_middle_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_front_middle_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_front_middle_trig, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
   ultrasonic_Sensor_front_middle_duration = pulseIn(ultrasonic_Sensor_front_middle_echo, HIGH);
  
// Calculating the distance
  ultrasonic_Sensor_front_middle_distance = ultrasonic_Sensor_front_middle_duration * 0.034/2;
  }

  
 void ultrasonic_Sensor_front_left(){
   // Clears the trigPin
  
  digitalWrite(ultrasonic_Sensor_front_left_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_front_left_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_front_left_trig, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
   ultrasonic_Sensor_front_left_duration = pulseIn(ultrasonic_Sensor_front_left_echo, HIGH);
  
// Calculating the distance
  ultrasonic_Sensor_front_left_distance = ultrasonic_Sensor_front_left_duration * 0.034/2;
  }


   void ultrasonic_Sensor_front_right(){
   // Clears the trigPin
  
  digitalWrite(ultrasonic_Sensor_front_right_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_front_right_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_front_right_trig, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
   ultrasonic_Sensor_front_right_duration = pulseIn(ultrasonic_Sensor_front_right_echo, HIGH);
  
// Calculating the distance
  ultrasonic_Sensor_front_right_distance = ultrasonic_Sensor_front_right_duration * 0.034/2;
  }


// Calculating the distance for the back side 

void ultrasonic_Sensor_back_middle(){
  // Clears the trigPin
  
  digitalWrite(ultrasonic_Sensor_back_middle_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_back_middle_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_back_middle_trig, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
   ultrasonic_Sensor_back_middle_duration = pulseIn(ultrasonic_Sensor_back_middle_echo, HIGH);
  
// Calculating the distance
  ultrasonic_Sensor_back_middle_distance = ultrasonic_Sensor_back_middle_duration * 0.034/2;
  }

  
 void ultrasonic_Sensor_back_left(){
   // Clears the trigPin
  
  digitalWrite(ultrasonic_Sensor_back_left_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_back_left_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_back_left_trig, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
   ultrasonic_Sensor_back_left_duration = pulseIn(ultrasonic_Sensor_back_left_echo, HIGH);
  
// Calculating the distance
  ultrasonic_Sensor_back_left_distance = ultrasonic_Sensor_back_left_duration * 0.034/2;
  }


   void ultrasonic_Sensor_back_right(){
   // Clears the trigPin
  
  digitalWrite(ultrasonic_Sensor_back_right_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_back_right_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_back_right_trig, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
   ultrasonic_Sensor_back_right_duration = pulseIn(ultrasonic_Sensor_back_right_echo, HIGH);
  
// Calculating the distance
  ultrasonic_Sensor_back_right_distance = ultrasonic_Sensor_back_right_duration * 0.034/2;
  }
