#include <iostream>

class Bird
{
public:
    virtual void fly() = 0;
    virtual void makeSound() = 0;
    virtual ~Bird() = default;
};

class Sparrow : public Bird
{
public:
    void fly() override
    {
        std::cout << "Flying\n";
    }

    void makeSound() override
    {
        std::cout << "Chirp Chirp\n";
    }
};

class ToyDuck
{
public:
    virtual void squeak() = 0;
    virtual ~ToyDuck() = default;
};

class PlasticToyDuck : public ToyDuck
{
public:
    void squeak() override
    {
        std::cout << "Squeak\n";
    }
};

class BirdAdapter : public ToyDuck, Sparrow
{
public:
    void squeak() override
    {
        makeSound();
    }
};

int main()
{
    Sparrow sparrow;
    PlasticToyDuck toyduck;

    BirdAdapter birdApdater;

    std::cout << "Sparrow:\n";
    sparrow.fly();
    sparrow.makeSound();

    std::cout << "Toy duck:\n";
    toyduck.squeak();

    std::cout << "Bird adapter:\n";
    birdApdater.squeak();
}