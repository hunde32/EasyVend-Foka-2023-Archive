#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo servo;
Servo myservo;
Servo yourservo;
Servo servos[] = { servo, myservo, yourservo };
int buttonfunction = 0;
String data = "";
String transactionnumber;
int quantity;
int money = 0;
int selected = 0;
int rotate[] = { 3220, 200, 1650 };
int selection = 0;
const byte ROWS = 4;
const byte COLS = 4;
int saveitem[] = {0, 0, 0};
int savequantity[] = {0, 0, 0};
int rotatetime[] = {100, 1500, 300};
int stepperPins [] = {2, 3, 4};
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 22, 24, 26, 28 };
byte colPins[COLS] = { 30, 32, 34, 36 };
int bill;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int itemNumbers[] = {1, 2, 3 };
int servoPins[] = { 11, 12, 13 };
int price[] = { 45, 30, 80 };
int priceto = 0;
int numberOfItems = sizeof(itemNumbers) / sizeof(itemNumbers[0]);

int stocks[] = { 4, 4, 4};
int stocks1 = 1;
int scroll = 1;
bool trnumber = true;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(38, OUTPUT);
  for (int y = 0; y < 3; y++) {
    servos[y].attach(servoPins[y]);
    servos[y].writeMicroseconds(1502);
  }


  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

}

void loop() {
  if (trnumber == true) {
    char key = keypad.getKey();
    lcd.setCursor(0, 0);
    lcd.print("User Option");
    lcd.setCursor(3, 1);
    lcd.print("Order Here");
    lcd.setCursor(3, 2);
    lcd.print("Enter Order ID");
    lcd.setCursor(0, scroll);
    lcd.print("->");
    if (key == 'B') {
      
      scroll++;
      lcd.clear();
    }
    if (scroll < 1) {
      scroll = 3;

    }
    if (key == 'A') {
      
      scroll--;
      lcd.clear();
    }
    if (scroll > 2) {
      scroll = 1;
    }
    if (key == '#') {
      selected = scroll;
      trnumber = false;
      lcd.clear();
    }
  }
  if (selected == 2) {
    if (trnumber == false) {
      char key = keypad.getKey();
      String ID = inputString("Enter your ID: ");
      lcd.clear();
      String PhonenumberID = inputString("Enter Phone Number: ");
    }
  }
  if (selected == 1) {
    if (trnumber == false) {
      char key = keypad.getKey();
      lcd.setCursor(3, 0);
      lcd.print("Item");
      lcd.setCursor(3, 1);
      lcd.print("Coca");
      lcd.setCursor(3, 2);
      lcd.print("Sun chips");
      lcd.setCursor(3, 3);
      lcd.print("Snickers");
      lcd.setCursor(15, 0);
      lcd.print("price");
      lcd.setCursor(15, 1);
      lcd.print(price[0]);
      lcd.setCursor(15, 2);
      lcd.print(price[1]);
      lcd.setCursor(15, 3);
      lcd.print(price[2]);
      lcd.setCursor(0, scroll);
      lcd.print("->");
      if (key == 'B') {

        scroll++;
        lcd.clear();
      }
      if (scroll < 2) {
        scroll = 4;

      }
      if (key == 'A') {

        scroll--;
        lcd.clear();
      }
      if (scroll > 3) {
        scroll = 1;
      }
      if (key == '#') {
        selected = scroll + 1;
        selection = scroll - 1;

        lcd.clear();
        quantity = inputNumber("Enter Quantity: ");
        bill = quantity * price[selection];
        bool orderagain = false;
        if (orderagain == false) {
          if (quantity == 1234) {
            lcd.clear();
            lcd.setCursor(0, 0);
            digitalWrite(38, HIGH);
            int stocks1 = inputNumber("item number: ");
            if (stocks1 == itemNumbers[0]) {
              selection = stocks1 - 1;

            }
            else if (stocks1 == itemNumbers[1]) {
              selection = stocks1 - 1;

            }
            else if (stocks1 == itemNumbers[2]) {
              selection = stocks1 - 1;

            }

            else {
              lcd.clear();
              lcd.print("there is no section");
              lcd.setCursor(0, 1);
              lcd.print("that called ");
              lcd.print(stocks1);
              delay(3000);
              lcd.clear();
              return;
            }
            lcd.setCursor(0, 1);
            lcd.clear();
            int stocks2 = inputNumber("Quantity: ");
            stocks[selection] = stocks2;
            lcd.clear();
            int pricequ = inputNumber("Set price: ");
            price[selection] = pricequ;
            lcd.clear();
            lcd.print("U selection successf");
            lcd.setCursor(0, 1);
            lcd.print("ully restock");
            orderagain = true;
            trnumber = true;
            selected = 1;
            delay(3000);
            digitalWrite(38, LOW);
            lcd.clear();
            return;
          }
          orderagain = true;
          if (quantity > stocks[selection]) {
            lcd.clear();
            lcd.print("there is only ");
            lcd.print(stocks[selection]);
            lcd.print(" items");
            delay(4000);
            lcd.clear();
            trnumber = false;
            return;
          }
          if (orderagain == true) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Item: ");
            lcd.print(quantity);
            lcd.setCursor(0, 1);
            lcd.print("Bill: ");
            lcd.print(bill);
            lcd.setCursor(0, 3);
            lcd.print("<- Add item");
            lcd.setCursor(14, 3);
            lcd.print("Pay ->");
            long lastTime = millis ();
            while (millis () - lastTime < 10000) {
              char key = keypad.getKey();
              if (key) {
                if (key == 'C') {
                  lcd.clear();
                  saveitem[0] = selection;
                  savequantity[0] = quantity;
                  orderagain = true;
                  return;
                }
                else if (key == 'D') {
                  trnumber = true;
                  break;
                }
                else {
                  lcd.clear();
                  lcd.print("you enter the wrong number");
                  delay(2000);
                  lcd.clear();
                  lastTime = millis ();
                }
              }
            }

            trnumber = true;
          }
          else {
            trnumber = true;
            bill = quantity * price[selection];
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("you bill is ");
            lcd.print(bill);
            delay(3000);
            lcd.clear();
          }
        }


        if (trnumber == true) {
          data = "";
          String phoneNumber = inputString("Enter Phone Number: ");
          Serial.println("phonenumber:"  + phoneNumber +  bill +":phonenumber");
          lcd.setCursor(0, 2);
          lcd.clear();
          lcd.println("please wait");
          while (data.equals ("")) {
            serialCheck();
          }

          if (phoneNumber.equals(data)) {
            for (int x = 0; x < rotate[selection] * quantity; x++) {
              digitalWrite(selected, HIGH);
              delayMicroseconds(rotatetime[selection]);
              digitalWrite(selected, LOW);
              delayMicroseconds(rotatetime[selection]);
            }
           

            int pin = stepperPins [saveitem[0]];
            for (int again = 0; again <  rotate[saveitem[0]] * savequantity[0]; again++) {
              digitalWrite(pin, HIGH);
              delayMicroseconds(rotatetime[saveitem[0]]);
              digitalWrite(pin, LOW);
              delayMicroseconds(rotatetime[saveitem[0]]);
            }
            lcd.clear();
            lcd.print("PAYMENT SECCESESFULL");
            delay (2000);
            stocks[selection] = stocks[selection] - quantity;
            selected = 1;
            trnumber = true;
            lcd.clear();
            return;
          }

          else {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Invalid TR number");
            lcd.setCursor(0, 1);
            lcd.print("Please try again");
            lcd.setCursor(0, 2);
            delay(3000);
            trnumber = true;
            return;
          }
        }
      }
    }
  }

}
String inputString(String prompt) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(prompt);

  String input = "";

  while (true) {
    char key = keypad.getKey();

    if (key) {
      if (key != '#' && key != '*') {
        input += key;
      } else if (key == '#') {
        return input;
      }
      else if (key == '*') {
        if (input.length() > 0) {
          String output = "";

          for (int c = 0; c < input.length() - 1; c++) {
            output += input.charAt(c);
          }
          input = output;
        }
      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(prompt);
      lcd.print(input);
    }
  }
}
int inputNumber(String prompt) {
  return inputString(prompt).toInt();
}

void serialCheck() {
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
    data.replace("\n", "");
    data.replace("\r", "");
  }
}
void serialEvent() {
  data = Serial.readStringUntil('\n');
  data.replace("\n", "");
  data.replace("\r", "");
}
