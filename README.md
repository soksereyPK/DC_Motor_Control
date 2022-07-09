# Control-Theory
### 1. Position control with P Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)

![](Img/Img1.png)
|Parameters | Value |
|---|---|
|wn1 | ```a*zeta/2```| 
|kp1 | ```wn1^2/2```|


### 2. Position control with PD Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)
![](Img/Img2.png)
|Parameters | Value |
|---|---|
|kp2 | ```wn^2/b```| 
|kd2 | ```(2*zeta*wn-a)/b``` |

### 3. Position control with PID Simulation (```a=30, b=20, zeta=1, wn=2*PI*2, lamdal=40```)
![](Img/Img3.png)
|Parameters | Value |
|---|---|
|kp3 | ```(wn^2+2*zeta*wn*lambdal)/b```| 
|kd3 | ```(lambdal+2*zeta*wn-a)/b``` |
|ki3 | ```lambdal*wn^2/b``` |

### 4. Position tracking control with PD and feedforward Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)
![](Img/Img5.png)
|Parameters | Value |
|---|---|
|kp4 | ```wn^2/b```| 
|kd4 | ```(2*zeta*wn-a)/b``` |

### 5. Cascade control with velocity and position feedback inner and outer loop Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)
![](Img/Img6.png)
|Parameters | Value |
|---|---|
|k1 | ```wn^2/b```| 
|k2 | ```(2*zeta*wn-a)/b``` |




### 6. Position control with PD Hardware Due (```a=30, b=20, zeta=1, wn=2*PI*2```)
![](Img/Img7.png)
![](Img/Img8.png)
|Parameters | Value |
|---|---|
|kp2 | ```wn^2/b```| 
|kd2 | ```(2*zeta*wn-a)/b``` |

- Calculate PWM and direction in Matlab function 
```
function [pwm,dir] = fcn(v_a)

vmax = 22.9;
pwm_cal = v_a*254/vmax;

if pwm_cal > 0
  pwm = pwm_cal;
  dir = 0;
elseif pwm_cal < 0
  pwm = abs(pwm_cal);
  dir = 1;
else
  pwm = 0;
  dir = 0;
end
```



