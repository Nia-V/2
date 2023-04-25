#include <Wire.h>
#include <wiring_private.h>
static void turnOffPWM(uint8_t timer) {
  switch (timer) {
#if defined(TCCR1A) && defined(COM1A1)
    case TIMER1A: cbi(TCCR1A, COM1A1); break;
#endif
#if defined(TCCR1A) && defined(COM1B1)
    case TIMER1B: cbi(TCCR1A, COM1B1); break;
#endif
#if defined(TCCR1A) && defined(COM1C1)
    case TIMER1C: cbi(TCCR1A, COM1C1); break;
#endif

#if defined(TCCR2) && defined(COM21)
    case TIMER2: cbi(TCCR2, COM21); break;
#endif

#if defined(TCCR0A) && defined(COM0A1)
    case TIMER0A: cbi(TCCR0A, COM0A1); break;
#endif

#if defined(TCCR0A) && defined(COM0B1)
    case TIMER0B: cbi(TCCR0A, COM0B1); break;
#endif
#if defined(TCCR2A) && defined(COM2A1)
    case TIMER2A: cbi(TCCR2A, COM2A1); break;
#endif
#if defined(TCCR2A) && defined(COM2B1)
    case TIMER2B: cbi(TCCR2A, COM2B1); break;
#endif

#if defined(TCCR3A) && defined(COM3A1)
    case TIMER3A: cbi(TCCR3A, COM3A1); break;
#endif
#if defined(TCCR3A) && defined(COM3B1)
    case TIMER3B: cbi(TCCR3A, COM3B1); break;
#endif
#if defined(TCCR3A) && defined(COM3C1)
    case TIMER3C: cbi(TCCR3A, COM3C1); break;
#endif

#if defined(TCCR4A) && defined(COM4A1)
    case TIMER4A: cbi(TCCR4A, COM4A1); break;
#endif
#if defined(TCCR4A) && defined(COM4B1)
    case TIMER4B: cbi(TCCR4A, COM4B1); break;
#endif
#if defined(TCCR4A) && defined(COM4C1)
    case TIMER4C: cbi(TCCR4A, COM4C1); break;
#endif
#if defined(TCCR4C) && defined(COM4D1)
    case TIMER4D: cbi(TCCR4C, COM4D1); break;
#endif

#if defined(TCCR5A)
    case TIMER5A: cbi(TCCR5A, COM5A1); break;
    case TIMER5B: cbi(TCCR5A, COM5B1); break;
    case TIMER5C: cbi(TCCR5A, COM5C1); break;
#endif
  }
}
void digitalWrite(int pin, bool value) {
  if (pin > 19) {
    Wire.beginTransmission(0x08);  // informs the bus that we will be sending data to slave device 8 (0x08)
    Wire.write(1);
    Wire.write(pin);
    Wire.write(value);  // send value_pot
    Wire.endTransmission();
  } else if (pin < 19) {
    uint8_t timer = digitalPinToTimer(pin);
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *out;

    if (port == NOT_A_PIN) return;

    // If the pin that support PWM output, we need to turn it off
    // before doing a digital write.
    if (timer != NOT_ON_TIMER) turnOffPWM(timer);

    out = portOutputRegister(port);

    uint8_t oldSREG = SREG;
    cli();

    if (value == LOW) {
      *out &= ~bit;
    } else {
      *out |= bit;
    }

    SREG = oldSREG;
  }
}

void pinMode(int pin, String MODE) {
  int IO;
  if (MODE == OUTPUT) {
    IO = 1;
  } else if (MODE == INPUT) {
    IO = 0;
  }
  if (pin >= 19) {
    Wire.beginTransmission(0x08);  // informs the bus that we will be sending data to slave device 8 (0x08)
    Wire.write(0);
    Wire.write(pin);
    Wire.write(IO);  // send value_pot
    Wire.endTransmission();
  } else if (pin < 19) {
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *reg, *out;

    if (port == NOT_A_PIN) return;

    // JWS: can I let the optimizer do this?
    reg = portModeRegister(port);
    out = portOutputRegister(port);

    if (MODE == INPUT) {
      uint8_t oldSREG = SREG;
      cli();
      *reg &= ~bit;
      *out &= ~bit;
      SREG = oldSREG;
    } else if (MODE == INPUT_PULLUP) {
      uint8_t oldSREG = SREG;
      cli();
      *reg &= ~bit;
      *out |= bit;
      SREG = oldSREG;
    } else {
      uint8_t oldSREG = SREG;
      cli();
      *reg |= bit;
      SREG = oldSREG;
    }
  }
}


// void digitalRead(int pin, bool value) {
//   if (pin > 19) {
//    Wire.requestFrom(9, 20);
//   }
//   else {


//   }}
