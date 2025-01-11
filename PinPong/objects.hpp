#include <raylib.h>

const int ballSpeed =3;

class Top
{

    public:

    float x;
    float y;
    float radius = 10;
    float vely = ballSpeed;
    float velx = ballSpeed;

    void Update( int &p1Score , int &p2Score , Sound &winSound , Sound &Bounce);
    void Start();
    void Render();

};


class Player
{
    public:

    float x;
    float y;
    float height = 70;
    float width = 10;
    float speed = 5;

    void Update();
    void Start();
    void Render();

};

class Player2
{
    public:

    float x;
    float y;
    float height = 70;
    float width = 10;
    float speed = 5;

    void Update();
    void Start();
    void Render();

};
