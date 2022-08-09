#include <iostream>

using std::cout;

class BasicPhone
{
public:
    BasicPhone(uint16_t batCap, uint16_t ram)
    {
        this->batteryCapacity = batCap;
        this->ramSize = ram;
    }

    void showMobilePhoneSpecifications()
    {
        cout << "Mobile Phone Specifications:\n";
        cout << "Phone Type: Basic Phone\nBattery Capacity: " << this->batteryCapacity
             << "mAh\nRAM Size: " << this->ramSize << "GB\n";
    }

private:
    uint16_t batteryCapacity;
    uint16_t ramSize;
};

class SmartPhone
{
public:
    SmartPhone(uint16_t batCap, uint16_t ram)
    {
        this->batteryCapacity = batCap;
        this->ramSize = ram;
    }

    void showMobilePhoneSpecifications()
    {
        cout << "Mobile Phone Specifications:\n";
        cout << "Phone Type: Smart Phone\nBattery Capacity: " << this->batteryCapacity
             << "mAh\nRAM Size: " << this->ramSize << "GB\n";
    }

private:
    uint16_t batteryCapacity;
    uint16_t ramSize;
};

int main()
{
    BasicPhone objBasicPhone(2000, 2);
    SmartPhone objSmartPhone(4000, 6);

    objBasicPhone.showMobilePhoneSpecifications();
    cout << "\n";
    objSmartPhone.showMobilePhoneSpecifications();
}