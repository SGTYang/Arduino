#define pinINTERRUPT 3
#define pinENCB 11
#define pinINTERRUPT 3

void init_Interrupt(){
  pinMode(pinINTERRUPT, INPUT_PULLUP);
}     

void init_pulse(){
  pinMode(pinENCB, INPUT_PULLUP);
  pinMode(pinINTERRUPT, INPUT_PULLUP);
  attachInterrupt(INT1, ISR_pulse, FALLING);
}

void ISR_pulse(){
  pulse++;
  pulse_time = now_time;
}
