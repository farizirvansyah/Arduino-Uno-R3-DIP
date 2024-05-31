// Menyalakan LED sekaligus nada dengan Push Button serta Push Button ke 4 sebagai penanda mode nada
const int red = 0;         // Pin yang terhubung ke LED merah
const int green = 1;       // Pin yang terhubung ke LED hijau
const int button1Pin = 2;  // Pin yang terhubung ke tombol 1
const int button2Pin = 3;  // Pin yang terhubung ke tombol 2
const int button3Pin = 4;  // Pin yang terhubung ke tombol 3
const int button4Pin = 5;  // Pin yang terhubung ke tombol 4
const int buzzerPin = 6;   // Pin yang terhubung ke buzzer

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
bool useSecondSet = false;  // Flag untuk menentukan set nada yang digunakan

// Nada frekuensi untuk dua set tangga nada
int notesSet1[] = {
  262,  // C (Do)
  294,  // D (Re)
  330   // E (Mi)
};

int notesSet2[] = {
  349,  // F (Fa)
  392,  // G (Sol)
  440   // A (La)
};

void setup() {
  // Inisialisasi pin LED sebagai output
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  // Inisialisasi pin push button sebagai input
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  // Inisialisasi pin buzzer sebagai output
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(red, HIGH);
}

void loop() {
  // Baca status push button
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);

  // Periksa apakah tombol 4 ditekan
  if (button4State == HIGH) {
    useSecondSet = !useSecondSet;  // Ganti set nada
    if (useSecondSet) {
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
    } else {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
    }
    delay(500);  // Penundaan untuk debounce
  }
  // Periksa tombol 1
  if (button1State == HIGH) {
    if (useSecondSet) {
      tone(buzzerPin, notesSet2[0]);
    } else {
      tone(buzzerPin, notesSet1[0]);
    }
    delay(500);
    noTone(buzzerPin);
  }

  // Periksa tombol 2
  if (button2State == HIGH) {
    if (useSecondSet) {
      tone(buzzerPin, notesSet2[1]);
    } else {
      tone(buzzerPin, notesSet1[1]);
    }
    delay(500);
    noTone(buzzerPin);
  }

  // Periksa tombol 3
  if (button3State == HIGH) {
    if (useSecondSet) {
      tone(buzzerPin, notesSet2[2]);
    } else {
      tone(buzzerPin, notesSet1[2]);
    }
    delay(500);
    noTone(buzzerPin);
  }

  // Tambahkan sedikit penundaan untuk debounce
  delay(50);
}
