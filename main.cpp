#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <vector>

#include "CSDLManagerLite.h"
#include "CSDLInputManagerLite.h"
#include "Flock.h"
#include "defs.h"

using namespace std;

void update() {
    CSDLManagerLite::getInstance() -> drawFrame();
    CSDLManagerLite::getInstance() -> background();
    CSDLInputManagerLite::getInstance() -> update();
    CSDLManagerLite::getInstance()->setColor(255, 255, 255, 255);
}


int main(int argc, char *argv[]) {
    CSDLManagerLite::getInstance()->initializeSDL(WIDTH, HEIGHT, TITLE);

    Flock f = Flock(NUM_BOIDS);

    Uint32 iTime = SDL_GetTicks(), iTime2 = 0;

    while (!CSDLInputManagerLite::getInstance() -> isExit()) {
        iTime2 = SDL_GetTicks();

        if (iTime2 - iTime >= TICK) {
            iTime = SDL_GetTicks();
            f.update();
        }

        f.draw();
        update();
    }

    CSDLManagerLite::getInstance()->clean();
    return 0;
}
