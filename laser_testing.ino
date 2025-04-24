const int inputPin = 15;  // GPIO5 as an example

void setup() {
  Serial.begin(9600);            // Start serial communication
  pinMode(inputPin, INPUT);      // Set pin as input (use INPUT_PULLUP or INPUT_PULLDOWN if needed)
}

void loop() {
  int pinValue = digitalRead(inputPin);  // Read the digital state (HIGH or LOW)
  Serial.println(pinValue);              // Print the value to the Serial Monitor
  delay(500);                            // Delay for readability
}
