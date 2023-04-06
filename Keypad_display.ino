#include <Keypad.h>            // burnout keypad library
#include <TM1637TinyDisplay.h>    // burnout Display library

// Display inputs

  #define CLK 3
  #define DIO 2

// Keyboard inputs

  const byte rows=4;             // N° of rows
  const byte columns=3;         // N° of columns
  char keys [rows][columns]={    // key distribution
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'},
  };

byte Rowpins[rows]={4,5,6,7};
byte Columnspins[columns]={8,9,10};

char key;
char code[5];
char codeT[5]="8546";
byte index=0;

Keypad keyboard= Keypad(makeKeymap(keys), Rowpins, Columnspins, rows, columns);    // Made object "keyboard"
TM1637TinyDisplay display(CLK, DIO);                                                 // Made object "display"

const int ledTest=13;


void setup() {

  Serial.begin(9600);
  display.setBrightness (0x0f);     // Set brightness
  display.clear();
  
  pinMode(ledTest, OUTPUT);
  digitalWrite(ledTest, LOW);

  //Saludo inicial
    for (int i=0; i<5; i++)
    digitalWrite(ledTest, HIGH);
    delay(50);
    digitalWrite(ledTest, LOW); 
    delay(50);

}

void loop() {
  
  key = keyboard.getKey();

  if (key){
    code[index] = key;
    index++;
    Serial.print(key);
  }

  if (index==4){
    Serial.println();
      if(!strcmp(code, codeT)){
        display.showString("7-----7");
        display.clear();
      }

      else{
        display.showString("8-----8");
        display.clear();         
      }
  index = 0;       
  }
}
