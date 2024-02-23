#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

String ssid = ""; //!!INSERT YOUR SSID HERE
String password = ""; //!!INSERT YOUR PASSWORD HERE
ESP8266WebServer server(80);

String head = "<!DOCTYPE html><html><head><title>ESP8266 Motor Control</title></head>";
String footer = "</body></html>";
String html;

int motorSpeed = 0;  // Speed of the DC motor
const int motorPin = D1;  // Pin for the DC motor

void page()
{
  html = head;
  html += "<body><h1>DC Motor Control</h1>";
  html += "<a href=\"/motoron\"><button class=\"button\" style=\"font-size: 40px;\">Turn On</button></a>";
  html += "<a href=\"/motoroff\"><button class=\"button\" style=\"font-size: 40px;\">Turn Off</button></a>";
  html += "<a href=\"/increase\"><button class=\"button\" style=\"font-size: 40px;\">Increase Speed</button></a>";
  html += "<a href=\"/decrease\"><button class=\"button\" style=\"font-size: 40px;\">Decrease Speed</button></a>";
  html += "<p>Motor Speed: " + String(motorSpeed) + "</p>";
  html += footer;
  server.send(200, "text/html", html);
}



void motorOn()
{
  analogWrite(motorPin, motorSpeed);
  server.sendHeader("Location", "/", true);
  server.send(303);
}

void motorOff()
{
  analogWrite(motorPin, 0);
  server.sendHeader("Location", "/", true);
  server.send(303);
}

void increaseSpeed()
{
  if (motorSpeed < 255) {
    motorSpeed += 25;
  }
  motorOn();
}

void decreaseSpeed()
{
  if (motorSpeed > 0) {
    motorSpeed -= 25;
  }
  motorOn();
}

void setup()
{
  Serial.begin(115200);
  IPAddress ip(192, 168, 1, 108);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);

  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to LAN");
  Serial.println(WiFi.localIP());

  pinMode(motorPin, OUTPUT);

  server.begin();
  Serial.println("Server online");

  server.on("/", page);
  server.on("/motoron", motorOn);
  server.on("/motoroff", motorOff);
  server.on("/increase", increaseSpeed);
  server.on("/decrease", decreaseSpeed);
}

void loop()
{
  server.handleClient();
}
