int AOUTpin = A0;
int DOUTpin = 0;

int AOUTpi = A1;
int DOUTpi = 10;

int limit;
int value;

int imit;
int alue;

#include<IRremote.h>
#include <LiquidCrystal.h>
#include <idDHT11.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
IRrecv Yashitha(2);
decode_results results;


#define DHT11_PIN 12

void setup() {
  Serial.begin(9600);
  Yashitha.enableIRIn();
  pinMode(DOUTpin, INPUT);
  pinMode(DOUTpi , INPUT);
  pinMode(11, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("GARDEN MONITRING");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  delay(5000);

}

void loop() {

  if (Yashitha.decode(&results)) {
    Serial.println(results.value, DEC);
    Yashitha.resume();
  }

  long val = results.value;

  if (val == 117141647) {

    value = analogRead(AOUTpin);
    limit = digitalRead(DOUTpin);

    Serial.print("Rain Drop:");
    Serial.println(value);
    Serial.print("Limit:");
    Serial.print(limit);
    delay(100);

    if ((value > 1000) && (value < 1023))
    {

      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("LEVEL NORMAL");




      lcd.setCursor(2, 2);
      lcd.print("<-NO RAIN->");
      delay(3000);



    }
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("GMS");

    lcd.setCursor(0, 1);
    lcd.print("Rain Value:- ");
    lcd.setCursor(12, 1);
    lcd.println(value);
    delay(3050);


    if (value < 700)
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("LEVEL HIGH");


      lcd.setCursor(2, 2);

      lcd.print("<RAIN START>");
      delay(1000);

      digitalWrite(11, HIGH);

      delay(30000);


    }



    lcd.clear();

    lcd.setCursor(6, 0);
    lcd.print("GMS");

    lcd.setCursor(0, 1);
    lcd.print("Rain Value:- ");
    lcd.setCursor(12, 1);
    lcd.println(value);
    delay(150);


    delay(50);



  }
  value = analogRead(AOUTpin);
  limit = digitalRead(DOUTpin);

  Serial.print("Rain Drop:");
  Serial.println(value);
  Serial.print("Limit:");
  Serial.print(limit);
  delay(100);

  if (value < 700) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("LEVEL HIGH");


    lcd.setCursor(2, 2);

    lcd.print("<RAIN START>");
    delay(1000);

    digitalWrite(11, HIGH);

    delay(30000);


  }//2 wani senser eka

  if (val == 117166127) {


    alue = analogRead(AOUTpi);
    imit = digitalRead(DOUTpi);

    Serial.print("Soil Moistrue:");
    Serial.println(alue);
    Serial.print("Limit:");
    Serial.print(imit);
    delay(100);

    if ((alue > 900) && (alue < 1023))
    {

      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("LEVEL NORMAL");




      lcd.setCursor(0, 2);
      lcd.print("AVERAGE MOISTRUE");
      delay(3000);



    }
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("GMS");

    lcd.setCursor(0, 1);
    lcd.print("Soil Mois:- ");
    lcd.setCursor(12, 1);
    lcd.println(alue);
    delay(3050);


    if (alue < 700)
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("LEVEL HIGH");


      lcd.setCursor(1, 2);

      lcd.print("MORE MOISTRUE");
      delay(1000);

      digitalWrite(11, HIGH);

      delay(10000);
      digitalWrite(11, LOW);


    }



    lcd.clear();

    lcd.setCursor(6, 0);
    lcd.print("GMS");

    lcd.setCursor(0, 1);
    lcd.print("Soil Mois:- ");
    lcd.setCursor(12, 1);
    lcd.println(alue);
    delay(150);


    delay(50);



  }

  alue = analogRead(AOUTpi);
  imit = digitalRead(DOUTpi);

  Serial.print("Soil Moistrue:");
  Serial.println(alue);
  Serial.print("Limit:");
  Serial.print(imit);
  delay(100);

  if (alue < 700)
  {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("LEVEL HIGH");


    lcd.setCursor(1, 2);

    lcd.print("MORE MOISTRUE");
    delay(1000);

    digitalWrite(11, HIGH);

    delay(10000);
    digitalWrite(11, LOW);
  }

  if (val == 117115127) {

    int chk = idDHT11.read11(DHT11_PIN);
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    delay(1000);

  }

}
