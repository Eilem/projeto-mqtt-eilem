#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>

//Variável utilizada para enviar as mensagens utilizando o cliente MQTT
bool mensagem;

//Define o endereço MAC que será utilizado
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

//Inicia o cliente Ethernet
EthernetClient client;

//Inicia o client MQTT
PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
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

    //Aguarda 10 segundos
    delay(5000);
}

void loop() {

    //Define o nome do cliente MQTT e efetua a conexão com o servidor.
    mqttClient.connect("lucasjorge");

    /*
      Variável que envia a mensagem e armazena o valor de '1' caso
      a mensagem seja enviada com sucesso e '0' caso o envio falhe
    */
    mensagem = mqttClient.publish("ar_condicionado", "LIGADO");

    //Função que verifica a conexão entre o Cliente e o Broker e evita a queda de conexão entre eles.
    mqttClient.loop();

    //Aguarda um período de 0,5 segundos
    delay(500);
}
