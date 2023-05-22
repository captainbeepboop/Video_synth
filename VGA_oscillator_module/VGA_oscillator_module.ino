
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable
#define knob1 A1
#define knob2 A1
#define xpin A2
#define ypin A3
#define output1 9
#define output2 10

int knob1reading;
int knob2reading;
int delay1 = 1000;
int delay2 = 2000;
int xreading = 0;
int yreading = 0;
int modx = 0;
int mody = 0;
bool state1 = 0;
bool state2 = 0;

unsigned long       msec;
unsigned long       msecLst1;
unsigned long       msecLst2;





void setup(){
  
pinMode(output1, OUTPUT);
pinMode(output2, OUTPUT);
}


void loop(){
  
knob1reading = analogRead(knob1);
knob2reading = analogRead(knob2);
xreading = analogRead(xpin);
yreading = analogRead(ypin);

modx = map(xreading, 0, 1024, 5000, -5000);
mody = map(yreading, 0, 1024, 5000, -5000);

delay1 = (map(knob1reading, 0, 1024, 10000, 1)+modx);
delay2 = (map(knob2reading, 0, 1024, 10000, 1)+mody);

unsigned long msec = micros ();

if(msec - msecLst1 > delay1)
{msecLst1 = msec;
PORTB = PORTB ^ B000010;}

if(msec - msecLst2 > delay2)
{msecLst2 = msec;
PORTB = PORTB ^ B000100;}

}