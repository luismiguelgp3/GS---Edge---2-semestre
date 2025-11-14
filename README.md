# GS - Edge - 2 Semestre

## 👥 Integrantes

* **Rafael Joda** - RM: 561939
* **Luis Miguel** - RM: 561232
* **Matheus Kitamura** - RM: 563205

---

## 💻 Projeto Wokwi

<img width="405" height="336" alt="image" src="https://github.com/user-attachments/assets/f35a746b-98c8-4d7e-ae44-5b3d19bb05a0" />

[**🔗 Link do projeto do Wokwi**](https://wokwi.com/projects/442197804454616065)

---

## Descrição do problema e sua Solução

---

## Dependências

No simulador wokwi, é obrigatório o uso da biblioteca DHT sensor library e ArduinoHttpClient

---

## 🔌 Instruções de uso

Coloque o aparelho em uma area externa que abrange os elementos desejados e ligue para que comece o funcionamento.

# Para simulação do dispositivo

# Wokwi

No wokwi, temos que iniciar o projeto com o ESP-32, no botão com o sinal de mais adicionar o DHT22 e o Photoresistor (LDR) sensor.
Com o DHT22, temos que ligar o VCC no 5V, o GND em um GND e o SDA no pino 15.
Com o LDR, temos que ligar o VCC no 3V3, o GND em um GND e o A0 no pino 34.
Para ter o código, basta copiar o conteúdo presente no arquivo main.cpp

# ThingSpeak

No thingspeak, crie uma conta, acesse My chanells na aba Chanells, crie um canal com New Chanell, coloque o nome referente ao projeto, nos campos fields coloque os dados referentes como temperatura, umidade, luminosidade, entre outros e clique em Save Chanell. Seu dashboard com os dados estará criado.
Para integrar com o wokwi, basta pegar o Write API Key e adicionar no campo "const char* apiKey";

