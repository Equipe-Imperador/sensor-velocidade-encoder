int pino_sensor = 2; // Pino digital utilizado pelo sensor
volatile double tempo_ultimo_sinal = 0;
volatile float frequencia = 0; // [RPM]

void setup(){  
  Serial.begin(9600);
  Serial.println("Frequencia,tempo");
  attachInterrupt(digitalPinToInterrupt(pino_sensor), calculo_frequencia, RISING);
}  

volatile unsigned long int TempoRPM = 0; // Tempo do último pulso
volatile unsigned long int RPM = 0;
void calculo_frequencia() 
{
  /*
      Para calcular a frequencia é feita a seguinte fórmula:
              frequencia = (1 / Período) * 1000 * 60
      No nosso caso o período e dado pelo tempo entre os dois pulsos e que sai em milissegundos.
      Sendo assim, para poder achar o RPM precisamos multiplicar por 1000 e depois por 60.
   */
  float frequencia_ = 60000/(millis()- TempoRPM);
  
  if(frequencia_ < 10000 && frequencia_ > 0){
     frequencia = frequencia_;
  }
  
  TempoRPM = millis();
  Serial.print(frequencia);
  Serial.print(",");
  Serial.println(TempoRPM);

}

void loop(){

}
