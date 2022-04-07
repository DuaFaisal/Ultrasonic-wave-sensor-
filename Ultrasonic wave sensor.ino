// C++ code
//
int echoPin = 2;
int trigPin = 3;
int led1 = 4;
int led2 = 5;

float duration;
float distance;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delay(100); 
  
  //Set the trigPin HIGH (ACTIVE) for 10 seconds 
  digitalWrite(trigPin, HIGH);
  delay(100); 
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);
  
    //Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance < 10){
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
  }
  else if(distance > 20){
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  //Displays the distance on the Serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}