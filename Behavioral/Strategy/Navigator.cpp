#include <iostream>

using std::cout;
using std::string;

class MapNavigator
{
public:
    void findRouteByCar(string origin, string destination)
    {
        cout << "Map shows route for a car drive\n";
    }

    void findRouteByBus(string origin, string destination)
    {
        cout << "Map shows route for a bus ride\n";
    }

    void findRouteByWalk(string origin, string destination)
    {
        cout << "Map shows route for a walk\n";
    }
};

int main()
{
    MapNavigator objMap;

    objMap.findRouteByCar("home", "airport");
    objMap.findRouteByBus("home", "airport");
    objMap.findRouteByWalk("home", "airport");
}