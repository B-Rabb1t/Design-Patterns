#include <iostream>
#include <vector>

using std::cout;

/**
 * The Visitor Interface declares a set of visiting methods that correspond to
 * component classes.
 */
class BasicPhone;
class SmartPhone;

class MobileVisitor
{
public:
    virtual void visitBasicPhone(const BasicPhone *element) const = 0;
    virtual void visitSmartPhone(const SmartPhone *element) const = 0;
};

/**
 * The Component interface declares an "accept" function that should take the base
 * visitor interface as an argument.
 */
class MobileComponent
{
public:
    virtual ~MobileComponent() {}
    virtual void accept(MobileVisitor *visitor) const = 0;
};

/**
 * Each Concrete Component must implement the `accept` function in such a way that
 * it calls the visitor's function corresponding to the component's class.
 */
class BasicPhone : public MobileComponent
{
public:
    BasicPhone(uint16_t batCap, uint16_t ram)
    {
        this->batteryCapacity = batCap;
        this->ramSize = ram;
    }

    void accept(MobileVisitor *visitor) const
    {
        visitor->visitBasicPhone(this);
    }

    /**
     * Concrete Components may have special methods that don't exist in their base
     * class or interface. The Visitor is still able to use these methods since
     * it's aware of the component's concrete class.
     */
    uint16_t getBasicPhoneBatteryCapacity() const
    {
        return this->batteryCapacity;
    }

    uint16_t getBasicPhoneRamSize() const
    {
        return this->ramSize;
    }

private:
    uint16_t batteryCapacity;
    uint16_t ramSize;
};

class SmartPhone : public MobileComponent
{
public:
    SmartPhone(uint16_t batCap, uint16_t ram)
    {
        this->batteryCapacity = batCap;
        this->ramSize = ram;
    }

    void accept(MobileVisitor *visitor) const
    {
        visitor->visitSmartPhone(this);
    }

    /**
     * Concrete Components may have special methods that don't exist in their base
     * class or interface. The Visitor is still able to use these methods since
     * it's aware of the component's concrete class.
     */
    uint16_t getSmartPhoneBatteryCapacity() const
    {
        return this->batteryCapacity;
    }

    uint16_t getSmartPhoneRamSize() const
    {
        return this->ramSize;
    }

private:
    uint16_t batteryCapacity;
    uint16_t ramSize;
};

/**
 * Concrete Visitors implement several versions of the same algorithm, which can
 * work with all concrete component classes.
 *
 * We can experience the biggest benefit of the Visitor pattern when using it
 * with a complex object structure, such as a Composite tree. In this case, it
 * might be helpful to store some intermediate state of the algorithm while
 * executing visitor's methods over various objects of the structure.
 */
class MobileVisitorImpl : public MobileVisitor
{
public:
    void visitBasicPhone(const BasicPhone *element) const
    {
        cout << "Mobile Phone Specifications:\n";
        cout << "Phone Type: Basic Phone\nBattery Capacity: " << element->getBasicPhoneBatteryCapacity()
             << "mAh\nRAM Size: " << element->getBasicPhoneRamSize() << "GB\n";
    }

    void visitSmartPhone(const SmartPhone *element) const
    {
        cout << "Mobile Phone Specifications:\n";
        cout << "Phone Type: Smart Phone\nBattery Capacity: " << element->getSmartPhoneBatteryCapacity()
             << "mAh\nRAM Size: " << element->getSmartPhoneRamSize() << "GB\n";
    }
};

int main()
{
    std::vector<MobileComponent *> mobilePhones = {new BasicPhone(2000, 2), new SmartPhone(4000, 6)};
    MobileVisitorImpl *visitor = new MobileVisitorImpl;

    for (auto phone : mobilePhones)
    {
        phone->accept(visitor);
        cout << "\n";
        // delete phone;
    }

    delete visitor;
}