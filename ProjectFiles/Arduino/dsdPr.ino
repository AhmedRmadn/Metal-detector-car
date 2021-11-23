const int IN11 = 4;
const int IN12 = 5;
const int EN = 3;
const int IN21 = 6;
const int IN22 = 7;
const int trigPin = 9;
const int P = 12;
const int U = 11;
const int b0 = 8;
const int b1 = 10;
///const String BUZZ = "A5";
///const String MOTION = "A4";
int bluetooth;
int limitSwitch = 13;
int state = LOW;
long duration;
int distance;
bool pro=false;






void setup() {

  pinMode (IN11, OUTPUT);
  pinMode (IN12, OUTPUT);
  pinMode (EN, OUTPUT);
  pinMode (IN21, OUTPUT);
  pinMode (IN22, OUTPUT);
  pinMode(limitSwitch,INPUT);
  pinMode(2, OUTPUT);  // buzzer on pin 3
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(A1, INPUT); // Sets the echoPin as an Input
  pinMode(P,OUTPUT);
  pinMode(U,OUTPUT);
  pinMode(b0,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(A5,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A0,INPUT);
  pinMode(A4,INPUT);
  Serial.begin(9600); // Starts the serial communication


}

void loop() {
  
  digitalWrite(P,prox());
  digitalWrite(U,ultra());
  if(Serial.available()>0){

      bluetooth=Serial.read();
  }  
     if(bluetooth==49){
          digitalWrite(b0,HIGH);
          digitalWrite(b1,HIGH);
     }
     else if(bluetooth==51){
         digitalWrite(b0,HIGH);
         digitalWrite(b1,LOW);
    }
     else if(bluetooth==52){
         digitalWrite(b0,LOW);
         digitalWrite(b1,HIGH);
    }
    else if(bluetooth==50){
         digitalWrite(b0,LOW);
         digitalWrite(b1,LOW);
    }

    /// Serial.println(bluetooth);
    /// Serial.print(digitalRead(A2));Serial.print(digitalRead(A3));Serial.print(digitalRead(A3));Serial.print(digitalRead(A4));
    if(digitalRead(A2)==0 && digitalRead(A3)==1&&digitalRead(A4)==0&&digitalRead(A5)==1){
      buzzerOff();
      forward();
      pro=false;
    }
    else if(digitalRead(A2)==1 && digitalRead(A3)==0&&digitalRead(A4)==0&&digitalRead(A5)==1){
      buzzerOff();
      left();
      pro=false;
    }
    else if(digitalRead(A2)==0 && digitalRead(A3)==1&&digitalRead(A4)==1&&digitalRead(A5)==0){
      buzzerOff();
      right();
      pro=false;
    }
    else {
      buzzerOff();
      Stop();
      bluetooth=50;
      pro=false;
    }
     if(digitalRead(A0)==1){   
      
      ///Prox
      buzzerOn();
     
      pro=true;
      delay(1000);
    }
    else{
      ///Ultra
      pro=false;
      buzzerOff();
      

     }
    





  }


void forward(){
  analogWrite(EN,150);
  digitalWrite(IN11,HIGH);
  digitalWrite(IN12,LOW);
  digitalWrite(IN21,HIGH);
  digitalWrite(IN22,LOW);

  
}
void backward(){
  analogWrite(EN,80);
  digitalWrite(IN11,LOW);
  digitalWrite(IN12,HIGH);
  digitalWrite(IN21,LOW);
  digitalWrite(IN22,HIGH);

  
}
void right(){
  analogWrite(EN,200);
  digitalWrite(IN11,LOW);
  digitalWrite(IN12,HIGH);
  digitalWrite(IN21,HIGH);
  digitalWrite(IN22,LOW);

  
}

void left(){
  analogWrite(EN,200);
  digitalWrite(IN11,HIGH);
  digitalWrite(IN12,LOW);
  digitalWrite(IN21,LOW);
  digitalWrite(IN22,HIGH);

  
}
void Stop(){
  analogWrite(EN,0);
  digitalWrite(IN11,LOW);
  digitalWrite(IN12,LOW);
  digitalWrite(IN21,LOW);
  digitalWrite(IN22,LOW);

  
}



bool ultra(){
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(A1, HIGH);
// Calculating the distance
distance= duration*0.034/2;
if(distance<=15){
  return 1;
}
else{
  return 0;
}
}
int prox(){
    int val = digitalRead(limitSwitch);
    if( val != state ){
       state = val;
       if( state == 0 )
         return 1 ;
       else
        return 0;
    }
}
void buzzerOn(){
  digitalWrite(2, HIGH); // switch buzzer off
}
void buzzerOff(){
  digitalWrite(2, LOW); // switch buzzer off
}
