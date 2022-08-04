#include <iostream>

using std::cout;

#define STATE_SWITCHED_ON 0
#define STATE_SILENT      1

class Mobile
{
private:
    uint8_t state;
    
public:
    Mobile()
    {
        this->state = STATE_SWITCHED_ON;
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

void reqPlayRingTone(Mobile& objMobile)
{
    if (objMobile.getState() == STATE_SWITCHED_ON)
    {
        cout << "Mobile is in a SwitchedOn state and is playing a ring tone now\n";
    } 
    else if (objMobile.getState() == STATE_SILENT)
    {
        cout << "Mobile is in a Silent state and is turning the Silent Mode Off\n";
    }
}

void reqToggleSilentMode(Mobile& objMobile)
{
    if (objMobile.getState() == STATE_SWITCHED_ON)
    {
        cout << "Mobile is in a SwitchedOn state and is turning the Silent Mode On\n";
        objMobile.setState(STATE_SILENT);
    } 
    else if (objMobile.getState() == STATE_SILENT)
    {
        cout << "Mobile is in a Silent state and is turning the Silent Mode Off\n";
        objMobile.setState(STATE_SWITCHED_ON);
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