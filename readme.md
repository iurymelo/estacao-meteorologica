# Estação Meteorológica - Arduino

Estação meteorológica com disponibilização dos dados em página web. Apesar de utilizar um DHT11 para leitura de umidade, a temperatura, que também poderia ser realizado por ele, foi feita por um LM35 devido a sua melhor precisão.

# Equipamentos
- [Arduino Due](https://store.arduino.cc/usa/due)
- [Sensor de Temperatura LM35](http://www.ti.com/lit/ds/symlink/lm35.pdf)
- [Sensor de Umidade e Temperatura DHT11](https://www.filipeflop.com/produto/sensor-de-umidade-e-temperatura-dht11/)
- [Sensor de índice UV GUVA-S12SD](https://www.filipeflop.com/produto/sensor-de-raio-ultravioleta-uv-guva-s12sd/)
- [Giroscópio, Acelerômetro e Bussola MinIMU-9 v3 (pode ser trocado pelo v5) para leitura de altitude e direção do vento.](https://www.pololu.com/product/2468)
- [Módulo Sensor IR para cálculo da velocidade do vento](https://www.osepp.com/electronic-modules/sensor-modules/64-ir-detector)
- [Abrigo para sensor](https://www.ebay.com/itm/Plastic-Outer-Shield-for-Thermo-Hygro-Sensor-Spare-Part-for-Weather-Statio-E1Y8/254412760729?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2060353.m2749.l2649)
- [Ethernet Shield W5100](https://www.filipeflop.com/produto/ethernet-shield-w5100-para-arduino/)

# Funcionamento
## Arduino
Arduino lê sensores -> broker requisita os dados e trata para envio -> envia ao banco de dados (firestore)

## Webapp
Webapp -> lê do banco de dados -> mostra os resultados na web

## Passos:
### Protótipo em bancada
 em breve

### Montagem
em breve


## License
[MIT](https://choosealicense.com/licenses/mit/)