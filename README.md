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

O problema que buscamos resolver é o monitoramento ambiental que pode ser considerado falho em muita das vezes e consequentemente afeta a vida de trabalhadores de várias areas como o empregado rural e urbano e pode prejudicar detecção de desmatamento, poluição e outras eventos maléficos que podem atrapalhar e muito a sociedade no futuro sendo uma das dificuldades futuras exercer funções que dependem de um clima favorável. Para isso o meu grupo criou um aparelho sensorial com dados confiáveis e precisos que mandam dados continuos para avaliações de dados de curto espaço tempo e que medem vários tipos de dados como temperatura, umidade, luminosidade(radiação solar) e futuramente qualidade do ar, da água, entre outros.

---

## Explicação do uso do HTTP

O código está criando uma URL com parametros que contem api_key, field1, field2 e field3. Depois, com o http.GET(), ele abre uma conexão com o servidor ThingSpeak, envia uma requisição HTTP GET e se deu certo o servidor responde com código 200 e o número indicando o ID da atualização criada. E o String payload = http.getString() recebe a resposta HTTP que geralmetne é o número da entrada salva.

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

