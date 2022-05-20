#ifndef COLLISION_H
#define COLLISION_H
#include <SDL2/SDL.h>

const static int s_buffer = 4; // the buffer function is to reduce slightly 
                               // the collision surface to check

static bool RectRect(SDL_Rect* A, SDL_Rect* B)
{
    int aHBuf = A->h / s_buffer;
    int aWBuf = A->w / s_buffer;

    int bHbuf = B->h / s_buffer;
    int bWBuf = B->w / s_buffer;

    // if the bottom of A is less than the top of B - no collision
    if((A->y + A->h) - aHBuf <= B->y + bHbuf)
    {
        return false;
    }

    // if the top of A is more than the bottom of B - no collision
    if(A->y + aHBuf >= (B->y + B-> h) - bHbuf)
    {
        return false;
    }

    // if the right of A is less than the left of B - no collision
    if((A->x + A->w) - aWBuf <= B->x + bWBuf)
    {
        return false;
    }

    // if the left of A is more than the right of B - no collision
    if(A->x + aWBuf >= (B->x + B->w) - bWBuf)
    {
        return false;
    }
    return true;
}

#endif