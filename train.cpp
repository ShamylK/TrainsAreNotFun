#include "train.h"
#include <iostream>
#include <cmath>

using namespace std;

// default values
train::train()
{
    x_coord = 0;
    y_coord = 0;
    slope = 1;
    speed = 0;
}

// values to be set
train::train(double x, double y)
{
    x_coord = x;
    y_coord = y;
}

// the actual constructor that would be used
train::train(double x, double y, double sl)
{
    x_coord = x;
    y_coord = y;
    slope = sl;
}

// sets the direction of the train
void train::setDirection(bool dir)
{
    direction = dir;
}

// gets the direction of the train
bool train::getDirection()
{
    return direction;
}

// gets the slope of the train
double train::getSlope()
{
    return slope;
}

// sets the speed of the train
void train::setSpeed(double sp)
{
    if (sp >= 100)
    {
        speed = 100;
    }
    else if (sp <= 0)
    {
        speed = 0;
    }
    else
    {
        speed = sp;
    }
}

// gets the speed of the train
double train::getSpeed()
{
    return speed;
}

// displays the current status of the train
void train::Display()
{
    cout << "track: " << "(y - " << y_coord << ") = " << slope << "(x - " << x_coord << ")" << endl;
    cout << "Speed: " << speed << endl;
    if (direction == true)
    {
        cout << "Direction = Forward" << endl;
    }
    else if (direction == false)
    {
        cout << "Direction = Backwards" << endl;
    }
}

// function to make the train move
void train::Move()
{
    // y = m (x-x1) +y1
    // checking if the direction is forward or backward
    if (direction == true)
    {
        // solving for x
        double x = x_coord + speed * 1;
        // getting new y cord
        y_coord = slope * (x - x_coord) + y_coord;
        // setting new x cord
        x_coord = x;
    }
    // repeat of the if statement but negative for backwards
    else if (direction == false)
    {
        double x = x_coord + speed * -1;
        y_coord = slope * (x - x_coord) + y_coord;
        x_coord = x;
    }
}

// speeds up train
void train::SpeedUp()
{
    if (speed >= 100)
    {
        speed += 0;
    }
    else
    {
        speed += 1;
    }
}

// slows down train
void train::SlowDown()
{
    if (speed <= 0)
    {
        speed += 0;
    }
    else
    {
        speed -= 1;
    }
}

// detects if another train will collide with this train
bool train::DetectCollision(train t)
{
    train copyOne(x_coord,y_coord,slope);
    copyOne.setSpeed(speed);
    copyOne.setDirection(direction);

    train copyTwo(t.x_coord,t.y_coord,t.slope);
    copyTwo.setSpeed(t.speed);
    copyTwo.setDirection(t.direction);

    // creating variables two evaluate distance formula
    double distanceOne;
    double distanceTwo;
    bool collision;

    // calculating the distance between two points of the train
    // sqrt((x-x')^2 + (y-y')^2)
    distanceOne = sqrt(pow((copyOne.x_coord-copyTwo.x_coord),2) + pow((copyOne.y_coord-copyTwo.x_coord),2));

    // moving trains to get new coords to evaluate distance
    copyOne.Move();
    copyTwo.Move();

    distanceTwo = sqrt(pow((copyOne.x_coord-copyTwo.x_coord),2) + pow((copyOne.y_coord-copyTwo.x_coord),2));

    // checking if the distances are not growing apart aka going opposite ways so no collision
    if (distanceTwo > distanceOne)
    {
        collision = false;
        return collision;
    }
    else
    {
        // while the distance is decreasing checking to see if there is a collision, otherwise
        while(distanceTwo < distanceOne)
        {
            // moving trains to get new coords to evaluate distance
            copyOne.Move();
            copyTwo.Move();

            //evaluating distance
            distanceOne = sqrt(pow((copyOne.x_coord-copyTwo.x_coord),2) + pow((copyOne.y_coord-copyTwo.x_coord),2));
            distanceTwo = sqrt(pow((copyOne.x_coord-copyTwo.x_coord),2) + pow((copyOne.y_coord-copyTwo.x_coord),2));

            //checking for collision
            if (copyOne.x_coord == copyTwo.x_coord && copyOne.y_coord == copyTwo.y_coord)
            {
                collision = true;
                return collision;
            }
        }
        collision = false;
        return collision;
    }
}

int train::FindCollision(train t)
{
   int counter = 0;

   if (DetectCollision(t) == false)
   {
       return -1;
   }
   else
   {
       while(x_coord != t.x_coord && y_coord != t.y_coord)
       {
           counter +=1;
           Move();
           t.Move();
       }
       return counter;
   }
}

train train::GetPerpendicularTrain()
{
    //setting the variable to zero so no stupid shit happens
    double reciprocalSlope = 0;

    //finding the reciprocal slope
    reciprocalSlope = -(1/slope);

    //returning the perpendicular train
    return train(x_coord,y_coord,reciprocalSlope);
}