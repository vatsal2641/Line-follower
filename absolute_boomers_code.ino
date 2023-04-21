const int M_A1 = 8; //motor a RIGHT, HIGH=forward(+)
const int M_A2 = 9; //motor a -
const int M_B1 = 12; //motor b LEFT
const int M_B2 = 13; //motor b = +
const int ENA = 10;
const int ENB = 11;


const int R_S = 3; //sensor R
const int S_S = 4; //sensor S
const int L_S = 5; //sensor L 
const int RD_S = 6; //sensor R Diagonal 
const int LD_S = 7; //sensor L Diagonal

int RS = digitalRead (R_S); //sensor R
int CS = digitalRead (S_S); //sensor S
int LS = digitalRead (L_S); //sensor L
int RDS = digitalRead (RD_S); //sensor R Diagonal
int LDS = digitalRead (LD_S); //sensor L Diagonal

void FORWARD();
void SRTURN();
void SLTURN();
void SHRTURN();
void SHLTURN();
void STOP();
void BACK();
void UTURN();

void setup() {
  // put your setup code here, to run once:
pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);
pinMode(LD_S, INPUT);
pinMode(RD_S, INPUT);
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);

digitalWrite(M_A1, HIGH);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);
//analogWrite (ENA,90);
//analogWrite (ENB,90);
   
Serial.begin (9600);



}

void loop() {
  int RS = digitalRead (R_S); //sensor R
  int CS = digitalRead (S_S); //sensor S
  int LS = digitalRead (L_S); //sensor L
  int RDS = digitalRead (RD_S); //sensor R Diagonal
  int LDS = digitalRead (LD_S); //sensor L Diagonal
  
  Serial.print(LS);
  Serial.print(CS);
  Serial.print(RS); 
  Serial.print(RDS);
  Serial.print(LDS);
  
  if (LS == 0 && LDS==0 && CS == 0 && RDS==0 && RS==0)
  { 
    FORWARD();
    
  }
  else if( CS == 1 && RS==1){SHRTURN();}
  else if( CS == 1 && LS==1){SHLTURN();}
  else if(LS == 0 && LDS==0 && CS == 0 && RDS==0 && RS==1){SHRTURN();}
  else if(LS == 0 && LDS==0 && CS == 0 && RDS==1 && RS==0){ }
  else if(LS == 0 && LDS==0 && CS == 0 && RDS==1 && RS==1){SRTURN(); }
  else if(LS == 0 && LDS==0 && CS == 1 && RDS==0 && RS==0){ }
  else if(LS == 0 && LDS==0 && CS == 1 && RDS==0 && RS==1){ }
  else if(LS == 0 && LDS==0 && CS == 1 && RDS==1 && RS==0){SHLTURN1(); }
  else if(LS == 0 && LDS==0 && CS == 1 && RDS==1 && RS==1){SHRTURN(); }
  else if(LS == 0 && LDS==1 && CS == 0 && RDS==0 && RS==0){ }
  else if(LS == 0 && LDS==1 && CS == 0 && RDS==0 && RS==1){ }
  else if(LS == 0 && LDS==1 && CS == 0 && RDS==1 && RS==0){ }
  else if(LS == 0 && LDS==1 && CS == 0 && RDS==1 && RS==1){ }
  else if(LS == 0 && LDS==1 && CS == 1 && RDS==0 && RS==0){SHRTURN1(); }
  else if(LS == 0 && LDS==1 && CS == 1 && RDS==0 && RS==1){ }
  else if(LS == 0 && LDS==1 && CS == 1 && RDS==1 && RS==0){FORWARD(); }
  else if(LS == 0 && LDS==1 && CS == 1 && RDS==1 && RS==1){SHRTURN(); }
  else if(LS == 1 && LDS==0 && CS == 0 && RDS==0 && RS==0){SHLTURN(); }
  else if(LS == 1 && LDS==0 && CS == 0 && RDS==0 && RS==1){ }
  else if(LS == 1 && LDS==0 && CS == 0 && RDS==1 && RS==0){ }
  else if(LS == 1 && LDS==0 && CS == 0 && RDS==1 && RS==1){ }
  else if(LS == 1 && LDS==0 && CS == 1 && RDS==0 && RS==0){ }
  else if(LS == 1 && LDS==0 && CS == 1 && RDS==0 && RS==1){ }
  else if(LS == 1 && LDS==0 && CS == 1 && RDS==1 && RS==0){ }
  else if(LS == 1 && LDS==0 && CS == 1 && RDS==1 && RS==1){ }
  else if(LS == 1 && LDS==1 && CS == 0 && RDS==0 && RS==0){SHLTURN(); }
  else if(LS == 1 && LDS==1 && CS == 0 && RDS==0 && RS==1){ }
  else if(LS == 1 && LDS==1 && CS == 0 && RDS==1 && RS==0){ }
  else if(LS == 1 && LDS==1 && CS == 0 && RDS==1 && RS==1){ }
  else if(LS == 1 && LDS==1 && CS == 1 && RDS==0 && RS==0){SLTURN(); }
  else if(LS == 1 && LDS==1 && CS == 1 && RDS==0 && RS==1){ }
  else if(LS == 1 && LDS==1 && CS == 1 && RDS==1 && RS==0){SHLTURN(); }
  else if(LS == 1 && LDS==1 && CS == 1 && RDS==1 && RS==1){SHRTURN(); }
  else {BACK(); }


}

void FORWARD()
{
   digitalWrite(M_A1, HIGH);
   digitalWrite(M_A2, LOW);
   digitalWrite(M_B1, HIGH);
   digitalWrite(M_B2, LOW);  
   analogWrite (ENA,60);
   analogWrite (ENB,60);
   
}

void SRTURN()
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);  
  analogWrite (ENA,0);
  analogWrite (ENB,60);
}

void SLTURN()
{
   digitalWrite(M_A1, HIGH);
   digitalWrite(M_A2, LOW);
   digitalWrite(M_B1, LOW);
   digitalWrite(M_B2, LOW);
   analogWrite (ENA,60);
   analogWrite (ENB,0); 
}

void SHRTURN()
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);  
  analogWrite (ENA,90);
  analogWrite (ENB,90);
}

void SHLTURN()
{
   digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);  
  analogWrite (ENA,90);
  analogWrite (ENB,90);
}
void STOP()
{
   digitalWrite(M_A1, LOW);
   digitalWrite(M_A2, LOW);
   digitalWrite(M_B1, LOW);
   digitalWrite(M_B2, LOW);
   analogWrite (ENA,0);
   analogWrite (ENB,0); 
}
void BACK()
{
   digitalWrite(M_A1, LOW);
   digitalWrite(M_A2, HIGH);
   digitalWrite(M_B1, LOW);
   digitalWrite(M_B2, HIGH);  
   analogWrite (ENA,60);
   analogWrite (ENB,60);
   
}
void UTURN()
{
  
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);  
  analogWrite (ENA,60);
  analogWrite (ENB,60);
  
}
void SHRTURN1()
{
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);  
  analogWrite (ENA,65);
  analogWrite (ENB,60);
}
void SHLTURN1()
{
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);  
  analogWrite (ENA,60);
  analogWrite (ENB,65);
}
