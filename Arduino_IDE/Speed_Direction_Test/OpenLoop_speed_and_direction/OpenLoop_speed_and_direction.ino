#include <util/atomic.h> // For the ATOMIC_BLOCK macro

#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE
#define PWM 5
#define IN2 11
#define IN1 12

int STBY = 10;
volatile int posi = 0; // specify posi as volatile: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/

void setup() {
  pinMode(STBY, OUTPUT);

  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
}

void loop() {
  
  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running
  // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
  int pos = 0; 
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }

  setMotor(1, 240, PWM, IN1, IN2);
  delay(1000);
  stop();
  delay(250);

  setMotor(-1, 240, PWM, IN1, IN2);
  delay(1000);
  stop();
  delay(250);

  setMotor(0, 25, PWM, IN1, IN2);
  delay(1000);
  stop();
  delay(250);


void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  digitalWrite(STBY, HIGH); 
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }
}

void readEncoder(){
  int b = digitalRead(ENCB);
  if(b > 0){
    posi++;
  }
  else{
    posi--;
  }
}
  
void stop(){
//enable standby  
  digitalWrite(STBY, LOW); 
}
