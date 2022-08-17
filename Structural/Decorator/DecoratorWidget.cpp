#include <iostream>

class Widget
{
public:
    virtual void draw() = 0;
    virtual ~Widget() = default;
};

class TextField : public Widget
{
    int width, height;

public:
    TextField(int width, int height) : width(width), height(height) {}

    void draw() override
    {
        std::cout << "TextField: " << width << ", " << height << "\n";
    }
};

class Decorator : public Widget
{
    Widget *wid;

public:
    Decorator(Widget *w) : wid(w) {}

    void draw() override
    {
        wid->draw();
    }
};

class BorderDecorator : public Decorator
{
public:
    BorderDecorator(Widget *w) : Decorator(w) {}

    void draw() override
    {
        Decorator::draw();
        std::cout << "  BorderDecorator\n";
    }
};

class ScrollDecorator : public Decorator
{
public:
    ScrollDecorator(Widget *w) : Decorator(w) {}

    void draw() override
    {
        Decorator::draw();
        std::cout << "  ScrollDecorator\n";
    }
};

int main()
{
    Widget *decorated = new BorderDecorator(new BorderDecorator(
        new ScrollDecorator(new TextField(25, 25))));

    decorated->draw();
}