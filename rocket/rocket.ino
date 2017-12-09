//Rocket Button Safety
const int RED=13;
const int BUTTON=2;
const int LAUNCHLED=4;
const int LAUNCHBUTTON=7;

void setup()
{
  pinMode(BUTTON,INPUT);
  pinMode(RED,OUTPUT);
  pinMode(LAUNCHLED,OUTPUT);
  pinMode(LAUNCHBUTTON,INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(BUTTON)==LOW)
  {
    digitalWrite(RED,LOW);
  }

  if(digitalRead(BUTTON)==HIGH)
  {
    digitalWrite(RED,HIGH);
    if(digitalRead(LAUNCHBUTTON)==HIGH)
    {
      digitalWrite(LAUNCHLED,HIGH);
      countdown(10);
    }
  }
  if(digitalRead(LAUNCHBUTTON)==LOW)
  {
    digitalWrite(LAUNCHLED,LOW);
  }


}

void countdown(int time)
{
  Serial.print("Countdown=");
  Serial.println(time);
  time=time-1;
  delay(1000);
  if(digitalRead(BUTTON)==HIGH||digitalRead(LAUNCHBUTTON)==HIGH||(digitalRead(BUTTON)==HIGH&&digitalRead(LAUNCHBUTTON)))
  {
    time=-1;
    return loop();
  }

  if(time==0){
    Serial.println("BLAST OFF");
    return loop();
  }
  countdown(time);
}
