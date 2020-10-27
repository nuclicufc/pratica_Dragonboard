#include <HTTPClient.h>

#include <WiFiType.h>
#include <WiFiMulti.h>
#include <WiFiServer.h>
#include <WiFiAP.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <ETH.h>
#include <WiFiScan.h>
#include <WiFiGeneric.h>
#include <WiFiSTA.h>
#include <WiFi.h>


const char* ssid = "Uai-fai";
const char* password = "constante";

const char* serverName = "http://192.168.0.163:3000/smash";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  pinMode(2,INPUT);
}

void loop() {
  if(digitalRead(2)!=0){
      //Check WiFi connection status
      if(WiFi.status()== WL_CONNECTED){
        HTTPClient http;
        http.begin(serverName);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        String httpRequestData = "data";
        int httpResponseCode = http.POST(httpRequestData);
       
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
  
        http.end();
      }
      else {
        Serial.println("WiFi Disconnected");
      }
  }
  delay(100);
}
