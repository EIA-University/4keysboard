#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables won't change

const int  mayusPin = 6;
const int minusPin = 7;  
const int numbersPin = 8;
const int  enterPin = 9;  

//Arrays

char mayus[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char minus[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};

// Variables will change:

//Buttons
int enterState;       
int lastEnterState = 0;    
int mayusState;       
int lastMayusState = 0;
int minusState;       
int lastMinusState = 0;
int numbersState;       
int lastNumbersState = 0;
  
int a = 0; //Cursor

// Contadores
int i = 0;  
int j = 0;  
int k = 0;  

void setup() {

  //Activate pin
   pinMode(mayusPin, INPUT);
   pinMode(minusPin, INPUT);
   pinMode(numbersPin, INPUT);
   pinMode(enterPin, INPUT);
   
   mayusState = digitalRead(mayusPin);  
   minusState = digitalRead(minusPin);   
   numbersState = digitalRead(numbersPin);   
   enterState = digitalRead(enterPin);   
   
   lcd.begin(16,2);
   
}


void loop() {

   //Leer estado
   mayusState = digitalRead(mayusPin);  
   minusState = digitalRead(minusPin);   
   numbersState = digitalRead(numbersPin);   
   enterState = digitalRead(enterPin);   

   if (mayusState != lastMayusState) {
      if(mayusState == HIGH){
           if(i<26){
              lcd.setCursor(a,0);
              lcd.print(mayus[i]);
              i++;
              delay(500);
           }
          else{
            i=0;
            j=0;
            k=0;
          }
      }
  }

     if (minusState != lastMinusState) {
      if(minusState == HIGH){
           if(j<26){
              lcd.setCursor(a,0);
              lcd.print(minus[j]);
              j++;
              delay(500);
           }
          else{
            i=0;
            j=0;
            k=0;
          }
      }
  }

     if (numbersState != lastNumbersState) {
      if(numbersState == HIGH){
           if(k<10){
              lcd.setCursor(a,0);
              lcd.print(numbers[k]);
              k++;
              delay(500);
           }
          else{
            i=0;
            j=0;
            k=0;
          }
      }
  }

  if(enterState != lastEnterState){
    if(enterState == HIGH){
        a++;
        i=0;
        j=0;
        k=0;
    }
  }




  //Guardar estados actuales
  lastMayusState = mayusState;
  lastMinusState = minusState;
  lastNumbersState = numbersState;
  lastEnterState = enterState;

 
}

 

