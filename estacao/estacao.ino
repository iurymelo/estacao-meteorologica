#include "leituras.h"
#include "Mensageiro.h"

// Struct para armazenar os resultados
struct resultados {
  double temperatura = -100.0;
  float umidade = -100.0;
  float sensacaoTermica = -100.0;
  int indiceUv = 9999;
};


resultados leituras;

// Inicialização das structs
lm35 temperatura = criaSensorTemperatura(A0);
dht11 umidade = criaSensorUmidade();
guva indiceUv = criaSensorUv(A2);

Mensageiro mensageiro;

void setup() {  
  Serial.begin(9600);
  mensageiro.inicia();
  
}

void loop() {
  medirTemperatura(&temperatura);
  medirUmidade(&umidade, temperatura.valor);
  medirIndiceUv(&indiceUv);
  
  leituras.temperatura = temperatura.valor;
  leituras.umidade = umidade.valor;
  leituras.sensacaoTermica = umidade.temperaturaRelativa;
  leituras.indiceUv = indiceUv.valor;
  
  Serial.print("Temperatura: ");
  Serial.print(leituras.temperatura, 1);
  Serial.print(" C       ");
  Serial.print(leituras.umidade);
  Serial.print("%      Sensação Térmica: "); 
  Serial.print(leituras.sensacaoTermica, 1);
  Serial.print("C       ");
  Serial.print("Indice UV: ");
  Serial.println(leituras.indiceUv);
  
  
}
