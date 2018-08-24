/*
  Retenção Bounce
  IOT na prática com o ESP8266
  https://projetosiot.com.br/
  Include the Bounce2 library found here :
  https://github.com/thomasfredericks/Bounce2
*/

#include <Bounce2.h>


// Definições dos pinos de Entrada e Saída
#define buttonPin  D1     // D1 = GPIO5 (General Purpose Input/Output) 
#define ledPin     D4      // D4 = GPIO2 LEDBuiltin (Cuidado GPIO 16 nao tem esta funcao)

int ledState = LOW;

// Instantiate a Bounce object
Bounce debouncer = Bounce(); 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // Incializa o ledPin  como saída
  
  pinMode(buttonPin, INPUT_PULLUP); // Incializa o buttonPin com PULLUP
  debouncer.attach(buttonPin);
  debouncer.interval(25); // intervalo em ms
  
}

void loop() {

  // Update the Bounce instance :
  debouncer.update();

  // Get the updated value :
  int value = debouncer.read();

/*
  // Turn on or off the LED as determined by the state :
  if ( value == LOW ) {
    digitalWrite(ledPin, HIGH );
  } 
  else {
    digitalWrite(ledPin, LOW );
  }
*/

  if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
     ledState = !ledState; // Toggle LED state
     digitalWrite(ledPin,ledState); // Apply new LED state
   }

}
