
import processing.sound.*;
import processing.serial.*;
Serial port;
SoundFile tubeOne, tubeTwo, tubeThree, tubeFour;


Float setVolumeOne = 0.0;
Float setVolumeTwo = 0.1;
Float setVolumeThree = 0.1;
Float setVolumeFour = 0.1;

int tubeOneFirstHand = 0 ;
int tubeTwoFirstHand = 0 ;
int tubeThreeFirstHand = 0 ;
int tubeFourFirstHand = 0 ;

int loopWholeAvoidanceTubeOne = 0;
int loopWholeAvoidanceTubeThree = 0;


void setup() 
{
  size(640, 360);
  background(255);

  printArray(Serial.list());
  
  String portName = Serial.list()[5];
  port = new Serial(this, portName, 9600);

  // Load a soundfile from the data folder of the sketch and play it back in a loop

  tubeOne = new SoundFile(this, "Reflection.mp3");
  tubeTwo = new SoundFile(this, "Chad_Crouch_-_Algorithms.mp3");
  tubeThree = new SoundFile(this, "Blear_Moon_-_07_-_Few_survivors.mp3");
  tubeFour = new SoundFile(this, "meditation.mp3");

  //tubeOne.loop();
  //tubeOne.pause();

  tubeTwo.loop();
  //tubeTwo.pause();

  tubeThree.loop();
  //tubeThree.pause();

  tubeFour.loop();
  //tubeFour.pause();
} 

void draw() 
{

  if ( port.available() > 0) 
  { 
    // If data is available,
    String val = port.readStringUntil('\n');         // read it and store it in val

    if (val != null)
    {
      val = val.trim(); //remove whitespace before and after the string
      println(setVolumeOne+":"+setVolumeTwo+":"+setVolumeThree+":"+setVolumeFour);

      String[] sensor = val.split(":");
      println(sensor.length);
      
      if(sensor.length==4)
      {
        /*
                    //Tube and Sensor 1          
                    if (int(sensor[0])<35)
                    {
                      if (loopWholeAvoidanceTubeOne>2)
                      {    
                        if (!tubeOne.isPlaying()) {
                          tubeOne.play();
                          tubeOne.amp(setVolumeOne);
                        } else if (setVolumeOne<=1.0) {
                          if (tubeOneFirstHand<2) {
                            setVolumeOne = setVolumeOne + 0.05;
                            tubeOneFirstHand = tubeOneFirstHand +1;
                          } else {
                            setVolumeOne = setVolumeOne + 0.008;
                          }
                          tubeOne.amp(setVolumeOne);
                        }
                      } else {
                        loopWholeAvoidanceTubeOne =  loopWholeAvoidanceTubeOne+1;
                      }
                    } else
                    {
                      loopWholeAvoidanceTubeOne = 0;
                      tubeOneFirstHand = 0;
                      if (tubeOne.isPlaying()) {
                        if (setVolumeOne>0.1) {
                          setVolumeOne = setVolumeOne - 0.01;
                          tubeOne.amp(setVolumeOne);
                        } else if (setVolumeOne>0) {
                          setVolumeOne = setVolumeOne - 0.007;
                          tubeOne.amp(setVolumeOne);
                        } else {
                          tubeOne.pause();
                          setVolumeOne = 0.1;
                        }
                      }
                    }*/
              
              
                    //Tube and Sensor 3
              
                    if (int(sensor[2])<35)
                    {
                          
                        if (!tubeThree.isPlaying()) {
                          tubeThree.play();
                          tubeThree.amp(setVolumeThree);
                        } 
                        else if (setVolumeThree<=1.0) 
                        {
                          if (tubeThreeFirstHand<2) 
                          {
                            setVolumeThree = setVolumeThree + 0.05;
                            tubeThreeFirstHand = tubeThreeFirstHand +1;
                          } 
                          else 
                          {
                            setVolumeThree = setVolumeThree + 0.008;
                          }
                          tubeThree.amp(setVolumeThree);
                        } 
                     }
                      else
                      {
                        loopWholeAvoidanceTubeThree = 0 ;
                        tubeThreeFirstHand = 0;
                        if (tubeThree.isPlaying()) {
                          if (setVolumeThree>0.1) {
                            setVolumeThree = setVolumeThree - 0.01;
                            tubeThree.amp(setVolumeThree);
                          } else if (setVolumeThree>0) {
                            setVolumeThree = setVolumeThree - 0.007;
                            tubeThree.amp(setVolumeThree);
                          } else {
                            tubeThree.pause();
                            setVolumeThree = 0.1;
                          }
                        }
                      }
                    
              
                      //Tube and Sensor 2
              
                      if (int(sensor[1])<35)
                      {
                        if (!tubeTwo.isPlaying()) {
                          tubeTwo.play();
                          tubeTwo.amp(setVolumeThree);
                        } else if (setVolumeTwo<=1.0) {
                          if (tubeTwoFirstHand<2) {
                            setVolumeTwo = setVolumeTwo + 0.05;
                            tubeTwoFirstHand = tubeTwoFirstHand +1;
                          } else {
                            setVolumeTwo = setVolumeTwo + 0.008;
                          }
                          tubeTwo.amp(setVolumeTwo);
                        }
                      } else
                      {
                        tubeTwoFirstHand = 0;
                        if (tubeTwo.isPlaying())
                        {
                          if (setVolumeTwo>0.1)
                          {
                            setVolumeTwo = setVolumeTwo - 0.01;
                            tubeTwo.amp(setVolumeTwo);
                          } else if (setVolumeTwo>0)
                          {
                            setVolumeTwo = setVolumeTwo - 0.007;
                            tubeTwo.amp(setVolumeTwo);
                          } else
                          {
                            tubeTwo.pause();
                            setVolumeTwo = 0.1;
                          }
                        }
                      }
              
                      //Tube and Sensor 4
              
                      if (int(sensor[3])<35)
                      {
                        if (!tubeFour.isPlaying())
                        {
                          tubeFour.play();
                          tubeFour.amp(setVolumeOne);
                        } else if (setVolumeFour<=1.0)
                        {
                          if (tubeFourFirstHand<2)
                          {
                            setVolumeFour = setVolumeFour + 0.05;
                            tubeFourFirstHand = tubeFourFirstHand +1;
                          } else
                          {
                            setVolumeFour = setVolumeFour + 0.008;
                          }
                          tubeFour.amp(setVolumeFour);
                        }
                      } 
                      else
                      {
                        tubeFourFirstHand = 0;
                        if (tubeFour.isPlaying())
                        {
                          if (setVolumeFour>0.1)
                          {
                            setVolumeFour = setVolumeFour - 0.01;
                            tubeFour.amp(setVolumeFour);
                          } else if (setVolumeFour>0)
                          {
                            setVolumeFour = setVolumeFour - 0.007;
                            tubeFour.amp(setVolumeFour);
                          } else
                          {
                            tubeFour.pause();
                            setVolumeFour = 0.1;
                          }
                        }
              }
        }
      }
    }
  }
