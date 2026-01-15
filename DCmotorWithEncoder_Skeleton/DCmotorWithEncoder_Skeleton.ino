#define IN1   5  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   6   // Replace the ? with the GPIO pin you selected to connect IN2
#define A  1 // Replace the ? with the GPIO pin you selected to connect encoder A
#define B  2 // Replace the ? with the GPIO pin you selected to connect encoder B
#define PWM 15  // Replace the ? with the GPIO pin you selected to output PWM

// encoder output value
int A_data=0;
int B_data=0;

String command;

void setup() {
  /*setup baud and pin mode */
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  
  // Set pin modes
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);

  /*Set rotation direction as forward rotation (CCW)*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

}

void loop() {
    // send the duty cycle of PWM to control the speed of DC motor
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
        if (command == "0") {
        // output PWM signals with 0% duty cycle
        analogWrite(PWM, 0);  
        } 
        else if (command == "25") {
        // output PWM signals with 25% duty cycle
        analogWrite(PWM, 64);   
        }
        else if (command == "50") {
        // output PWM signals with 50% duty cycle
        analogWrite(PWM, 128);   
        }
        else if (command == "75") {
        // output PWM signals with 75% duty cycle
        analogWrite(PWM, 191);   
        }
        else if (command == "100") {
        // output PWM signals with 100% duty cycle
        analogWrite(PWM, 255);   
        }
        }
    // Read values of A and B
    A_data = digitalRead(A);
    B_data = digitalRead(B);
    // Plot A B in Serial Plotter
    Serial.print("A:");
    Serial.print(A_data);
    Serial.print(",");
    Serial.print("B:");
    Serial.print(B_data);
    Serial.println("\t"); 
    
}
