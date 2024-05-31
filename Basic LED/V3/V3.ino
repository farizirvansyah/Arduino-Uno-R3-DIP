// Menyalakan LED secara selang seling
const int RED = 0;     // ini adalah lampu warna merah
const int ORANGE = 1;  // ini adalah lampu warna jingga
const int YELLOW = 2;  // ini adalah lampu warna kuning
const int GREEN = 3;   // ini adalah lampu warna hijau
const int BLUE = 4;    // ini adalah lampu warna biru
const int WHITE = 5;   // ini adalah lampu warna putih

void setup() {
  pinMode(RED, OUTPUT);     // lampu merah sebagai output
  pinMode(ORANGE, OUTPUT);  // lampu jingga sebagai output
  pinMode(YELLOW, OUTPUT);  // lampu kuning sebagai output
  pinMode(GREEN, OUTPUT);   // lampu hijau sebagai output
  pinMode(BLUE, OUTPUT);    // lampu biru sebagai output
  pinMode(WHITE, OUTPUT);   // lampu putih sebagai output
}
void loop() {
  digitalWrite(RED, HIGH);     // lampu merah menyala
  digitalWrite(YELLOW, HIGH);  // lampu kuning menyala
  digitalWrite(BLUE, HIGH);    // lampu biru menyala
  delay(1000);                 // tunggu 1 detik
  digitalWrite(RED, LOW);      // lampu merah mati
  digitalWrite(YELLOW, LOW);   // lampu kuning mati
  digitalWrite(BLUE, LOW);     // lampu biru mati
  delay(250);                  // tunggu 250 milidetik

  digitalWrite(ORANGE, HIGH);  // lampu jingga menyala
  digitalWrite(GREEN, HIGH);   // lampu hijau menyala
  digitalWrite(WHITE, HIGH);   // lampu putih menyala
  delay(1000);                 // tunggu 1 detik
  digitalWrite(ORANGE, LOW);   // lampu jingga mati
  digitalWrite(GREEN, LOW);    // lampu hijau mati
  digitalWrite(WHITE, LOW);    // lampu putih mati
  delay(250);                  // tunggu 250 milidetik
}
