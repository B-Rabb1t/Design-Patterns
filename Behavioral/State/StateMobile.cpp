#include <iostream>
#include <typeinfo>

using std::cout;

class ContextMobile;

/**
 * The base State class declares functions that all Concrete States should
 * implement.
 * It also provides a backreference to the ContextMobile object, associated
 * with the State.
 * This backreference can be used by States to transition the ContextMobile
 * to another State.
 */
class State
{
protected:
    ContextMobile *context;

public:
    //Why virtual?
    virtual ~State() {}

    void setContext(ContextMobile *context) 
    {
        this->context = context;
    }

    virtual void playRingTone() = 0;
    virtual void toggleSilentMode() = 0;
};

/**
 * The ContextMobile defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the ContextMobile.
 */
class ContextMobile
{
    /**
     * state is a reference to the current state of the ContextMobile.
     */
private:
    State *state;

public:
    ContextMobile(State *state) : state(nullptr)
    {
        this->TransitionTo(state);
    }

    ~ContextMobile()
    {
        delete state;
    }

    /**
     * The ContextMobile allows changing the State object at runtime.
     */
    void TransitionTo(State *stateTrans)
    {
        cout << "Context: Transition to " << typeid(*stateTrans).name() << ".\n";

        delete this->state;
        this->state = stateTrans;
        //What's the purpose of this?
        this->state->setContext(this);
    }

    /**
     * The ContextMobile delegates part of its behavior to the current State object.
     */
    void reqPlayRingTone()
    {
        this->state->playRingTone();
    }

    void reqToggleSilentMode()
    {
        this->state->toggleSilentMode();
    }
};

/**
 * ConcreteStateSilent and ConcreteStateSwitchedOn are the Concrete States
 * that implement various behaviors, associated with a state of the
 * ContextMobile.
 */

class ConcreteStateSilent : public State
{
public:
    void playRingTone()
    {
        cout << "Mobile is in a Silent state. So, it can't playing a ring tone\n";        
    }

    void toggleSilentMode(); 
};

class ConcreteStateSwitchedOn : public State
{
public:
    void playRingTone()
    {
        cout << "Mobile is in a SwitchedOn state and is playing a ring tone now\n";
    }

    void toggleSilentMode()
    {
        cout << "Mobile is in a SwitchedOn state and is turning the Silent Mode On\n";
        this->context->TransitionTo(new ConcreteStateSilent);
    }
};

void ConcreteStateSilent::toggleSilentMode()
{
    cout << "Mobile is in a Silent state and is turning the Silent Mode Off\n";
    this->context->TransitionTo(new ConcreteStateSwitchedOn);
}

int main()
{
    ContextMobile contextSwitchOn(new ConcreteStateSwitchedOn);
    contextSwitchOn.reqPlayRingTone();
    contextSwitchOn.reqToggleSilentMode();
    contextSwitchOn.reqPlayRingTone();
    contextSwitchOn.reqToggleSilentMode();

    return 0;
}