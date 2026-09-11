#define buzzer 11
int trigpin=8;
int echopin=9;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
    int sure,mesafe;
  	digitalWrite(trigpin, LOW);
  	delayMicroseconds(2); 
  	digitalWrite(trigpin, HIGH);
  	delayMicroseconds(10); 
  	digitalWrite(trigpin, LOW);
 	  sure=pulseIn(echopin, HIGH);
  	mesafe=(sure/2)/29.1;
  
    if(mesafe<=50 && mesafe>=0){
      digitalWrite(buzzer, HIGH);
    }
    else{
    digitalWrite(buzzer, LOW);
    }
}


int buzer = 11 ;// buzer pini
 
int flame_sensor_pin = 13 ;// alev sensörü pini
int flame_pin = HIGH ; // alev durumu
 
void setup ( ) {
 
pinMode ( buzer , OUTPUT ); // buzerı çıkış olarak ayarlıyoruz
pinMode ( flame_sensor_pin , INPUT ); // alev sensörünü giriş olarak ayarlıyoruz
Serial.begin ( 9600 );// seri haberleşme bağlantı hızı ayarlama
}
 
void loop ( ) {
flame_pin = digitalRead ( flame_sensor_pin ) ; // sensörü oku
if (flame_pin == LOW ) // alev kontrolü
{
Serial.println ( " ALEV , ALEV , ALEV " ) ;
digitalWrite ( buzer , HIGH ) ;// buzerı çalıştır
}
 
else
{
Serial.println ( " Alev Yok " ) ;
digitalWrite ( buzer , LOW ) ; // buzerı durdur
}
}