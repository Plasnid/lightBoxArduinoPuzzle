int lightPin = 0;  //define a pin for Photo resistor
int lightPin2 = 3; //defining a pin for the second photo resistor
int ledPin=9;     //define a pin for LED
int ledPin2=6;
int pinOn=false;
int value, val2;


void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    
    pinMode( ledPin, OUTPUT );
    pinMode( lightPin, INPUT );
    pinMode( ledPin2, OUTPUT );
    pinMode( lightPin2, INPUT );
}

void loop()
{
    //Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    //analogWrite(ledPin, analogRead(lightPin)*-4);  //send the value to the ledPin. Depending on value of resistor 
    value = analogRead(lightPin);
    val2 = analogRead(lightPin2);
    Serial.print("resistor 1:  ");
    Serial.println(value);
    Serial.print("resistor 2:  ");
    Serial.println(val2);
    if(value<200){
      Serial.print("turn 1 off");
      digitalWrite(ledPin, LOW);
    }else{
      Serial.print("turn 1 on");
      digitalWrite(ledPin, HIGH);
    }
    if(val2<300){
      Serial.print("turn 2 off");
      digitalWrite(ledPin2, LOW);
    }else{
      Serial.print("turn 2 on");
      digitalWrite(ledPin2, HIGH);
    }
    

                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(500); //short delay for faster response to light.
}
