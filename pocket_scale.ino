#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define trigPin 6
#define echoPin 7
// The amount of time (in milliseconds) between tests
#define TEST_DELAY   500

TM1637Display display(CLK, DIO);
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(115200);
pinMode(8,OUTPUT);
digitalWrite(8,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
display.setBrightness(0x0f);
uint8_t data[] = {0x0, 0x0, 0x0, 0x0};
display.setSegments(data);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance= duration*0.034/2;

  Serial.println(distance);

display.showNumberDec(distance,false,3,1);
delay(TEST_DELAY);

}
