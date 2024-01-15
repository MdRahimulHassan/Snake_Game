#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "inc/SDL.h"

#undef main

using namespace std;

void renderPlayer(SDL_Renderer* renderer, SDL_Rect player, int x, int y, int scale, vector<int>tailX, vector<int>tailY, int tailLength)
{ 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    player.w=scale;
    player.h=scale;

    for(int i=0;i<tailLength;i++)
    {
        player.x=tailX[i];
        player.y=tailY[i];
        SDL_RenderFillRect(renderer, &player);
    }
    player.x=x;
    player.y=y;

    SDL_RenderFillRect(renderer, &player);
}

void renderFood(SDL_Renderer* renderer, SDL_Rect food)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &food);
}

void renderScore(SDL_Renderer* renderer, int tailLength, int scale, int wScale)
{

}

bool checkCollision(int foodx, int foody, int playerx, int playery)
{
    return(playerx==foodx&&playery==foody);
}

pair<int, int>getFoodSpawn(vector<int>tailX, vector<int> tailY, int playerX, int playerY, int scale, int wScale, int tailLength)
{
    bool valid=false;
    int x=0;
    int y=0;
    srand(time(0));
    x=scale*(rand()%wScale);
    y=scale*(rand()%wScale);
    valid=true;

    for(int i=0;i<tailLength;i++)
    {
        if((x==tailX[i]&&y==tailY[i])||(x=playerX&&y==playerY))
        {
            valid=false;
        }
    }

    if(!valid)
    {
        pair<int, int>foodLoc;
        foodLoc=make_pair(-100, -100);
        return foodLoc;
    }
    pair<int, int>foodLoc;
    foodLoc=make_pair(x,y);
    return foodLoc;
}

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