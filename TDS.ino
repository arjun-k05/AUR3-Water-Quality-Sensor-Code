int analogInput;
int buf[10];
float voltage, tds, temp = 25.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogInput = analogRead(A1);

  for (int i = 0; i < 10; i++) {
    buf[i] = analogInput;
    delay(10);
  }
  sort();

  for (int i = 2; i < 8; i++) 
    voltage += buf[i];
  voltage /= 6;  
  voltage *= 5.0 / 1024.0;

  // TDS formula: 0.5 * (113.42x^3 - 255.86x^2 + 857.39x)
  tds = (133.42 * pow(voltage, 3.0) - (255.86 * square(voltage)) + (857.39 * voltage)) * 0.5;

  Serial.print("TDS Value: ");
  Serial.print(tds);
  Serial.println(" ppm");
  

  delay(1000);
}

// sort array method
void sort() {
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        int temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
}