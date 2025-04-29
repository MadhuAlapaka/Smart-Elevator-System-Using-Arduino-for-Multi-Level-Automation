const int CW =1;
const int CCW =2;
const int STOP =3;
int Pin1 = 2;//IN1 is connected to 8 int Pin2 = 3;//IN2 is
connected to 9 int Pin3 = 4;//IN3 is connected to 10 int Pin4 =
5;//IN4 is connected to 11 int switchSTOP =2;//define input pin
for STOP push button int stopType=1;//1=normal stop, 2=hold
stop (consumes power) int speedFactor =1;//1=fastest, 2=slower
or 3 more slower
long angles[] = {2880, 2880, 1000, 2790, 2790.5, 1500};//angles of each push
button int pushButtons[] ={6, 7, 8, 9, 10, 11};//digial pin for each push button
int directions[] ={CCW, CW, CCW, CW, CCW, CW};//direction of
eacch
push button int speedFactors[] = {1, 1, 1, 1, 1, 1};//speed for each
push button
int correction_CW = 150;
int correction_CCW = 150;
int poleStep = 0; long stepVale =0; const int
SPR=64*64; long goToAngle=0; int
activeButton=0; int pole1[] ={0,0,0,0, 0,1,1,1,
0};//pole1, 8 step values int pole2[] ={0,0,0,1, 1,1,0,0,
0};//pole2, 8 step values int pole3[] ={0,1,1,1, 0,0,0,0,
0};//pole3, 8 step values int pole4[] ={1,1,0,0, 0,0,0,1,
0};//pole4, 8 step values
int count=0; int dirStatus = STOP;// stores direction status 3= stop (do
not change)
void setup()
{
Serial.begin(9600);
Serial.begin("elevator using arduino");
pinMode(Pin1, OUTPUT);//define pin for ULN2003 in1 pinMode(Pin2,
OUTPUT);//define pin for ULN2003 in2 pinMode(Pin3,
OUTPUT);//define pin for ULN2003 in3 pinMode(Pin4,
OUTPUT);//define pin for ULN2003 in4
pinMode(switchSTOP,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(switchSTOP), stopMotor,
FALLING );
for (byte i = 0; i < (sizeof(pushButtons) / sizeof(pushButtons[0])); i++) {
pinMode(i,INPUT_PULLUP);
}
} //setup
void loop()
{
stepVale = (SPR * goToAngle)/360 ;
for (byte i = 0; i < (sizeof(angles) / sizeof(angles[0])); i++) {
if(digitalRead(pushButtons[i]) == LOW)
{ goToAngle
=angles[i];
dirStatus =directions[i];
count =0;
activeButton =i;
}// if ends }//for
loop ends
if(dirStatus ==CCW){
poleStep++;
count++;
if(count+correction_CCW <= stepVale)
{
driveStepper(poleStep);
}else{
stopMotor();
}
//full explannation at Arduino Course on Udemy.com see link above
}else if(dirStatus ==CW){
poleStep--; count++;
if(count+correction_CW <=stepVale)
{
driveStepper(poleStep);
}else{
stopMotor();
}
}else{
stopMotor(); }
if(poleStep>7){
poleStep=0; }
if(poleStep<0){
poleStep=7;
} delay(speedFactors[activeButton]);
//Robojax.com Stepper Push button Any Angle STPB-5
}// loop
void driveStepper(int c)
{
//Robojax.com Stepper Push button Any Angle STPB-5
digitalWrite(Pin1, pole1[c]); digitalWrite(Pin2, pole2[c]);
digitalWrite(Pin3, pole3[c]); digitalWrite(Pin4, pole4[c]);
}//driveStepper ends here
void stopMotor()
{
for (byte i = 0; i < (sizeof(angles) / sizeof(angles[0])); i++) {
digitalWrite(pushButtons[i], HIGH);
}//for loop ends dirStatus
= STOP;
if( stopType ==2)
{ driveStepper(8);
}
}//stopMotor()