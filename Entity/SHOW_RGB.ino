void showRGB(){                                                                 /*************************************/
  readColor(r, g, b);
  if (currentColor(r, g, b) == 2)
    digitalWrite(LED_red, HIGH); 
  else 
    digitalWrite(LED_red, LOW);
  readColor(r, g, b);
  if (currentColor(r, g, b) == 3)
    digitalWrite(LED_blue, HIGH); 
  else 
    digitalWrite(LED_blue, LOW);
}
