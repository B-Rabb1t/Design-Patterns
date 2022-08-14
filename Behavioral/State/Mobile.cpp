#include <iostream>

using std::cout;

struct States
{
    static const int SWITCHED_ON = 0;
    static const int SILENT = 0;
};

class Mobile
{
private:
    uint8_t state;

public:
    Mobile()
    {
        this->state = States::SWITCHED_ON;
    }

    uint8_t getState()
    {
        return state;
    }

    void setState(uint8_t stateTrans)
    {
        this->state = stateTrans;
    }
};

void reqPlayRingTone(Mobile &objMobile)
{
    if (objMobile.getState() == States::SWITCHED_ON)
    {
        cout << "Mobile is in a SwitchedOn state and is playing a ring tone now\n";
    }
    else if (objMobile.getState() == States::SILENT)
    {
        cout << "Mobile is in a Silent state and is turning the Silent Mode Off\n";
    }
}

void reqToggleSilentMode(Mobile &objMobile)
{
    if (objMobile.getState() == States::SWITCHED_ON)
    {
        cout << "Mobile is in a SwitchedOn state and is turning the Silent Mode On\n";
        objMobile.setState(States::SILENT);
    }
    else if (objMobile.getState() == States::SILENT)
    {
        cout << "Mobile is in a Silent state and is turning the Silent Mode Off\n";
        objMobile.setState(States::SWITCHED_ON);
    }
}

int main()
{
    Mobile objMobile;
    reqPlayRingTone(objMobile);
    reqToggleSilentMode(objMobile);
    reqPlayRingTone(objMobile);
    reqToggleSilentMode(objMobile);

    return 0;
}