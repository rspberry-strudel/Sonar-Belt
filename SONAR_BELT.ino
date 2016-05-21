#define SONAR_FRONT_TRIGGER 16
#define SONAR_FRONT_ECHO 15

#define SONAR_LEFT_TRIGGER 13
#define SONAR_LEFT_ECHO 12

#define SONAR_RIGHT_TRIGGER 10
#define SONAR_RIGHT_ECHO 9

#define RUMBLE_ONE 7
#define RUMBLE_TWO 6
#define RUMBLE_THREE 5

#define SONAR_UPPER_BOUND 50
#define SONAR_LOWER_BOUND 0

#define SPEED_OF_SOUND_DIVISION_CONSTANT 58

#define SONAR_TIMEOUT 100000

void setup() {
  pinMode(SONAR_FRONT_TRIGGER, OUTPUT);
  pinMode(SONAR_FRONT_ECHO, INPUT);

  pinMode(SONAR_LEFT_TRIGGER, OUTPUT);
  pinMode(SONAR_LEFT_ECHO, INPUT);

  pinMode(SONAR_RIGHT_TRIGGER, OUTPUT);
  pinMode(SONAR_RIGHT_ECHO, INPUT);

  pinMode(RUMBLE_ONE, OUTPUT);
  pinMode(RUMBLE_TWO, OUTPUT);
  pinMode(RUMBLE_THREE, OUTPUT);
}

void loop() {

  if(isWithinThreshold(getDistance(SONAR_FRONT_TRIGGER, SONAR_FRONT_ECHO), SONAR_UPPER_BOUND, SONAR_LOWER_BOUND)) {
    digitalWrite(RUMBLE_ONE, HIGH);
  } else {
    digitalWrite(RUMBLE_ONE, LOW);
  }

  if(isWithinThreshold(getDistance(SONAR_LEFT_TRIGGER, SONAR_LEFT_ECHO), SONAR_UPPER_BOUND, SONAR_LOWER_BOUND)) {
    digitalWrite(RUMBLE_TWO, HIGH);
  } else {
    digitalWrite(RUMBLE_TWO, LOW);
  }

  if(isWithinThreshold(getDistance(SONAR_RIGHT_TRIGGER, SONAR_RIGHT_ECHO), SONAR_UPPER_BOUND, SONAR_LOWER_BOUND)) {
    digitalWrite(RUMBLE_THREE, HIGH);
  } else {
    digitalWrite(RUMBLE_THREE, LOW);
  }

}

long getDistance(int sonarTrigger, int sonarEcho) {
  digitalWrite(sonarTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonarTrigger, LOW);
  return pulseIn(sonarEcho, HIGH, SONAR_TIMEOUT) / SPEED_OF_SOUND_DIVISION_CONSTANT;
}

bool isWithinThreshold(long distance, int upperBound, int lowerBound) {
  return (distance < upperBound && distance > lowerBound);
}
