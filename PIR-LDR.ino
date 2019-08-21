const int in1 = 9;//Bulb relay
const int in2 = 11;//Fan relay
const int PIR_1 = 10;
const int PIR_2 = 5;
const int LDR = A0;
const int led = 7;
const int led1 = 8; //For debugging
unsigned long t = 0;
float LDRval = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);

  digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  while(millis() < 5000){
    digitalWrite(led,HIGH);
    digitalWrite(led1,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    delay(1000);
  }
  digitalWrite(led,LOW); 

  digitalWrite(led1,LOW); 
}

void loop() {
  LDRval = analogRead(LDR);

  if(digitalRead(PIR_1)==HIGH||digitalRead(PIR_2)==HIGH){
   digitalWrite(led,LOW);
   digitalWrite(led1,LOW);
   digitalWrite(in1,LOW);
   t=millis();
   while(millis()<(t+5000)){
    if (LDRval<120){
    digitalWrite(led,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,HIGH);
    }
    else{   
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    }
    delay(2300);
    if ((digitalRead(PIR_1)==HIGH||digitalRead(PIR_2)==HIGH)) {
       digitalWrite(led,LOW);
       digitalWrite(led1,LOW);
       digitalWrite(in1,LOW);
       if (LDRval<120){
         digitalWrite(led,HIGH);
         digitalWrite(led1,HIGH);
         t=millis();
       }
       else{
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        if (LDRval<120){
         digitalWrite(led1,HIGH);    
         }
        else{    
         digitalWrite(led1,LOW);
         }
        }
      }
    }
   }
  else{
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    if (LDRval<120){
         digitalWrite(led1,HIGH);
         digitalWrite(in1,LOW);
    }
    else{    
     digitalWrite(led1,LOW);
    }
   }
}
