#define MAX_SPEED 250
#define MIN_SPEED -250
#define SPEED_GAP 10

int get_speed(enum sw_style_t sw){
  static int speed = 0;
  
  if(sw == SW_SHORT){
   speed = 0;
  }else if(sw == SW_U_CW){
   speed += SPEED_GAP;
  }else if(sw == SW_U_CCW){
   speed -= SPEED_GAP;
  }
  speed = speed>250 ? 250 : speed<-250 ? -250 : speed;  
  return speed;
}
