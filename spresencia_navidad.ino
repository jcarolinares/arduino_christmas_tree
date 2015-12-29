#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define SPRESENCIA 9
#define LEDS 11
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            11

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      30

// Cosntantes de las notas
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int melodia[] = {
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_FS4,
  NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D5,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4 };

int duracionNotas[] = {
  8, 8, 8, 8, 3, 16, 16,
  8, 8, 8, 8, 2,
  8, 8, 8, 8, 2, 
  8, 8, 8, 8, 3, 8,
  8, 8, 8, 8, 3, 16, 16,
  8, 8, 8, 8, 3, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 2,
  8, 8, 4, 8, 8, 4,
  8, 8, 6, 16, 2,
  8, 8, 6, 16, 8, 8, 8, 16, 16,
  8, 8, 8, 8, 4, 4,
  8, 8, 4, 8, 8, 4, 8, 8, 6, 16, 2,
  8, 8, 6, 16, 8, 8, 8, 16, 16,
  8, 8, 8, 8, 2 };

int speakerPin =10;
int length = 73;
char notes[] = "ggagsed deggsgg ggagsed deggsgg DCbCDbCbabCabagabgagsgasgsesgeseddeggsgg "; // a space represents a rest
int beats[] = { 2,2,1,1,1,1,4,2,2,2,2,2,2,4,2,2,2,2,1,1,1,1,4,2,2,2,2,2,2,4,2,2,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,2,2,2,2,2,2,4,2,2 };
int tempo = 300;

long tiempo_inicial=0;
long tiempo_final=0;
long periodo_actuacion=300000;
int sensibilidad=5000;
int r=0;
int g=0;
int b=0;

int random_mode=0;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup(){
  Serial.begin(9600);
  pinMode(SPRESENCIA,INPUT);
  pinMode(speakerPin, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
  tiempo_inicial=(millis());
  randomSeed(analogRead(0));
  random_mode=random(0,4);
}

void loop(){
  //Serial.println(digitalRead(SPRESENCIA));
  
  tiempo_final=millis()-tiempo_inicial;
  
  if((digitalRead(SPRESENCIA)==1)&&(tiempo_final>periodo_actuacion)){
  
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(256,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  
  //Suena la melodia
  for (int nota = 0; nota < 100; nota++) {
    playNota(nota);
    //pixels.setPixelColor(random(0,30), pixels.Color(random(0,255),random(0,255),random(0,255))); //LED aleatorio a color aleatorio
    //pixels.show(); // This sends the updated pixel color to the hardware.
    
    r=random(0,256);
    g=random(0,256);
    b=random(0,256);
  
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,pixels.Color(r,g,b));  
    pixels.show(); // This sends the updated pixel color to the hardware.  
  }
    
  }
  
  //Apagamos los LEDS
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    
  }
  
  //Esperamos un tiempo
  random_mode=random(0,4);
  delay(60000);
  tiempo_inicial=millis();
  }
    
  //Hacemos brillar los LEDs de forma aleatoria sin melodia
  switch(random_mode){
   case 0: 
    all_leds_random();
    sensibilidad=5000;
    break;
   case 1:
    array_on_leds_random(100);
    sensibilidad=5000;
    break;
   case 2:
    random_leds();
    sensibilidad=5000; 
    break;
   case 3:
     random_individual_led();
     sensibilidad=1000;
     break;
  }
  
  delay(sensibilidad);
  
}


void playNota (int nota) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1800/duracionNotas[nota];
   
      tone(speakerPin, melodia[nota],noteDuration);
    
  
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
}

void all_leds_random(){
  r=random(0,256);
  g=random(0,256);
  b=random(0,256);
  
  for(int i=0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i,pixels.Color(r,g,b));  
  pixels.show(); // This sends the updated pixel color to the hardware.  
  }  
}

void array_on_leds_random(int time){
  r=random(0,256);
  g=random(0,256);
  b=random(0,256);
  
  for(int i=0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i,pixels.Color(r,g,b));  
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(time);  
  }  
}

void random_leds(){
  r=random(0,256);
  g=random(0,256);
  b=random(0,256);
  
  int led_begin=random(0,NUMPIXELS+1);
  
  for(int i=led_begin;i<random(led_begin,NUMPIXELS+1);i++){
  pixels.setPixelColor(i,pixels.Color(r,g,b));  
  pixels.show(); // This sends the updated pixel color to the hardware.
  //delay(time);  
  }
}

void random_individual_led(){
  r=random(0,256);
  g=random(0,256);
  b=random(0,256);
  
  pixels.setPixelColor(random(0,NUMPIXELS+1),pixels.Color(r,g,b));  
  pixels.show(); // This sends the updated pixel color to the hardware.
  
}
