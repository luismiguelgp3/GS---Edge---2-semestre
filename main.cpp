#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 15 // Pino GPIO15 do ESP32 para o DHT22
#define DHTTYPE DHT22 // Tipo de sensor DHT (DHT22)
DHT dht(DHTPIN, DHTTYPE);

#define LDR_PIN 34 // Pino GPIO34 do ESP32 para o LDR

// Credenciais
const char* ssid = "Wokwi-GUEST"; // Rede Wi-Fi
const char* password = ""; // Senha da rede Wi-Fi
const char* apiKey = "Q6WO2ZD3MHFSN06M"; // Write API Key
const char* server = "http://api.thingspeak.com"; // Servidor ThingSpeak

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Configuração dos pinos
  pinMode(LDR_PIN, INPUT); // Configura o pino do LDR como entrada

  // Inicialização e loop de verificação da rede Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Leitura dos sensores
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int ldrValue = analogRead(LDR_PIN); // Leitura do valor do LDR

    if (isnan(h) || isnan(t)) {
      Serial.println("Falha ao ler o sensor DHT22!");
      return;
    }

    // Converte o valor do LDR para uma escala de 0 a 100 (porcentagem de luminosidade)
    float luminosidade = map(ldrValue, 0, 4095, 0, 100);

    // Exibe os valores de temperatura, umidade e luminosidade como porcentagem
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" °C");

    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.println(" %");

    Serial.print("Luminosidade: ");
    Serial.print(luminosidade);
    Serial.println(" %");

    // Envio de dados para o ThingSpeak
    HTTPClient http;
    String url = String(server) + "/update?api_key=" + apiKey + 
                                 "&field1=" + String(t) +  // Temperatura
                                 "&field2=" + String(h) +  // Umidade
                                 "&field3=" + String(luminosidade); // Luminosidade

    http.begin(url);

    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString(); // Resposta da requisição HTTP
      Serial.println("Dados enviados ao ThingSpeak.");
      Serial.print("Código HTTP: ");
      Serial.println(httpCode);
      Serial.println("Resposta: ");
      Serial.println(payload);
    } else {
      Serial.print("Erro ao enviar dados. Código HTTP: ");
      Serial.println(httpCode);
    }
    
    http.end();
  } else {
    Serial.println("WiFi não conectado. Tentando reconectar...");
  }
  
  // Espera 10 segundos para enviar a requisição novamente
  delay(10000);
}
