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

class BirdAdapter : public ToyDuck
{
    Bird *bird;

public:
    BirdAdapter(Bird *bird) : bird(bird) {}

    void squeak() override
    {
        bird->makeSound();
    }
};

int main()
{
    Sparrow* sparrow = new Sparrow();
    PlasticToyDuck* toyduck = new PlasticToyDuck();

    ToyDuck* birdApdater = new BirdAdapter(sparrow);

    std::cout << "Sparrow:\n";
    sparrow->fly();
    sparrow->makeSound();

    std::cout << "Toy duck:\n";
    toyduck->squeak();

    std::cout << "Bird adapter:\n";
    birdApdater->squeak();

    delete birdApdater;
    delete toyduck;
    delete sparrow;
}