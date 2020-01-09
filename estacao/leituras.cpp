#include "leituras.h"

#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


//Filtro de entrada
float filtro(int portaEntrada){
  float somatorio = 0.0;
  int x = 0;
  while(x < 100) {
    somatorio += analogRead(portaEntrada);
    x++;
  }

  return (somatorio/100);
}

// Funções para leitura de temperatura
struct lm35 criaSensorTemperatura(int portaEntrada) {
  struct lm35 temperatura;
  temperatura.porta = portaEntrada;
  temperatura.valorLeituraPorta = 0;
  temperatura.tensao = 0.0;
  temperatura.valor = 0.0;

  return temperatura;
}

void medirTemperatura(struct lm35 *medicoes) {
  float valorLeituraPorta = filtro(medicoes->porta);
  float tensao = (valorLeituraPorta/1023.0)*3300;
  float temperaturaC = tensao * 0.1;

  medicoes->valorLeituraPorta = valorLeituraPorta;
  medicoes->tensao = tensao;
  medicoes->valor = temperaturaC;
}

// Funções para medir umidade e sensação térmica
struct dht11 criaSensorUmidade() {
  dht.begin();
  struct dht11 umidade;
  umidade.valor = 0.0;
  umidade.temperaturaRelativa = 0.0;

  return umidade;
}

void medirUmidade(struct dht11 *medicoes, double temperatura) {
  float umidade = dht.readHumidity();
  float indice = dht.computeHeatIndex(temperatura, umidade, false );
  medicoes->valor = umidade;
  medicoes->temperaturaRelativa = indice;
}

// Funções para medir índice UV
struct guva criaSensorUv(int portaEntrada) {
  struct guva indiceUv;
  indiceUv.porta = portaEntrada;
  indiceUv.valor = 0;
  indiceUv.tensao = 0;
  indiceUv.valorLeituraPorta = 0;
  
  return indiceUv;
}

int tensaoParaIndice(float tensaoMiliVolt) {
  float valor = tensaoMiliVolt;
  if(valor <= 50) {
    return 0;
  }
  else if(valor > 50 && valor <= 227) {
    return 0;
  }
  else if(valor > 227 && valor <= 318) {
    return 1;
  }
  else if(valor > 318 && valor <= 408) {
    return 2;
  }
  else if(valor > 408 && valor <= 503) {
    return 3;
  }
  else if(valor > 503 && valor <= 606) {
    return 4;
  }
  else if(valor > 606 && valor <= 696) {
    return 5;
  }
   else if(valor > 696 && valor <= 795) {
    return 6;
  }
   else if(valor > 795 && valor <= 881) {
    return 7;
  }
   else if(valor > 881 && valor <= 976) {
    return 8;
  }
  else if(valor > 976 && valor <= 1079) {
    return 9;
  }
  else if(1079 > 976 && valor <= 1170) {
    return 10;
  }
  else {
    return 11;
  }
}

void medirIndiceUv(struct guva *medicoes) {
  float leituraSensor = filtro(medicoes->porta);
  float tensaoMiliVolt = (leituraSensor/1023.0)*3.3;
  int indiceUv = tensaoParaIndice(tensaoMiliVolt);

  medicoes->tensao = tensaoMiliVolt;
  medicoes->valorLeituraPorta = leituraSensor;
  medicoes->valor = indiceUv;
}
