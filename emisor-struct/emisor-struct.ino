#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
// Magia Negra
#include <types.h>

//Variable con la dirección del canal por donde se va a transmitir
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
 
//Abrimos un canal de escritura
 radio.openWritingPipe(direccion);
 
}
 
void loop()
{ 
 //cargamos los datos en la variable datos[]
 coord.x=0;
 coord.y=1;
 //enviamos los datos
 bool ok = radio.write(&coord, sizeof(coord));
  //reportamos por el puerto serial los datos enviados 
  if(ok)
  {
     Serial.print("Datos enviados: ("); 
     Serial.print(coord.x); 
     Serial.print(" ; "); 
     Serial.print(coord.y); 
     Serial.println(")"); 
  }
  else
  {
     Serial.println("no se ha podido enviar");
  }
  delay(1000);
}