// Merancang Karakter Kustom pada LCD 16x2 Tanpa I2C
#include <LiquidCrystal.h>

// Inisialisasi pin LCD dengan pin Arduino yang sesuai
const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Membuat karakter kustom
byte hati[8] = { 0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000 };
byte senyum[8] = { 0b00000, 0b00000, 0b01010, 0b00000, 0b00000, 0b10001, 0b01110, 0b00000 };
byte tanganTurun[8] = { 0b00100, 0b01010, 0b00100, 0b00100, 0b01110, 0b10101, 0b00100, 0b01010 };
byte tanganNaik[8] = { 0b00100, 0b01010, 0b00100, 0b10101, 0b01110, 0b00100, 0b00100, 0b01010 };
String penulis = "Fariz  Irvansyah";

// Menampilkan kredit
void tampilkanKredit() {
  lcd.setCursor(3, 0);
  lcd.print("Credit By:");
  delay(1000);

  lcd.setCursor(0, 1);  // Mengatur kursor di baris kedua
  for (byte i = 0; i < penulis.length(); i++) {
    lcd.print(penulis[i]);
    delay(100);
  }
  delay(500);
}

// Menampilkan pesan saat startup
void tampilkanPesanStartup() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  delay(1000);

  lcd.setCursor(0, 1);  // Mengatur kursor di baris kedua
  for (byte i = 0; i < penulis.length(); i++) {
    lcd.print(penulis[i]);
    delay(100);
  }
  delay(500);
}

// Menampilkan layar tunggu dengan animasi
void tampilkanLayarTunggu(int delayMillis) {
  lcd.setCursor(2, 1);
  lcd.print("[..........]");
  lcd.setCursor(3, 1);
  for (byte i = 0; i < 10; i++) {
    delay(delayMillis);
    lcd.print("=");
  }
}

// Menampilkan karakter-karakter kustom
void tampilkanKarakter() {
  lcd.setCursor(0, 0);
  lcd.write(byte(2));
  lcd.write(byte(0));
  lcd.write(byte(3));
  lcd.setCursor(13, 0);
  lcd.write(byte(3));
  lcd.write(byte(0));
  lcd.write(byte(2));
  delay(500);
  lcd.setCursor(0, 0);
  lcd.write(byte(3));
  lcd.print(" ");
  lcd.write(byte(2));
  lcd.setCursor(13, 0);
  lcd.write(byte(2));
  lcd.print(" ");
  lcd.write(byte(3));
  delay(300);
}

void setup() {
  lcd.createChar(0, hati);         // Membuat karakter hati
  lcd.createChar(1, senyum);       // Membuat karakter senyum
  lcd.createChar(2, tanganTurun);  // Membuat karakter tangan turun
  lcd.createChar(3, tanganNaik);   // Membuat karakter tangan naik
  lcd.begin(16, 2);                // Menginisialisasi LCD dengan 16 kolom dan 2 baris
  tampilkanKredit();               // Menampilkan kredit
  lcd.clear();                     // Membersihkan layar
  tampilkanLayarTunggu(100);       // Menampilkan layar tunggu
  lcd.clear();                     // Membersihkan layar
  tampilkanPesanStartup();         // Menampilkan pesan startup
}

void loop() {
  tampilkanKarakter();  // Menampilkan karakter-karakter kustom berulang-ulang
}
