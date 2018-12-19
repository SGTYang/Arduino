#define pwmUH 10
#define pwmVH 9
#define digUL 7
#define digVL 8

void init_motor(){
  pinMode(pwmUH, OUTPUT);
  pinMode(digUL, OUTPUT);
  pinMode(pwmVH, OUTPUT);
  pinMode(digVL, OUTPUT);
}

void stop_motor(){
  digitalWrite(digUL, 0);
  digitalWrite(digVL, 0);
  analogWrite(pwmUH, 0);
  analogWrite(pwmVH, 0);
}

void run_motor(int speed){
   static int prev_speed = 0;
  
  if(speed != prev_speed){
    if(speed == 0){
      stop_motor();
    }else{
      if(speed * prev_speed < 0) stop_motor();
      digitalWrite(speed > 0 ? digVL : digUL, 1);
      analogWrite(speed > 0 ? pwmUH : pwmVH, speed > 0 ? speed : -speed);
    }
    prev_speed = speed;
  }
}
