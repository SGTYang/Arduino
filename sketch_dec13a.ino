long now_time;
long pulse;
long pulse_time;

void setup() {
  init_motor();
  init_pulse();
  run_motor();
  Serial.begin(38400);
}

void loop() {
  now_time = millis();
  rpm_calculation();
  display_pulse();
  delay(2000);
}
