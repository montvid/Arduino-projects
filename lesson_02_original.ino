void setup()
{
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  // put your main code here, to run repeatedly:
  // jei mygtukas įjungtas, dega žalia lemputė arba atvirkščiai - valdoma digitalRead(2) == 1 arba 0
  if (digitalRead(2) == 1)
  {
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
  }
  // jei mygtukas neįjungtas blyksi 2 raudonos lemputės
  else
  {
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    delay(250);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    delay(250);
   }
}
