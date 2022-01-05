#include <time.h>
#include "Object.h"
#include "Definition.h"

using namespace simplecpp;

int dice(int N)
{
    // returns a random number between 0 and N-1
    return rand() % N;
}

// Node is basically an object consiting of three sub-Objects
// namely Textual data, node_circle, node_background_circle

class Node : public Object
{
    double node_x;
    double node_y;
    double speed;
    double release_angle_deg;
    double node_ax;
    double node_ay;
    int level = 0;

    // Moving parts
    Circle node_circle;
    Circle node_bg_circle;
    Text node_data;

    // State info
    bool node_looped;
    void initNode(int S);   // int s will set the Text message of the node as S

public:
    int color = 0;
    Node() : Object() {}
    Node(int msg) : Object()
    {
        speed = 0;
        release_angle_deg = 0;
        node_ax = 0;
        node_ay = 0;
        initNode(msg);
    }
    Node(double arg_speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta, int msg) : Object(arg_speed, angle_deg, argax, argay, argpaused, rtheta)
    {
        speed = arg_speed;
        release_angle_deg = angle_deg;
        node_ax = argax;
        node_ay = argay;
        initNode(msg);
    }


    void addAngle(double angle_deg);
    void addSpeed(double arg_speed);
    void setFill(bool flag);
    double getX() { return node_x; }
    double getY() { return node_y; }
    void changeColor(Color c);

    // void nextStep(double t);
};