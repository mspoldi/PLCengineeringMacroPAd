#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},  // basso
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}   // alto
};
byte rowPins[ROWS] = {17,16,15,14}; 
byte colPins[COLS] = {9,10,11,12};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode     (13,OUTPUT);
  digitalWrite(13,HIGH);  
}
  
void loop(){
  switch (customKeypad.getKey())
  {
    case '0':
      Keyboard.println("IF <> THEN");
      Keyboard.println("");
      Keyboard.println("END_IF;");
      break;

    case '1':
      Keyboard.println("CASE <>");
      Keyboard.println("1: //");
      Keyboard.println(";");
      Keyboard.println("2: //");
      Keyboard.println(";");
      Keyboard.println("ELSE");
      Keyboard.println(";");
      Keyboard.println("END_CASE;");
      break;

    case '2':
      Keyboard.println("FOR _Index := 0 TO <> BY 1 DO");
      Keyboard.println("");
      Keyboard.println("END_FOR;");
      break;

    case '3':
      Keyboard.println("alarm_Set(");
      Keyboard.println("      Station         :=  _This.Station,");
      Keyboard.println("Alarm_Type      :=  ,");
      Keyboard.println("Alarm_Num       :=  ,");
      Keyboard.println("Alarm_Condition :=  ");
      Keyboard.println(");");
      Keyboard.println("");
      break;

    case '7': // cattura
      SendKey(MODIFIERKEY_GUI, KEY_R);
      delay(100);
      Keyboard.println("SnippingTool");
      break;

    case '8': // calc
      SendKey(MODIFIERKEY_GUI, KEY_R);
      delay(100);
      Keyboard.println("calc");
      break;

   case '9': // notepad
      SendKey(MODIFIERKEY_GUI, KEY_R);
      delay(100);
      Keyboard.println("notepad");
      break;
      
   case 'A': // chrome
      SendKey(MODIFIERKEY_GUI, KEY_R);
      delay(100);
      Keyboard.println("chrome");
      break;

    case 'B': // win + tab
      SendKey(MODIFIERKEY_GUI, KEY_UP);
      break;

    case 'C': // win + tab
      SendKey(MODIFIERKEY_GUI, KEY_TAB);
      break;
      
    case 'D': // shift + ctrl + tab      
      SendKey(MODIFIERKEY_SHIFT | MODIFIERKEY_CTRL, KEY_TAB);
      break;

    case 'E': // win + ctr + left
      SendKey(MODIFIERKEY_GUI | MODIFIERKEY_CTRL, KEY_LEFT);
      break;

    case 'F': // win + ctr + right
      SendKey(MODIFIERKEY_GUI | MODIFIERKEY_CTRL, KEY_RIGHT);
      break;
      
    default: 
    break;
  }
}


void SendKey(int _modifier, int _key)
{
    Keyboard.set_modifier(_modifier);      
    Keyboard.press(_key);
    Keyboard.release(_key);
    Keyboard.set_modifier(0);      
    Keyboard.send_now();
}
