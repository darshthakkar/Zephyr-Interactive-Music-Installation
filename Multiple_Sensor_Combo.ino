//Used Pins = 2,3,5,6,7,8,9,10,11,12,13,A2,A3,A4,A5


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
    #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        10 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 66 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 15 // Time (in milliseconds) to pause between pixels

#include <SparkFun_TB6612.h>

#define AIN1 88
#define AIN2 77

#define STBY 13

#define PWMA_1 6
#define PWMB_2 3
#define PWMA_3 11
#define PWMB_4 5

// defines pins numbers
const int trigPin_1 = 2;
const int echoPin_1 = 7;

const int trigPin_2 = 12;
const int echoPin_2 = 9;

const int trigPin_3 = A5;
const int echoPin_3 = A4;

const int trigPin_4 = A3;
const int echoPin_4 = A2;

const int offsetA = 1;
const int offsetB = 1;
const int offsetC = 1;
const int offsetD = 1;

// defines variables
long duration_1;
long duration_2;
long duration_3;
long duration_4;

int distance_1=300;
int distance_2;
int distance_3;
int distance_4;

int firstTime_1 = 1;
int firstTime_2 = 1;
int firstTime_3 = 1;
int firstTime_4 = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA_1, offsetA, STBY);
Motor motor2 = Motor(AIN1, AIN2, PWMB_2, offsetB, STBY);
Motor motor3 = Motor(AIN1, AIN2, PWMA_3, offsetC, STBY);
Motor motor4 = Motor(AIN1, AIN2, PWMB_4, offsetD, STBY);


void setup()
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
      clock_prescale_set(clock_div_1);
  #endif
  
   pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.
  }
  
  // END of Trinket-specific code.

  

  //pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  
  pinMode(trigPin_1, OUTPUT); // Sets the trigPin_1 as an Output
  pinMode(echoPin_1, INPUT);  // Sets the echoPin_1 as an Input

  pinMode(trigPin_2, OUTPUT); // Sets the trigPin_2 as an Output
  pinMode(echoPin_2, INPUT);  // Sets the echoPin_2 as an Input

  pinMode(trigPin_3, OUTPUT); // Sets the trigPin_4 as an Output
  pinMode(echoPin_3, INPUT);  // Sets the echoPin_4 as an Input

  pinMode(trigPin_4, OUTPUT); // Sets the trigPin_4 as an Output
  pinMode(echoPin_4, INPUT);  // Sets the echoPin_4 as an Input

  Serial.begin(9600);       // Starts the serial communication
}

void loop()
{
  delay(50);
  
  //pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  /*
  for(int i=0; i<NUMPIXELS; i++) { // 

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));

    pixels.show();   // Send the updated pixel colors to the hardware.

    //delay(DELAYVAL); // Pause before next pass through loop
  }

  //pixels.setPixelColor(66, pixels.Color(255, 255, 255));
  //pixels.show();
  */
  /*
  //******Sensor 1******
  // Clears the trigPin_1
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);

  // Sets the trigPin_1 on HIGH state for 10 micro seconds
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin_1, LOW);

  // Reads the echoPin_1, returns the sound wave travel time in microseconds
  duration_1 = pulseIn(echoPin_1, HIGH);

  // Calculating the distance_1
  distance_1 = duration_1 * 0.034 / 2;
*/
  //******Sensor 2******

  // Clears the trigPin_2
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);

  // Sets the trigPin_2 on HIGH state for 10 micro seconds
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin_2, LOW);

  // Reads the echoPin_2, returns the sound wave travel time in microseconds
  duration_2 = pulseIn(echoPin_2, HIGH);

  // Calculating the distance_2
  distance_2 = duration_2 * 0.034 / 2;

  //******Sensor 3******

  // Clears the trigPin_3
  digitalWrite(trigPin_3, LOW);
  delayMicroseconds(2);

  // Sets the trigPin_3 on HIGH state for 10 micro seconds
  digitalWrite(trigPin_3, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin_3, LOW);

  // Reads the echoPin_3, returns the sound wave travel time in microseconds
  duration_3 = pulseIn(echoPin_3, HIGH);

  // Calculating the distance_3
  distance_3 = duration_3 * 0.034 / 2;


  //******Sensor 4******

  // Clears the trigPin_4
  digitalWrite(trigPin_4, LOW);
  delayMicroseconds(2);

  // Sets the trigPin_4 on HIGH state for 10 micro seconds
  digitalWrite(trigPin_4, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin_4, LOW);

  // Reads the echoPin_4, returns the sound wave travel time in microseconds
  duration_4 = pulseIn(echoPin_4, HIGH);

  // Calculating the distance_4
  distance_4 = duration_4 * 0.034 / 2;


  String output = String(distance_1) + ":" + String(distance_2) + ":" + String(distance_3) + ":" + String(distance_4);
  Serial.println(output);


//  Serial.print(distance_1);
//  Serial.print("(1)");
//  Serial.print(distance_1);
//  Serial.print("(2)");
//  Serial.print(distance_1);
//  Serial.print("(3)");
//  Serial.println(distance_1);



  if (distance_1 < 30)
  {
    /*
    if (firstTime_1)
    {
      motor1.brake();
      delay(1050);
      firstTime_1 = 0;
    }
    motor1.drive(255);
    delay(405);
    motor1.brake();
    delay(415);
    */
    motor1.brake();
    
  }
  else
  {
    /*
    motor1.drive(238);
    firstTime_1 = 1;
    */
    motor1.drive(255);
  }

  if (distance_2 < 30)
  {
    /*
    if (firstTime_2)
    {
      motor2.brake();
      delay(1050);
      firstTime_2 = 0;
    }
    motor2.drive(255);
    delay(405);
    motor2.brake();
    delay(415);
    */
    motor2.brake();
  }
  else
  {
    /*
    motor2.drive(238);
    firstTime_2 = 1;
    */
    motor2.drive(255);
  }



  if (distance_3 < 30)
  {
    motor3.brake();
  }

  else
  {
    motor3.drive(255);
  }

  if (distance_4 < 30)

  {
    motor4.brake();
  }
  else
  {
    motor4.drive(255);
  }
}

/*
    if(firstTime)
      {
          motor4.brake();
          delay(650);
          firstTime=0;
        }
      Serial.println(air_controller_4);
      /*
      motor4.brake();
      delay(600+(air_controller_4*70));

      motor4.drive(234);
      delay(500);
      motor4.brake();
      delay(90 + (air_controller_4*25));

      if(air_controller_4<5 && air_controller_4>=0)
      {
        air_controller_4 = air_controller_4+1;
        motor4.drive(235 - (air_controller_4*20));
      }
      else if(air_controller_4==5) {
         air_controller_4 = -1;
        }

       if(air_controller_4>-5 && air_controller_4<0)
      {

        motor4.drive(270 + ((air_controller_4)*20));
        delay(50);
        air_controller_4 = air_controller_4-1;
      }
      else if (air_controller_4==-5){
         air_controller_4 = 0;
         motor4.brake();
         delay(200);
        }
      /*
      else{
        air_controller_4 = 0;
        upcoming_time = upcoming_time+1;
        if(upcoming_time==4){
            air_controller_4=1;
            upcoming_time=0;
            motor4.brake();
            delay(450);
          }
        }

  }
  else
  {
    motor4.drive(230);
    firstTime=1;
    air_controller_4=1;
  }
*/
/*
  Serial.print(air_controller_4);
  Serial.print(":");
  Serial.print(upcoming_time);
  Serial.print(":");
  Serial.println(230 - (air_controller_4*20));
*/
/*
  if(distance_1<30){

  if(firstTime)
  {
      motor1.brake();
      delay(400);
      firstTime=0;
    }
  motor1.brake();
  delay(600);
  motor1.drive(255);
  delay(530);
  }
  else
  {
  motor1.drive(255);
  firstTime=1;
  }
  }
*/
