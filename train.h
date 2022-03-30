#include <string>
#include <iostream>

using namespace std;

class train
{ructor to set the default private values;
    train();

    // setting the train beginning cords
    public:

    // Default const
    train(double x, double y);

    // setting the train beginning cords and slope (idk why we need the constructor above this)
    train(double x, double y, double sl);

    // a setter and a getter for the direction of the train
    void setDirection(bool dir);
    bool getDirection();

    // getter for slope
    double getSlope();

    // a setter and a getter for the speed of the train
    void setSpeed(double sp);
    double getSpeed();

    // function that prints out current train attributes
    void Display();

    // function that calculates the movement
    void Move();

    // increases the speed of the train or decreases the speed of the train
    void SpeedUp();
    void SlowDown();

    // detects if the train
    bool DetectCollision(train t);

    // finds the point of collision
    int FindCollision(train t);

    // makes a perpendicular train to the train you pass in;
    train GetPerpendicularTrain();

private:

    double x_coord;
    double y_coord;
    double slope;
    double speed;
    bool direction;

};