#include <LowPower.h>

#define positivo_on 2
#define positivo_off 3
#define negativo_on 4
#define negativo_off 5

#define output_sensor_sol 7
#define output_sensor_lluvia 8
#define power_sensor_lluvia 9
#define power_sensor_sol 10


bool last_state;

void setup(){
  pinMode(positivo_on, OUTPUT);
  pinMode(positivo_off, OUTPUT);
  pinMode(negativo_on, OUTPUT);
  pinMode(negativo_off, OUTPUT);
  pinMode(output_sensor_sol, INPUT);
  pinMode(output_sensor_lluvia, INPUT);
  pinMode(power_sensor_lluvia, OUTPUT);
  pinMode(power_sensor_sol, OUTPUT);

  digitalWrite(power_sensor_sol,HIGH);
  delay(100);
  last_state = digitalRead(output_sensor_sol);
  digitalWrite(power_sensor_sol,LOW);
  delay(1000);
  riego_off(100);
}

void loop(){
  digitalWrite(power_sensor_sol,HIGH);
  delay(50);
  bool state = digitalRead(output_sensor_sol);
  digitalWrite(power_sensor_sol,LOW);

  if( state != last_state){
    last_state = state;
    if(check_rain()){
      riego_on(100,60);
      riego_off(100);
    }

  }
  else{
    LowPower.powerDown(SLEEP_8S,ADC_OFF,BOD_OFF);
  }

}

void riego_on( int pulso, int espera){
  int repeticion_espera = (60*espera) / 8;
  digitalWrite(negativo_on, HIGH);
  delay(1000);
  digitalWrite(positivo_on, HIGH);
  delay(pulso);
  digitalWrite(positivo_on, LOW);
  delay(2000);
  digitalWrite(positivo_on, HIGH);
  delay(pulso);
  digitalWrite(positivo_on, LOW);
  delay(1000);
  digitalWrite(negativo_on, LOW);

  for (int i = 1; i<=repeticion_espera; i++){
    LowPower.powerDown(SLEEP_8S,ADC_OFF,BOD_OFF);
  }
}
void riego_off( int pulso){
  digitalWrite(negativo_off, HIGH);
  delay(1000);
  digitalWrite(positivo_off, HIGH);
  delay(pulso);
  digitalWrite(positivo_off, LOW);
  delay(2000);
  digitalWrite(positivo_off, HIGH);
  delay(pulso);
  digitalWrite(positivo_off, LOW);
  delay(1000);
  digitalWrite(negativo_off, LOW);
}
bool check_rain(){
  digitalWrite(power_sensor_lluvia, HIGH);
  delay(500);
  int check = digitalRead(output_sensor_lluvia);
  delay(500);
  digitalWrite(power_sensor_lluvia,LOW);
  
  if(check==HIGH){
    return true;
  }
  else{
    return false;
  }
}
