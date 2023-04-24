#ifndef GENERAL_H_
#define GENERAL_H_

#include <cstdlib>

#define WIDTH 1800
#define HEIGHT 1200
#define HALF 50
#define FULL_ROTATION 360
#define FRAME_RATE_LIMIT 60
#define GAME_TITLE "Flappy Bird"
int percentage(int per, int amount);
float convertRotation(float degree);
int randomIntBetween(int l, int r);
#endif // GENERAL_H_
