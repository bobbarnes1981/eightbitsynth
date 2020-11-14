
long int freq = 262000; // 262Hz middle c
byte nclk = 168; // set to number of cycles for loop() 
long unsigned int phase;
long unsigned int phase_inc;

// https://www.instructables.com/Arduino-Waveform-Generator-1/

byte sine[] = {
  128,131,134,137,140,143,146,149,152,155,158,162,165,168,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,255,255,255,255,254,254,254,253,253,252,251,250,249,249,248,246,245,244,243,241,240,238,237,235,233,232,230,228,226,224,222,220,218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,164,161,158,155,152,149,146,143,140,137,134,131,127,124,121,118,115,112,109,106,103,99,96,93,90,87,84,82,79,76,73,70,67,65,62,59,57,54,51,49,47,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,8,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,6,6,8,9,10,11,12,14,15,17,18,20,22,23,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,65,68,70,73,76,79,82,85,88,91,94,97,100,103,106,109,112,115,118,121,125
};

void setup() {
  PCICR = 0x01; // enable pcint0 interrupt
  TIMSK0 &= ~_BV(TOIE0); // disable timer0 overflow interrupt
  
  phase = 0;

  // 2^32/16E6=268.435456
  phase_inc=0.268435456*nclk*freq;

  // maybe use DDRD
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // maybe use DDRB
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  phase += phase_inc;
  int calcphase = phase >> 24;
  output(sine[calcphase]);
}

void output(byte data) {
  // maybe use PORTD |= (data<<2|0x03)
  digitalWrite(2, data & 0x01);
  digitalWrite(3, data & 0x02);
  digitalWrite(4, data & 0x04);
  digitalWrite(5, data & 0x08);
  digitalWrite(6, data & 0x10);
  digitalWrite(7, data & 0x20);
  // maybe use PORTB |= (data>>6|0xFC)
  digitalWrite(8, data & 0x30);
  digitalWrite(9, data & 0x80);
}

ISR (PCINT0_vect){
  // nothing on interrupt yet
}
