const int MOTOR_A1 = 4;
const int MOTOR_A2 = 5;
const int ENA      = 9;
const int MOTOR_B1 = 7;
const int MOTOR_B2 = 6;
const int ENB      = 3;

int sensor[6];
void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);

}
void loop() {
  sensor_read();
  sensor_print();
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0 && sensor[5] == 0) {
    motor(100, 100);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 0)
  {
    motor(80, 100);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 1 && sensor[5] == 0)
  {
    motor(80, 100);
  }
  if (sensor[0] == 0 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(100, 90);
  }
  if (sensor[0] == 0 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(100, 80);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 0)
  {
    motor(100, 80);
  }
  if (sensor[0] == 0 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(70, 100);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(0, 0);
  }
  if (sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(100, 0);
  }
  if (sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(100, 0);
  }
  if (sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 0 && sensor[5] == 0)
  {
    motor(100, 0);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 1)
  {
    motor(0, 100);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 0 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 1)
  {
    motor(0, 100);
  }
  if (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 0 && sensor[3] == 0 && sensor[4] == 1 && sensor[5] == 1)
  {
    motor(0, 100);
  }
  if (sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 1 && sensor[3] == 1 && sensor[4] == 1 && sensor[5] == 1)
  {
    motor(0, 0);
  }
}


void sensor_read() {
  for (int i = 0; i < 6; i++)
  {
    sensor[i] = analogRead(i) > 300;
  }
}

void sensor_print()
{
  for (int i = 0; i < 6; i++)
  {
    sensor[i] = analogRead(i) > 300;
    Serial.print(sensor[i]);
    Serial.print('\t');
  }
  Serial.println();
}
void motor(int left_speed, int right_speed) {
  if (left_speed >= 0) {
    digitalWrite(MOTOR_B1, 1);
    digitalWrite(MOTOR_B2, 0);
    analogWrite(ENB, left_speed);
  }
  if (left_speed < 0) {
    digitalWrite(MOTOR_B1, 0);
    digitalWrite(MOTOR_B2, 1);
    analogWrite(ENB, abs(left_speed));
  }
  if (right_speed >= 0) {
    digitalWrite(MOTOR_A1, 1);
    digitalWrite(MOTOR_A2, 0);
    analogWrite(ENA, right_speed);
  }

  if (right_speed < 0) {
    digitalWrite(MOTOR_A1, 0);
    digitalWrite(MOTOR_A2, 1);
    analogWrite(ENA, abs(right_speed));
  }
}
