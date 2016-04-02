#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#define WIDTH 1500
#define HEIGHT 800
#define TITLE "boids simulation"

#define TICK 10
#define TURN_INCREMENT PI/180

#define PI 3.1415

#define bWIDTH 30
#define bHEIGHT 15

#define NUM_BOIDS 50
#define BOID_RADIUS 120 //how far the boid can see
#define SEPARATION_BOID_RADIUS 40 //needs to be smaller than boid radius; the "personal space" bubble

#define W_COHESION 0.01 //weight
#define W_SEPARATION 0.09
#define W_ALIGNMENT 0.9

#define DRAW_RADIUS false
#define DRAW_VECTOR false

#endif // DEFS_H_INCLUDED
