#include "../include/general.h"

int percentage(int per, int amount){
    return amount * per / 100;
}

float convertRotation(float degree){
    if(degree > percentage(HALF, FULL_ROTATION)){
        degree -= FULL_ROTATION;
    }
    return degree;
}

int randomIntBetween(int l, int r){
    int eq = r - l + 1;
    int x = rand() % eq;
    x += l;
    return x;
}
