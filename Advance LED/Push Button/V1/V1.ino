// Menyalakan LED dengan Push Button
const int ledPin = 6;     // Pin yang terhubung ke LED
const int buttonPin = 7;  // Pin yang terhubung ke push button

int buttonState = 0;  // Variabel untuk menyimpan status push button

void setup() {
  // Inisialisasi pin LED sebagai output
  pinMode(ledPin, OUTPUT);
  // Inisialisasi pin push button sebagai input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Baca status push button
  buttonState = digitalRead(buttonPin);

  // Periksa apakah push button ditekan
  if (buttonState == HIGH) {
    // Jika ditekan, nyalakan LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Jika tidak ditekan, matikan LED
    digitalWrite(ledPin, LOW);
  }
}
