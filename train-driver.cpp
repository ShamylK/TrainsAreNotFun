#include "train.h"
#include <iostream>

int main()
{
    train t1(0,0,1);
    train t2 = t1.GetPerpendicularTrain();
    t1.setSpeed(1);
    t1.setDirection(true);
    t2.setSpeed(1);
    t2.setDirection(false);

    if (t1.DetectCollision(t2) == false)
    {
        cout << "Train one will not collide with train two" << endl;
    }
    else
    {
        cout << "Train one will collide with train two" << "at" << t1.FindCollision(t2) << endl;
    }

    train t3(0,0,1);
    train t4(0,4,-1);

    t3.setSpeed(1);
    t3.setDirection(true);
    t4.setSpeed(1);
    t4.setDirection(true);

    if (t3.DetectCollision(t4) == false)
    {
        cout << "Train one will not collide with train two" << endl;
    }
    else
    {
        cout << "Train one will collide with train two" << "at" << t3.FindCollision(t4) << endl;
    }

    //speed up for 10 instances
    for (int i=0; i < 10; i++)
    {
        t1.SpeedUp();
        t1.Move();
        t1.Display();
    }

    //slowdown for 10 instances
    for (int i=0; i < 10; i++)
    {
        t1.SlowDown();
        t1.Move();
        t1.Display();
    }

    // prints out for the prependicular train speed up and slow down
    for (int i=0; i < 10; i++)
    {
        t2.SpeedUp();
        t2.Move();
        t2.Display();
    }

    for (int i=0; i < 10; i++)
    {
        t2.SlowDown();
        t2.Move();
        t2.Display();
    }

}