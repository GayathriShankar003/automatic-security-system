#define BLYNK_TEMPLATE_ID "TMPLUDopsdS7"
#define BLYNK_DEVICE_NAME "Automatic Security System"
#define BLYNK_AUTH_TOKEN "_T1sxEyouwU-k-I_ovUDVNdkUU6iTZWw"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


long duration;
int distance;


#define trig D2
#define echo D1
#define buzzer D6

char auth[] = "_T1sxEyouwU-k-I_ovUDVNdkUU6iTZWw";
char ssid[] = "Redmi 10 Prime";
char pass[] = "123456789";

BlynkTimer timer;

void notification()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration * 0.034/2;

  if (distance>100)
  {
    digitalWrite(buzzer,LOW);  
  }
  else
  {
    Blynk.logEvent("theft_alert", "Someone has opened the door");  
    digitalWrite(buzzer,HIGH);
   
  }
}


void setup()
{
  pinMode (trig,OUTPUT);
  pinMode (buzzer,OUTPUT);
  pinMode (echo,INPUT);
  
  
  Serial.begin(9600);
 
  Blynk.begin("_T1sxEyouwU-k-I_ovUDVNdkUU6iTZWw","Redmi 10 Prime","123456789");
  
  timer.setInterval(1000L, notification);
}

void loop()
{
  Blynk.run();
  timer.run();
}
