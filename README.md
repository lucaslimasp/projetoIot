# Projeto Objetos Inteligentes Conectados
**Automação de pagamentos e pedidos de Restaurantes Self Service - Parte Inicial**

**Objetivo**
Passar informações de peso do prato do cliente de um restaurante self service, no qual o valor do peso, e o preço serão armazenados e associados a conta do usuário.

**Como fazer? - Modelo Idealizado para meu TCC:**
- O modelo a seguir tem como intenção ilustrar o objetivo final deste projeto, que será utilizado em meu TCC futuramente. Portanto, este modelo não será totalmente desenvolvido para a entrega do projeto na matéria de Objetos Inteligentes Conectados, devido à alta complexidade do mesmo, e a escassez de tempo.
- Pegar o valor e o preço do prato, armazenar e associar a uma tag rfid colocada logo abaixo do prato do cliente. 
- Durante a pesagem, para uma primeira experiencia do cliente, o mesmo deverá baixar um aplicativo, que irá solicitar que o mesmo habilite o bluetooth em seu celular. Feito isso será realizado a conexão com um modulo bluetooth Beacon BLE localizado próximo a balança, que irá atrelar os valores do prato com a conta do usuário. Um possível incremento será permitir que o as informações sejam passadas através do wifi do local, utilizando o aplicativo como intermediador de informações.
- As mesas do restaurante, possuirão um leitor de rfid, com uma antena, e alimentação em toda a mesa, a fim de permitir que a tag localizada embaixo do prato seja alimentada, e então a antena consiga captar todas as tags da mesa.
- Considerando que o usuário somente ira sincronizar seu bluetooth com o da balança na primeira visita, as tags dos pratos desempenham função de serem auxiliadoras para identificação correta dos clientes, uma vez que o Beacon da balança estará sempre analisando todos os smartphones próximos a balança durante a pesagem, e em cada mesa haverá um Beacon, que por sua vez irá verificar os celulares ao redor da mesa.
Desta forma, vamos supor o seguinte cenário:
```
- Usuario 1 com prato x e usuário 2 com prato y, próximos a balança. Beacon identifica smartphone dos usuários 1 e 2 que estão próximos a balança. Beacon não identifica de imediato para qual smartphone atrelar a leitura do peso do prato do usuário 1, pois ambos clientes estão próximos.
- Usuário 1 parte para mesa K enquanto que o usuário 2 parte para mesa J.
- Ambas as mesas identificam os valores das tags abaixo dos pratos.
- Beacon da mesa k identifica prato x na mesa graças a leitura da tag rfid. Este Beacon identifica então que embora durante a pesagem do prato x, houvessem os usuários 1 e 2, a leitura do valor do prato na verdade pertencia ao usuário 1, pois o mesmo ainda está com o prato x, e o seu smartphone permanece com ele.
```
**Para esta matéria – O que será feito:**
Conforme dito, devido à alta complexidade do modelo proposto, o projeto que será entregue para esta matéria será uma versão simplificada.
Portanto, o modelo desenvolvido será o seguinte:
- Leitura de tag rfid - Atrelagem de valor simulado do peso do prato ao valor da tag. Não foi adquirido balança para a simulação pratica, portanto, o valor será feito a partir de simulação no código.
- Conexão com modulo bluetooth – Não consegui adquirir um Beacon para o projeto, portanto improvisadamente o bluetooth da balança será feito com um modulo bluetooth ht-06. 
- Será elaborado aplicação ou forma de comunicação com usuário a fim de atrelar o valor do prato com a conta do usuário e armazenar em banco de dados FireBase.

**Componentes**

```
- Arduino - Utilizado Arduino Uno r3
- Módulo Bluetooth Ht-06
- Leitor de Rfid Mfrc522 
- Tag Rfid no formato de chaveiro
- Smartphone Android para uso do Aplicativo Desenvolvido
```
**Desenho do circuito**

![Alt Text](https://github.com/lucaslimasp/projetoIot/blob/master/imagens/projeto_desenho.jpg)

**Esquema Elétrico**

![Alt Text](https://github.com/lucaslimasp/projetoIot/blob/master/imagens/projeto_Esquem%C3%A1tico.jpg)

**Documentação das Interfaces**
Todo o aplicativo foi desenvolvido utilizando o site http://ai2.appinventor.mit.edu que possibilita a criação de aplicativos para Android via Browser(navegador de internet), de forma simplificada, apenas arrastando os ícones das telas, e toda a programação é feita através de blocos pré definidos de códigos.
O projeto da aplicação desenvolvida está disponível neste repositório, com o nome app_inventor_projeto.aia, para abri-lo basta acessa o site, logar com seu usuário, e importar este arquivo.
- Segue algumas imagens:

![Alt Text](https://github.com/lucaslimasp/projetoIot/blob/master/imagens/appinventor.png)

- Blocos de programação:


![Alt Text](https://github.com/lucaslimasp/projetoIot/blob/master/imagens/appinventor_blocos1.png)

**Rede e hardware**

Para comunicação entre Arduino e aplicativo, foi utilizado o módulo bluetooth Ht-06, que envia e recebe as interações do usuário via interações bluetooth.
Toda informação recolhida pelo aplicativo a partir desta conexão, é armazenada em um banco de dados via FireBase.

**Código Arduino**
Os códigos utilizados para programar o Arduino encontram se no arquivo codigo_arduino.ino, que possuem uma explicação simplificada de certas partes importantes do código.

