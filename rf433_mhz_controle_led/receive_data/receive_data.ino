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

// Récepteur RF 433Mhz sur l'interruption 1 => cela correspond à la broche n°3.
#define interrupt_pin 1 

// Pins connectés aux leds
#define LED_V 4
#define LED_R 5

RCSwitch rf_cmd = RCSwitch();

unsigned long value = 0;

void setup() {
  Serial.begin(9600);
  
  rf_cmd.enableReceive(interrupt_pin);  

  // Configuration des pins
  pinMode(LED_V, OUTPUT);
  pinMode(LED_R, OUTPUT);
}

void loop() {
  if (rf_cmd.available()){
    value = rf_cmd.getReceivedValue();

    Serial.print("Received " + String(value) + " / ");
    Serial.println(String(rf_cmd.getReceivedBitlength()) + " bit");
    
    rf_cmd.resetAvailable();

    // Mise à jour des sortie
    if(value==1)
      digitalWrite(LED_V, HIGH);
    else if(value==2)
      digitalWrite(LED_V, LOW);
    else if(value==3)
      digitalWrite(LED_R, HIGH);
    else if(value==4)
      digitalWrite(LED_R, LOW);
  }
}
