
int val; 
int encoder0PinA = 4;
int encoder0PinB = 5;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;
float setpoint = 0;
float angle = 0;
float error = 0;
unsigned long lastTime;
float errSum, lastErr;
float kp;
float ki;
float kd;
 
void setup() { 
    pinMode (encoder0PinA,INPUT);
    pinMode (encoder0PinB,INPUT);
    Serial.begin (9600);
} 

void loop() { 
    n = digitalRead(encoder0PinA);
    if ((encoder0PinALast == LOW) && (n == HIGH)) {
      if (digitalRead(encoder0PinB) == LOW) {
        encoder0Pos--;
      } else {
        encoder0Pos++;
      }
      Serial.print (encoder0Pos);
      Serial.print ("/");
    } 
    encoder0PinALast = n;
   
    angle = encoder0Pos; 
    error = angle - setpoint;
    
} 
