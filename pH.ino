#define OFFSET 0.00
int analogInput;
int buf[10];
double voltage, pH;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogInput = analogRead(A2);
  
  // input 10 buffer array values from analog input, increased accuracy
  for (int i = 0; i < 10; i++) {
    buf[i] = analogInput;
    delay(10);
  }
  sort(); // calls sort method 

  // find 6 center values for average
  int avg = 0; 
  for (int i = 2; i < 8; i++) 
    avg += buf[i];
  avg /= 6;
  
  voltage = (double)avg * (5.0 / 1024.0);
  
  pH = 3.5 * voltage - OFFSET; // convert from volt to pH  
  
  // Serial.println(voltage);
  Serial.print("pH Value: ");
  if (pH < 14.00)
    Serial.println(pH);
  else
    Serial.println(14.00);
  
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