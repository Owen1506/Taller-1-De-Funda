int pin1 = 7;
int pin2 = 8;
int pin3 = 9;
int pin4 = 10;
int boton1Pin = 6;  // Ajusta los pines según tu configuración real
int boton2Pin = 4;
int boton3Pin = 3;
int boton4Pin = 2;
int n = 0;
int var = 0;
int negativo = 1;
int res = 0;
int expo = 1;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(boton1Pin, INPUT); // Configura los pines de los botones como entradas
  pinMode(boton2Pin, INPUT);
}

void loop() {
  if (digitalRead(boton3Pin) == HIGH)
  {
    expo = 1;
  	res = 0;
    negativo *=-1;
  Serial.print(negativo);
  delay(1000);}
  // Lee el estado del primer botón
  if (digitalRead(boton1Pin) == HIGH)
  { 
    expo = 1;
  	res = 0;
    //Serial.print(n);
    var +=(2*negativo);
    n = var;
    //Serial.print(var);

    delay(2000);
  }
    if (digitalRead(boton2Pin) == HIGH)
  { 
    expo = 1;
  	res = 0;
    //Serial.print(n);
    var +=1*negativo;
    n = var;
    //Serial.print(var);

    delay(2000);
  }

  // Convertir `n` a binario
  while (n > 0) {
    Serial.print(var);
    Serial.print("\n");
    delay(100);
    res += (n % 2) * expo;
    expo *= 10;
    n /= 2;
  }
	
  
  // Encender o apagar los LEDs según el valor de `res`
  if (res % 10 == 1) {
    digitalWrite(pin1, HIGH);
  }
  if ((res / 10) % 10 == 1) {
    digitalWrite(pin2, HIGH);
  }
  if ((res / 100) % 10 == 1) {
    digitalWrite(pin3, HIGH);
  }
  if ((res / 1000) % 10 == 1) {
    digitalWrite(pin4, HIGH);
  }

  // Apagar LEDs si el bit correspondiente en `res` es 0
  if (res % 10 == 0) {
    digitalWrite(pin1, LOW);
  }
  if ((res / 10) % 10 == 0) {
    digitalWrite(pin2, LOW);
  }
  if ((res / 100) % 10 == 0) {
    digitalWrite(pin3, LOW);
  }
  if ((res / 1000) % 10 == 0) {
    digitalWrite(pin4, LOW);
  }
  
}
