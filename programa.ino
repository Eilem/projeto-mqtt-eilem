#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>
#include <PubSubClient.h>

//Define o endereço MAC que será utilizado
// @todo pegar o ip da aula
byte mac[] = {0x44, 0x6E, 0x0F, 0x7F, 0xA4, 0xFE};

int pino2 = 2; //Cria uma variável para o Pino 2
bool estado_sensor; //Cria uma variável para Armazenar o estado do sensor

//Inicia o cliente Ethernet
EthernetClient client;

//Variável utilizada para enviar as mensagens utilizando o cliente MQTT
bool mensagem;

//Inicia o client MQTT
PubSubClient mqttClient(client);

void setup()
{
  pinMode(pino2,INPUT_PULLUP); //Coloca o Pino 2 como Entrada

  //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
  Ethernet.begin(mac);

  //Inicia o Monitor Serial
  Serial.begin(9600);

  //Define o IP e Porta TCP do Broker MQTT que vamos utilizar
  mqttClient.setServer("192.168.4.229", 1883);

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
  //Aguarda 5 segundos
  delay(5000);

}

void loop()
{
  estado_sensor = digitalRead(pino2); //Efetua a leitura do Pino 2 e armazena o valor obtido na variável
  Serial.println(estado_sensor); //Exibe no Monitor Serial o Estado do Sensor

  //Define o nome do cliente MQTT e efetua a conexão com o servidor.
  mqttClient.connect("eilem");

  /*
    Variável que envia a mensagem e armazena o valor de '1' caso
    a mensagem seja enviada com sucesso e '0' caso o envio falhe
  */
  mensagem = mqttClient.publish("sensor_rack_lab1", "LIGADO");

  //Função que verifica a conexão entre o Cliente e o Broker e evita a queda de conexão entre eles.
  mqttClient.loop();

  //Aguarda 5 segundos
  delay(5000);

}
