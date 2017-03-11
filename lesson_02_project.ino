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
  // If the button is off show green light
  if (digitalRead(2) == 0)
  {
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
  }
  // jei mygtukas įjungtas blyksi 2 raudonos lemputės
  // If the button is on blink 2 red lights
  else
  {
    int count=0;
    while ( digitalRead(2) == 1 )
    {
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      delay(1000);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      delay(1000);
      count++;
    }
    // jei lemputės sublyksėjo daugiau nei 2 kartus atleidus mygtuką užsidegs ir degs visos 3 lemputės. Jei mažiau tai ims vėl degti tik žalia.
    // If the button is on & the 2 red lights are blinking for 3 counts or more - turn on all 3 lights on release of the button.
    if (count > 2)
      {
        digitalWrite(3, 1);
        digitalWrite(4, 1);
        digitalWrite(5, 1);
        delay(5000);
      } 
   }
}
