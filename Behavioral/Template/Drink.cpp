#include <iostream>

using std::cout;

class OrangeJuice
{
public:
    void prepareOrangeJuice()
    {
        peelOrange();
        cutInPieces();
        addToMixerGrinder();
        startMixerGrinder();
        stopMixerGrinder();
    }

    void peelOrange()
    {
        cout << "Peeling orange\n";
    }

    void cutInPieces()
    {
        cout << "Cutting orange in pieces\n";
    }

    void addToMixerGrinder()
    {
        cout << "Adding orange pieces to mixer grinder\n";
    }

    void startMixerGrinder()
    {
        cout << "Starting mixer grinder\n";
    }

    void stopMixerGrinder()
    {
        cout << "Stopping mixer grinder\n";
    }
};

class BananaMilkShake
{
public:
    void prepareBananaMilkShake()
    {
        peelBanana();
        cutInPieces();
        addToMixerGrinder();
        addMilkAndSugar();
        startMixerGrinder();
        stopMixerGrinder();
    }

    void peelBanana()
    {
        cout << "Peeling banana\n";
    }

    void cutInPieces()
    {
        cout << "Cutting banana in pieces\n";
    }

    void addToMixerGrinder()
    {
        cout << "Adding banana pieces to mixer grinder\n";
    }

    void addMilkAndSugar()
    {
        cout << "Adding milk and sugar\n";
    }

    void startMixerGrinder()
    {
        cout << "Starting mixer grinder\n";
    }

    void stopMixerGrinder()
    {
        cout << "Stopping mixer grinder\n";
    }
};

int main(void)
{
    OrangeJuice objOrangeJuice;
    BananaMilkShake objBananaMilkShake;

    objOrangeJuice.prepareOrangeJuice();
    objBananaMilkShake.prepareBananaMilkShake();

    return 0;
}