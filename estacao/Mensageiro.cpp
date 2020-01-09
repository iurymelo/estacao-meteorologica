#include "mensageiro.h"

Mensageiro::Mensageiro() {
 
}

void Mensageiro::inicia() {
  byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
  // Caso de falha no DHCP, tenta o endereço de IP seguinte
  IPAddress ip(192, 168, 0, 177);
  IPAddress myDns(192, 168, 0, 1);
  char server[] = SERVIDOR;

  // Iniciliza o cliente ethernet
  EthernetClient client;

  bool printWebData = true;  // set to false for better speed measurement

  // Inicializa conexão com a internet:
  Serial.println("Inicializando conexão com DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Falha ao usar DHCP");
    // Verifica integridade do shield
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet Shield não conectado ou com defeito.");
      while (true) {
        delay(1);
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Cabo de internet desconectado ou sem conexão.");
    }
    // Tenta usar IP estático
    Ethernet.begin(mac, ip, myDns);
  } else {
    Serial.print("  Endereço de IP DHCP: ");
    Serial.println(Ethernet.localIP());
  }
  
  delay(1000);
  Serial.print("conectando com: ");
  Serial.print(server);
  Serial.println("...");

 
  if (client.connect(server, 80)) {
    Serial.print("Conectado em ");
    Serial.println(client.remoteIP());
    // Make a HTTP request:
    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("conexão falhou");
  }
}
  
