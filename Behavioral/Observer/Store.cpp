#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;

const int TOTAL_GROCERY_ITEMS = 5;

struct GroceryItem
{
    string itemName;
    bool available;
};

std::vector<GroceryItem> groceryItems(TOTAL_GROCERY_ITEMS);

class GroceryStore
{
public:
    GroceryStore(std::vector<GroceryItem> grocery)
    {
        groceryItems = grocery;
    }

    void refillInventory(string itemName)
    {
        auto refilled = find_if(begin(groceryItems), end(groceryItems), [itemName](GroceryItem item)
                                { return item.itemName == itemName; });

        if (refilled != end(groceryItems))
        {
            refilled->available = true;
            cout << "Item " << itemName << " has been refilled in the Grocery Store\n";
        }
    }
};

class Customer
{
public:
    bool purchaseItem(string itemName)
    {
        auto purchased = find_if(begin(groceryItems), end(groceryItems), [itemName](GroceryItem item)
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

int main(void) 
{ 
    std::vector<GroceryItem> itemList = {{"Flour", true}, {"Rice", true}, {"Brown Bread", false}, \
                              {"Blueberry Syrup", false}, {"Detergent", true}};
    GroceryStore objGs(itemList);
    Customer objCust;

    objCust.purchaseItem("Detergent");
    objCust.purchaseItem("Flour");
    objCust.purchaseItem("Rice");
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
    cout << "\n";
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
    cout << "\n";
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
    cout << "\n";
    objGs.refillInventory("Brown Bread");
    objGs.refillInventory("Blueberry Syrup");
    cout << "\n";
    objCust.purchaseItem("Brown Bread");
    objCust.purchaseItem("Blueberry Syrup");
}