
#define C3 130.81

#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define A4 440.00
#define B4 493.88

#define C5 523.25

long int freq = A4; //frequency in Hz
byte nclk = 42; // set to number of cycles for loop() 
long unsigned int phase;
long unsigned int phase_inc;

// https://www.instructables.com/Arduino-Waveform-Generator-1/

byte wave_sin[] = {
  128,131,134,137,140,143,146,149,152,155,158,162,165,168,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,255,255,255,255,254,254,254,253,253,252,251,250,249,249,248,246,245,244,243,241,240,238,237,235,233,232,230,228,226,224,222,220,218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,164,161,158,155,152,149,146,143,140,137,134,131,127,124,121,118,115,112,109,106,103,99,96,93,90,87,84,82,79,76,73,70,67,65,62,59,57,54,51,49,47,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,8,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,6,6,8,9,10,11,12,14,15,17,18,20,22,23,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,65,68,70,73,76,79,82,85,88,91,94,97,100,103,106,109,112,115,118,121,125
};
byte wave_squ[] = {
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
byte wave_tri[] {
  0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,230,232,234,236,238,240,242,244,246,248,250,252,254,255,255,254,252,250,248,246,244,242,240,238,236,234,232,230,228,226,224,222,220,218,216,214,212,210,208,206,204,202,200,198,196,194,192,190,188,186,184,182,180,178,176,174,172,170,168,166,164,162,160,158,156,154,152,150,148,146,144,142,140,138,136,134,132,130,128,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,94,92,90,88,86,84,82,80,78,76,74,72,70,68,66,64,62,60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2
};
byte wave_saw[] {
  0,0,2,2,4,4,6,6,8,8,10,10,12,12,14,14,16,16,18,18,20,20,22,22,24,24,26,26,28,28,30,30,32,32,34,34,36,36,38,38,40,40,42,42,44,44,46,46,48,48,50,50,52,52,54,54,56,56,58,58,60,60,62,62,64,64,66,66,68,68,70,70,72,72,74,74,76,76,78,78,80,80,82,82,84,84,86,86,88,88,90,90,92,92,94,94,96,96,98,98,100,100,102,102,104,104,106,106,108,108,110,110,112,112,114,114,116,116,118,118,120,120,122,122,124,124,126,126,128,128,130,130,132,132,134,134,136,136,138,138,140,140,142,142,144,144,146,146,148,148,150,150,152,152,154,154,156,156,158,158,160,160,162,162,164,164,166,166,168,168,170,170,172,172,174,174,176,176,178,178,180,180,182,182,184,184,186,186,188,188,190,190,192,192,194,194,196,196,198,198,200,200,202,202,204,204,206,206,208,208,210,210,212,212,214,214,216,216,218,218,220,220,222,222,224,224,226,226,228,228,230,230,232,232,234,234,236,236,238,238,240,240,242,242,244,244,246,246,248,248,250,250,252,252,254,254
};

void setup() {
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
  output(wave_sin[calcphase]);
}

void calc_phase_inc(){
  phase_inc=0.268435456 * nclk * freq * 1000;    
}

void output(byte data) {
  // write data bits 0-5 to pin 2-7
  //  1  1  1  1  1  1  -  -
  // 07 06 05 04 03 02 01 00
  PORTD &= B00000011;
  PORTD |= (data<<2);
  // write data bits 6-7 to pin 8-9
  //  -  -  -  -  -  -  1  1
  // cx cx 13 12 11 10 09 08
  PORTB &= B11111100; 
  PORTB |= (data>>6);
}

ISR (PCINT0_vect){
  // react to pins 10,11,12 in here
}
