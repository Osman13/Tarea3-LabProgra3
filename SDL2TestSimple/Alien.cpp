#include "Alien.h"

Alien::Alien(SDL_Renderer* renderer, Jugador* jugador) : Enemigo(renderer, jugador)
{
    this->renderer = renderer;
    this->jugador = jugador;
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/down1.png"));
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/down2.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/up1.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/up2.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/left1.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/left2.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/right1.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo3/right2.png"));

    SDL_QueryTexture(this->textures["down"][0], NULL, NULL, &rect.w, &rect.h);
    x = rand()%100;
    y = rand()%100;

    velocity=1;
    animation_velocity=20;

    current_texture=0;

    state="down";
}

Alien::~Alien()
{
    //dtor
}

void Alien::logica()
{
    if(jugador->x-5>x)
    {
        state="right";
    }
    if(jugador->x+5<x)
    {
        state="left";
    }
    if(state=="right")
    {
        x+=velocity;
    }
    if(state=="left")
    {
        x-=velocity;
    }

    if(jugador->x == x && jugador->y == y)
    {
        state="down";
    }

    if(frames%animation_velocity==0)
    {
        current_texture++;
        if(current_texture>=textures[state].size())
            current_texture=0;
    }

    frames++;
}

