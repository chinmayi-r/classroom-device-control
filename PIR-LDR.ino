const int in1 = 9;
const int PIR_1 = 10;
const int PIR_2 = 5;
const int LDR = A0;
const int led = 7;
const int led1 = 8; //For debugging
unsigned long t = 0;
float LDRval = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);

  digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(in1,LOW);

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
  digitalWrite(led,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(in1,LOW);
  if(digitalRead(PIR_1)==HIGH||digitalRead(PIR_2)==HIGH){
   t=millis();
   while(millis()<(t+5000)){
    if (LDRval<120){
    digitalWrite(led,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(in1,HIGH);
    }
    else{   
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(in1,HIGH);
    }
    delay(2300);
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    if ((digitalRead(PIR_1)==HIGH||digitalRead(PIR_2)==HIGH)) {
       if (LDRval<120){
         digitalWrite(led,HIGH);
         digitalWrite(led1,HIGH);
         t=millis();
       }
     }
   }
  }
  else{
    if (LDRval<120){
         digitalWrite(led1,HIGH);
  }
  else{    
    digitalWrite(led1,LOW);
  }

    
  }
}
