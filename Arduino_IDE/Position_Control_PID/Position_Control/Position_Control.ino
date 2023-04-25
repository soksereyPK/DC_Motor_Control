#define ENCA 2 
#define ENCB 3
#define PWM 5
#define IN2 6
#define IN1 7

 int pos =0;
 
 long prevT = 0;
 float eprev = 0;
 float eintegral = 0;


 

 void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
 
 }

 void loop() {
//  setMotor(1,25,PWM,IN1,IN2);
//  delay(200);
//  Serial.println(pos);
//  setMotor(-1,25,PWM,IN1,IN2)
//  delay(200);
//  Serial.println(pos);
//  setMotor(0,25,PWM,IN1,IN2);
//  delay(200);
//  Serial.println(pos);
 int target = 1200;
 float kp = 1;
 float kd = 0;
 float ki = 0;
 long currT = micros();

 float deltaT = ((float)(currT-prevT)/1.0e6;
 prevT = currT;
 int e = pos-target; 

 float dedt = (e-eprev)/(deltaT);
 
 eintegral = eintegral + e*deltaT;

 float u = kp*e + kd*dedt + ki*eintegral;

 float pwr = fabs(u);
 if(pwr>255){
  pwr = 255;
 }
 int dir = 1;
 if (u<0){
  dir = -1;
 }

 setMotor(dir,pwr,PWM,IN1,IN2);

 eprev = e;

 Serial.print(target);
 Serial.print(" ");
 Serial.print(pos);
 Serial.println();

 void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal)
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }

  
 }
 

 void readEncoder(){
  int b = digitalRead(ENCB);
  if (b>0){
    pos++;
  }
  else{
    pos--;
  }
 }


  
 }
