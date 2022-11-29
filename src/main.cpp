#include <Arduino.h>
#include <AccelStepper.h>
//-----Motor-Bibo-----//
//To-Do:
//Sensor-Pin obstacle drive as long no black

AccelStepper HL(1, 22, 23);
AccelStepper HR(1, 24, 25); 
AccelStepper VL(1, 26, 27); 
AccelStepper VR(1, 28, 29); 

#define S0RP A0 

void setup() {
  drive_left_green();
  delay(1000);
  drive_right_green();
  delay(1000);
  drive_right_obstacle();
  delay(1000);
  drive_left_obstacle();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void setMotor(int pin, int v) // set up Motor 
{
  pinMode(pin, OUTPUT);     // SET PIN
  pinMode(pin + 1, OUTPUT);
  pinMode(pin + 2, OUTPUT); 

  digitalWrite(pin, v & 1 ? HIGH : LOW);     // WRITE PIN
  digitalWrite(pin + 1, v & 2 ? HIGH : LOW); 
  digitalWrite(pin + 2, v & 4 ? HIGH : LOW); 

  HL.setMaxSpeed(3000); // set Maxpeed
  HR.setMaxSpeed(3000); 
  VL.setMaxSpeed(3000); 
  VR.setMaxSpeed(3000); 

}

void drive_left_green(){
  int Gang = 4;       // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang);
  setMotor(39, Gang); 

  VR.move(1500);     // set Steps and speeds for Motors
  VR.setSpeed(2000);
  HR.move(1500);     
  HR.setSpeed(2000);
  VL.move(1500);     
  VL.setSpeed(2000); 
  HL.move(1500);    
  HL.setSpeed(2000); 

  while (HR.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    HR.runSpeed(); 
    VL.runSpeed(); 
    HL.runSpeed(); 
  }

  VR.move(3000);     // set Steps and speeds for Motors
  VR.setSpeed(2000);  
  HR.move(3000);      
  HR.setSpeed(2000);  
  VL.move(3000);      
  VL.setSpeed(-2000);
  HL.move(3000);      
  HL.setSpeed(-2000);

  while (HR.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed();
    HR.runSpeed(); 
    VL.runSpeed(); 
    HL.runSpeed(); 
  }

  Gang = 2;            // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang); 
  setMotor(39, Gang);
}

void drive_right_green(){
  int Gang = 4;       // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang);
  setMotor(39, Gang); 

  VR.move(1700);     // set Steps and speeds for Motors
  VR.setSpeed(2000); 
  HR.move(1700);     
  HR.setSpeed(2000);
  VL.move(1700);    
  VL.setSpeed(2000); 
  HL.move(1700);     
  HL.setSpeed(2000); 

  while (HR.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    HR.runSpeed();
    VL.runSpeed(); 
    HL.runSpeed(); 
  }

  VR.move(3000);       // set Steps and speeds for Motors
  VR.setSpeed(-2000); 
  HR.move(3000);     
  HR.setSpeed(-2000); 
  VL.move(3000);      
  VL.setSpeed(2000); 
  HL.move(3000);      
  HL.setSpeed(2000); 

  while (HL.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    HR.runSpeed(); 
    VL.runSpeed(); 
    HL.runSpeed(); 
  }

  Gang = 2;           // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang); 
  setMotor(39, Gang);
}

void drive_right_obstacle(){
  int Gang = 4;       // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang);
  setMotor(39, Gang); 

  VR.move(2000);       // set Steps and speeds for Motors
  VR.setSpeed(-3000); 
  VL.move(2000);      
  VL.setSpeed(3000);  
  HR.move(2000);     
  HR.setSpeed(3000);  
  HL.move(2000);      
  HL.setSpeed(-3000); 

  while (HR.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    VL.runSpeed(); 
    HR.runSpeed(); 
    HL.runSpeed(); 
  }

  VR.move(4250);      // set Steps and speeds for Motors
  VR.setSpeed(3000); 
  VL.move(4250);     
  VL.setSpeed(3000);
  HR.move(4250);     
  HR.setSpeed(3000); 
  HL.move(4250);     
  HL.setSpeed(3000); 
  while (VR.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    VL.runSpeed(); 
    HR.runSpeed(); 
    HL.runSpeed(); 
  }

  VR.setSpeed(3000);  
  VL.setSpeed(-3000); 
  HR.setSpeed(-3000); 
  HL.setSpeed(3000);  

  
 // Read Value from IR-Sensor
  while (false)
  {                              // Moves the motor(s) until the sensor see black
    // Read Value from IR-Sensor
    VR.runSpeed();               
    VL.runSpeed();              
    HR.runSpeed();               
    HL.runSpeed();              
  }

  Gang = 2;           // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang); 
  setMotor(39, Gang); 
}

void drive_left_obstacle(){
  int Gang = 4;       // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang);
  setMotor(39, Gang); 

  VR.move(2000);       // set Steps and speeds for Motors
  VR.setSpeed(3000); 
  VL.move(2000);      
  VL.setSpeed(-3000);  
  HR.move(2000);     
  HR.setSpeed(-3000);  
  HL.move(2000);      
  HL.setSpeed(3000); 

  while (HL.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    VL.runSpeed(); 
    HR.runSpeed(); 
    HL.runSpeed(); 
  }

  VR.move(4250);      // set Steps and speeds for Motors
  VR.setSpeed(3000); 
  VL.move(4250);     
  VL.setSpeed(3000);
  HR.move(4250);     
  HR.setSpeed(3000); 
  HL.move(4250);     
  HL.setSpeed(3000); 
  while (VR.distanceToGo() != 0)
  { // Moves the motor(s) until the specified number of steps is reached

    VR.runSpeed(); 
    VL.runSpeed(); 
    HR.runSpeed(); 
    HL.runSpeed(); 
  }

  VR.setSpeed(-3000);  
  VL.setSpeed(3000); 
  HR.setSpeed(3000); 
  HL.setSpeed(-3000);  

   // Read Value from Pin

  while (false)
  {                              // Moves the motor(s) until the sensor see black
    // Read Value from IR-Sensor
    VR.runSpeed();               
    VL.runSpeed();              
    HR.runSpeed();               
    HL.runSpeed();              
  }

  Gang = 2;           // set up Motor 
  setMotor(30, Gang); 
  setMotor(33, Gang); 
  setMotor(36, Gang); 
  setMotor(39, Gang); 
}

