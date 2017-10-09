# smartpark

## Organização do repositório

* **epos2svn**: pasta com o svn do epos2
* **arm**: link simbólico para epos2svn/branches/arm, é onde as aplicações para o eposMote III devem ser compiladas
* **mote_playground_**: pasta com aplicações de experimentos e testes com o eposMote III
* **mote_sink**: pasta com a aplicação sink para o eposMote III
* **mote_spot**: pasta com a aplicação do eposMoteIII com o sensor que fica acima da vaga
* **mote_counter**: pasta com a aplicação do eposMoteIII que tem o contador de vagas de um conjunto de setores
* **gateway**: código do gateway que lê os dados do sink pelo USB e manda para a API
* **web_admin**: pasta com a app da área de administração do estacionamento
* **web_client**: pasta com a app do cliente de um estacionamento, onde pode visualizar vagas disponíveis

## Compilando para o eposMoteIII

Exemplo:

````
// desconecta o eposMote do USB
cd arm
make APPLICATION=smartpark_ultrasonic_sensor_test clean flash
// conecta o eposMote no USB
````
