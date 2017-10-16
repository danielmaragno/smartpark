# smartpark

## Organização do repositório

* **epos2svn**: pasta com o svn do epos2
* **arm**: link simbólico para epos2svn/branches/arm, é onde as aplicações para o eposMote III devem ser compiladas
* **mote_playground_**: pasta com aplicações de experimentos e testes com o eposMote III
* **mote_sink**: pasta com a aplicação sink para o eposMote III
* **mote_spot**: pasta com a aplicação do eposMoteIII com o sensor que fica em cima da vaga de estacionamento
* **gateway**: código do gateway que lê os dados do sink pelo USB e manda para a API
* **web_admin**: pasta com a app da área de administração do estacionamento
* **web_client**: pasta com a app do cliente de um estacionamento, onde pode visualizar vagas disponíveis

## Sink (gateway)

````
// desconecta o eposMote do USB
cd arm
make APPLICATION=smartpark_sink clean flash
// conecta o eposMote no USB
````

## Spot (sensor ultra-sônico)

````
// desconecta o eposMote do USB
cd arm
make APPLICATION=smartpark_spot clean flash
// conecta o eposMote no USB
````

## Teste do sensor ultra-sônico

````
// desconecta o eposMote do USB
cd arm
make APPLICATION=smartpark_ultrasonic_sensor_test clean flash
// conecta o eposMote no USB
````

## Enviando dados do sink para a núvem IoT

Usamos a núvem IoT do LISHA para armazenar os dados de interesse recebidos pelo
sink. Para fazer a leitura dos dados do sink, usamos um script em Python que
faz a leitura pela USB e envia para a núvem do LISHA.

````
// Conecta ao sink a USB
cd gateway
./gateway -c cert.pem -P 'SENHA'
// Insira a senha do certificado

// Para dar kill no gateway execute
./kill_gateway.sh
````
