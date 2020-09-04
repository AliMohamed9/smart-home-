include < LiquidCrystal.h >
const int gas = A0 ;
const int DH = A1 ;
const int flame = A2 ;
const int RS  = 8 ;
const int sensorMin = 0 ;
const int sensorMax = 1024 ;
int redled = 12 ;
int buzzer_1 = 11 ;
int buzzer_2 = 13 ;
int sensorthers = 400 ;

LiquidCrystal lcd (10 ,9 ,5 ,4 ,3 ,2 );


void setup ()
{ 
  pinMode ( redled , OUTPUT ) ;
  pinMode ( buzzer , OUTPUT ) ;
  pinMode ( gas , INPUT ) ;
  Serial.begin (9600);
  lcd.begin ( 16 , 2 );
  pinMode ( RS , OUTPUT );
   
}


void loop ()
{
  int analogsensor = analogRead (gas);
  Serial.print ( " gas : " );
  Serial.println ( analogsensor ) ;

  if ( analogsensor > sensorthers )
  {
    lcd.setCursor(0,1);
    lcd.print(" gas laeking !!");
    digitalWrite ( redled , HIGH ) ;
    tone ( buzzer , 1000 , 200 );
  }


  else 
  {
     digitalWrite ( redled , HIGH ) ;
     noTone ( buzzer );
  }
  delay ( 100 ) ;




  

  digitalWrite ( RS , LOW );
  int temp = analogRead ( DH );
  float volt = ( temp/965.0 )*5 ;
  float c = (volt - 0.5 )*100 ;
  float f = (c * 9 / 5 + 32 );
  serial.println (f) ;
  lcd.setCursor ( 0, 2 ) ;
  lcd.print ( f ) ;
  delay (3000) ; 






 
 
  int sensorReading = analogRead (A2) ;
  int range = map (sensorReading , sensorMin , sensorMax ,0 , 3);
  switch ( range )
  {
    case 0 :
    tone (buzzer_2 , 1000 , 200 );
    lcd.setCursor(5,2);
    lcd.print("close fire!");
    break ;

    case 1 : 
    noTone ( buzzer_2 );
    lcd.setCursor ( 5 , 2 ) ;
    lcd.print ( "Distant Fire!" ) ;
    break ;
  }


}

