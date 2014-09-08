/**
 * File: L9110S_Starter_Code.ino
 * Author: Charles Kiorpes
 * Date: September 6th, 2014
 *
 * This file contains some basic control functions for the dual L9110S driver board.
 *
 * The default behavior is to speed up and slow down both motors in each direction,
 *  then wait for two seconds.
 **/


// The pins used:
const int A_IA = 3;   // Motor A input A
const int A_IB = 9;   // Motor A input B
const int B_IA = 10;  // Motor B input A
const int B_IB = 11;  // Motor B input B


void setup() {
  // set up motor control pins as output
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  pinMode(B_IA, OUTPUT);
  pinMode(B_IB, OUTPUT);
}

////////////////////////////////////////////////////////
// set motor A's speed and direction
// dir: 0 -> forward, anything else -> backward
// rate: 0 - 255 (PWM rate)
////////////////////////////////////////////////////////
void move_A(int dir, int rate){
  if(dir){
    digitalWrite(A_IA, LOW);
    analogWrite(A_IB, rate);
  } else {
    digitalWrite(A_IB, LOW);
    analogWrite(A_IA, rate);
  }
}

////////////////////////////////////////////////////////
// set motor B's speed and direction
// dir: 0 -> forward, anything else -> backward
// rate: 0 - 255 (PWM rate)
////////////////////////////////////////////////////////
void move_B(int dir, int rate){
  if(dir){
    digitalWrite(B_IA, LOW);
    analogWrite(B_IB, rate);
  } else {
    digitalWrite(B_IB, LOW);
    analogWrite(B_IA, rate);
  }
}

///////////////////////////////////////////////////////
// stop_all_motors: stop both of the motors at once
// (a.k.a. emergency brake)
///////////////////////////////////////////////////////
void stop_all_motors(){
  digitalWrite(A_IA, LOW);
  digitalWrite(A_IB, LOW);
  digitalWrite(B_IA, LOW);
  digitalWrite(B_IB, LOW);
}

///////////////////////////////////////////////////////
// loop: the main program execution loop
// add all desired behaviors here
///////////////////////////////////////////////////////
void loop() {
  int i;
  // Both forwards:
  for(i = 0; i < 255; i++){
     move_A(0, i);
     move_B(0, i);
     delay(10);
  }
  for(i = 255; i >= 0; i--){
     move_A(0, i);
     move_B(0, i);
     delay(10);
  }
  
  // Both backwards:
  for(i = 0; i < 255; i++){
     move_A(1, i);
     move_B(1, i);
     delay(10);
  }
  for(i = 255; i >= 0; i--){
     move_A(1, i);
     move_B(1, i);
     delay(10);
  }  

  delay(2000);
}
