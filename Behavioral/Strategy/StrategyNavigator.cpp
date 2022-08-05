#include <iostream>

using std::cout;
using std::string;

/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */
class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void findRoute(string origin, string destination) const = 0;
};

/**
 * The Context defines the interface of interest to clients.
 */
class Context
{
    /**
     * The Context maintains a reference to one of the Strategy objects.
     * The Context does not know the concrete class of a strategy. It
     * should work with all strategies via the Strategy interface.
     */
private:
    Strategy *strategy_;
    /**
     * Usually, the Context accepts a strategy through the constructor, but also
     * provides a setter to change it at runtime.
     */
public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy) {}
    ~Context()
    {
        delete this->strategy_;
    }

    /**
     * Usually, the Context allows replacing a Strategy object at runtime.
     */
    void setStrategy(Strategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing multiple versions of the algorithm on its own.
     */
    void showMeRoute(string source, string destination) const
    {
        cout << "Context: Need to show an appropriate route. I don't know how to do it though\n";
        this->strategy_->findRoute(source, destination);
    }
};

/**
 * Concrete Strategies implement the algorithm while following the base Strategy
 * interface. The interface makes them interchangeable in the Context.
 */
class ConcreteStrategyCarRoute : public Strategy
{
public:
    void findRoute(string source, string destination) const
    {
        cout << "Map shows route for a car drive\n";
    }
};

class ConcreteStrategyBusRoute : public Strategy
{
    void findRoute(string source, string destination) const
    {
        cout << "Map shows route for a bus ride\n";
    }
};

class ConcreteStrategyWalkRoute : public Strategy
{
    void findRoute(string source, string destination) const
    {
        cout << "Map shows route for a walk\n";
    }
};

/**
 * main() function is our client here. The client picks a concrete strategy and passes it to the context.
 * The client should be aware of the differences between strategies in order to make the right choice.
 */
int main()
{
    Context context(new ConcreteStrategyCarRoute);
    cout << "Client is setting Strategy to Car Route\n";
    context.showMeRoute("home", "airport");
    cout << "\n";
    cout << "Client is setting Strategy to Bus Route\n";
    context.setStrategy(new ConcreteStrategyBusRoute);
    context.showMeRoute("home", "airport");
    cout << "\n";
    cout << "Client is setting Strategy to Walk Route\n";
    context.setStrategy(new ConcreteStrategyWalkRoute);
    context.showMeRoute("home", "airport");

    return 0;
}