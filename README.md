### Summary

A simple visualization of flocking behavior with [boids](http://www.red3d.com/cwr/boids/).

![demo](https://i.gyazo.com/d6741f0e8091731673d51cf91cee5f88.gif)

### How it works

Three rules govern how each boid moves.  
1) Separation: each boid will try to move away from other boids if they get too close.  
2) Alignment: each boid will try to steer in the average direction of neighboring boids.  
3) Cohesion: each boid will try to move towards the average location of neighboring boids.  

### Customizable options under `defs.h`  
`TICK`: Update frequency  
`TURN_INCREMENT`: How many radians a boid can turn in one tick  

`NUM_BOIDS`: Number of boids  
`BOID_RADIUS`: Radius where boid can detect other boids  
`SEPARATION_BOID_RADIUS`: Radius where boid will try to move away from other boids (personal space!)  

`W_COHESION`: Cohesion weight  
`W_SEPARATION`: Separation weight  
`W_ALIGNMENT`: Alignment weight  

`DRAW_RADIUS`: Whether to draw `BOID_RADIUS` and `SEPARATION_BOID_RADIUS`  
`DRAW_VECTOR`: Whether to draw the vectors for the three rules  

Requires SDL2 for graphics. I included all the necessary files along with the .exe to avoid the hassle of installing SDL.
