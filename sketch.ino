
const int buttonPin = 12;
const int led1 = 4;
const int led2 = 7;
const int led3 = 8;
const int led0 = 2;
const int pwmPin = 3;

const int S0 = A1;
const int S1 = A2;
const int S2 = A3;
const int S3 = A4;

int buttonState = 0;
int counter = 0;
int fadeValue = 0;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(buttonPin, INPUT);
  pinMode(pwmPin, OUTPUT);

  digitalWrite(S3, 0);
  digitalWrite(S2, 0);
  digitalWrite(S1, 0);
  digitalWrite(S0, 0);

  Serial.begin(9600);
  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    moveNext();
    delay(500);
  }

}

void moveNext() {
  if (counter < 15) counter += 1;
  else counter = 0;

  bool a = bitRead(counter, 0);     
  bool b = bitRead(counter, 1);
  bool c = bitRead(counter, 2);
  bool d = bitRead(counter, 3);

  digitalWrite(S0, a);        
  digitalWrite(S1, b);
  digitalWrite(S2, c);
  digitalWrite(S3, d);

  digitalWrite(led0, a);        
  digitalWrite(led1, b);
  digitalWrite(led2, c);
  digitalWrite(led3, d);

  Serial.print(a);
  Serial.print(b);
  Serial.print(c);
  Serial.println(d);

}
