# Control-Theory
### Position control with P Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)

![](Img/Img1.png)
|Parameters | Value |
|---|---|
|wn1 | ```a*zeta/2```| 
|kp1 | ```wn1^2/2```|


### Position control with PD Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)
![](Img/Img2.png)
|Parameters | Value |
|---|---|
|kp2 | ```wn^2/b```| 
|kd2 | ```(2*zeta*wn-a)/b``` |

### Position control with PID Simulation (```a=30, b=20, zeta=1, wn=2*PI*2```)
![](Img/Img3.png)
|Parameters | Value |
|---|---|
|kp3 | ```(wn^2+2*zeta*wn*lambdal)/b```| 
|kd3 | ```(lambdal+2*zeta*wn-a)/b``` |
|ki3 | ```lambdal*wn^2/b``` |

### Position control with PD Hardware Due (```a=30, b=20, zeta=1, wn=2*PI*2```)

