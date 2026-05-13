String receivedPath = "C:/Users/hp/Documents/Messages/new telebirr details.csv";
Periodically listenPeriod;
import processing.serial.*;
Serial mega;
Table details;

int amounts;
String phoneNumber;
boolean save = false;
String replaceOPT = "";
String amount;
String Phonenumber;
void setup() {
  listenPeriod = new Periodically (5000);


  mega = new Serial (this, "COM12", 9600);
}
void draw() {
  if (listenPeriod.itsTime ()) {
    details = loadTable (receivedPath, "header");

    String phoneNumbers [] = details.getStringColumn ("Phone Number");
    float  amounts [] = details.getFloatColumn ("Amount");
    println(".");
  }
}
void serialEvent (Serial s) {
  String data = mega.readStringUntil ('\n');

  if (data != null) {
    try {
      println ("Data: ", data);

      int i = data.indexOf (":") + 1;
      int f = data.lastIndexOf (":");
      String all = data.substring (i, f);
      Phonenumber = all.substring(0, 10);
      amount = all.substring(10, all.length());
      String change = "_" + Phonenumber;
      println("this: ", change);
      println(Phonenumber);
      println(amount);
      if(PhoneNumber(change)){
        println("works");
        mega.write(Phonenumber);
      }
    }
    catch (Exception e) {
      println (e);
    }
  }
}
