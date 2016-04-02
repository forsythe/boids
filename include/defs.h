#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#define WIDTH 1000
#define HEIGHT 800
#define TITLE "boids simulation"

#define TICK 10
#define TURN_INCREMENT PI/90

#define PI 3.1415

#define bWIDTH 30
#define bHEIGHT 15

#define NUM_BOIDS 20
#define BOID_RADIUS 80 //how far the boid can see
#define SEPARATION_BOID_RADIUS 30 //needs to be smaller than boid radius; the "personal space" bubble

#define W_COHESION 0 //weight
#define W_SEPARATION 0
#define W_ALIGNMENT 1

#define DRAW_RADIUS true
#define DRAW_VECTOR false

#endif // DEFS_H_INCLUDED
