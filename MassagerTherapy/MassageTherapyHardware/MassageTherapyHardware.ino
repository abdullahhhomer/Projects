const int emgPin = 36;  // Analog pin connected to the EMG sensor

void setup() {
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);
  
  // Set the EMG sensor pin as input
  pinMode(emgPin, INPUT);
}

void loop() {
  // Read the EMG sensor value
  int emgValue = analogRead(emgPin);
  
  // Print the EMG value to the Serial Monitor
  Serial.println(emgValue);
  
  // Delay for a short period to control the data rate
  delay(10);
}
