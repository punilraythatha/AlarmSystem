#include <IRremote.h>
const int receiver = 11;
IRrecv irrecev(receiver);
decode_results results;
String value = "";
int number = 0;
unsigned long key_value = 0;
String passwordReceived = "";
String password = "4321";
bool passwordSuccess = false;

void setup() {
  // put your setup code here, to run once:
   pinMode(3, INPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(12, OUTPUT);
   
   Serial.begin(9600);

}
void ledFlash() {
  
  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(7, HIGH);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  delay(100);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  delay(50);
  
}

void detectPassword() {
  if (irrecev.decode(&results)) {

     if (results.value == 0XFFFFFFFF) 
          results.value = key_value;

   value = results.value;
   Serial.println(value);

   if (value == "16603303"){
    number = 9;
    passwordReceived = passwordReceived + "9";
  } else if (value == "16582903") {
    number = 1;
    passwordReceived = passwordReceived + "1";
  } else if (value == "16615543") {
    number = 2;
    passwordReceived = passwordReceived + "2";
  } else if (value == "16599223") {
  number = 3;
  passwordReceived = passwordReceived + "3";
  } else if (value == "16591063") {
  number = 4;
  passwordReceived = passwordReceived + "4";
  } else if (value == "16623703") {
  number = 5;
  passwordReceived = passwordReceived + "5";
  } else if (value == "16607383") {
  number = 6;
  passwordReceived = passwordReceived + "6";
  } else if (value == "16586983") {
  number = 7;
  passwordReceived = passwordReceived + "7";
  } else if (value == "16619623") {
  number = 8;
  passwordReceived = passwordReceived + "8";
  } 
    key_value = results.value;

  }

  if (passwordReceived == password) {
    Serial.println("password done");
    passwordSuccess = true;


  }
  
  
}

void executeAlarm()
 {
  Serial.print("\n EXECUTING ALARM");
  while (passwordSuccess == false) {
    irrecev.enableIRIn();
    ledFlash();
    detectPassword();
    
  }
    
    
  
 }

void loop() {
  // put your main code here, to run repeatedly:

  int digitalValue = digitalRead(3);
  if (digitalValue==LOW) {
    executeAlarm();
  }

}
