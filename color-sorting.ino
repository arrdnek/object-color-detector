#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Servo.h>

// Definisikan pin untuk servo
const int servoPin = 9;

// Objek Servo
Servo myServo;

// Buat objek sensor warna
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Inisialisasi servo
  myServo.attach(servoPin);
  myServo.write(0); // Servo ke posisi awal (0 derajat)

  // Inisialisasi sensor warna
  if (tcs.begin()) {
    Serial.println("Sensor warna TCS34725 ditemukan!");
  } else {
    Serial.println("Sensor warna TCS34725 tidak ditemukan. Periksa koneksi!");
    while (1); // Berhenti di sini jika sensor tidak ditemukan
  }
}

void loop() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("R: "); Serial.print(r, DEC);
  Serial.print(" G: "); Serial.print(g, DEC);
  Serial.print(" B: "); Serial.print(b, DEC);
  Serial.print(" C: "); Serial.print(c, DEC);
  Serial.println(" ");

  // Jika semua nilai warna di bawah 130, servo tetap diam
  if (r < 130 && g < 130 && b < 130) {
    Serial.println("Nilai warna terlalu rendah. Servo tidak bergerak.");
    delay(10000); // Tunggu selama 5 detik
    return; // Lanjutkan ke iterasi berikutnya dari loop
  }

  if (r > g && r > b) {
    // Warna merah terdeteksi
    Serial.println("Warna Merah Terdeteksi");
    myServo.write(60);
    delay(5000);
  } else if (g > r && g > b) {
    // Warna hijau terdeteksi
    Serial.println("Warna Hijau Terdeteksi");
    myServo.write(120);
    delay(5000);
  } else if (b > r && b > g) {
    // Warna biru terdeteksi
    Serial.println("Warna Biru Terdeteksi");
    myServo.write(180);
    delay(5000);
  }

  // Kembalikan servo ke posisi awal (0 derajat)
  myServo.write(0);
  delay(5000);
}
