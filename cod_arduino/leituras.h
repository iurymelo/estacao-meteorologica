#include "DHT.h"
#include <Arduino.h>

/* STRUCTS */
// Sensor de Temperatura
struct lm35 {
  float valor;
  int porta;
  int valorLeituraPorta;
  float tensao;
};

// Sensor de Umidade
struct dht11 {
  float valor;
  float temperaturaRelativa;
};

// Sensor de Índice UV
struct guva {
  int valor;
  int porta;
  float tensao;
  float valorLeituraPorta;
};


/* FUNÇÕES */
// Filtro de sinal de entrada
float filtro(int portaEntrada);

// Leitura de Temperatura
struct lm35 criaSensorTemperatura(int portaEntrada);
void medirTemperatura(struct lm35 *medicoes);

// Leitura de Humidade e Sensação térmica
struct dht11 criaSensorUmidade();
void medirUmidade(struct dht11 *medicoes, double temperatura);

// Leitura de Índice UV
struct guva criaSensorUv(int portaEntrada);
int tensaoParaIndice(float tensaoMiliVolt);
void medirIndiceUv(struct guva *medicoes);
