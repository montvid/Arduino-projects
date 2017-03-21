const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;
const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup()
{
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop()
{
  //Calculate temperature from the sensor value 0-1023 range
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue / 1024.0 * 5.0;
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  //Choose LED color for different temperatures from 0-255 range
  if(temperature < baselineTemp)
  {
    analogWrite(redLEDPin, 0);
    analogWrite(greenLEDPin, 0);
    analogWrite(blueLEDPin, 50);
  }
  if(temperature >= baselineTemp)
  {
    analogWrite(redLEDPin, 0);
    analogWrite(greenLEDPin, 150);
    analogWrite(blueLEDPin, 0);
  }
  if(temperature >= baselineTemp + 2)
  {
    analogWrite(redLEDPin, 250);
    analogWrite(greenLEDPin, 0);
    analogWrite(blueLEDPin, 0);
  }
  delay(5000);
}
