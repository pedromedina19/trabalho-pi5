//bibliotecas
#include <ESP8266WiFi.h> 
#include <FirebaseArduino.h>     
#include <DHT.h> 
#include <NTPClient.h>
#include <WiFiUdp.h>

//autenticação do banco de dados
#define FIREBASE_HOST "esp8266-dht22-d73de-default-rtdb.firebaseio.com"      
#define FIREBASE_AUTH "rpU9CQS5TkWwXbnW0RrerXEqUhYTE3N22VelIuCf"    
//definições do wifi        
#define WIFI_SSID "GLEISON"                                  
#define WIFI_PASSWORD "1903021502850"    

// Define NTP Client para buscar o tempo
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// variavel que salva o tempo
int timestamp;

// funcao que pega o tempo atual
unsigned long getTime() {
  timeClient.update();
  unsigned long now = timeClient.getEpochTime();
  return now;
}

//definições dos pinos ligados 
#define DHTPIN D5                                            
#define DHTTYPE DHT22                                        
DHT dht(DHTPIN, DHTTYPE);                                                    
 
void setup() 
{
  Serial.begin(115200);
  //inicia o sensor
  timeClient.begin();
  dht.begin();                                                  
  //conectando ao wifi             
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 
  //conectando no banco de dados
  Firebase.begin(FIREBASE_HOST);
  
}
 
void loop() 
{
  //variaveis do sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature(); //temperatura lida em celsius
  timestamp = getTime();
  Serial.print ("time: ");
  Serial.println (timestamp);
  //Lendo as variaveis e mostrando no monitor serial
  String fireHumid = String(timestamp) + String(";") + String (h);
  Serial.print("Humidade: ");  
  Serial.print(h);
  //String fireHumid = String(h) + String("%"); //metodo para se caso for necessário armazenar os ados como string ao invés de float
  String fireTemp = String(timestamp) + String(";") + String (t);
  Serial.print("%  Temperatura: ");  
  Serial.print(t);  
  Serial.println("°C ");
  //String fireTemp = String(t) + String("ºC"); //metodo para se caso for necessário armazenar os ados como string ao invés de float
  //enviando dados para o banco de dados 
  
  Firebase.pushString ("/dht22/humidade",fireHumid);
  Firebase.pushString ("/dht22/temperatura",fireTemp);
  //Firebase.pushInt ("/dht22/timestamp",timestamp);


  //intervalo de leitura do sensor e de envio para o banco de dados
  delay(300000);
}
