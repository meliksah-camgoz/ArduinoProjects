#define buton 7
int ledPins[] = {8, 9, 10}; // LED pinlerini bir dizi içinde tanımlayın: Yeşil, Sarı, Kırmızı
int durum = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT); // Tüm LED pinlerini çıkış olarak ayarla
  }
  pinMode(buton, INPUT);
}

void inLeds(){
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], HIGH); // LED'i yak
    delay(2000); // 2 saniye bekle
    digitalWrite(ledPins[i], LOW); // LED'i söndür
  }
  for (int i = 3; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH); // LED'i yak
    delay(2000); // 2 saniye bekle
    digitalWrite(ledPins[i], LOW); // LED'i söndür
  }
}

void offLeds(){
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], LOW); // LED'i söndür
  }
}
void loop() {
  durum=digitalRead(buton);
  if(durum==1){
    inLeds();
  }
  else{
  	offLeds();
  }
}