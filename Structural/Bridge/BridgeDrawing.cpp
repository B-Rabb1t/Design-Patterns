#include <iostream>

class DrawAPI
{
public:
    virtual void DrawCircle(int radius, int x, int y) = 0;
    virtual ~DrawAPI() = default;
};

class RedCircle : public DrawAPI
{
public:
    void DrawCircle(int radius, int x, int y) override
    {
        std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", y: " << y << " ]\n";
    }
};

class GreenCircle : public DrawAPI
{
public:
    void DrawCircle(int radius, int x, int y) override
    {
        std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", y: " << y << " ]\n";
    }
};

class Shape
{
protected:
    DrawAPI *drawAPI;
    Shape(DrawAPI *drawAPI) : drawAPI(drawAPI) {}

public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    int x, y, radius;

public:
    Circle(int x, int y, int radius, DrawAPI *drawAPI) : Shape(drawAPI), x(x), y(y), radius(radius) {}

    void draw() override
    {
        drawAPI->DrawCircle(radius, x, y);
    }
};

int main()
{
    Shape *redCircle = new Circle(100, 100, 10, new RedCircle());
    Shape *greenCircle = new Circle(100, 100, 10, new GreenCircle());

    redCircle->draw();
    greenCircle->draw();
}