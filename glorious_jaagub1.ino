int pin1 = 7;
int pin2 = 8;
int pin3 = 9;
int pin4 = 10;
int pinrojo = 5;
int boton1Pin = 6;  
int boton2Pin = 4;
int boton3Pin = 12;
int boton4Pin = 2;
int n = 0;
int var = 0;
int negativo = 1;
int res = 0;
int expo = 1;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(boton1Pin, INPUT);
  pinMode(boton2Pin, INPUT);
  pinMode(boton3Pin, INPUT); 
  pinMode(boton4Pin, INPUT);
}

void loop() {
  if (digitalRead(boton4Pin) == HIGH) 
  {
    expo = 1;
  	res = 0;
    negativo *=-1;
    var = 0;
    n = 0;
  	Serial.print(negativo);
    Serial.print("\n");
  	//delay(1000);
    millis();
     delay(100);
  }

  if (var>15 || var <-15)
  {
  	digitalWrite(pinrojo,HIGH);
  }
  else
  {
    digitalWrite(pinrojo,LOW);
  }
  if (digitalRead(boton1Pin) == HIGH)
  { 
    expo = 1;
  	res = 0;
   
    var +=2;
    n = var;
   
    if (negativo == -1)
  {
    n = var;
    n = (16-n);
    
  }

    //delay(1000);
    millis();
     delay(100);
  }
    if (digitalRead(boton2Pin) == HIGH)
  { 
    
    expo = 1;
  	res = 0;
   
    var +=1;
    n = var;
    if (negativo == -1)
  {
    n = var;
    n = (16-n);
    
  }
    

    //delay(1000);
      millis();
      delay(100);
  }

  if (digitalRead(boton3Pin)==HIGH)
  {
    Serial.print("Reset");
    Serial.print("\n");
   	var = 0;
    n = 0;
    res = 0;
    expo = 1;

  }
  // Convertir `n` a binario
  
  while (n > 0) {
    if (negativo == 1)
    {
        Serial.print(var);
        Serial.print("\n");
        delay(100);
        res += (n % 2) * expo;
        expo *= 10;
        n /= 2;
        millis();
    }
    if (negativo == -1)
    {
        Serial.print(var);
        Serial.print("\n");
        delay(100);
        res += (n % 2) * expo;
        expo *= 10;
        n /= 2;
        millis();
         delay(100);
    }

  }
	
  
  // Encender o apagar los LEDs según el valor de `res`
  if (var <= 15 || var >=-15)
  {
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
}
