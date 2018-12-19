#define pinROT_SW 12
#define pinROT_ENA 4
#define pinROT_ENB 5

void init_sw(){
  pinMode(pinROT_SW, INPUT_PULLUP);
  pinMode(pinROT_ENA, INPUT_PULLUP);
  pinMode(pinROT_ENB, INPUT_PULLUP);
}

////////////////////////////////////// return one of rotary switch movement as enum rot_sw_t
enum rot_sw_t sw_movement(){
  static int nsw = digitalRead(pinROT_SW);
  static int nenA = digitalRead(pinROT_ENA);

  int psw = nsw;  nsw = digitalRead(pinROT_SW);
  int penA = nenA; nenA = digitalRead(pinROT_ENA);

  if(psw==1 && nsw==0){       return ROT_FALLING;
  }else if(psw==0 && nsw==1){ return ROT_RISING;
  }else if(penA==1 && nenA==0 ){
    return digitalRead(pinROT_ENB)==0 ? ROT_CW : ROT_CCW;
  }else if(psw==0 && nsw==0){ return ROT_DN;
  }else if(psw==1 && nsw==1){ return ROT_UP;
  }else return ROT_NONE;
}

enum sw_style_t sw_style(){
  static enum {ST_READY, ST_DOWN, ST_ROTATION} state=ST_READY;
  static long press_time;
  enum rot_sw_t rot_sw = sw_movement();
  enum sw_style_t ret_value = SW_NOTHING;
  
  switch( state ){
    case ST_READY:
    if(rot_sw == ROT_FALLING){
      press_time = now_time;
      state = ST_DOWN;
    }
    else if(rot_sw == ROT_CW){
      ret_value = SW_U_CW;
    }
    else if(rot_sw == ROT_CCW){
      ret_value = SW_U_CCW;
    }
    break;
    
    case ST_DOWN:
    if(rot_sw == ROT_RISING && (now_time - press_time >= 1000L)){
      state = ST_READY;
    }else if(rot_sw == ROT_RISING && (now_time - press_time < 1000L)){
      ret_value = SW_SHORT;
      state = ST_READY;
    }else if(rot_sw == ROT_CW || rot_sw == ROT_CCW){
      state = ST_ROTATION;
    }
    break;
 
    case ST_ROTATION:
    if(rot_sw == ROT_RISING){
      state = ST_READY;
    }else if(rot_sw == ROT_CW){
      ret_value = SW_D_CW;
    }else if(rot_sw == ROT_CCW){
      ret_value = SW_D_CCW;
    }
    break;
  }
  return ret_value;
}
/////////////////////////////////////////////////////
