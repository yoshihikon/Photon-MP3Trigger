#include "application.h"
#include "MP3Trigger/MP3Trigger.h"

#define mySerial Serial1

MP3Trigger trigger;

void setup()
{

    Spark.function("playsound", playSound);
    Spark.function("stopsound", stopSound);
    
    trigger.setup(&mySerial);
    mySerial.begin(38400);
    
    // Start looping TRACK001.MP3
    //trigger.setLooping(true,1);
    //trigger.play(1);
}

void loop()
{
}

int playSound(String command) {
    
    trigger.play(atoi(command));
    
}

int stopSound(String command) {
    
    trigger.stop();
    
}
