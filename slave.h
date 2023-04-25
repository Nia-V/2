#include <Wire.h>
#include <Arduino.h>
void slave(int opt, int pin, int bvalue) {
  if (opt == 1) {
    switch (pin) {
      case 19:
        digitalWrite(0, bvalue);
        break;
      case 20:
        digitalWrite(1, bvalue);
        break;
      case 21:
        digitalWrite(2, bvalue);
        break;
      case 22:
        digitalWrite(3, bvalue);
        break;
      case 23:
        digitalWrite(4, bvalue);
        break;
      case 24:
        digitalWrite(5, bvalue);
        break;
      case 25:
        digitalWrite(6, bvalue);
        break;
      case 26:
        digitalWrite(7, bvalue);
        break;
      case 27:
        digitalWrite(8, bvalue);
        break;
      case 28:
        digitalWrite(9, bvalue);
        break;
      case 29:
        digitalWrite(10, bvalue);
        break;
      case 30:
        digitalWrite(11, bvalue);
        break;
      case 31:
        digitalWrite(12, bvalue);
        break;
      case 32:
        digitalWrite(13, bvalue);
        break;
      case 33:
        digitalWrite(14, bvalue);
        break;
      case 34:
        digitalWrite(15, bvalue);
        break;
      case 35:
        digitalWrite(16, bvalue);
        break;
      case 36:
        digitalWrite(17, bvalue);
        break;
      case 37:
        digitalWrite(18, bvalue);
        break;
      case 38:
        digitalWrite(19, bvalue);
        break;
      default:

        break;
    }
  }

  if (opt == 0) {
    if (bvalue == 0) {
      switch (pin) {
        case 19:
          pinMode(0, OUTPUT);
          break;
        case 20:
          pinMode(1, OUTPUT);
          break;
        case 21:
          pinMode(2, OUTPUT);
          break;
        case 22:
          pinMode(3, OUTPUT);
          break;
        case 23:
          pinMode(4, OUTPUT);
          break;
        case 24:
          pinMode(5, OUTPUT);
          break;
        case 25:
          pinMode(6, OUTPUT);
          break;
        case 26:
          pinMode(7, OUTPUT);
          break;
        case 27:
          pinMode(8, OUTPUT);
          break;
        case 28:
          pinMode(9, OUTPUT);
          break;
        case 29:
          pinMode(10, OUTPUT);
          break;
        case 30:
          pinMode(11, OUTPUT);
          break;
        case 31:
          pinMode(12, OUTPUT);
          break;
        case 32:
          pinMode(13, OUTPUT);
          break;
        case 33:
          pinMode(14, OUTPUT);
          break;
        case 34:
          pinMode(15, OUTPUT);
          break;
        case 35:
          pinMode(16, OUTPUT);
          break;
        case 36:
          pinMode(17, OUTPUT);
          break;
        case 37:
          pinMode(18, OUTPUT);
          break;
        case 38:
          pinMode(19, OUTPUT);
          break;
        default:

          break;
      }
    }
    if (bvalue == 1) {
      switch (pin) {
        case 19:
          pinMode(0, INPUT);
          break;
        case 20:
          pinMode(1, INPUT);
          break;
        case 21:
          pinMode(2, INPUT);
          break;
        case 22:
          pinMode(3, INPUT);
          break;
        case 23:
          pinMode(4, INPUT);
          break;
        case 24:
          pinMode(5, INPUT);
          break;
        case 25:
          pinMode(6, INPUT);
          break;
        case 26:
          pinMode(7, INPUT);
          break;
        case 27:
          pinMode(8, INPUT);
          break;
        case 28:
          pinMode(9, INPUT);
          break;
        case 29:
          pinMode(10, INPUT);
          break;
        case 30:
          pinMode(11, INPUT);
          break;
        case 31:
          pinMode(12, INPUT);
          break;
        case 32:
          pinMode(13, INPUT);
          break;
        case 33:
          pinMode(14, INPUT);
          break;
        case 34:
          pinMode(15, INPUT);
          break;
        case 35:
          pinMode(16, INPUT);
          break;
        case 36:
          pinMode(17, INPUT);
          break;
        case 37:
          pinMode(18, INPUT);
          break;
        case 38:
          pinMode(19, INPUT);
          break;
        default:

          break;
      }
    }
  }
}

void Rec(int numBytes) {
  int pin;
  int opt;
  int value;
  opt = Wire.read();
  pin = Wire.read();
  value = Wire.read();
  slave(opt, pin, value);
}

void Req() {  // read all bytes received
  Wire.write(8);
}



void Init() {
  Wire.begin(0x08);     // join I2C bus as Slave with address 0x08
  Wire.onReceive(Rec);  // register an event handler for received data
  Wire.onRequest(Req);
}
