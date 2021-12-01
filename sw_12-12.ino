
enum rot_sw_t {ROT_NONE, ROT_DN, ROT_UP, ROT_FALLING, ROT_RISING, ROT_CW, ROT_CCW};
enum sw_style_t {SW_LONG, SW_SHORT, SW_NOTHING, SW_U_CW, SW_U_CCW, SW_D_CW, SW_D_CCW};
long now_time;

void setup() {
  init_sw();
  init_lcd();
  init_motor();
  init_encoder();
  Serial.begin(9600);
  Serial.println("Speed 0 to 250");
}

void loop() {
  now_time = millis();
  enum sw_style_t sw = sw_style();
  int speed = get_speed(sw);
  display_lcd(speed);
  run_motor(speed);
  get_encoder();
  
}
