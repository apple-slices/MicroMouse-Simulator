
#include "micromouseserver.h"
struct position{
    int x;
    int y;
    int dir;
};

void microMouseServer::studentAI()
{
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
    static int timesRun=0;
    static struct position myPos;

    if(timesRun==0){
        myPos.x=0;
        myPos.y=0;

    }

    timesRun++;
    static int timesTurnedLeft=0;

    if(!isWallRight()){
        turnRight();
        moveForward();
        timesTurnedLeft=0;
    }
    else if(!isWallForward()){
        moveForward();
         timesTurnedLeft=0;
    }
    else if (!isWallLeft()){
        turnLeft();
        moveForward();
        timesTurnedLeft++;

    }
    else{
        turnRight();
        turnRight();
        moveForward();
        timesTurnedLeft=0;
    }
    if(timesTurnedLeft==3){
        foundFinish();
        timesTurnedLeft=0;
    }
}

