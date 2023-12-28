/**
 * e-mail : openprogramming23@gmail.com
 * gitHub : https://github.com/RS-malik-el
 *
 * @AUTEUR : Exaucé KIMBEMBE / @OpenProgramming
 * DATE : 27/12/2023
 * 
 * @Board : Arduino
 * 
*/
#include <RCSwitch.h>

// L'émetteur rf 433Mhz est connecté à la broche n°2 de l'Arduino. 
#define PIN_RF_SEND 2
// Pins connectés aux boutons-poussoir
#define PIN_UP    A1
#define PIN_DOWN  A2
#define PIN_LEFT  A3
#define PIN_RIGHT A4

// Données a envoyé en fonction du bouton appuyer (nombre, taille)
#define BIT_TAILLE 10
#define DATA_UP()    1,BIT_TAILLE
#define DATA_DOWN()  2,BIT_TAILLE
#define DATA_LEFT()  3,BIT_TAILLE
#define DATA_RIGHT() 4,BIT_TAILLE

RCSwitch rf_cmd = RCSwitch();

void sendData(uint8_t pin, uint8_t num);

void setup() {  
  // Activation de la transmition
  rf_cmd.enableTransmit(PIN_RF_SEND);

  // Définition des pins comme entrée
  pinMode(PIN_UP, INPUT_PULLUP);
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_LEFT, INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);
}

void loop() {
  sendData(PIN_UP,   1);
  sendData(PIN_DOWN, 2);
  sendData(PIN_LEFT, 3);
  sendData(PIN_RIGHT,4);
}

void sendData(uint8_t pin, uint8_t num){
  // Détecte l'appui sur un bouton
  if(not digitalRead(pin)==true){
    delayMicroseconds(100);// Attente après chaque appui
    while(not digitalRead(pin)==true){delayMicroseconds(10);}// Si appui maintenant on ne fait rien
    
    // Transfert des données
    if (num==1)
      rf_cmd.send(DATA_UP());
    else if (num==2)
      rf_cmd.send(DATA_DOWN());
    else if (num==3)
      rf_cmd.send(DATA_LEFT());
    else if (num==4)
      rf_cmd.send(DATA_RIGHT());

    delayMicroseconds(100); // Pause avant la sortie de la fonction
  }
}