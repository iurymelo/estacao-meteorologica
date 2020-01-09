#ifndef Mensageiro_h
#define Mensageiro_h

#include <SPI.h>
#include <Ethernet.h>
#include "Arduino.h"
#define SERVIDOR "www.google.com"

class Mensageiro {
  public:
    Mensageiro();
    void inicia();
};

#endif
