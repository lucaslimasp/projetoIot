//Programa : Controle de Pagamentos Restaurantes Self Service
//Autor : Lucas Lima Mauricio de Sousa

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.


char st[20];
float valor; //armazenara valor do prato
String conteudo= ""; // armazenara a tag
int readBluetooth; //para ler retorno do bluetooth pela aplicação
void setup() 
{
  randomSeed(analogRead(0));
  Serial.begin(9600); // Inicia a serial
  SPI.begin();    // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
}

void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  byte letra;
 
  if(conteudo == ""){ //se conteudo estiver vazio atribui valor do prato e tag
     for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
      conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  conteudo.toUpperCase();
  valor =  random(10, 30); // gera valor do prato a ser pago aleatóriamente
  String mensagem = "Tag do prato : " + conteudo.substring(1) +" Valor do Prato: " + valor;
  Serial.print(mensagem);
  }
  if(Serial.available()){
    readBluetooth = Serial.read();
    if(readBluetooth == 'a'){ // se pagamento for realizado pelo usuario, bluetooth retorna valor "a"
           conteudo = ""; //torna conteudo vazio para permitir nova leitura de tag e prato
          
     }
  } 
}
