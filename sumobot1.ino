// For Motor Driver L298N
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // TX,RX
const int pin[6] = {11 , 13 , 12 , 9 ,  8,  10};

/*
  int MR1 = 3;  // IN1
  int MR2 = 5;  // IN2
  int ML1 = 9;  // IN4
  int ML2 = 10; // IN3
*/

int data = 0;
int Speed = 10;
boolean jalan = true;
int kec[11] = {0, 80, 100, 120, 140, 160, 180, 200, 220, 240, 255}; //array kecepatan

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(pin[i], OUTPUT);
  }

}

void loop() {

  /* Commands/Characters sent from APP Bluetooth RC Controller (ANDROID)
    Forward ->F
    Back  -> B
    Left  -> L
    Right -> R
    Forward Left  -> G
    Forward Righ  -> I
    Back Left -> H
    Back Right  -> J
    Stop  -> S
    Speed 10  -> 1
    Speed 20  -> 2
    Speed 30  -> 3
    Speed 40  -> 4
    Speed 50  -> 5
    Speed 60  -> 6
    Speed 70  -> 7
    Speed 80  -> 8
    Speed 90  -> 9
    Speed 100 -> q
    Stop All  -> D */

  if (mySerial.available() > 0) {
    data = mySerial.read();
    Serial.println(data);


    //penyimpan data kecepatan
    

    if (data == 83) {
      Stop();
    } // S=Stop

    if (data == 70) {
      maju();
    } // F=Maju

    if (data == 73) {
      majuKanan;
    } // I=Maju sambil belok kanan

    if (data == 71) {
      majuKiri();
    } // G=Maju sambil belok kiri

    if (data == 82) {
      kanan();
    } // R=Belok kanan

    if (data == 76) {
      kiri();
    } // L=Belok kiri

    if (data == 66) {
      mundur();
    } // B=Mundur

    if (data == 72) {
      mundurKiri();
    } // H=Mundur sambil belok kiri

    if (data == 74) {
      mundurKanan();
    } // J=Mundur sambil belok kanan
  }
}
/*
 * ban kanan pin[3,4] -> pin[3] = in 2, pin[4] = in 1
 * ban kiri pin[2,1} -> pin[2] = in 3, pin[1] = in 4
 */
void Stop( ) {
  digitalWrite(pin[1] , HIGH);
  digitalWrite(pin[2] , LOW);
  analogWrite(pin[0] , 0);

  digitalWrite(pin[4] , HIGH);
  digitalWrite(pin[3] , LOW);
  analogWrite(pin[5] , 0);
}
/*
 * Ban Kiri Pin[1] dan Pin[2]
 * Ban Kanan Pin[3] dan Pin[4]
 */
void maju( ) {
  digitalWrite(pin[1] , HIGH);
  digitalWrite(pin[2] , LOW);
  analogWrite(pin[0] ,  kec[2]);

  digitalWrite(pin[4] , HIGH);
  digitalWrite(pin[3] , LOW);
  analogWrite(pin[5] ,  kec[10]);
}

void mundur( ) {
  digitalWrite(pin[2] , HIGH);
  digitalWrite(pin[1] , LOW);
  analogWrite(pin[0] ,  kec[Speed]);

  digitalWrite(pin[3] , HIGH);
  digitalWrite(pin[4] , LOW);
  analogWrite(pin[5] ,  kec[Speed]);
}

void kiri( ) {
  digitalWrite(pin[1] , HIGH);
  digitalWrite(pin[2] , LOW);
  analogWrite(pin[0] ,  kec[Speed]);

  digitalWrite(pin[3] , HIGH);
  digitalWrite(pin[4] , LOW);
  analogWrite(pin[5] ,  kec[Speed]);
}

void kanan( ) {
  digitalWrite(pin[2] , HIGH);
  digitalWrite(pin[1] , LOW);
  analogWrite(pin[0] ,  kec[Speed]);

  digitalWrite(pin[4] , HIGH);
  digitalWrite(pin[3] , LOW);
  analogWrite(pin[5] ,  kec[Speed]);
}

void majuKanan( ) {
  digitalWrite(pin[1] , HIGH);
  digitalWrite(pin[2] , LOW);
  analogWrite(pin[0] , kec[Speed]);

  digitalWrite(pin[4] , HIGH);
  digitalWrite(pin[3] , LOW);
  analogWrite(pin[5] , kec[Speed] / 2);
}

void majuKiri( ) {
  digitalWrite(pin[1] , HIGH);
  digitalWrite(pin[2] , LOW);
  analogWrite(pin[0] , kec[Speed] / 2);

  digitalWrite(pin[4] , HIGH);
  digitalWrite(pin[3] , LOW);
  analogWrite(pin[5] , kec[Speed]);
}

void mundurKiri( ) {
  digitalWrite(pin[2] , HIGH);
  digitalWrite(pin[1] , LOW);
  analogWrite(pin[0] , kec[Speed] / 2);

  digitalWrite(pin[3] , HIGH);
  digitalWrite(pin[4] , LOW);
  analogWrite(pin[5] , kec[Speed]);
}

void mundurKanan( ) {
  digitalWrite(pin[2] , HIGH);
  digitalWrite(pin[1] , LOW);
  analogWrite(pin[0] , kec[Speed]);

  digitalWrite(pin[3] , HIGH);
  digitalWrite(pin[4] , LOW);
  analogWrite(pin[5] , kec[Speed] / 2);
}
