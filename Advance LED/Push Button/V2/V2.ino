// Menyalakan LED sekaligus nada dengan Push Button
const int ledPin = 0;     // Pin yang terhubung ke LED
const int buttonPin = 1;  // Pin yang terhubung ke push button
const int buzzerPin = 2;  // Pin yang terhubung ke buzzer

int buttonState = 0;      // Variabel untuk menyimpan status push button
int lastButtonState = 0;  // Variabel untuk menyimpan status push button sebelumnya
int noteIndex = 0;        // Indeks untuk melacak nada saat ini

// Nada frekuensi untuk tangga nada do-re-mi-fa-sol-la-si
int notes[] = {
  262,  // C (Do)
  294,  // D (Re)
  330,  // E (Mi)
  349,  // F (Fa)
  392,  // G (Sol)
  440,  // A (La)
  494   // B (Si)
};

void setup() {
  // Inisialisasi pin LED sebagai output
  pinMode(ledPin, OUTPUT);
  // Inisialisasi pin push button sebagai input
  pinMode(buttonPin, INPUT);
  // Inisialisasi pin buzzer sebagai output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Baca status push button
  buttonState = digitalRead(buttonPin);

  // Periksa apakah push button baru saja ditekan
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Mainkan nada saat ini
    tone(buzzerPin, notes[noteIndex]);
    // Menyalakan LED
    digitalWrite(ledPin, HIGH);
    delay(500);  // Durasi nada, LED
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);

    // Pindah ke nada berikutnya
    noteIndex++;
    if (noteIndex > 6) {
      noteIndex = 0;  // Kembali ke nada pertama (Do)
    }
  }

  // Simpan status push button sebelumnya
  lastButtonState = buttonState;

  // Tambahkan sedikit penundaan untuk debounce
  delay(50);
}
