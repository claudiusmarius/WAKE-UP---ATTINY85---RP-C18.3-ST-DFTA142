// ####################################################################################################################################################################################
//                                                            CLAUDE DUFOURMONT WakeUp ATtiny85 par RP-C18.3-ST
// ####################################################################################################################################################################################          
// Fonctionne en mode deep sleep logiciel
// Alimentation unique en 5V, le courant de sommeil est de 0,51µA
// Le wake up consiste à venir créer un front descendant sur le RESET (PB05)de l'ATtiny85 grâce à la saturation du mosfet aprés une pression sur le RP-C18.3-ST ("jauge de contrainte")
// Vidéo DFT_#142
// https://www.youtube.com/c/ClaudeDufourmont
// #####################################################################################################################################################################################
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 
// Ici le code a été considéré comme du setup,  (un seul démarrage, pas de bouclage)
// 
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  #include<avr/sleep.h>
  #define adc_disable()(ADCSRA &=~(1<<ADEN))       
  
  #define BrocheLedBleue 0
  #define BrocheBuzzer 2
  
  void setup()
  {
  pinMode (BrocheLedBleue, OUTPUT);                                             
  pinMode (BrocheBuzzer, OUTPUT);                                             

  digitalWrite (BrocheBuzzer, HIGH);
  delay(100);
  digitalWrite (BrocheBuzzer, LOW);
  delay(50);
  
  digitalWrite (BrocheBuzzer, HIGH);
  delay(100);
  digitalWrite (BrocheBuzzer, LOW);
  delay(50);
  
  digitalWrite (BrocheBuzzer, HIGH);
  delay(100);
  digitalWrite (BrocheBuzzer, LOW);
  delay(50);

  digitalWrite (BrocheBuzzer, HIGH);
  delay(100);
  digitalWrite (BrocheBuzzer, LOW);
  delay(50);
  
  digitalWrite (BrocheBuzzer, HIGH);
  delay(100);
  digitalWrite (BrocheBuzzer, LOW);
  delay(50);
  
  digitalWrite (BrocheBuzzer, HIGH);
  delay(100);
  digitalWrite (BrocheBuzzer, LOW);
  delay(50);

  digitalWrite (BrocheLedBleue, HIGH);
  
  adc_disable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      
  delay(10000);                       // Preparation SLEEP : animation LedBleue et Buzzer avant sleep
  digitalWrite (BrocheLedBleue, LOW);
  digitalWrite (BrocheBuzzer, LOW);
  
  delay (200);
  digitalWrite (BrocheLedBleue, HIGH);
  
  delay (200);
  digitalWrite (BrocheLedBleue, LOW);

  delay (200);
  digitalWrite (BrocheLedBleue, HIGH);

  delay (200);
  digitalWrite (BrocheLedBleue, LOW);

  delay (200);
  digitalWrite (BrocheLedBleue, HIGH);
  
  delay (200);
  digitalWrite (BrocheLedBleue, LOW);
  digitalWrite (BrocheBuzzer, HIGH);
  delay(700);                         
  digitalWrite (BrocheBuzzer, LOW);
  
  sleep_enable();                                     // Activation deep sleep
  sleep_cpu();
  }
  
  void loop () {
//***************************************************************************************************************************************************************************************
//                                                                                  VOLONTAIREMENT PAS DE BOUCLE  
//***************************************************************************************************************************************************************************************
  }
  
