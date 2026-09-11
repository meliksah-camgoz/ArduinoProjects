// Define the pin numbers
const int kapi = 6;
const int buttonPin = 2;
const int buzzer = 7; // Assign a pin for the buzzer

// Define the notes' frequencies in Hertz
const int noteE7 = 2637;
const int noteE7_ = 2489; // E7 flat
const int noteG7 = 3136;
const int noteA7 = 3520;
const int noteB7 = 3951;
const int noteC8 = 4186;

void setup() {
  pinMode(kapi, OUTPUT);  // Set pin 7 as an output for the LED
  pinMode(buttonPin, INPUT); // Set pin 2 as an input for the switch
  pinMode(buzzer, OUTPUT); // Set pin for the buzzer as an output
}

void loop() {
  int switchState = digitalRead(buttonPin); // Read the state of the switch
  if (switchState == HIGH) {
    digitalWrite(kapi, HIGH); // If the switch is on, turn the LED on
    playJingleBells();          // Play Jingle Bells melody
  } else {
    digitalWrite(kapi, LOW);  // If the switch is off, turn the LED off
    noTone(buzzer);          // Stop playing any tone
  }
}

void playJingleBells() {
  // Play the first line of "Jingle Bells" melody
  tone(buzzer, noteE7, 500);
  delay(500);
  tone(buzzer, noteE7, 500);
  delay(500);
  tone(buzzer, noteE7, 500);
  delay(500);
  tone(buzzer, noteE7, 500);
  delay(500);
  tone(buzzer, noteE7, 500);
  delay(500);
  tone(buzzer, noteG7, 500);
  delay(400);
  tone(buzzer, noteC8, 500);
  delay(100);
  tone(buzzer, noteB7, 500);
  delay(500);
  // ... Add more notes to complete the song

  // Add a small delay to prevent immediate loop repetition
  delay(500);
}