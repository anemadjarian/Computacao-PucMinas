int vermelho = 13;
int amarelo = 12; 
int verde = 11;
int azul = 10;    

String memoria[100]; //Declarar o vetor de memória
String comando[4]; //Declarar o Registrador

void setup() {
  Serial.begin(9600); //Tempo de execução do programa

  //LEDS
  pinMode(vermelho, OUTPUT); 
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  String value = Serial.readStringUntil(' '); //Lê a String
  int i = 0;

  while(value != "GGG") { //Lê a String até o comando GGG
    if(value != "") {
    	memoria[i] = value; //Carrega o comando no vetor de memória
    	i++;
    }
    value = Serial.readStringUntil(' ');
  }
  
  Serial.print("Memoria carregada!\n");
  
  //Inicialia o Registrador com 0
  comando[0] = '0'; 
  comando[1] = '0';
  comando[2] = '0';
  comando[3] = '0';
  printComando(0, i);
  
  Serial.print("Deseja executar o programa (S/N)?\n");
  
  while (Serial.available() == 0) {
    // trava execução enquanto não há resposta
  }

  char resposta = Serial.read();
  if(resposta == 'S') { // Se sim, executa o programa
  
    for(int j = 0; j < i; j++) {
      comando[0] = memoria[j][0];
      comando[1] = memoria[j][1];
      comando[2] = memoria[j][2];
      comando[3] = (char) ('0' + j);

      String resp = minemonics(comando);
      printComando(j, i);

      digitalWrite(vermelho, resp[0] - '0');
      digitalWrite(amarelo, resp[1] - '0');
      digitalWrite(verde, resp[2] - '0');
      digitalWrite(azul, resp[3] - '0');

      delay(4000);
    }
  }
  
  Serial.print("Fim\n");
}

String minemonics(String comando[]) {
  int x = hexaToInt(comando[0][0]);
  int y = hexaToInt(comando[1][0]);

  String resp = "";

  switch(comando[2][0]) {
    case '0': 
   		resp = intToBin(x); 
    break;
    case '1': 
    	resp = intToBin(y); 
    break;
    case '2': 
    	resp = intToBin(x ^ y); 
    break;
    case '3': 
    	resp = intToBin(((~x)&0x0F) ^ ((~y)&0x0F)); 
    break;
    case '4': 
    	resp = intToBin(x & ((~y)&0x0F)); 
    break;
    case '5': 
    	resp = intToBin((~y)&0x0F); 
    break;
    case '6':
    	resp = intToBin(((~x)&0x0F) | ((~y)&0x0F)); 
    break;
    case '7': 
    	resp = intToBin((~x)&0x0F); 
    break;
    case '8': 
    	resp = intToBin(x | ((~y)&0x0F)); 
    break;
    case '9': 
    	resp = "1111"; 
    break;
    case 'A': 
    	resp = "0000"; 
    break;
    case 'B': 
    	resp = intToBin(x & y);
    break;
    case 'C': 
    	resp = intToBin(((~x)&0x0F) & y); 
    break;
    case 'D': 
    	resp = intToBin(x & ((~y)&0x0F)); 
    break;
    case 'E': 
    	resp = intToBin(x | y);
    break;
    case 'F': 
   		resp = intToBin(((~x)&0x0F) & ((~y)&0x0F)); 
    break;
  }

  return resp;
}

void printComando(int begin, int end) {
    int times = 5;
    int index = begin;
    Serial.print("               \\/\n");
    Serial.print("Memoria:       ");

    while ((times > 0 && index < end) && memoria[index] != "GGG") {
        Serial.print(memoria[index]);
      	if(index < end-1) {
      		Serial.print("|");
        }
        times--;
        index++;
    }

    if (index < end && memoria[index] != "GGG") {
        Serial.print("...");
    }

    Serial.print("\n");

    Serial.print("Registradores: ");
    Serial.print(comando[3]);
    Serial.print("|");
    Serial.print(comando[2]);
    Serial.print("|");
    Serial.print(comando[0]);
    Serial.print("|");
    Serial.print(comando[1]);

    Serial.print("\n\n");
}

String intToBin(int value) {
  String resp = "";
  for(int i = 3; i >= 0; i--) {
    resp += ((value >> i) & 1) ? '1' : '0';
  }
  return resp;
}

int hexaToInt(char carac) {
  int resp = 0;
  if(carac >= '0' && carac <= '9') {
  	resp = carac - '0';
  } else {
  	resp = carac - 'A' + 10;
  }
  
  return resp;
}