const int EnableL = 5;
const int HighL = 6; // LEFT SIDE MOTOR
const int LowL =7;
const int EnableR = 10;
const int HighR = 8; //RIGHT SIDE MOTOR
const int LowR =9;
const int D0 = 0; //Raspberry pin 21 LSB
const int D1 = 1; //Raspberry pin 22
const int D2 = 2; //Raspberry pin 23
const int D3 = 3; //Raspberry pin 24 MSB
int a,b,c,d,data;
void setup() {
36 | P a g e
pinMode(EnableL, OUTPUT);
pinMode(HighL, OUTPUT);
pinMode(LowL, OUTPUT);
pinMode(EnableR, OUTPUT);
pinMode(HighR, OUTPUT);
pinMode(LowR, OUTPUT);
pinMode(D0, INPUT_PULLUP);
pinMode(D1, INPUT_PULLUP);
pinMode(D2, INPUT_PULLUP);
pinMode(D3, INPUT_PULLUP);
}
void Data()
{
 a = digitalRead(D0);
 b = digitalRead(D1);
 c = digitalRead(D2);
 d = digitalRead(D3);
 data = 8*d+4*c+2*b+a;
}
void Forward()
{
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,255);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,255);
 
}
void Backward()
{
 digitalWrite(HighL, HIGH);
 digitalWrite(LowL, LOW);
37 | P a g e
 analogWrite(EnableL,255);
 digitalWrite(HighR, HIGH);
 digitalWrite(LowR, LOW);
 analogWrite(EnableR,255);
 
}
void Stop()
{
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,0);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,0);
 
}
void Left1()
{
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,100);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,255);
 
}
void Left2()
{
 digitalWrite(HighL, HIGH);
 digitalWrite(LowL, LOW);
 analogWrite(EnableL,30);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,255);
 
}
38 | P a g e
void Left3()
{
 digitalWrite(HighL, HIGH);
 digitalWrite(LowL, LOW);
 analogWrite(EnableL,10);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,255);
 
}
void Right1()
{
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,255);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,100); //200
 
}
void Right2()
{
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,255);
 digitalWrite(HighR, HIGH);
 digitalWrite(LowR, LOW);
 analogWrite(EnableR,30); //160
 
}
void Right3()
{
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,255);
 digitalWrite(HighR, HIGH);
 digitalWrite(LowR, LOW);
 analogWrite(EnableR,10); //100
 
39 | P a g e
}
void Stop_end()
{
 
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 analogWrite(EnableL,0);
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableR,0);
 delay(20000);
}
void Arrow()
{
 analogWrite(EnableL, 0); //stop
 analogWrite(EnableR, 0);
 delay(300);
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH); //forward
 digitalWrite(HighR, LOW);
 digitalWrite(LowR, HIGH);
 analogWrite(EnableL, 255);
 analogWrite(EnableR, 255);
 delay(1100);
 analogWrite(EnableL, 0); //stop
 analogWrite(EnableR, 0);
 delay(300);
 digitalWrite(HighL, LOW);
 digitalWrite(LowL, HIGH);
 digitalWrite(HighR, HIGH); //right
 digitalWrite(LowR, LOW);
 analogWrite(EnableL, 255);
 analogWrite(EnableR, 255);
 delay(1000);
 analogWrite(EnableL, 0); //stop
40 | P a g e
 analogWrite(EnableR, 
0);
 delay(300);
 }
void loop() {
 Data();
 if(data==
0
)
 
{
 Forward();
 
}
 
 else if(data==
1
)
 
{
 Right1();
 
}
 
 else if(data==
2
)
 
{
 Right2();
 
}
 
 else if(data==
3
)
 
{
 Right3();
 
}
 
 else if(data==
4
)
 
{
 Left1();
 
}
 
 else if(data==
5
)
 
{
 Left2();
 
}
 
 else if(data==
6
)
 
{
 Left3();
 
}
 
 else if (data==
7
)
41 | P a g e
 {
 Stop_end();
 }
 
 
 else if (data==8)
 {
 analogWrite(EnableL, 0);
 analogWrite(EnableR, 0);
 delay(7000); // stop sign detection
 analogWrite(EnableL, 150);
 analogWrite(EnableR, 150);
 delay(1000);
 }
 else if(data==9)
 {
 Arrow();
 }
 else if(data>9)
 {
 Stop();
 }
}