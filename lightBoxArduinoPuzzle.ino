int lightPin1 = 6; //defining a pin for the first photoresistor
int lightPin2 = 4; //defining a pin for the second photoresistor
int lightPin3 = 2; //defining a pin for the third photoresistor
int lightPin4 = 0; //defining a pin for the fourth photoresistor
int ledPin1 = 3;   //define a pin for LED
int ledPin2 = 5;
int ledPin3 = 7;
int ledPin4 = 10;
int MagRelay = 12; //define a pin for electromagnet relay
volatile byte relayState = LOW;  //set state of relay
int pinOn = false;
int val1, val2, val3, val4;



void setup()
{
  Serial.begin(9600);  //Begin serial communcation

  pinMode( ledPin1, OUTPUT );
  pinMode( lightPin1, INPUT );
  pinMode( ledPin2, OUTPUT );
  pinMode( lightPin2, INPUT );
  pinMode( ledPin3, OUTPUT );
  pinMode( lightPin3, INPUT );
  pinMode( ledPin4, OUTPUT );
  pinMode( lightPin4, INPUT );
  pinMode( MagRelay, OUTPUT );
  digitalWrite( MagRelay, LOW );  //set relay to on
}

void loop()
{
  //Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
  //analogWrite(ledPin, analogRead(lightPin)*-4);  //send the value to the ledPin. Depending on value of resistor
  val1 = analogRead(lightPin1);
  val2 = analogRead(lightPin2);
  val3 = analogRead(lightPin3);
  val4 = analogRead(lightPin4);
  Serial.print("resistor 1:  ");
  Serial.println(val1);
  Serial.print("resistor 2:  ");
  Serial.println(val2);
  Serial.print("resistor 3:  ");
  Serial.println(val3);
  Serial.print("resistor 4:  ");
  Serial.println(val4);
  if (val1 < 100) {
    Serial.print("Turn 1 OFF\n");
    digitalWrite(ledPin1, LOW);
  } else {
    Serial.print("Turn 1 ON\n");
    digitalWrite(ledPin1, HIGH);
  }
  if (val2 < 300) {
    Serial.print("Turn 2 OFF\n");
    digitalWrite(ledPin2, LOW);
  } else {
    Serial.print("Turn 2 ON\n");
    digitalWrite(ledPin2, HIGH);
  }
  if (val3 < 40) {
    Serial.print("Turn 3 OFF\n");
    digitalWrite(ledPin3, LOW);
  } else {
    Serial.print("Turn 3 ON\n");
    digitalWrite(ledPin3, HIGH);
  }
  if (val4 < 15) {
    Serial.print("Turn 4 OFF\n");
    digitalWrite(ledPin4, LOW);
  } else {
    Serial.print("Turn 4 ON\n");
    digitalWrite(ledPin4, HIGH);
  }
  if (val1>100 && val2>300 && val3>40 && val4>15){
    Serial.print("Turn Magnet OFF");
    digitalWrite( MagRelay, HIGH);
    relayState = HIGH;
  }else{
    Serial.print("Magnet is ON");
    digitalWrite( MagRelay, LOW);
    relayState = LOW;
  }

  //you have  to divide the value. for example,
  //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
  delay(500); //short delay for faster response to light.
}
