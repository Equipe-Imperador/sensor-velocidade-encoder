int pino_sensor = 8; // Pino digital utilizado pelo sensor
   
void setup(){  
  pinMode(pino_sensor, INPUT); // Define o pino como entrada
  Serial.begin(9600);
}  
   
void loop(){
  if (digitalRead(pino_sensor) == HIGH){ // Se a leitura do pino for igual a low, faz
        Serial.println("HIGH");
  }else{//SENÃO, FAZ
        Serial.println("LOW");
  }    
}
