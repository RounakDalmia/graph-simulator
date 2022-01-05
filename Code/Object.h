#include <iostream>
#include <vector>
#include <simplecpp>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <composite.h>
#include <sprite.h>

using namespace std;

class Object : public Sprite
{
    vector<Sprite *> parts;
    double vx, vy;
    double ax, ay;
    bool paused;
    void initMO(double argvx, double argvy, double argax, double argay, bool argpaused = true)
    {
        vx = argvx;
        vy = argvy;
        ax = argax;
        ay = argay;
        paused = argpaused;
    }

public:
    Object() : Sprite()
    {
        initMO(0, 0, 0, 0, true);
    }
    Object(double argvx, double argvy, double argax, double argay, bool argpaused = true)
        : Sprite()
    {
        initMO(argvx, argvy, argax, argay, argpaused);
    }
    Object(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : Sprite()
    {
        double angle_rad = angle_deg * PI / 180.0;
        double argvx = speed * cos(angle_rad);
        double argvy = -speed * sin(angle_rad);
        initMO(argvx, argvy, argax, argay, argpaused);
    }
    //   void set_vx(double argvx) { vx = argvx; }
    //   void set_vy(double argvy) { vy = argvy; }
    //   void set_ax(double argax) { ax = argax; }
    //   void set_ay(double argay) { ay = argay; }
    double getXPos();
    double getYPos();
    void reset_all(double argx, double argy, double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta);

    //   void pause() { paused = true; }
    //   void unpause() { paused = false; }
    //   bool isPaused() { return paused; }

    void addPart(Sprite *p)
    {
        parts.push_back(p);
    }
    void nextStep(double t);
    void getAttachedTo(Object *m);
};
