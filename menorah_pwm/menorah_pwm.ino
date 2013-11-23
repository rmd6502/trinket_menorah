#define MOSI 0
#define SCK 1
#define SS 2

#define MILLIS_PER_DAY (24L * 3600L * 1000L)

uint32_t startMillis = 0;
void setup()
{
  pinMode(SS,OUTPUT);
  digitalWrite(SS,HIGH);
  pinMode(MOSI,OUTPUT);
  pinMode(SCK,OUTPUT);
  startMillis = millis();
}

uint8_t pwmLevel = 50;
uint8_t count = 1;
uint8_t pwmCount = 0;

void loop()
{
  uint8_t newCount = pwmCount + pwmLevel;
  digitalWrite(SS,LOW);
  shiftOut(MOSI,SCK,LSBFIRST,(newCount < pwmCount) ? count : 0);
  digitalWrite(SS,HIGH);

  pwmCount = newCount;
  if (millis() - startMillis >= MILLIS_PER_DAY) {
    if (count == 255) {
      count = 0;
    } else {
      count = (count << 1) + 1;
    }
    startMillis = millis();
  }
}
