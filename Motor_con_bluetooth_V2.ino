#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int velocidad = 250;
int estado;
int pinReversa = 10;
int pinBalizasDer = 11;
int pinBalizasIzq = 9;
int potenciometro = 0;
int intensidad = 0;

void setup() {
  Serial.begin(9600);    // Inicializamos  el puerto serie
  pinMode(pinReversa, OUTPUT);
  pinMode(pinBalizasDer, OUTPUT);
  pinMode(pinBalizasIzq, OUTPUT);

  motor1.setSpeed(250);  //Velocidad estándar de 250, máxima velocidad posible 255
  motor1.run(RELEASE);

  motor2.setSpeed(250);  //Recuerda que puedes cambiar la velocidad estándar en el loop
  motor2.run(RELEASE);

  motor3.setSpeed(250);
  motor3.run(RELEASE);

  motor4.setSpeed(250);
  motor4.run(RELEASE);
}

void loop() {
  if (Serial.available() > 0) {  // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if (estado == 'a') {  // Boton ADELANTE
    Mover_Adelante();
  }

  if (estado == 'i') {  // Boton IZQUIERDA
    Mover_Izquierda();
  }

  if (estado == 'd') {  // Boton DERECHA
    Mover_Derecha();   
  }

  if (estado == 'r') {  // Boton ATRAS
    Mover_Retroceso();
  }

  if (estado == 'f') {  // Boton FRENO
    Mover_Stop(); 
  }

  if(estado != 'r') {   //Comprobar si se esta moviendo hacia atras, sino no se prende el led
    analogWrite(pinReversa, LOW);
  }

  if(estado == 'b') { //Alternar el estado de las balizas
    balizasEncendidas = !balizasEncendidas;
  }
  if(balizasEncendidas == true){
      prenderLedsBalizas();
    }else {
      apagarLedsBalizas();
    }

  if (estado == 'e') {
    luz_dere = !luz_dere;
  }
  if (estado == 'q') {
    luz_izq = !luz_izq;
  }
  if(luz_dere == true){
    //Luz_Giro_Dere();
  }else {
    analogWrite(pinBalizasDer, LOW);
  }
  
  if(luz_izq == true){
    //Luz_Giro_Izq();
  }else {
  analogWrite(pinBalizasIzq, LOW);
  }
}//void loop cierre

//Funcion para desplazarse hacia adelante
void Mover_Adelante() {
  motor1.run(FORWARD);         //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
  motor1.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor2.run(FORWARD);
  motor2.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor3.run(FORWARD);
  motor3.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor4.run(FORWARD);
  motor4.setSpeed(velocidad);  //Sin embargo con velocidades menores a 100 generalmente el motor ya no tiene la potencia para mover un robot
}
//Funcion para desplazarse hacia atras
void Mover_Retroceso() {
  motor1.run(BACKWARD);        //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
  motor1.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor2.run(BACKWARD);
  motor2.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor3.run(BACKWARD);
  motor3.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor4.run(BACKWARD);
  motor4.setSpeed(velocidad);  //Sin embargo con velocidades menores a 100 generalmente el motor ya no tiene la potencia para mover un robot

  intensidad = analogRead(potenciometro) / 4;
  analogWrite(pinReversa, intensidad);
}
//Funcion para desplazarse hacia la derecha
void Mover_Derecha() {
  motor1.run(FORWARD);         //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
  motor1.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor2.run(FORWARD);
  motor2.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor3.run(RELEASE);
  motor3.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor4.run(FORWARD);
  motor4.setSpeed(velocidad);  //Sin embargo con velocidades menores a 100 generalmente el motor ya no tiene la potencia para mover un robot
}
//Funcion para desplazarse hacia la izquierda
void Mover_Izquierda() {
  motor1.run(FORWARD);        //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
  motor1.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor2.run(FORWARD);
  motor2.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor3.run(FORWARD);
  motor3.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor4.run(RELEASE);
  motor4.setSpeed(velocidad);  //Sin embargo con velocidades menores a 100 generalmente el motor ya no tiene la potencia para mover un robot
}
//Funcion para detenerse
void Mover_Stop() {
  motor1.run(RELEASE);  //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
  //motor1.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor2.run(RELEASE);
  //motor2.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor3.run(RELEASE);
  //motor3.setSpeed(velocidad);  //Puedes varias la velocidad de 0 como mínima a 255 como maxima
  motor4.run(RELEASE);
  //motor4.setSpeed(velocidad);  //Sin embargo con velocidades menores a 100 generalmente el motor ya no tiene la potencia para mover un robot
}

//Funcion encender los LEDs de las balizas
void prenderLedsBalizas(){
  analogWrite(pinBalizasDer, HIGH);
  analogWrite(pinBalizasIzq, HIGH);
  delay(400);
  analogWrite(pinBalizasDer, LOW);
  analogWrite(pinBalizasIzq, LOW);
  delay(400);
}
void apagarLedsBalizas(){
  analogWrite(pinBalizasDer, LOW);
  analogWrite(pinBalizasIzq, LOW);
}