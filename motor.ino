#define pwmUH 10
#define pwmVH 9
#define digUL 7
#define digVL 8

void init_motor(){
  pinMode(pwmUH, OUTPUT);
  pinMode(digUL, OUTPUT);
  pinMode(pwmVH, OUTPUT);
  pinMode(digVL, OUTPUT);

  stop_motor();
}

void stop_motor(){
  digitalWrite(digUL, 0);
  digitalWrite(digVL, 0);
  analogWrite(pwmUH, 0);
  analogWrite(pwmVH, 0);
}

void run_motor(){
      digitalWrite(digVL, 1);
      analogWrite(pwmUH, 50);
}
