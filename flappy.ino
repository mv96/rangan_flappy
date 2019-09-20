#include<LiquidCrystal.h>
LiquidCrystal lcd (2,3,4,5,6,7); //RS, E, D4, D5, D6, D7
int ledPin = 13;
int buttonPin = 9;
const int pResistor = A5;

int ledToggle;
int previousState = HIGH;
unsigned int previousPress; //NOOB PATTHA GOBAR
volatile int buttonFlag;
int buttonDebounce = 20;
int i=0;
int pos=0;
int Speed=100;
const int trigPin = 10;
const int echoPin = 11;
String typea    = "                      ##        ######     ##       ####     ####       ########       ##                  ";  
String typeaa   = "                 ##       ####          ##     ####       ##         ##           ##                       ";int tonePin=8;
String check="game";
String check_1="identify";                                    
                
int  typeA[]    = {22,23,32,33,34,35,36,37,43,44,52,53,54,55,61,62,63,64,72,73,74,75,76,77,78,79,87,88};//28
int typeAA[]    = {17,18,26,27,28,29,40,41,47,48,49,50,58,59,69,70,82,83};//18
void vict(){
   tone(tonePin, 195, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 261, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 329, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 391, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 523, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 659, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 783, 294.7591125);
    delay(327.510125);
    delay(17.237375);
    tone(tonePin, 659, 294.7591125);
    delay(327.510125);
    delay(17.237375);
    tone(tonePin, 207, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 261, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 311, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 415, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 523, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 622, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 830, 294.7591125);
    delay(327.510125);
    delay(17.237375);
    tone(tonePin, 622, 294.7591125);
    delay(327.510125);
    delay(17.237375);
    tone(tonePin, 233, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 293, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 349, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 466, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 587, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 698, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 932, 294.7591125);
    delay(327.510125);
    delay(17.237375);
    tone(tonePin, 932, 98.2530375);
    delay(109.170041667);
    delay(5.02756770833);
    tone(tonePin, 932, 98.2530375);
    delay(109.170041667);
    delay(5.74579166667);
    tone(tonePin, 932, 97.6066359375);
    delay(108.451817708);
    delay(7.18223958333);
    tone(tonePin, 659, 294.7591125);
    delay(327.510125);
  }
void end(){
    tone(tonePin, 523, 150.0);
    delay(166.666666667);
    delay(166.666666667);
    tone(tonePin, 391, 150.0);
    delay(166.666666667);
    delay(166.666666667);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 440, 172.5);
    delay(191.666666667);
    delay(2.77777777778);
    tone(tonePin, 493, 172.5);
    delay(191.666666667);
    delay(2.77777777778);
    tone(tonePin, 440, 175.0);
    delay(194.444444444);
    tone(tonePin, 415, 225.0);
    delay(250.0);
    tone(tonePin, 466, 225.0);
    delay(250.0);
    tone(tonePin, 415, 225.0);
    delay(250.0);
    tone(tonePin, 391, 112.5);
    delay(125.0);
    tone(tonePin, 349, 112.5);
    delay(125.0);
    tone(tonePin, 391, 30.0);
    delay(33.3333333333);
    tone(tonePin, 349, 600.0);
    delay(666.666666667);
    tone(tonePin, 349, 2.5);
    delay(2.77777777778);
  }

void intro() {
tone(tonePin,660,100);
delay(150);
tone(tonePin,660,100);
delay(300);
tone(tonePin,660,100);
delay(300);
tone(tonePin,510,100);
delay(100);
tone(tonePin,660,100);
delay(300);
tone(tonePin,770,100);
delay(550);
tone(tonePin,380,100);
delay(575);
tone(tonePin,510,100);
delay(450);
tone(tonePin,380,100);
delay(400);
tone(tonePin,320,100);
delay(500);
tone(tonePin,440,100);
delay(300);
tone(tonePin,480,80);
delay(330);
tone(tonePin,450,100);
delay(150);
tone(tonePin,430,100);
delay(300);
tone(tonePin,380,100);
delay(200);
tone(tonePin,660,80);
delay(200);
tone(tonePin,760,50);
delay(150);
tone(tonePin,860,100);
delay(300);
tone(tonePin,700,80);
delay(150);
tone(tonePin,760,50);
delay(350);
tone(tonePin,660,80);
delay(300);
tone(tonePin,520,80);
delay(150);
tone(tonePin,580,80);
delay(150);
tone(tonePin,480,80);
delay(500);

tone(tonePin,510,100);
delay(450);
tone(tonePin,380,100);
delay(400);
tone(tonePin,320,100);
delay(500);
tone(tonePin,440,100);
delay(300);
tone(tonePin,480,80);
delay(330);
tone(tonePin,450,100);
delay(150);
tone(tonePin,430,100);
delay(300);
tone(tonePin,380,100);
delay(200);
tone(tonePin,660,80);
delay(200);
tone(tonePin,760,50);
delay(150);
tone(tonePin,860,100);
delay(300);
tone(tonePin,700,80);
delay(150);
tone(tonePin,760,50);
delay(350);
tone(tonePin,660,80);
delay(300);
tone(tonePin,520,80);
delay(150);
tone(tonePin,580,80);
delay(150);
tone(tonePin,480,80);
delay(500);
tone(tonePin,500,100);
delay(300);
tone(tonePin,760,100);
delay(100);
tone(tonePin,720,100);
delay(150);
tone(tonePin,680,100);
delay(150);
tone(tonePin,620,150);
delay(300);
tone(tonePin,650,150);
delay(300);
tone(tonePin,380,100);
delay(150);
tone(tonePin,430,100);
delay(150);
tone(tonePin,500,100);
delay(300);
tone(tonePin,430,100);
delay(150);
tone(tonePin,500,100);
delay(100);
tone(tonePin,570,100);
delay(220);
tone(tonePin,500,100);
delay(300);
tone(tonePin,760,100);
delay(100);
tone(tonePin,720,100);
delay(150);
tone(tonePin,680,100);
delay(150);
tone(tonePin,620,150);
delay(300);
tone(tonePin,650,200);
delay(300);
tone(tonePin,1020,80);
delay(300);
tone(tonePin,1020,80);
delay(150);
tone(tonePin,1020,80);
delay(300);
tone(tonePin,380,100);
delay(300);
tone(tonePin,500,100);
delay(300);

tone(tonePin,760,100);
delay(100);
tone(tonePin,720,100);
delay(150);
tone(tonePin,680,100);
delay(150);
tone(tonePin,620,150);
delay(300);
}
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};


void run_game()
{
  lcd.createChar(3, armsDown);
  // create a new character
  lcd.createChar(4, armsUp);
  lcd.createChar(0, heart);
  lcd.begin(16,2);
  lcd.begin(16,2);
  intro();
  while(ledToggle==0)
  {
    lcd.clear();
    delay(500);
    lcd.print("SAVE RANGAN");
    lcd.setCursor(12, 0);
    lcd.write(byte(3));
    delay(200);
    lcd.setCursor(12, 0);
    lcd.write(byte(4));
    delay(500);
    lcd.setCursor(2, 2);
    lcd.write(byte(0));
    delay(400);
    lcd.setCursor(6, 2);
    lcd.write(byte(0));
    delay(400);
    lcd.setCursor(12, 2);
    lcd.write(byte(0));
    delay(400);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write((byte)3);
  //lcd.print('O');
  //lcd.print(bala.substring(1,3));
  
  while(1)
 {
   for(i=0;i<89;i++)//
   {
    if(pos==0)
    {
      lcd.setCursor(1,0);
      lcd.print(typea.substring(i+1,16+i));
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print(typea.substring(i,16+i));
    }

    
    if(pos==1)
    {
      lcd.setCursor(1,1);
      lcd.print(typeaa.substring(i+1,16+i));
    }
    else
    {
      lcd.setCursor(0,1);
      lcd.print(typeaa.substring(i,16+i));
    }
    
   
    
    for(int j=0;j<28;j++)
    {
      if(typeA[j]==i)
      {
        if(pos==0)
        {
          gameover();
        }
      }
    }
    for(int j=0;j<18;j++)
    {
      if(typeAA[j]==i)
      {
        if(pos==1)
        {
          gameover();
        }
      }
    }
    delay(Speed);
  }
   winner();
 }
 }

void gameover (void)
{
  detachInterrupt(digitalPinToInterrupt(2));
  while(1)
  {
    lcd.clear();
    delay(500);
    lcd.print("RANGAN PATTHA");
    lcd.setCursor(0,2);
    lcd.print("Died");
    while(1){
    lcd.setCursor(6,2);
    lcd.write((byte)3);
    delay(200);
    lcd.setCursor(6,2);
    lcd.write((byte)4);
    delay(200);
    lcd.setCursor(6,2);
    lcd.write((byte)3);
    delay(200);
    lcd.setCursor(6,2);
    lcd.write((byte)4);
    delay(500);
    lcd.setCursor(6,2);
    lcd.write((byte)3);
    delay(500);
    lcd.setCursor(6,2);
    lcd.write((byte)4);
    delay(500);
    lcd.setCursor(6,2);
    lcd.write((byte)3);
    delay(500);
    lcd.setCursor(6,2);
    lcd.write((byte)4);
    delay(500);
    lcd.setCursor(6,2);
    lcd.write((byte)3);
    delay(500);
    lcd.setCursor(6,2);
    lcd.write((byte)4);
    delay(500);
    lcd.setCursor(8,2);
    lcd.print("No admit");
    end();
    delay(500);
  }
  }
}
void winner (void)
{
  detachInterrupt(digitalPinToInterrupt(2));
  while(1)
  {
    lcd.clear();
    delay(500);
    lcd.print(" WINNER! WINNER!");
    lcd.setCursor(0,1);
    lcd.print(" CHICKEN DINNER ");
    vict();
    lcd.clear();
    lcd.print("Eventually he");
    delay(500);
    lcd.setCursor(0,2);
    lcd.print("got admit");
    delay(500);
    delay(1000);
    lcd.clear();
    lcd.print("He left Dell");
    delay(1500);
  }
}

void button_ISR()
{
   buttonFlag = 1;
   if((millis() - previousPress) > buttonDebounce && buttonFlag)
  {
    previousPress = millis();
    if(digitalRead(buttonPin) == LOW && previousState == HIGH)
    {
      ledToggle =! ledToggle;
      digitalWrite(ledPin, ledToggle);
      previousState = LOW;
      if(ledToggle)
      {
       lcd.setCursor(0,0);
       lcd.write(byte(3));
       delay(200);
       lcd.setCursor(0,0);
       lcd.write(byte(4));
       delay(200);
       lcd.setCursor(0,1);
       lcd.print(' ');
       pos=0;
      }
      else
      {
       lcd.setCursor(0,1);
       lcd.write(byte(3));
       delay(200);
       lcd.setCursor(0,0);
       lcd.write(byte(4));
       delay(200);
       lcd.setCursor(0,0);
       lcd.print(' ');
       pos=1;
      }

    }
    
    else if(digitalRead(buttonPin) == HIGH && previousState == LOW)
    {
      previousState = HIGH;
    }
    buttonFlag = 0;
  }
}

int get_distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  const int duration = pulseIn(echoPin, HIGH);
  const int distance= duration*0.0133/2;
  Serial.print("Distance in inch:");
  Serial.println(distance);
  return distance;
  }
void setup()
{ lcd.begin(16, 2); // initialize for lcd set cursor
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), button_ISR, CHANGE);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() 
{
  if(Serial.available()>0) // Chek for availablity of data at Serial Port
  {
    String data = Serial.readString(); // Reading Serial Data and saving in data variable
    //Serial.println(data); // Printing the Serial data
    if (data==check){
      Serial.println("executing game ....");
      run_game();
      }
    if (data ==check_1){
      get_distance();
      }  
    else{
      lcd.clear();
      lcd.setCursor(0, 0);//col=0 row=1
      lcd.print(data);
      delay(10000);
      }
  }
 else{
  //Serial.println("no Data");
  int value = analogRead(pResistor);
  Serial.println("The value of the photoresistor is:");
  Serial.println(value);
  delay(2000);
  }
}
