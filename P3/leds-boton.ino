// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  if(digitalRead(7)== HIGH){
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  else{
    digitalWrite(12, HIGH);
    delay(1500);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    delay(1500);
    digitalWrite(11, LOW);
  }
}
