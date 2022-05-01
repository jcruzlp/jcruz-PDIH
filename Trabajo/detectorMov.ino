#include <TimerFreeTone.h> //librerias para los tonos (no es la estándar porque esta da error en ejecución)
#define TONE_PIN 3 // pin estandar para el zumbador
#include <Wire.h> //para el lcd
#include <LiquidCrystal_I2C.h> //librerias del lcd

int trig = 5; 
int echo = 6; //Pines del ecolocalizador
int pir = 7; //pin digigital 
int zumbador = 3; //pin "analogico"
int redLED = 2; //pin digigital 
int yellowLED = 4; //pin digigital 
int redRGB = 9; //pin "analogico"
int greenRGB = 10; //pin "analogico"
int blueRGB = 11; //pin "analogico"
LiquidCrystal_I2C lcd(0x27, 16, 2); //lcd display address

void setup() { //preparar inpunts, outputs y el lcd
  pinMode(redLED, OUTPUT); 
  pinMode(yellowLED, OUTPUT);
  pinMode(zumbador, OUTPUT);
  pinMode(pir, INPUT); 
  pinMode(redRGB, OUTPUT);
  pinMode(blueRGB, OUTPUT);
  pinMode(greenRGB, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init(); //inicializando lcd
  lcd.backlight(); //encender luz trasera del lcd
}

void setColorines(int r, int g, int b) { //Configuración de colores del LED RGB

  //Solo para el LED RGB!!
  r = 255-r;
  g = 255-g;
  b = 255-b;
   
  analogWrite(redRGB,r);
  analogWrite(greenRGB,g);
  analogWrite(blueRGB,b);
}

void sirena (){ 
    int tonadilla[] = { //Notas de la alarma, imita a los coches de choque
    370 , 370, 262, 262, 370, 370, 262, 262, 370, 370, 262, 262, 370, 370, 262, 262, 370
  };
  
  // Duración de la nota, 8 = octava... etc.
  int duraciones[] = { //duración de las notas en el orden de las mismas
    4, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 16, 16,
  };
  int duracionCancion = sizeof(tonadilla)/sizeof(tonadilla[0]);
    for (int nota = 0; nota < duracionCancion; nota++){
      int duracion = 1200/ duraciones[nota];
      TimerFreeTone(TONE_PIN, tonadilla[nota], duracion);
      int pause = duracion * 0.1;
       // Play
      delay(pause);   
  }
}

void alarma(){ //codigo de colores
  setColorines(204,0,0); //dark red
  delay(600);
  setColorines(0,0,255); // blue
  delay(600);
  setColorines(255,51,51); // light red
  delay(600);
  setColorines(0,0,153); //dark blue
  delay(600); 
  setColorines(255,128,0); //orange
  delay(600);
  setColorines(0,0,255); // blue
  delay(600);
  setColorines(255,108,92); //blush
  delay(600);
}

void loop() { //main
  long duracion, distancia; //setup del sensor de distancia 
  digitalWrite(trig, LOW); //apaga el ping
  delayMicroseconds(2); //delay 2 milisegundos
  digitalWrite(trig, HIGH);  //enciende el ping
  delayMicroseconds(10); //delay durante 10 milisegundos, suficiente para que el ping llegue a algo (como un radar)
  digitalWrite(trig, LOW); //apaga el ping
  delayMicroseconds(2); //delay 2 milisegundos

  duracion = pulseIn(echo, HIGH); //lanza un ping
  distancia = (duracion/2)/29; //distancia en centimetros dividir por 29 (vel. sonido = 1/29 cm/us, calculado de vel. sonido = 345 m/s) y por 2 porque el ping  es ida y vuelta

  //Posibles escenarios

  if ( digitalRead(pir) == 1){ //si el sensor de movimiento detecta algo
    digitalWrite(redLED, LOW); //apaga el led rojo
    digitalWrite(yellowLED, HIGH); //enciende el led amarillo
    lcd.setCursor(0,0); //coloca el cursor del lcd en la primera fila primera columna
    lcd.println("Hay movimiento!!"); //escribe en el LCD
    delay(1000); //pausa
    lcd.clear(); //hace un clear en el lcd 
  }

  if(digitalRead(pir) == 0){ //si el sensor de movimiento no detecta nada
    digitalWrite(yellowLED, LOW); //apaga el led amarillo
    digitalWrite(redLED, LOW); //apaga el led rojo
    setColorines(0,102,0); //Usa la función de antes para poner el led verde
    lcd.setCursor(0,0); //coloca el cursor del lcd en la primera fila primera columna
    lcd.print("Despejado!");//escribe en el LCD
    delay(1000); //pausa
    lcd.clear(); //hace un clear en el lcd 
  }

  if (distancia >= 100){ //Si la distancia del sensor es mayor de un metro (mas o menos)
    lcd.setCursor(0,0); ///coloca el cursor del lcd en la primera fila primera columna
    lcd.print("Hay algo a: ");//escribe en el LCD
    lcd.setCursor(0,1);  //coloca el cursor del lcd en la segunda fila primera columna
    lcd.print(distancia); //print de la distancia
    lcd.setCursor(2,1); //coloca el cursor del lcd en la segunda fila segunda columna
    lcd.print(" metros"); //escribe en el LCD
    delay(1000); //pausa
    lcd.clear(); //hace un clear en el lcd 
    
  }
  if (distancia <= 100){ //Si la distancia del sensor es mayor de un metro (mas o menos)
    digitalWrite(yellowLED, LOW); //apaga el led amarillo
    digitalWrite(redLED, HIGH); //enciende el led rojo
    setColorines(0,0,0); //apaga el led rgb
    lcd.setCursor(0,0); ///coloca el cursor del lcd en la primera fila primera columna
    lcd.print("Alerta de Intruso a: ");//escribe en el LCD
    lcd.setCursor(0,1);//coloca el cursor del lcd en la segunda fila primera columna
    lcd.print(distancia); //print de la distancia
    lcd.setCursor(2,1); //coloca el cursor del lcd en la segunda fila segunda columna
    lcd.print(" metros"); //escribe en el LCD
    sirena(); //El codigo de arriba, que imita la sirena de los coches de choque
    alarma(); //El codigo de arriba, que imita las luces de las sirenas de la policia
    sirena(); //repite la tonadilla de los coches de choque
    delay(1000); //pausa
    lcd.clear(); //hace un clear en el lcd 
  }
}
