
double freq = 440; //frequency in Hz
byte nclk = 65; // set to number of cycles for loop(), TODO: calculate this
long unsigned int phase;
long unsigned int phase_inc;

int note = 0;
int numNotes = 8;
int wave = 0;
int numWaves = 7;
int prog = 0;
int numProgs = 6;
int key = 0;
int numKeys = 128;

double vol = 1.0;

// https://www.instructables.com/Arduino-Waveform-Generator-1/

// 0=C0 to 127=G10 (current offset -48)
double notes[] = {
  261.63, // C4
  277.18, // C4#
  293.66, // D4
  311.13, // D4#
  329.63, // E4
  349.23, // F4
  369.99, // F4#
  392.00, // G4
  415.30, // G4#
  440.00, // A4
  466.16, // A4#
  493.88, // B4
  523.25  // C5
};

const PROGMEM byte waves[][256] = {
  // non
  {
    128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128
  },
  // sin
  {
    128,131,134,137,140,143,146,149,152,155,158,162,165,168,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,255,255,255,255,254,254,254,253,253,252,251,250,249,249,248,246,245,244,243,241,240,238,237,235,233,232,230,228,226,224,222,220,218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,164,161,158,155,152,149,146,143,140,137,134,131,127,124,121,118,115,112,109,106,103,99,96,93,90,87,84,82,79,76,73,70,67,65,62,59,57,54,51,49,47,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,8,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,6,6,8,9,10,11,12,14,15,17,18,20,22,23,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,65,68,70,73,76,79,82,85,88,91,94,97,100,103,106,109,112,115,118,121,125
  },
  // tan
  {
    128,128,129,129,130,130,131,131,132,132,133,133,134,135,135,136,136,137,138,138,139,140,140,141,142,142,143,144,145,146,147,148,149,150,151,152,153,155,156,158,159,161,163,165,167,170,172,175,179,183,187,192,198,204,212,222,235,250,15,44,88,161,52,239,222,44,211,97,169,212,241,5,21,33,43,51,58,63,68,72,76,80,83,85,88,90,92,94,96,97,99,100,102,103,104,105,106,107,108,109,110,111,112,113,113,114,115,115,116,117,117,118,119,119,120,120,121,122,122,123,123,124,124,125,125,126,126,127,128,128,129,129,130,130,131,131,132,132,133,133,134,135,135,136,136,137,138,138,139,140,140,141,142,142,143,144,145,146,147,148,149,150,151,152,153,155,156,158,159,161,163,165,167,170,173,176,179,183,187,192,198,205,213,223,235,251,16,45,90,164,59,14,244,71,217,100,170,213,241,6,21,33,43,51,58,63,68,73,76,80,83,85,88,90,92,94,96,97,99,100,102,103,104,105,106,107,108,109,110,111,112,113,113,114,115,116,116,117,117,118,119,119,120,121,121,122,122,123,123,124,124,125,125,126,126,127
  },
  // squ
  {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
  },
  // tri
  {
    2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,256,256,254,252,250,248,246,244,242,240,238,236,234,232,230,228,226,224,222,220,218,216,214,212,210,208,206,204,202,200,198,196,194,192,190,188,186,184,182,180,178,176,174,172,170,168,166,164,162,160,158,156,154,152,150,148,146,144,142,140,138,136,134,132,130,128,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,94,92,90,88,86,84,82,80,78,76,74,72,70,68,66,64,62,60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2
  },
  // saw
  {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
  },
  // rnd
  {
    221,115,96,97,57,189,161,129,182,125,160,11,100,101,27,162,3,67,114,164,118,141,9,13,81,21,168,221,207,160,242,112,147,118,14,142,55,141,96,35,209,256,57,249,85,155,194,87,226,207,175,209,98,81,217,190,241,74,156,141,4,106,63,37,236,223,233,88,88,215,62,192,46,102,203,147,104,144,117,169,175,162,136,34,181,173,248,45,30,32,228,140,118,48,37,94,44,100,217,1,111,152,108,139,177,68,203,114,20,5,54,11,181,238,81,242,22,240,123,46,112,249,234,133,198,151,196,82,156,201,178,77,97,121,151,119,198,203,101,215,139,155,50,237,166,226,35,175,219,16,133,109,232,61,103,27,154,131,128,196,63,84,39,144,2,24,207,106,104,251,225,197,220,7,99,223,3,66,247,250,157,173,9,231,142,46,89,5,98,196,152,59,55,14,124,131,45,24,238,165,139,10,219,234,215,120,244,114,52,62,85,99,81,147,246,117,216,173,162,102,202,133,204,19,175,169,74,153,79,25,38,231,202,70,98,176,93,185,50,42,110,170,83,34,187,32,184,238,229,55,46,197,26,216,30,114
  }
};

void setup() {
  Serial.begin(115200);
  
  PCICR = 0x01; // enable pcint0 interrupt
  PCMSK0 = B00011100;  // mask for interrupt pins 10,11,12
  
  TIMSK0 &= ~_BV(TOIE0); // disable timer0 overflow interrupt
  
  phase = 0;
  calc_phase_inc();

  // pin 2-7 output
  DDRD |= B11111100;
  // pin 8-9 output
  DDRB |= B00000011;
}

void loop() {
  phase += phase_inc;
  int calcphase = phase >> 24;
  output(pgm_read_byte(&(waves[wave][calcphase])));
}

void calc_phase_inc(){
  // 2^32/16E6=268.435456
  phase_inc=0.268435456 * nclk * freq * 1000;    
}

// TODO: remove this from function. Save some clock cycles?
void output(byte data) {
  // write data bits 0-5 to pin 2-7
  //  1  1  1  1  1  1  -  -
  // 07 06 05 04 03 02 01 00
  PORTD &= B00000011; // TODO: get these as one line
  PORTD |= (data<<2);
  //PORTD &= (data<<2) | 0x03;
  
  // write data bits 6-7 to pin 8-9
  //  -  -  -  -  -  -  1  1
  // cx cx 13 12 11 10 09 08
  PORTB &= B11111100; // TODO: get these as one line
  PORTB |= (data>>6);
  //PORTB &= (data>>6) | 0xFC;
}

ISR (PCINT0_vect){
  // react to pins 10,11,12 in here
}

// allow control through serial for debugging
void serialEvent() {
  while (Serial.available()) {
    byte stat = Serial.read();
    byte cmd = stat & 0xF0;
    byte chn = stat & 0x0F;
#ifdef DEBUG
    Serial.print("Channel: 0x");
    Serial.print(chn, HEX);
    Serial.print(" ");
#endif
    byte b1, b2;
    switch (cmd) {
      case 0xC0:
#ifdef DEBUG
        Serial.print("Program Change: Prog=0x");
#endif
        while(!Serial.available());
        b1 = Serial.read();
#ifdef DEBUG
        Serial.println(b1, HEX);
#endif
        if (b1 < numProgs && b1 >= 0) {
          prog = b1;
        }
        break;
      case 0x80:
#ifdef DEBUG
        Serial.print("Note Off: Key=0x");
#endif
        while(!Serial.available());
        b1 = Serial.read();
        while(!Serial.available());
        b2 = Serial.read();
#ifdef DEBUG
        Serial.print(b1, HEX);
        Serial.print(" Vel=0x");
        Serial.println(b2, HEX);
#endif
        if (b1 < numKeys && b1 >= 0) {
          if (b1 == key) {
            key = -1;
            wave = 0; // no sound
            freq = 0;
            calc_phase_inc();
          }
        }
        break;
      case 0x90:
#ifdef DEBUG
        Serial.print("Note On: Key=0x");
#endif
        while(!Serial.available());
        b1 = Serial.read();
        while(!Serial.available());
        b2 = Serial.read();
#ifdef DEBUG
        Serial.print(b1, HEX);
        Serial.print(" Vel=0x");
        Serial.println(b2, HEX);
#endif
        if (b1 < numKeys && b1 >= 0) {
          key = b1;
          wave = prog + 1; // offset because of 'no sound' program at beginning
          freq = notes[key-48]; // not all keys implemented -48
          calc_phase_inc();
        }
        break;
      default:
#ifdef DEBUG
        Serial.print("unhandled command: 0x");
        Serial.println(cmd, HEX);
#endif
        break;
    }
  }
}
