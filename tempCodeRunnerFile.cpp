#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "inc/SDL.h"

#undef main

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    SDL_Rect player;
    player.x=0;
    player.y=0;
    player.h=0;
    player.w=0;

    int tailLength=0;
    vector<int>tailX;
    vector<int>tailY;

    int scale=24;
    int wscale=24;

    int x=0;
    int y=0;
    int prevX=0;
    int prevY=0;

    bool up=false;
    bool down=false;
    bool right=false;
    bool left=false;

    bool inputThisFrame=false;
    bool redo=false;

    SDL_Rect food;
    food.w=scale;
    food.h=scale;
    food.x=0;
    food.y=0;

    pair<int, int>foodLoc=getFoodSpawn(tailX, tailY, x, y, scale, wScale, tailLength);
    food.x=foodLoc.first;
    food.y=foodLoc.second;

    window=SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scale*wScale+1, scale*wscale+1, SDL_WINDOW_RESIZABLE);
    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    float time=SDL_GetTicks()/100;


    return 0;

}
