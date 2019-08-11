#define trigPin 9
#define echoPin 10
#define LED 2
int red_light_pin= 6;
int green_light_pin = 11;
int blue_light_pin = 5;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  if (distance <=15 && distance >=5)
  {
    RGB_color(0, 255, 0); // Green
    delay(100);
    RGB_color(0, 0, 0); // Green
    delay(100);
    RGB_color(0, 255, 0); // Green
    delay(100);
    RGB_color(0, 0, 0); // Green
    delay(100);
  }
  if (distance <5)
  {
   RGB_color(255,0,0); 
   delay(100);
   digitalWrite(LED, HIGH);
   delay(100);
   RGB_color(0,0,0); 
   delay(100);
   digitalWrite(LED, LOW);
   delay(100);
   RGB_color(255,0,0);
   delay(100);
   digitalWrite(LED, HIGH);
   delay(100);
   RGB_color(0,0,0);
   delay(100); 
   digitalWrite(LED, LOW);
   delay(100);
  }
  if (distance >=30)
  {
    RGB_color(0, 0, 255); // Blue
    delay(1000);
  }
  else 
  {
    digitalWrite(LED,LOW);
  }
  Serial.print("Distance : ");
  Serial.println(distance);
  delay(1000);
}
