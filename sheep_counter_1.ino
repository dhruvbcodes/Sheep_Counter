int trg1 = 4, echo1 = 3; // trigger and echo pin - 1
int trg2 = 9, echo2 = 8; // trigger and echo pin - 2

int c = 0; // counter 

void setup()
{
  pinMode(trg1, OUTPUT);
  pinMode(trg2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float dur1, dur2;
  float dist1, dist2;
  float gate = 150;
  
  //to clear out the trigger pins
  digitalWrite(trg1, LOW);
  delayMicroseconds(2);
  digitalWrite(trg2, LOW);
  delayMicroseconds(2); 
  
  // entering sheep
  digitalWrite(trg1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trg1, LOW);  
  dur1 = pulseIn(echo1, HIGH);  
  dist1 = 0.034*(dur1/2);
  
  // exiting sheep
  digitalWrite(trg2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trg2, LOW);  
  dur2 = pulseIn(echo2, HIGH);  
  dist2 = 0.034*(dur2/2);
  
  if(dist1<gate)
  {
    c++;
    delay(700); //assuming this as the avg time it takes for a sheep to pass the gate 
  }
  
  if(dist2<gate)
  {
    if(c>0){
      c--;
      delay(700);
    }  	
  }
  
  Serial.print("\nNumber of Sheeps Inside = ");
  Serial.println(c);
  delay(500);
}