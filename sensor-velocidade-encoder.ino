int pino_sensor = 8; // Pino digital utilizado pelo sensor
int sinal = 0;
int ultimo_sinal = 0;
double tempo_ultimo_sinal = 0;
float periodo = 0; // [ms]
float frequencia = 0; // [RPM]

void setup(){  
  Serial.begin(9600);
  pinMode(pino_sensor, INPUT); // Define o pino como entrada
  Serial.println("Periodo,Frequencia,tempo");
}  
   
void loop(){
  // lê o sinal atual do sensor
  sinal = digitalRead(pino_sensor);

  // se houve uma mudança (tá em furo), significa que houve um ciclo, logo calcula o período e a frequência
  if(sinal != ultimo_sinal){
    // tempo atual do arduino
    float tempo_sinal_atual = millis();

    // intervalo de tempo entre a última passagem do furo e a atual (período)
    periodo = (tempo_sinal_atual - tempo_ultimo_sinal);
    // frequência em Hz = 1/periodo, frequencia em RPM = 60*frequência em Hz
    // Além disso, verifica se o perído é diferente de zero, caso seja igual mantém a leitura passada
    if(periodo != 0){
      frequencia = 60*(1000/periodo);
    }

    // armazena as últimas medições para o cálculo seguinte
    tempo_ultimo_sinal = tempo_sinal_atual;
    ultimo_sinal = sinal;
    Serial.print(periodo);
    Serial.print(",");
    Serial.print(frequencia);
    Serial.print(",");
    Serial.println(tempo_sinal_atual);
  }
}
