boolean PhoneNumber (String PhoneNumber) {
  int rIndex = details.findRowIndex (PhoneNumber,  "Phone Number");
  println (rIndex);
  if (rIndex  >= 0) {
    int Amount = details.getInt (rIndex, "Amount");
    int amounts = int(amount);
    int change = Amount - amounts;
    String changeamounts = str (change);
    if (Amount >= amounts) {
      details.setString (rIndex, "Amount", changeamounts);
      
      saveTable (details, receivedPath);
      return true;
    }
     else{
       return false;
     }
  } else {
    return false;
  }
  
}
