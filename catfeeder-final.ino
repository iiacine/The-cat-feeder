/*********
  Cat Feeder - ESGI
  Complete project details at https://github.com/Ahmedko/Iot
*********/



#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Servo.h>
#include <NTPClient.h>

MDNSResponder mdns;

/***** Creation d'une instance, un objet qui contiendra le serveur web. On communiquera avec lui sur le port 80,
  le port classique des requêtes HTTP utilisées par les navigateurs internet.
  *****/
const char* ssid = "ok";
const char* password = "ahmedlad94";

ESP8266WebServer server(80); // La boucle setup.
String webPage = "<html lang=fr-FR><head><meta http-equiv='refresh' content='5'/>"; //Initialisation de la page web avec une actualisation
const int gpio5_pin = D6;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

Servo myservo;

void setup(void) {
  
  webPage += "<h1>The CAT FEEDER Web page</h1><p>Socket #1 <a href=\"socket1On\"><button>Feed the cat</button></a>&nbsp;<a href=\"socket1Off\"><button>stop the feeding</button></a></p>";
  myservo.attach (gpio5_pin);

  // preparing GPIOs
  pinMode(gpio5_pin, OUTPUT);
  digitalWrite(gpio5_pin, LOW);
  delay(1000);

  // Ouverture du port serie en 115200 baud pour envoyer des messages de debug à l'ide par exemple
  Serial.begin(115200);
  Serial.println("Started");

  // On se connecte a reseau WiFi avec le SSID et le mot de passe precedemment configure
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  server.on("/", []() {
    server.send(200, "text/html", webPage);
  });
  server.on("/socket1On", []() {
    server.send(200, "text/html", webPage);
    myservo.write(90);
    digitalWrite(gpio5_pin, HIGH);
    delay(1000);
  });
  server.on("/socket1Off", []() {
    server.send(200, "text/html", webPage);
    myservo.write(0);
    digitalWrite(gpio5_pin, LOW);

    delay(1000);
  });

  // connexion OK, on demarre le server web // Start the server

  server.begin();
  Serial.println("HTTP server started");

}

void loop(void) {
  /*  Finalement, pour gérer l'arrivée http, nous avons besoin d'appeller la methode HandleClient*/

  server.handleClient();
  int sensorValue = analogRead(A0);


  delay(1000);
  int sensorValue2 = analogRead(A0);


  int comp = sensorValue - sensorValue2;
  if (comp > 100) {
    Serial.println("a cat has been detected");
     
    timeClient.update();
    Serial.println(timeClient.getFormattedTime());
    delay(1000);
    webPage += "a cat has been detected : "+timeClient.getFormattedTime();
    webPage += "<br>";
    myservo.write(90);              // tell servo to go to position in variable 'pos'
    delay(1000);
    myservo.write(0);


  }
}

