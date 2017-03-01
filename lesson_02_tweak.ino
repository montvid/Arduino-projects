int kartai=0;
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
  // jei mygtukas neijungtas, dega zalia lemputė
  if (digitalRead(2) == 0)
  {
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    kartai=0;
  }
  // jei mygtukas įjungtas blyksi 2 raudonos lemputės
  else
  {
    while ( digitalRead(2) == 1 )
    {
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      delay(1000);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      delay(1000);
      kartai++;
    }
    // jei lemputės sublyksėjo daugiau nei 2 kartus atleidus mygtuką užsidegs ir degs dvi raudonos lemputės. Jei mažiau tai ims vėl degti tik žalia.
    if (kartai > 2)
      {
        digitalWrite(5, 1);
        delay(5000);
      } 
   }
}
