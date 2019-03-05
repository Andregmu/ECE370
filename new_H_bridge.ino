int motorPinA = 9;
int motorPinB = 10;
float val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void setMotor(float val){
  if(val > 0){
    analogWrite(motorPinA, val);
    analogWrite(motorPinB, 0);
    Serial.println("forward");
  }else
  if(val < 0){
    analogWrite(motorPinA, 0);
    analogWrite(motorPinB, -val);
    Serial.println("Backward");
  }
  else{
    analogWrite(motorPinA, 0);
    analogWrite(motorPinB, 0);
    Serial.println("Brake");
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
  val = Serial.parseInt();
  setMotor(val);
  }
}


