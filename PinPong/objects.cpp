#include "objects.hpp"
#include <raylib.h>
#include <bits/stdc++.h>




//Top fonksiyonları

void Top::Update(int &p1Score , int &p2Score , Sound &winSound , Sound &Bounce)
{

    x += velx;
    y += vely;

    if(y + radius >= GetScreenHeight() or y - radius <=0)
    {

        vely *= -1;

        PlaySound(Bounce);

    }


    if(x + radius >= GetScreenWidth())
    {
        y = GetScreenHeight()/2;
        x = GetScreenWidth()/2;

        vely =  GetRandomValue(-ballSpeed, ballSpeed);
        velx = GetRandomValue(0, 1) ? -ballSpeed : ballSpeed;

        p1Score++;

        PlaySound(winSound);

    }

    if(  x - radius <=0)
    {

        y = GetScreenHeight()/2;
        x = GetScreenWidth()/2;

        vely =  rand() % (ballSpeed+1) - ballSpeed;
        velx = (rand() % 2 == 0) ? -ballSpeed : ballSpeed;

        p2Score++;

        PlaySound(winSound);

    }

}


void Top::Start()
{
    x = GetScreenWidth()/2;
    y = GetScreenHeight()/2;
}


void Top::Render()
{
    DrawCircle( x , y , radius , GREEN);
}

//Oyuncu fonksiyonları


void Player::Update()
{

    if(IsKeyDown(KEY_W) && y < GetScreenHeight())
    {
        y -= speed;
    }

    if(IsKeyDown(KEY_S) && y  + height > 0)
    {
        y += speed;
    }

    if(y<=0)
    {
        y=0;
    }

    if(y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }


}


void Player::Start()
{
    y = GetScreenHeight() / 2;

    x = 30;
}



void Player::Render()
{


    DrawRectangle( x , y , width , height , GREEN);


}

/////////////////////////////////////////////////////////////////////



void Player2::Start()
{
    y = GetScreenHeight() / 2;

    x = GetScreenWidth()-30;
}



void Player2::Render()
{


    DrawRectangle( x , y , width , height , GREEN);


}

void Player2::Update()
{

    if(IsKeyDown(KEY_UP))
    {
        y -= speed;
    }

    if(IsKeyDown(KEY_DOWN))
    {
        y += speed;
    }

    if(y<=0)
    {
        y=0;
    }

    if(y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }


}



