
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
int32_t counterr = 0;
uint8_t PinA = 10;
uint8_t PinB = 11;
uint8_t InterruptA = 10;
uint8_t InterruptB = 11;
      void ai10() {
      // ai8 is activated if DigitalPin nr 9 is going from LOW to HIGH
      // Check pin 9 to determine the direction
      if(digitalRead(PinA) == HIGH){
          if(digitalRead(PinB)==LOW) {
          counterr++;
          }else{
          counterr--;
          }
      }else{
          if(digitalRead(PinB)==LOW) {
              counterr--;
          }else{
              counterr++;
          }
      }
      
  }
   
  void ai11() {
  // ai8 is activated if DigitalPin nr 9 is going from LOW to HIGH
  // Check with pin 8 to determine the direction
      if(digitalRead(PinB) == HIGH){
          if(digitalRead(PinA)==LOW) {
              counterr--;
          }else{
              counterr++;
          }
      }else{
          if(digitalRead(PinA)==LOW) {
              counterr++;
          }else{
              counterr--;
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
void readEncDUEpin10_11_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
    #ifndef MATLAB_MEX_FILE
    pinMode(PinA, INPUT_PULLUP); // internal pullup input pin 22 
  
    pinMode(PinB, INPUT_PULLUP); // internal pullup input pin 23
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
    attachInterrupt(InterruptA, ai10, CHANGE);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
    attachInterrupt(InterruptB, ai11, CHANGE);
    
      #endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void readEncDUEpin10_11_Outputs_wrapper(int32_T *countt,
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
    countt[0] = counterr;
    #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void readEncDUEpin10_11_Update_wrapper(int32_T *countt,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

