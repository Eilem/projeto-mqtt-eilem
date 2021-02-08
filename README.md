# Projeto integração sensor - mqtt

Esta aplicação tem como objetivo identificar se a porta do Rack está ***aberta*** ou ***fechada*** através do monitoramento do estado de um sensor magnético que está implantado na porta do rack e integrado com um Arduino.

Os dados do sensor são enviados atravé do Arduino ( que está conectado em uma rede ) para o servidor hospedado na [AWS](https://aws.amazon.com/pt/) através do protocolo MQTT( Message Queuing Telemetry Transport ) onde a informação será exibida em um cliente MQTT através de um aplicativo ( ex. MQTT Dash* ) instalado em um Smartphone.


*Verifique qual aplicação pode ser utilizada em seu celular de acordo com o sistema operacional do mesmo.   
---

A informação disponibilizada pelo sensor é um boolean, onde:

- **0** ou **false** : Porta Fechada
- **1** ou **true** : Porta Aberta  

---

## Materiais necessários

- Arduino Uno
- Módulo Ethernet (ENC28J60)
- Sensor Magnético (MC-38)
- Jumpers

---

## Montagem

Na montagem do circuito os pinos devem seguir a sequência exibida na tabela abaixo:

[![N](https://user-images.githubusercontent.com/1204984/107174323-b2caf600-69a8-11eb-86cc-0582a025c966.png)](#)

---

## Modelo de implantação

Esquema visual da integração

[![N](https://user-images.githubusercontent.com/1204984/107174295-9a5adb80-69a8-11eb-8764-69a9f137fb79.png)](#)
