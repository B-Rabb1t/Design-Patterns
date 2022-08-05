#include <iostream>

using namespace std;

/**
 * This is an abstract class that defines the skeleton
 * of the algorithms that the concrete classes can inherit
 */
class FruitDrink
{
public:
    // Template function
    void prepareFruitDrink()
    {
        peel();
        cutInPieces();
        addToMixerGrinder();
        addCondiments();
        startMixerGrinder();
        stopMixerGrinder();
    }

    virtual ~FruitDrink() {}

protected:
    // Compulsory functions
    virtual void peel() const = 0;
    virtual void cutInPieces() const = 0;
    virtual void addToMixerGrinder() const = 0;
    virtual void startMixerGrinder() const = 0;
    virtual void stopMixerGrinder() const = 0;

    // Optional hook function
    virtual void addCondiments() const {};
};

/**
 * Concrete classes inheriting abstract class FruitDrink
 * They will implement all the compulsory functions (pure virtual)
 * as well as the optional hook functions
 */
class OrangeJuice : public FruitDrink
{
protected:
    void peel() const
    {
        cout << "Peeling orange\n";
    }

    void cutInPieces() const
    {
        cout << "Cutting orange in pieces\n";
    }

    void addToMixerGrinder() const
    {
        cout << "Adding orange pieces to mixer grinder\n";
    }

    void startMixerGrinder() const
    {
        cout << "Starting mixer grinder\n";
    }

    void stopMixerGrinder() const
    {
        cout << "Stopping mixer grinder\n";
    }
};

class BananaMilkShake : public FruitDrink
{
protected:
    void peel() const
    {
        cout << "Peeling banana\n";
    }

    void cutInPieces() const
    {
        cout << "Cutting banana in pieces\n";
    }

    void addToMixerGrinder() const
    {
        cout << "Adding banana pieces to mixer grinder\n";
    }

    void addCondiments() const
    {
        cout << "Adding milk and sugar\n";
    }

    void startMixerGrinder() const
    {
        cout << "Starting mixer grinder\n";
    }

    void stopMixerGrinder() const
    {
        cout << "Stopping mixer grinder\n";
    }
};

int main(void)
{
    FruitDrink *objFruitDrink = new OrangeJuice();
    objFruitDrink->prepareFruitDrink();
    delete objFruitDrink;

    cout << "\n";

    objFruitDrink = new BananaMilkShake();
    objFruitDrink->prepareFruitDrink();
    delete objFruitDrink;

    return 0;
}