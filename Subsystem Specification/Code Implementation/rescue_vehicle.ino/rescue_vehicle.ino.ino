bool done = false;
//motor
int in1 = 7;
int in2 = 6;
int in3 = 8;
int in4 = 9;

//motion sensor
int ledPin;    // LED
int pirPin;     // PIR Out pin
int pirStat = 0;    // PIR status

//light sensors
int left_Sensor = 5;
int right_Sensor = 13;

//sound sensor
int soundDetectedPin;
int soundDetectedVal = HIGH;
boolean bAlarm = false;
unsigned long lastSoundDetectTime;
int soundAlarmTime = 500;

// ultrasonic_Sensor_middle
int ultrasonic_Sensor_middle_trig = 11;
int ultrasonic_Sensor_middle_echo = 12;
int ultrasonic_Sensor_middle_distance; // bez
long ultrasonic_Sensor_middle_duration;

// ultrasonic_Sensor_left
int ultrasonic_Sensor_left_trig = 10; // 10
int ultrasonic_Sensor_left_echo = 4; //4
int ultrasonic_Sensor_left_distance; // bez
long ultrasonic_Sensor_left_duration;

// ultrasonic_Sensor_right
int ultrasonic_Sensor_right_trig = 2;
int ultrasonic_Sensor_right_echo = 3;
int ultrasonic_Sensor_right_distance; // bez
long ultrasonic_Sensor_right_duration;

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

int predkosc = 160;
bool received = false;


void setup() {
  //motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //motion sensor
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  //light sensors
  pinMode(left_Sensor, INPUT);
  pinMode(right_Sensor, INPUT);

  //ultrasonic sensors
  pinMode(ultrasonic_Sensor_middle_trig, OUTPUT);
  pinMode(ultrasonic_Sensor_middle_echo, INPUT);
  pinMode(ultrasonic_Sensor_left_trig, OUTPUT);
  pinMode(ultrasonic_Sensor_left_echo, INPUT);
  pinMode(ultrasonic_Sensor_right_trig, OUTPUT);
  pinMode(ultrasonic_Sensor_right_echo, INPUT);
  pinMode(ultrasonic_Sensor_back_middle_trig, OUTPUT);
  pinMode(ultrasonic_Sensor_back_middle_echo, INPUT);
  pinMode(ultrasonic_Sensor_back_left_trig, OUTPUT);
  pinMode(ultrasonic_Sensor_back_left_echo, INPUT);
  pinMode(ultrasonic_Sensor_back_left_trig, OUTPUT);
  pinMode(ultrasonic_Sensor_back_right_echo, INPUT);

  //sound sensor
  pinMode (soundDetectedPin, INPUT);


  Serial.begin(9600);
}
void loop() {
  //receiving info from car interface
  recvInfo();

  if (received) {
    digitalWrite(in1, LOW);
    analogWrite(in2, predkosc); // 191
    digitalWrite(in3, LOW);
    analogWrite(in4, predkosc); // 191

    //sensors start sensing

    sound_sensor();

    motion_sensor();

    ultrasonic_Sensor_middle();
    ultrasonic_Sensor_left();
    ultrasonic_Sensor_right();
    ultrasonic_Sensor_back_middle();
    ultrasonic_Sensor_back_left();
    ultrasonic_Sensor_back_right();

    if (bAlarm == true or pirStat == HIGH) {
      if (ultrasonic_Sensor_left_distance >= 15 && ultrasonic_Sensor_middle_distance >= 15 && ultrasonic_Sensor_right_distance >= 15) {
        forward();
        delay(100);
      }
      else if ((ultrasonic_Sensor_left_distance >= 15 && ultrasonic_Sensor_middle_distance >= 15) && (ultrasonic_Sensor_right_distance <= 15)){
        left();
        delay(75);
      }
      else if ((ultrasonic_Sensor_left_distance <= 15) && (ultrasonic_Sensor_middle_distance >= 15 && ultrasonic_Sensor_right_distance >= 15)){
        right();
        delay(75);
      }
      else if ((ultrasonic_Sensor_left_distance >= 15 && ultrasonic_Sensor_right_distance >= 15) && (ultrasonic_Sensor_middle_distance <= 15)){
        if (ultrasonic_Sensor_left_distance >= ultrasonic_Sensor_right_distance){
          reverse();
          delay(75);
          left();
          delay(75);
        }
        else {
          reverse();
          delay(75);
          right();
          delay(75);
        }
      }

      else {
        stops();
          received = false;
        }
    } else {
      stops();
    }
  }

}

void forward() {
  digitalWrite(in1, LOW);
  analogWrite(in2, predkosc); // 191
  digitalWrite(in3, LOW);
  analogWrite(in4, predkosc); // 191
}
void reverse() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void left() {
  digitalWrite(in1, LOW);
  analogWrite(in2, predkosc / 2);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}
void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  analogWrite(in4, predkosc / 2);

}
void stops() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);

}

void ultrasonic_Sensor_middle() {
  digitalWrite(ultrasonic_Sensor_middle_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonic_Sensor_middle_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_middle_trig, LOW);
  ultrasonic_Sensor_middle_duration = pulseIn(ultrasonic_Sensor_middle_echo, HIGH);
  ultrasonic_Sensor_middle_distance = ultrasonic_Sensor_middle_duration * 0.034 / 2;
}

void ultrasonic_Sensor_left() {
  // Clears the trigPin

  digitalWrite(ultrasonic_Sensor_left_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_left_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_left_trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  ultrasonic_Sensor_left_duration = pulseIn(ultrasonic_Sensor_left_echo, HIGH);

  // Calculating the distance
  ultrasonic_Sensor_left_distance = ultrasonic_Sensor_left_duration * 0.034 / 2;
}

void ultrasonic_Sensor_right() {

  digitalWrite(ultrasonic_Sensor_right_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_right_trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(ultrasonic_Sensor_right_trig, LOW);

  ultrasonic_Sensor_right_duration = pulseIn(ultrasonic_Sensor_right_echo, HIGH);

  ultrasonic_Sensor_right_distance = ultrasonic_Sensor_right_duration * 0.034 / 2;
}

// Calculating the distance for the back side

void ultrasonic_Sensor_back_middle() {
  // Clears the trigPin

  digitalWrite(ultrasonic_Sensor_back_middle_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_back_middle_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_back_middle_trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  ultrasonic_Sensor_back_middle_duration = pulseIn(ultrasonic_Sensor_back_middle_echo, HIGH);

  // Calculating the distance
  ultrasonic_Sensor_back_middle_distance = ultrasonic_Sensor_back_middle_duration * 0.034 / 2;
}


void ultrasonic_Sensor_back_left() {
  // Clears the trigPin

  digitalWrite(ultrasonic_Sensor_back_left_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_back_left_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_back_left_trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  ultrasonic_Sensor_back_left_duration = pulseIn(ultrasonic_Sensor_back_left_echo, HIGH);

  // Calculating the distance
  ultrasonic_Sensor_back_left_distance = ultrasonic_Sensor_back_left_duration * 0.034 / 2;
}


void ultrasonic_Sensor_back_right() {
  // Clears the trigPin

  digitalWrite(ultrasonic_Sensor_back_right_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(ultrasonic_Sensor_back_right_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_Sensor_back_right_trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  ultrasonic_Sensor_back_right_duration = pulseIn(ultrasonic_Sensor_back_right_echo, HIGH);

  // Calculating the distance
  ultrasonic_Sensor_back_right_distance = ultrasonic_Sensor_back_right_duration * 0.034 / 2;
}

void sound_sensor() {
  soundDetectedVal = digitalRead (soundDetectedPin) ; // read the sound alarm time

  if (soundDetectedVal == LOW) // If we hear a sound
  {

    lastSoundDetectTime = millis(); // record the time of the sound alarm
    // The following is so you don't scroll on the output screen
    if (!bAlarm) {
      Serial.println("There is a person to be rescued!");
      bAlarm = true;
    }
  }
  else
  {
    if ( (millis() - lastSoundDetectTime) > soundAlarmTime  &&  bAlarm) {
      Serial.println("No sound detected!");
      bAlarm = false;
    }
  }
}

void motion_sensor() {
  pirStat = digitalRead(pirPin);
  if (pirStat == HIGH) {            // if motion detected
    digitalWrite(ledPin, HIGH);  // turn LED ON
    Serial.println("Motion detected!");
  }
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
  }
}

void recvInfo() {
  done = false;
  while (Serial.available() > 0) {
    delay(5);
    int receivedChar = Serial.read();
    done = true;
  }
  if (done) {
    received = !received;
  }
}
