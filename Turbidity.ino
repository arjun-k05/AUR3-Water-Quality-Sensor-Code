double NTU, voltage;
int analogInput;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogInput = analogRead(A0);
  
  // voltage
  voltage = (double)analogInput * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
    
  // NTU
  if (voltage < 2.5) // if voltage <= 2.5, turbidity level >= 3000
    NTU = 3000;
  else // if voltage > 2.5, use formula: y = -1120.4x^2 + 5742.3x - 4352.9
    NTU = (-1120.4 * square(voltage)) + (5742.3 * voltage) - 4352.9; 
  Serial.print("NTU: ");
  Serial.println(NTU);
  
  delay(1000);
}