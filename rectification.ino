#define A D0
#define B D1
int freq = 400;
int voltage=0;
int inc = 50;

#define pot D4

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(A, OUTPUT);
pinMode(B,OUTPUT);
pinMode(pot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(map(analogRead(pot),0,1020, 1,50));
sine_wave();
//sqaure_wave();

  
}
void sine_wave(){
  Serial.println(map(analogRead(pot),0,1020, 1,50));
  freq = map(analogRead(pot),1,1020, 1,50);
  inc = 2;
   voltage=0;
  while(voltage < 1020){
    voltage+=inc;
    analogWrite(A, voltage);
    digitalWrite(B, LOW);
    delay(freq);
    }
     
  while(voltage>=0){
    voltage-=inc;
    analogWrite(A, voltage);
    digitalWrite(B, LOW);
    delay(freq);
    }
    
    while(voltage < 1020){
    voltage+=inc;
    analogWrite(B, voltage);
    digitalWrite(A, LOW);
    delay(freq);
    }
  while(voltage>=0){
    voltage-=inc;
    analogWrite(B, voltage);
    digitalWrite(A, LOW);
    delay(freq);
    }
  }

 void sqaure_wave(){
  freq=map(analogRead(pot),1,1020, 1,50);
  analogWrite(A, 1000);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  delay(freq);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  delay(freq);
  }
