/*working variables*/
int motor[]={6,9};
unsigned long lastTime;
double Input, Output;
double Setpoint=678;
double errSum, lastErr;
double kp=50;
double ki=30;
double kd=10;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  int i;
  for(i=0;i<2;i++)
      pinMode(motor[i],OUTPUT);
}

                                        // the loop routine runs over and over again forever:
void loop() {                           // read the input on analog pin 0:
  int pot = analogRead(A0);     // print out the value you read:
  Serial.println(pot);
  delay(0);                             // delay in between reads for stability

  if (pot>Setpoint){
   Input=pot;
   Compute();
   moveForward();
  }
  else if(pot<Setpoint){
   Input=pot;
   Compute();
   moveBackward();
  }
  
}


void Compute()
{
   /*How long since we last calculated*/
   unsigned long now = millis();
   double timeChange = (double)(now - lastTime);
  
   /*Compute all the working error variables*/
   double error = Setpoint - Input;
   Serial.println(error);
   errSum += (error * timeChange);
   double dErr = (error - lastErr) / timeChange;
  
   /*Compute PID Output*/
   Output = kp * error + ki * errSum + kd * dErr;
  Serial.println(Output);
   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
  
}


void moveForward()
{
  digitalWrite(motor[0], LOW);
  analogWrite(motor[1],Output/50000);
  
}

void moveBackward()
{
  analogWrite(motor[0],Output/50000);
  digitalWrite(motor[1],LOW);
}



