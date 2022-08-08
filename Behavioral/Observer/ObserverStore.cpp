#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;

#define TOTAL_GROCERY_ITEMS 5

struct GroceryItem
{
    string itemName;
    bool available;
};

// GroceryItem groceryItems[TOTAL_GROCERY_ITEMS];
std::vector<GroceryItem> groceryItems(TOTAL_GROCERY_ITEMS);

// This is an interface class for Customer (Subscriber) class
class Subscriber
{
public:
    virtual ~Subscriber(){};
    virtual void update(const string &message_from_subject) = 0;
};

// This is an interface class for GroceryStore (Publisher/Publisher) class
class Publisher
{
public:
    virtual ~Publisher(){};
    virtual void subscribe(Subscriber *observer) = 0;
    virtual void unsubscribe(Subscriber *observer) = 0;
    virtual void notify(string msg) = 0;
};

/**
 * GroceryStore is the Publisher/Publisher here that owns some important
 * state and notifies subscribers (i.e. customers) when the state changes.
 */
class GroceryStore : public Publisher
{
private:
    // elements in the Vector are stored in contiguous memory locations
    // also: vector brings more fun
    std::vector<Subscriber *> subscribers;

public:
    GroceryStore(std::vector<GroceryItem> grocery)
    {
        groceryItems = grocery;
    }

    virtual ~GroceryStore()
    {
        cout << "Goodbye, I was the Publisher.\n";
    }

    void subscribe(Subscriber *observer)
    {
        cout << "An observer has subscribed\n";
        subscribers.push_back(observer);
    }

    void unsubscribe(Subscriber *observer)
    {
        cout << "A customer has unsubscribed\n";
        subscribers.erase(find(begin(subscribers), end(subscribers), observer));
    }

    void notify(string msg)
    {
        for (auto subscriber : subscribers)
        {
            cout << "GroceryStore is sending an update to the customer\n";
            subscriber->update(msg);
        }
    }

    void refillInventory(string itemName)
    {
        auto refilled = find_if(begin(groceryItems), end(groceryItems), [&](GroceryItem item)
                                { return item.itemName == itemName; });

        if (refilled != end(groceryItems))
        {
            refilled->available = true;
            cout << "Refilling the stock for item " << itemName << "\n";
            notify(("Item " + itemName + " has been refilled in the Grocery Store"));
        }
    }
};

class Customer : public Subscriber
{
private:
    GroceryStore &subject_;

public:
    Customer(GroceryStore &subject) : subject_(subject)
    {
        this->subject_.subscribe(this);
    }

    virtual ~Customer()
    {
        cout << "Goodbye, I was the Subscriber.\n";
    }

    void update(const string &msg)
    {
        cout << "Hey customer! A new message is available --> " << msg << "\n";
    }

    void unsubscribeCustomer()
    {
        cout << "Customer wants to unsubscribe the Grocery Store notifications - ";
        subject_.unsubscribe(this);
    }

    bool purchaseItem(string itemName)
    {
        cout << "Customer wants to purchase item " << itemName << " - ";

        auto purchased = find_if(begin(groceryItems), end(groceryItems), [&](GroceryItem item)
                                 { return item.itemName == itemName && item.available; });

        if (purchased != end(groceryItems))
        {
            cout << "Item " << itemName << " is available\n";
            return true;
        }

        cout << "The item " << itemName << " is not available in the Grocery Store\n";
        return false;
    }
};

int main()
{
    std::vector<GroceryItem> itemList = {{"Flour", true}, {"Rice", true}, {"Brown Bread", false}, {"Blueberry Syrup", false}, {"Detergent", true}};
    GroceryStore objGs(itemList);
    Customer objCust(objGs);

    objCust.purchaseItem("Detergent");
    objCust.purchaseItem("Flour");
    objCust.purchaseItem("Rice");
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
    cout << "\n";
    objGs.refillInventory("Brown Bread");
    objCust.purchaseItem("Brown Bread");
    objCust.unsubscribeCustomer();
    cout << "\n";
    objGs.refillInventory("Blueberry Syrup");
}