int dataPin = 4;

int latchPin = 3;

int clockPin = 2;

int outputEnable = 5;

#define t1 10

#define t2 100

#define t3  50

//How many of the shift registers - change this

#define number_of_74hc595s 2

//do not touch

#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];


void setup() {

  pinMode(dataPin, OUTPUT);

  pinMode(latchPin, OUTPUT);

  pinMode(clockPin, OUTPUT);

  pinMode(outputEnable, OUTPUT);

  Serial.begin(9600);

  clearLed(0);

  turnOutputsOn();

}

void loop() {

  effect_1(1);

  clearLed(0);

  effect_2(2);

  clearLed(0);

  effect_3(2);

  clearLed(0);

  effect_4(4);

  clearLed(0);

  effect_5(2);

  clearLed(0);

  effect_6(1);

  clearLed(0);

  effect_7(2);

  clearLed(0);

  effect_8(2);

  clearLed(0);

  effect_9(1);

  clearLed(0);

  effect_10(1);

  clearLed(0);

  effect_11(2);

  clearLed(0);

  effect_12(1);

  clearLed(0);

  effect_13(1);

  clearLed(0);

  effect_14(1);

  clearLed(0);

  effect_15(4);

  clearLed(0);

  effect_16(1);

  clearLed(0);

  effect_17(1);

  clearLed(0);

  effect_18(4);

  clearLed(0);

  effect_4(4);

}

//////////////////////////////////////////////////////////// Effect 1

void effect_1(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 4; i++) {

      registersWrite(i, HIGH);

      delay(200);

    }

    clearLed(10);

    for (int i = 4; i < 7; i++) {

      registersWrite(i, HIGH);

      delay(200);

    }

    clearLed(10);

    for (int i = 7; i < 10; i++) {

      registersWrite(i, HIGH);

      delay(200);

    }

    clearLed(10);

    for (int i = 10; i < 13; i++) {

      registersWrite(i, HIGH);

      delay(200);

    }

    clearLed(10);

    for (int i = 13; i < 16; i++) {

      registersWrite(i, HIGH);

      delay(200);

    }

    clearLed(10);

  }

}

/////////////////////////////////////////////////////////////Effect 2

void effect_2(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      registersWrite(i, HIGH);

      delay(t1);

      registersWrite(i + 1, HIGH);

      delay(t1);

      registersWrite(i + 2, HIGH);

      delay(t1);

      registersWrite(i + 3, HIGH);

      delay(t1);

      registersWrite(i, LOW);

      delay(t1);

      registersWrite(i + 1, LOW);

      delay(t1);

    }

    clearLed(0);

    for (int i = 15; i >= 0; i--) {

      registersWrite(i, HIGH);

      delay(t1);

      registersWrite(i - 1, HIGH);

      delay(t1);

      registersWrite(i - 2, HIGH);

      delay(t1);

      registersWrite(i - 3, HIGH);

      delay(t1);

      registersWrite(i, LOW);

      delay(t1);

      registersWrite(i - 1, LOW);

      delay(t1);

    }

  }

}

////////////////////////////////////////////////////////Effect 3

void effect_3(int effectcount) {

  for (int j = 1; j <= effectcount; j++) {

    for (int i = 0; i < 16; i++) {

      registersWrite(i, HIGH);

      delay(50);

    }

    for (int i = 15; i >= 0; i--) {

      registersWrite(i, LOW);

      delay(50);

    }

  }

}

//////////////////////////////////////////////////////////Effect 4

void effect_4(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    byte led = 0b10101010;

    byte led1 = 0b10101010;

    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, led);

    shiftOut(dataPin, clockPin, LSBFIRST, led1);

    digitalWrite(latchPin, HIGH);

    delay(100);



    byte led2 = 0b01010101;

    byte led3 = 0b01010101;

    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, led2);

    shiftOut(dataPin, clockPin, LSBFIRST, led3);

    digitalWrite(latchPin, HIGH);

    delay(100);

  }

}

/////////////////////////////////////////////////////////Effect 5

void effect_5(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    byte led = 0b11111111;

    byte led1 = 0b11111111;

    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, led);

    shiftOut(dataPin, clockPin, LSBFIRST, led1);

    digitalWrite(latchPin, HIGH);

    turnOutputsOn();

    delay(100);

    turnOutputsOff();

    delay(100);

  }

}

/////////////////////////////////////////////////////////Effect 6

void effect_6(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    int count = 16;

    for (int i = 0; i < 16; i++) {

      clearLed(0);

      registersWrite(i, HIGH);  // chaser 1

      registersWrite(count, HIGH); // chaser 2

      count--;

    }

  }

}

/////////////////////////////////////////////////////////////Effect 7

void effect_7(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    int count2 = 16;

    for (int i = 0; i < 16; i++) {

      clearLed(0);

      registersWrite(i, HIGH);  // chaser 1

      registersWrite(i - 1, HIGH);

      registersWrite(count2, HIGH); // chaser 2

      registersWrite(count2 - 1, HIGH); // chaser 2

      count2--;

    }

  }

}

///////////////////////////////////////////////////////////////Effect 8

void effect_8(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    unsigned int leds = 0B1111111111111111;

    turnOutputsOff();

    updateShiftRegister(leds);

    delay(500);

    for (byte b = 255; b > 0; b--) {

      analogWrite(outputEnable, b);

      delay(8);

    }

  }

}



//////////////////////////////////////////////////////////////Effect 9

void effect_9(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      for (int k = i; k < 16; k++) {

        registersWrite(k, HIGH);

        delay(100);

        registersWrite(k, LOW);

        delay(10);

      }

      registersWrite(i, HIGH);

      delay(20);

    }

  }

}

//////////////////////////////////////////////////////////////////Effect 10

void effect_10(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 15; i >= 0; i--) {

      for (int k = 0; k < i; k++) {

        registersWrite(k, HIGH);

        delay(20);

        registersWrite(k, LOW);

        delay(10);

      }

      registersWrite(i, HIGH);

      delay(20);

    }

  }

}

////////////////////////////////////////////////////////////Effect 11

void effect_11(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      registersWrite(i, HIGH);

      delay(30);

      registersWrite(i + 2, LOW);

      delay(30);

      registersWrite(i - 5, LOW);

    } clearLed(0);

    for (int i = 15; i >= 0; i--) {

      registersWrite(i, HIGH);

      delay(30);

      registersWrite(i - 2, LOW);

      delay(30);

      registersWrite(i + 5, LOW);

    }

  }

}



///////////////////////////////////////////////////////////////Effect 12

void effect_12(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 8; i++) {

      for (int k = i; k < 8; k++)

      {

        registersWrite(k, HIGH);

        registersWrite(15 - k, HIGH);

        delay(20);

        registersWrite(k, LOW);

        registersWrite(15 - k, LOW);

        delay(20);

      }

      registersWrite(i, HIGH);

      registersWrite(15 - i, HIGH);

    }

  }

}

/////////////////////////////////////////////////////////////////Effect 13

void effect_13(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 7; i >= 0; i--) {

      for (int k = 0; k <= i; k++)

      {

        registersWrite(k, HIGH);

        registersWrite(15 - k, HIGH);

        delay(20);

        registersWrite(k, LOW);

        registersWrite(15 - k, LOW);

        delay(20);

      }

      registersWrite(i, HIGH);

      registersWrite(15 - i, HIGH);

    }

  }

}

////////////////////////////////////////////////////////////Effect 14

void effect_14(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      registersWrite(i, HIGH);

      delay(t3);

    }

    for (int i = 0; i < 16; i++) {

      registersWrite(i, LOW);

      delay(t3);

    }

    for (int i = 15; i >= 0; i--) {

      registersWrite(i, HIGH);

      delay(t3);

    }

    for (int i = 15; i >= 0; i--) {

      registersWrite(i, LOW);

      delay(t3);

    }

  }

}

/////////////////////////////////////////////////////////////Effect 15

void effect_15(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      registersWrite(i, HIGH);

    }

    for (int i = 0; i < 16; i++) {

      registersWrite(i, LOW);

    }

  }

}

////////////////////////////////////////////////////////////Effect 16

void effect_16(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      i = i + 1;

      registersWrite(i, HIGH);

      delay(50);

    }

    clearLed(20);

    for (int i = 17; i >= 0; i--) {

      int  j = i * 2;

      registersWrite(j, HIGH);

      delay(50);

    }

    for (int i = 17; i >= 0; i--) {

      int  j = i * 2;

      registersWrite(j, LOW);

      delay(50);

    }

  }

}



////////////////////////////////////////////////////////////Effect 17

void effect_17(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    unsigned int leds = 0B0101010101010101;

    turnOutputsOff();

    updateShiftRegister(leds);

    delay(500);

    analogWrite ( outputEnable, 255 );

    for ( byte bright = 255; bright > 0; bright -= 5 ){

      analogWrite ( outputEnable, bright );

      delay ( 50 );

    }

    analogWrite ( outputEnable, 0 );

    for ( byte bright = 0; bright < 255; bright += 5 ){

      analogWrite ( outputEnable, bright );

      delay ( 50 );

    }

  }

}

////////////////////////////////////////////////////////////Effect 18

void effect_18(int effectcount) {

  for (int i = 1; i <= effectcount; i++) {

    for (int i = 0; i < 16; i++) {

      registersWrite(i, HIGH);

      delay(10);

    }

    for (int i = 16; i > 3; i--) {

      registersWrite(i, LOW);

    }

  }

}

////////////////////////////////////////////////////////////

void updateShiftRegister(unsigned int leds) {

  byte lowLED  = lowByte(leds);

  byte highLED = highByte(leds);

  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, highLED);

  shiftOut(dataPin, clockPin, MSBFIRST, lowLED);

  digitalWrite(latchPin, HIGH);

}





/////////////////////////////////////////////////////////////

void clearLed(int clearSpeed) {

  for (int i = 0; i < 16; i++) {

    registersWrite(i, LOW);

    delay(clearSpeed);

  }

}

////////////////////////////////////////////////////////////

void turnOutputsOn() {

  digitalWrite(outputEnable, LOW);

}

void turnOutputsOff() {

  digitalWrite(outputEnable, HIGH);

}

////////////////////////////////////////////////////////////

void registersWrite(int index, int value) {

  digitalWrite(latchPin, LOW);

  turnOutputsOn();

  for (int i = numOfRegisterPins - 1; i >=  0; i--) {

    digitalWrite(clockPin, LOW);

    int val = registers[i];

    digitalWrite(dataPin, val);

    digitalWrite(clockPin, HIGH);

  }

  digitalWrite(latchPin, HIGH);

  registers[index] = value;

  delay(5);
}
