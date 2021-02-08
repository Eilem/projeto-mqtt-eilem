#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>



//Define o endereço MAC que será utilizado
// @todo pegar o ip da aula
byte mac[] = {0x44, 0x6E, 0x0F, 0x7F, 0xA4, 0xFE};


int pino2 = 2; //Cria uma variável para o Pino 2
bool estado_sensor; //Cria uma variável para Armazenar o estado do sensor

//Inicia o cliente Ethernet
EthernetClient client;

void setup()
{
  pinMode(pino2,INPUT_PULLUP); //Coloca o Pino 2 como Entrada

  //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
  Ethernet.begin(mac);

  //Inicia o Monitor Serial
  Serial.begin(9600);

  //Exibe no Monitor Serial as informações sobre o IP do Arduino
  Serial.print("O IP do Arduino e: ");
  Serial.println(Ethernet.localIP());

  //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
  Serial.print("A Mascara de Rede do Arduino e: ");
  Serial.println(Ethernet.subnetMask());

  //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
  Serial.print("O Gateway do Arduino e: ");
  Serial.println(Ethernet.gatewayIP());
  //Exibe uma linha em branco
  Serial.println("");

}

void loop()
{
  estado_sensor = digitalRead(pino2); //Efetua a leitura do Pino 2 e armazena o valor obtido na variável
  Serial.println(estado_sensor); //Exibe no Monitor Serial o Estado do Sensor

}
