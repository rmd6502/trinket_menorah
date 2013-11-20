#define MOSI 0
#define SCK 1
#define SS 2

void setup()
{
  pinMode(SS,OUTPUT);
  digitalWrite(SS,HIGH);
  pinMode(MOSI,OUTPUT);
  pinMode(SCK,OUTPUT);
}

uint8_t count = 0;
uint8_t delayCount = 0;
void loop()
{
  digitalWrite(SS,LOW);
  shiftOut(MOSI,SCK,LSBFIRST,count);
  digitalWrite(SS,HIGH);

  ++count;
  delay(100);
}
