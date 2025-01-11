#include <raylib.h>
#include <bits/stdc++.h>


const int screenWidth = 1024;
const int screenHeight = 768;
const int timeLap = 5;



#include "objects.hpp"

Top top;

Player p1;

Player2 p2;

double curTime;
double preTime =0;

int main()
{
    int p1Score =0;
    int p2Score =0;

    srand( (unsigned)time(NULL) );

    InitWindow(screenWidth, screenHeight, "PING PONG by EdizBey");

    SetTargetFPS(60); 

    top.Start();
    p1.Start();
    p2.Start();

    while (!WindowShouldClose())
    {



        BeginDrawing();
        ClearBackground(BLACK);

        int fps = GetFPS();

        top.Update(&p1Score , &p2Score);
        top.Render();

        p1.Update();
        p1.Render();

        p2.Update();
        p2.Render();

        curTime = GetTime();  

        if(curTime - preTime >= timeLap )
        {

            preTime = curTime;

            top.velx *= 1.1;
            top.vely *= 1.1;

        }

        if( CheckCollisionCircleRec( Vector2 {top.x,top.y}, top.radius , Rectangle {p1.x,p1.y,p1.width,p1.height}))
        {
            top.velx *= -1;
        }

        if( CheckCollisionCircleRec( Vector2 {top.x,top.y}, top.radius , Rectangle {p2.x,p2.y,p2.width,p2.height}))
        {
            top.velx *= -1;
        }

        DrawLine( screenWidth/2 , 0 , screenWidth/2 , screenHeight , GREEN );

        DrawText(TextFormat(" %i" ,p1Score) , 30 , 30 , 50 , GREEN);

        DrawText(TextFormat(" %i" ,p2Score) , GetScreenWidth()-80 , 30 , 50 , GREEN);

        EndDrawing();
    }


    CloseWindow(); 

    return 0;
}