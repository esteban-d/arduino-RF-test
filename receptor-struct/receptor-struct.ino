#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <types.h>

//Variable con la dirección del canal que se va a leer
byte direccion[5] ={'c','a','n','a','l'}; 

//creamos el objeto radio (NRF24L01)
RF24 radio(CE_PIN, CSN_PIN);

// Creamos una variable de tipo coordinates
coordinates coord;

void setup()
{
 //inicializamos el NRF24L01 
  radio.begin();
  //inicializamos el puerto serie
  Serial.begin(9600); 
  
  //Abrimos el canal de Lectura
  radio.openReadingPipe(1, direccion);
  
    //empezamos a escuchar por el canal
  radio.startListening();
 
}
 
void loop() {
 uint8_t numero_canal;
 if ( radio.available() )
 {    
     //Leemos los datos y los guardamos en la variable datos[]
     radio.read(&coord,sizeof(coord));
     
     //reportamos por el puerto serial los datos recibidos
     Serial.print("(" );
     Serial.print(coord.x);
     Serial.print(" ; ");
     Serial.print(coord.y);
     Serial.println(")" );
 }
 else
 {
     Serial.println("No hay datos de radio disponibles");
 }
 delay(1000);
}