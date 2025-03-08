const int outPins[] = {
  2,  // A  - outReady
  21, // B  - outLeftPreStage
  20, // C  - outLeftStage
  19, // D  - outLeftAmber1
  16, // E  - outLeftAmber2
  15, // F  - outLeftAmber3
  14, // G  - outLeftGreen
  39, // H  - outLeftRed
  3,  // I  - outRightPreStage
  4,  // J  - outRightStage
  5,  // K  - outRightAmber1
  6,  // L  - outRightAmber2
  7,  // M  - outRightAmber3
  8,  // N  - outRightGreen
  9   // O  - outRightRed
};

const int outPWM = 10;
char incomingByte = ' ';

void setup() {
  Serial.begin(9600);
  
  // Set all LED pins as OUTPUT
  for (int i = 0; i < sizeof(outPins) / sizeof(outPins[0]); i++) {
    pinMode(outPins[i], OUTPUT);
  }
  
  pinMode(outPWM, OUTPUT);
}

void loop() {
  analogWrite(outPWM, 255); // Ensure PWM is always at full duty cycle

  if (Serial.available()) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte);
    
    if (incomingByte == '#') {
      // Read configuration message
      String configMessage = Serial.readStringUntil('\n');
      configMessage.trim();  // Remove trailing newline characters
      Serial.print("Config Message Received: ");
      Serial.println(configMessage);
    } 
    else if (isAlpha(incomingByte)) { 
      handleCommand(incomingByte);
    }
  }
}

void handleCommand(char cmd) {
  int index = -1;

  if (cmd >= 'A' && cmd <= 'O') {
    index = cmd - 'A';  // Map 'A' to 0, 'B' to 1, ..., 'O' to 14
    digitalWrite(outPins[index], HIGH);
  } 
  else if (cmd >= 'a' && cmd <= 'o') {
    index = cmd - 'a';  // Map 'a' to 0, 'b' to 1, ..., 'o' to 14
    digitalWrite(outPins[index], LOW);
  }

  if (index != -1) {
    Serial.print("Pin ");
    Serial.print(outPins[index]);
    Serial.println((cmd < 'a') ? " ON" : " OFF");
  } else {
    Serial.println("Invalid command.");
  }
}