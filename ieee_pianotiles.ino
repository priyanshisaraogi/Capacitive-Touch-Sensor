#include <CapacitiveSensor.h> // Include the CapacitiveSensor library

// Define the capacitive touch sensor pins
#define CAP_SENSOR_1 2
#define CAP_SENSOR_2 4
#define CAP_SENSOR_3 6
#define CAP_SENSOR_4 8
  
// Define the threshold values for touch detection
#define TOUCH_THRESHOLD 200

// Create CapacitiveSensor objects for each touch sensor
CapacitiveSensor capSensor1 = CapacitiveSensor(2, 3); // 2 is the send pin, 7 is the receive pin
CapacitiveSensor capSensor2 = CapacitiveSensor(4, 5); // 3 is the send pin, 8 is the receive pin
CapacitiveSensor capSensor3 = CapacitiveSensor(6, 7); // 4 is the send pin, 9 is the receive pin
CapacitiveSensor capSensor4 = CapacitiveSensor(8, 9); // 5 is the send pin, 10 is the receive pin


void setup() {
  Serial.begin(9600); // Initialize serial communication
  // Initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Monitor to open

  // Print Graph Header
  Serial.println("Capacitance Graph");
}

void loop() {
  // Read capacitive touch sensor values
  long capValue1 = capSensor1.capacitiveSensor(30);
  long capValue2 = capSensor2.capacitiveSensor(30);
  long capValue3 = capSensor3.capacitiveSensor(30);
  long capValue4 = capSensor4.capacitiveSensor(30);
  long cap=0;
  

  // Check if touch sensor 1 is touched
  if (capValue1 > TOUCH_THRESHOLD) {
    // Trigger piano note or action for touch sensor 1
    Serial.println("Touch Sensor 1 Touched");
    tone(A3, 262, 100);
    cap = capValue1;
  }

  // Check if touch sensor 2 is touched
  if (capValue2 > TOUCH_THRESHOLD) {
    // Trigger piano note or action for touch sensor 2
    Serial.println("Touch Sensor 2 Touched");
    tone(A3, 294, 100);
    cap= capValue2;
  }

  // Check if touch sensor 3 is touched
  if (capValue3 > TOUCH_THRESHOLD) {
    // Trigger piano note or action for touch sensor 3
    Serial.println("Touch Sensor 3 Touched");
    tone(A3, 330, 100);
    cap=capValue3;
  }

  // Check if touch sensor 4 is touched
  if (capValue4 > TOUCH_THRESHOLD) 
  {
    // Trigger piano note or action for touch sensor 4
    Serial.println("Touch Sensor 4 Touched");
    tone(A3, 349, 100);
    cap=capValue4;
  }
 // Read Capacitance Value
//   long capacitance = capSensor.capacitiveSensor(30);

  // Map Capacitance Value to Graph Height
  int graphHeight = map(cap, 0, 1000, 0, 10);

  // Display Graph on Serial Monitor
  for (int i = 0; i < 10; i++) {
    if (i < graphHeight) {
      Serial.print("*");
    } else {
      Serial.print(" ");
    }
  }
  Serial.println();


