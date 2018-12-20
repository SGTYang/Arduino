#define GEAR_RATIO 51.
#define SINGLE_POLE 13.
#define RPM_BOX 5
#define NUM_ARRAY 5
#define RPM_INTERVAL 500L
float gear_coeff = 60000. / (GEAR_RATIO * SINGLE_POLE);
int rpm;

void display_pulse(){
  static long prev_time;
  
  if(now_time - prev_time >= 500L){
    Serial.println("RPM :");
    Serial.println(rpm);
    prev_time = now_time;
  }
}

int rpm_calculation(){
  
  int pindex = 0;
  static long prev_time;
  static long elapsed_sum = 0L;
  static long pulse_sum = 0L;
  static long earray[NUM_ARRAY];
  static long parray[NUM_ARRAY];

  if(now_time - prev_time >= RPM_INTERVAL){
    ////////////////////////////////////////
    pindex = (pindex + 1) % NUM_ARRAY;
    //////////////////////////////////////// 
    pulse_sum -= parray[pindex];
    pulse_sum += parray[pindex] = pulse;
    /////////////////////////////////////////
    ///////////////////////////////////////// 
    elapsed_sum -= earray[pindex];
    if(pulse==0){
      earray[pindex] = now_time - prev_time;
      elapsed_sum = elapsed_sum + earray[pindex];
      prev_time = now_time;
    }else{
      earray[pindex] = pulse_time - prev_time;
      elapsed_sum = elapsed_sum + earray[pindex];
      prev_time = pulse_time;
    }
    //////////////////////////////////////////
    rpm = (gear_coeff * pulse_sum) / elapsed_sum;
  } pulse = 0;

  return rpm;
}
