#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* url = "http://example.com/data";

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
}

void loop() {
  // Fetch data from URL
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.println("Data fetched successfully!");
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error fetching data. HTTP response code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  // Wait for 10 seconds before fetching data again
  delay(10000);
}







#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* host = "example.com";
const int port = 80;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
}

void loop() {
  // Create a TCP/IP connection to the web server
  WiFiClient client;
  if (client.connect(host, port)) {
    Serial.println("Connected to server!");

    // Send HTTP GET request
    client.print("GET /data HTTP/1.1\r\n");
    client.print("Host: ");
    client.print(host);
    client.print("\r\n");
    client.print("Connection: close\r\n\r\n");

    // Wait for response
    while (!client.available()) {
      delay(100);
    }

    // Read response and print to serial monitor
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }

    Serial.println();
    client.stop();
    Serial.println("Connection closed.");
  } else {
    Serial.println("Connection failed.");
  }

  // Wait for 10 seconds before fetching data again
  delay(10000);
}
