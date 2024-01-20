int valorADC;
float vACSensor;
int valor4b;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  valorADC = analogRead(A0);  
  valor4b = map(valorADC, 0, 890, 0, 15);
  vACSensor = valorADC*(5.0/1023);
  
  Serial.println("Binario 4 bits"); 
  Serial.print("Decimal 10b: "); 
  Serial.println(valorADC);
  Serial.print("Decimal 4b: ");
  Serial.println(valor4b);
  Serial.print("Tension: ");
  Serial.println(vACSensor);
  
  BinaryConversion(valor4b);
  Serial.println("");
  delay(3000);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  /*
  switch(valor4b){
    case 0:
      digitalWrite(6, LOW);
        digitalWrite(7, LOW);
      digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        delay(1000);
    break;
      
    case 1:
      digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 2:
      digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 3:
      digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 4:
      digitalWrite(6, LOW);
        digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 5:
      digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 6:
      digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 7:
      digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        delay(1000);
    break;
    
    case 8:
      digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 9:
      digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 10:
      digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 11:
      digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 12:
      digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 13:
      digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 14:
      digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
    
    case 15:
      digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        delay(1000);
    break;
  }
  */
}

int BinaryConversion(int num){
  
  int Result[4] = {};
  int z = 2;
  for (int i = 0; i < 4 ; i++){
  Result[i] = num % 2;
  num = num / 2;
  }
  
  for(int j = 0; j < 4; j++){
    if (Result[j] == 1){
      digitalWrite(z, HIGH);
    }
    z = z+1;
    Serial.println(Result[j]);
  }
}
