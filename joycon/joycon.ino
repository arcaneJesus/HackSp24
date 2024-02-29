#include <Stepper.h>

const int REV = 2048;

Stepper stepper_right = Stepper(REV, 2, 4, 3, 5);
Stepper stepper_left = Stepper(REV, 9, 11, 10, 12);

void setup(){
  FILE *fptr;
  stepper_left.setSpeed(15);
  stepper_right.setSpeed(15);
  Serial.begin(9600);
}

void loop() {
  int resistor_1 = analogRead(A0);
  int resistor_2 = analogRead(A1);

  const int LL = 200;
  const int UL = 800;
  const int step_size = 15;

  if (resistor_1 < LL) {
    stepper_left.step(-step_size);
  }
  if (resistor_1 > UL) {
    stepper_left.step(step_size);
  }
  if (resistor_2 < LL) {
    stepper_right.step(-step_size);
  }
  if (resistor_2 > UL) {
    stepper_right.step(step_size);
  }

  Serial.print(resistor_1);
  Serial.print(",");
  Serial.print(resistor_2);
  Serial.print("\n")

  delay(10);
}