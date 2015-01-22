  int readLDR()
  {
  ldr_value = analogRead(ldr);          //reads the LDR values
  Serial.println(ldr_value);                 //prints the LDR values to serial monitor
  delay(50);                  //wait
  }
