/* Tool Changer Starter Code
The when the Raspberry Pi Pico W is powered on,
the code will open the cover to the tool changer.
When the beam is broken, the cover will close.
*/

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo

int pos = 0;    // variable to store the servo position
int val = 0;    // variable for laser sensor input pin on the Pico
int coverOpen = 0; // state variable will be set to 0 if the cover is open, and 1 if the cover is closed
const int inputPin = 15;  // GPIO5 as an example

void setup() {
  myservo.attach(16);     // attaches the servo on pin 16 to the Servo object
  Serial.begin(9600);            // Start serial communication
  pinMode(inputPin, INPUT);      // Set pin as input (use INPUT_PULLUP or INPUT_PULLDOWN if needed)
}

void loop() {

  int pinValue = digitalRead(inputPin);  // Read the digital state (HIGH or LOW)


  if (coverOpen == 0){
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    coverOpen = 1;
  }

  if (pinValue == 0){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    delay(3000);
    coverOpen = 0;
  }

}
