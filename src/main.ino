#include <DHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 4         // Pino do sensor DHT22
#define DHTTYPE DHT22    // Tipo do sensor DHT22

// Definindo pinos do sensor de ultrassom HC-SR04
#define TRIG_PIN 12
#define ECHO_PIN 13

// Sensor LDR
#define LDR_PIN 34

// Sensor PIR
#define PIR_PIN 14

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  // Leitura do sensor DHT22 (Temperatura e Umidade)
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler do DHT sensor!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print("°C | Humidade: ");
  Serial.print(humidity);
  Serial.println("%");

  // Leitura do Sensor Ultrassom HC-SR04
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0344 / 2;

  Serial.print("Distância (cm): ");
  Serial.println(distance);

  // Leitura do Sensor PIR (Movimento)
  int motion = digitalRead(PIR_PIN);
  if (motion) {
    Serial.println("Movimento detectado!");
  } else {
    Serial.println("Sem movimento.");
  }

  // Leitura do Sensor LDR (Luminosidade)
  int lightLevel = analogRead(LDR_PIN);
  Serial.print("Nível de luz: ");
  Serial.println(lightLevel);

  delay(2000); // Atraso para a próxima leitura
}
