#include <vector>

#include "Flock.h"
#include "Boid.h"

Flock::Flock(int num_rhs)
{
    num = num_rhs;
    for (int k = 0; k < num; k++)
        boids.push_back(Boid());
}

void Flock::update(){
    for (int k = 0; k < num; k++){
        boids[k].update();
    }
}

void Flock::draw(){
    for (int k = 0; k < num; k++)
        boids[k].draw();
}
