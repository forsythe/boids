#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"

class Flock
{
    public:
        Flock(int);
        int num;
        std::vector<Boid> boids;

        void update();
        void draw();

};

#endif // FLOCK_H
