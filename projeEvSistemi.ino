#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

#define buzzer 11

const int noteE7 = 2637;
const int noteE7_ = 2489;  // E7 flat
const int noteG7 = 3136;
const int noteA7 = 3520;
const int noteB7 = 3951;
const int noteC8 = 4186;

int buttonPin = 6;

int trigpin = 8;
int echopin = 9;

int flame_sensor_pin = 13;  // alev sensörü pini
int flame_pin = HIGH;       // alev durumu

int sel = 2;     // yeşil
int kapi = 3;    // sarı
int deprem = 4;  // kırmızı
int yangin = 5;  // kırmızı yeşilin yanındaki

int sensorPin = A0;
int esikDegeri = 5;
int veri;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(sel, OUTPUT);
  pinMode(kapi, OUTPUT);
  pinMode(deprem, OUTPUT);
  pinMode(yangin, OUTPUT);
  pinMode(flame_sensor_pin, INPUT);  // alev sensörünü giriş olarak ayarlıyoruz

// MPU6050 başlatma
  Wire.begin();//
  mpu.initialize();//MPU6050 sensörünü başlatır.

  Serial.begin(9600);
}

void loop() {
  selBaskini();
  kapiZil();
  mesafe();
  alev();
  depremAlarmi();
}

void alev() {
  flame_pin = digitalRead(flame_sensor_pin);  // sensörü oku
  if (flame_pin == LOW)                       // alev kontrolü
  {
    Serial.println(" ALEV , ALEV , ALEV ");
    digitalWrite(yangin, HIGH);  // buzerı çalıştır
    digitalWrite(buzzer, HIGH);  // buzerı çalıştır
  }  else {
    Serial.println(" Alev Yok ");
    digitalWrite(yangin, LOW);  // buzerı çalıştır
    digitalWrite(buzzer, LOW);  // buzerı durdur
  }
}
void kapiZil() {
  int switchState = digitalRead(buttonPin);
  Serial.println(switchState);
  if (switchState == HIGH) {
    digitalWrite(kapi, HIGH);
  } else {
    digitalWrite(kapi, LOW);
  }
}

void selBaskini() {
  veri = analogRead(sensorPin);
  if (veri > esikDegeri) {
    //Serial.println(veri);
    digitalWrite(sel, HIGH);
  } else {
    digitalWrite(sel, LOW);
  }
}

void mesafe() {
  int sure, mesafe;

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  sure = pulseIn(echopin, HIGH);
  mesafe = (sure / 2) / 29.1;

  if (mesafe <= 50 && mesafe >= 0) {
    // Mesafe 50 cm'den küçükse ses çal
    tone(buzzer, noteE7, 500);
    delay(500);
    //Serial.println(mesafe);
  } else {
    // Mesafe 50 cm'den büyükse sesi kapat
    noTone(buzzer);
  }
}

void depremAlarmi() {
  // Ivme ve gyro verilerini al
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  // Toplam ivme hesapla
  int16_t Toplam = sqrt(ax*ax + ay*ay + az*az);

  // Veriyi ekrana yazdır
  Serial.print("Toplam: ");
  Serial.println(Toplam);

  // Deprem algılandığında
  if (Toplam > esikDegeri) {
    Serial.println("Deprem Algılandı!");
    digitalWrite(deprem, HIGH);  // LED'i yak
    tone(buzzer, 1000);        // Buzzer'ı çal
    delay(5000);                  // 5 saniye beklet
    digitalWrite(deprem, LOW);   // LED'i kapat
    noTone(buzzer);            // Buzzer'ı kapat
  }

  delay(1000);  // 1 saniye beklet
}
