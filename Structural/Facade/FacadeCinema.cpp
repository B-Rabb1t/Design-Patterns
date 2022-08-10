#include <iostream>
#include <string>

using std::cout;

class Microwave
{
public:
    void start()
    {
        cout << "Microwave is started\n";
    }

    void stop()
    {
        cout << "Microwave is stopped\n";
    }

    void preparePopcorn()
    {
        cout << "Preparing popcorn\n";
    }
};

class Light
{
public:
    void switchOn()
    {
        cout << "Microwave is started\n";
    }

    void switchOff()
    {
        cout << "Microwave is stopped\n";
    }

    void changeBrightness()
    {
        cout << "Changing brighness of the lights\n";
    }
};

class Television
{
public:
    void turnOn()
    {
        cout << "Television is started\n";
    }

    void turnOff()
    {
        cout << "Television is stopped\n";
    }

    void selectHdmiPort()
    {
        cout << "Selecting HDMI port\n";
    }
};

class Recliner
{
public:
    void adjustRecliner()
    {
        cout << "Recliner is adjusted\n";
    }
};

class Amplifier
{
public:
    void turnOn()
    {
        cout << "Amplifier is turned on\n";
    }

    void turnOff()
    {
        cout << "Amplifier is turned off\n";
    }

    void adjustVolume()
    {
        cout << "Adjusted amplifier volume\n";
    }

    void enableSurroundSound()
    {
        cout << "Surround sound effect is enabled\n";
    }

    void disableSurroundSound()
    {
        cout << "Surround sound effect is disabled\n";
    }
};

class MovieStreamingPlatform
{
public:
    std::string menu[10];

    void selectMovie()
    {
        cout << "Movie is selected\n";
    }

    void playMovie()
    {
        cout << "Movie has started\n";
    }

    void stopMovie()
    {
        cout << "Movie has been stopped\n";
    }
};

class AirConditioner
{
public:
    void startAC()
    {
        cout << "AC has started\n";
    }

    void stopAC()
    {
        cout << "AS has stopped\n";
    }

    void changeAcTemp()
    {
        cout << "AC temperature has changed\n";
    }
};

class MovieFacade
{
private:
    Microwave mwObj;
    Light lightObj;
    Television tvObj;
    Recliner recObj;
    Amplifier ampObj;
    MovieStreamingPlatform mspObj;
    AirConditioner acObj;

public:
    MovieFacade(Microwave mwObj,
                Light lightObj,
                Television tvObj,
                Recliner recObj,
                Amplifier ampObj,
                MovieStreamingPlatform mspObj,
                AirConditioner acObj)
    {

        this->mwObj = mwObj;
        this->lightObj = lightObj;
        this->tvObj = tvObj;
        this->recObj = recObj;
        this->ampObj = ampObj;
        this->mspObj = mspObj;
        this->acObj = acObj;
    }

    void startMovie()
    {
        cout << "***************************************\n";
        cout << "Start a movie\n";
        cout << "***************************************\n";
        mwObj.start();
        mwObj.preparePopcorn();
        lightObj.switchOn();
        lightObj.changeBrightness();
        acObj.startAC();
        tvObj.turnOn();
        tvObj.selectHdmiPort();
        recObj.adjustRecliner();
        ampObj.turnOn();
        ampObj.adjustVolume();
        ampObj.enableSurroundSound();
        mspObj.selectMovie();
        mspObj.playMovie();
    }

    void stopMovie()
    {
        cout << "***************************************\n";
        cout << "Stop the movie\n";
        cout << "***************************************\n";
        mspObj.stopMovie();
        ampObj.disableSurroundSound();
        ampObj.turnOff();
        recObj.adjustRecliner();
        tvObj.turnOff();
        acObj.stopAC();
        lightObj.changeBrightness();
    }
};

int main(void)
{
    Microwave mwObj;
    Light lightObj;
    Television tvObj;
    Recliner recObj;
    Amplifier ampObj;
    MovieStreamingPlatform mspObj;
    AirConditioner acObj;
    MovieFacade facadeObj(mwObj, lightObj, tvObj, recObj, ampObj, mspObj, acObj);

    cout << "***************************************\n";
    cout << "Welcome to movie watching application\n";
    cout << "***************************************\n\n";

    facadeObj.startMovie();
    facadeObj.stopMovie();
}