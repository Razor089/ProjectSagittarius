#ifndef COLLISION_H
#define COLLISION_H
#include <SDL2/SDL.h>
#include <iostream>

const static int s_buffer = 2; // the buffer function is to reduce slightly 
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

static bool CheckRect(SDL_Rect* A, SDL_Rect* B)
{
    int aHBuf = A->h / s_buffer;
    int aWBuf = A->w / s_buffer;

    int bHbuf = B->h / s_buffer;
    int bWBuf = B->w / s_buffer;

    // First we check collision horizontally
    if((A->x + A->w) - aWBuf >= B->x + bWBuf ||
        A->x + aWBuf <= (B->x + B->w) - bWBuf)
    {
        // then we check vertically
        if((A->h + A->h) - aHBuf >= B->h + bHbuf ||
            A->h + aHBuf <= (B->h + B->w) - bHbuf)
        {
            return true;
        }
    } 
    return false;
}

static bool Overlapping(int minA, int maxA, int minB, int maxB)
{
    return minB <= maxA && minA <= maxB;
}

static bool RectanglesCollide(SDL_Rect *A, SDL_Rect *B)
{
    /*
    int aHBuf = A->h / s_buffer;
    int aWBuf = A->w / s_buffer;
    int bHBuf = B->h / s_buffer;
    int bWBuf = B->w / s_buffer;
    */
    int aLeft = A->x;
    int aRight = A->x + A->w;

    int bLeft = B->x;
    int bRight = B->x + B->w;

    int aTop = A->y;
    int aBottom = A->y + A->h;

    int bTop = B->y;
    int bBottom = B->y + B->h;

    return Overlapping(aLeft, aRight, bLeft, bRight) && Overlapping(aTop, aBottom, bTop, bBottom);
}

#endif