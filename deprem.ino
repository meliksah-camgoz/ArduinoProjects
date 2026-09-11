int sensorPin=A0;
int esikDegeri=100;
int veri;

void setup() {
  Serial.begin(9600);
}

void loop() {

    veri=analogRead(sensorPin);
    if(veri>esikDegeri){
      Serial.println(veri);
    }
}

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int ledPin = 11;    // LED pin
int buzzerPin = 10;  // Buzzer pin
int esik_degeri = 100; // Deprem algılama eşiği

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // MPU6050 başlatma
  Wire.begin();//
  mpu.initialize();//MPU6050 sensörünü başlatır.

}

void loop() {
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
  if (Toplam > esik_degeri) {
    Serial.println("Deprem Algılandı!");
    digitalWrite(ledPin, HIGH);  // LED'i yak
    tone(buzzerPin, 1000);        // Buzzer'ı çal
    delay(5000);                  // 5 saniye beklet
    digitalWrite(ledPin, LOW);   // LED'i kapat
    noTone(buzzerPin);            // Buzzer'ı kapat
  }*

  delay(1000);  // 1 saniye beklet
}