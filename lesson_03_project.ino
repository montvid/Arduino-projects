const int sensorPin = A0;
const int temp = 1;
float compare = 0.0;
int difference = 0;

void setup()
{
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT); //3 LEDs
    digitalWrite(pinNumber, LOW);
  }
  pinMode(5, INPUT); //1 Button
}
void loop()
{
  if (digitalRead(5) == HIGH)
  {
    //Read and calculate temperature when the button is pushed.
    int sensorVal = analogRead(sensorPin);
    float voltage = sensorVal / 1024.0 * 5.0;
    float temperature = (voltage - .5) * 100;
    //If there is nothing to compare add a temparature value to compare, write to the console, blink 1 led 
    if (compare == 0.0)
    {
      compare = temperature;
      Serial.print("Comparing between degrees C ");
      Serial.print(compare);
      digitalWrite(2, HIGH);
      delay(500);   
    }
    //If there is a compare value compare it to the new value and output console text and turn on lights
    //according to the rounded(integrer abs function) difference in temperature - 0;1;2; more than 2.
    else
    {
      difference = compare - temperature;
      difference=abs(difference);
      compare = 0.0;
      
      Serial.print(" and C ");
      Serial.print(temperature);
      Serial.print(" rounded differenceerence is ");
      Serial.println(difference);
      
      if(difference < temp)
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
      }
      if(difference == temp)
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
      }
      if(difference > temp)
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
      }
      if(difference > temp + 1)
      {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
      }
      delay(2000);
    }
    //Turn the lights off after use
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
}
