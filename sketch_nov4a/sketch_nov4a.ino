void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("bonjour :3");

  pinMode(15, OUTPUT);
  pinMode(4, INPUT);
}

void blink() {
  digitalWrite(16,HIGH);
  delay(500);
  digitalWrite(16,LOW);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("...");

  int potValue = analogRead(4);
  int brightness = map(potValue, 0, 4095, 0, 255);
  analogWrite(15, brightness);
  Serial.println(brightness);
  delay(50);
}
