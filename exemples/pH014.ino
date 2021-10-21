/*=======================================================================
  Esse código é dimensionado para um modelo especifico de módulo
  amplificador usado em conjunto com a sonda de pH, por isso, em 
  alguns módulos podem não funcionar da maneira adequada. 
   
  Certifique-se que está usando o mesmo módulo que essa biblioteca foi 
  desenvolvida em: https://elcereza.com/ph014
  Site  : https://elcereza.com/
   
  Autor : Gustavo Cereza
  Disponibilizado por : Elcereza
  Redes : @ellcereza
  Canal : https://t.me/elcereza
=======================================================================*/

#include <Elcereza_pH014.h>
pH014 pH(7);                                                            // Define a porta A7 como entrada e leitura AD
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("pH: " + String(pH.getpH()));                         // Imprime na serial o valor de ponto flutuante retornado por 'getpH'
  delay(1000);
}
