#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SoftwareSerial.h>

#define SEALEVELPRESSURE_HPA (1013.25)


String start_chat = "start_chat";
String stop_chat = "stop_chat";
byte incoming_bytes;
String mensaje = "";

Adafruit_BME280 bme;
SoftwareSerial HC12(3,2); 

void setup() {
  Serial.begin(9600);            
  HC12.begin(9600);
  
  if (!bme.begin(0x76)) {
    HC12.print((String) "BME280 sensor not found.");
    while (1);
  }
  else{
    HC12.println((String) "Starting BME280");              
  }

}

void loop() {
  while (HC12.available() > 0) {
    char incoming_bytes = HC12.read();
    mensaje += char(incoming_bytes);
  }
  if (mensaje == start_chat){
    Serial.println("Entering chat.");
    HC12.print((String) "Entering chat.");
    chat();
  } 
  mensaje = "";

  meteo();
  delay(60000);
}

void chat(){
  while (true){
    mensaje = "";
    while (HC12.available() > 0) {
      char incoming_bytes = HC12.read();
      mensaje += char(incoming_bytes);
    }
    Serial.println("==============");
    if (sizeof(mensaje) >= 1){
      Serial.println(mensaje);
      HC12.print(mensaje);
    }
    if (mensaje == stop_chat){
      Serial.println("Exiting chat.");
      HC12.println((String) "/////// Exiting chat.");
      break;
    }
    delay(1000);
  }
}

void meteo(){
  HC12.print((String) "T:" + bme.readTemperature() + "," +"H:" + bme.readHumidity() + "," + "P:" + bme.readPressure()/ 100.0F);  
}
