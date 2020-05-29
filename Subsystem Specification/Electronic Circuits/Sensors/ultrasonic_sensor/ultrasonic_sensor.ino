/* Ping))) Sensor

   This sketch reads a PING))) ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.

   The circuit:
    * +V connection of the PING))) attached to +5V
    * GND connection of the PING))) attached to ground
    * SIG connection of the PING))) attached to digital pin 8

   http://www.arduino.cc/en/Tutorial/Ping

   This example code is in the public domain.

 */

// constant pin number of the sensor's output:
const int led = 7;
const int ping = 8;

// serial data transmission at normal 9600 bps:
void setup() {  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  /* 1. long variables for how long the ping lasts.
     2. the distance in cm (centimetres): */
  long time, dist_cm;

  /* The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
     Give a short LOW pulse beforehand to ensure a clean HIGH pulse: */
  pinMode(ping, OUTPUT);
  digitalWrite(ping, LOW);
  delayMicroseconds(2);
  digitalWrite(ping, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping, LOW);

  /* The same pin is used to read the signal from the PING))): a HIGH
     pulse whose duration is the time (in microseconds) from the sending
     of the ping to the reception of its echo off of an object. */
  pinMode(ping, INPUT);
  time = pulseIn(ping, HIGH);

  // convert the time into a distance
  dist_cm = microsecondsToCentimeters(time);

  // Print the distance (in cm)
  Serial.print("Distance: ");
  Serial.print(dist_cm);
  Serial.print("cm");
  Serial.println();

  // Turn on the LED if the object is too close:
  if(dist_cm < 100) {
    digitalWrite(led, HIGH);
    // maybe we can put a variable here to make sure the robot can move away, when there is an obstacle?
  }
  else {
    digitalWrite(led, LOW);
  }
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  /* The speed of sound is 340 m/s or 29 microseconds per centimeter.
     The ping travels out and back, so to find the distance of the
     object we take half of the distance travelled. */
  return microseconds / 29 / 2;
}
