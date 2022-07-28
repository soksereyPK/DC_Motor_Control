
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#include <math.h>
int32_t counter = 0;
uint8_t pinA = 8;
uint8_t pinB = 9;
uint8_t interruptA = 8;
uint8_t interruptB = 9;
      void ai8() {
      // ai8 is activated if DigitalPin nr 9 is going from LOW to HIGH
      // Check pin 9 to determine the direction
      if(digitalRead(pinA) == HIGH){
          if(digitalRead(pinB)==LOW) {
          counter++;
          }else{
          counter--;
          }
      }else{
          if(digitalRead(pinB)==LOW) {
              counter--;
          }else{
              counter++;
          }
      }
      
  }
   
  void ai9() {
  // ai8 is activated if DigitalPin nr 9 is going from LOW to HIGH
  // Check with pin 8 to determine the direction
      if(digitalRead(pinB) == HIGH){
          if(digitalRead(pinA)==LOW) {
              counter--;
          }else{
              counter++;
          }
      }else{
          if(digitalRead(pinA)==LOW) {
              counter++;
          }else{
              counter--;
          }
      }
 
  }
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void readEncDUEpin8_9_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    #ifndef MATLAB_MEX_FILE
    pinMode(pinA, INPUT_PULLUP); // internal pullup input pin 22 
  
    pinMode(pinB, INPUT_PULLUP); // internal pullup input pin 23
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
    attachInterrupt(interruptA, ai8, CHANGE);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
    attachInterrupt(interruptB, ai9, CHANGE);
    
      #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void readEncDUEpin8_9_Outputs_wrapper(int32_T *count,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */

    #ifndef MATLAB_MEX_FILE
    count[0] = counter;
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void readEncDUEpin8_9_Update_wrapper(int32_T *count,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

