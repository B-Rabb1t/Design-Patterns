#include <iostream>

using std::cout;

class Bank
{
private:
    uint32_t accountBalance;

public:
    Bank(uint32_t openingBalance)
    {
        this->accountBalance = openingBalance;
    }

    bool debitMoney(uint32_t amount)
    {
        cout << "Bank Object has received debitMoney request for amount " << amount << "\n";
        if ((amount > this->accountBalance) || (amount == 0))
        {
            cout << "Sorry, the debit transaction wasn't suffessful\n";
            return false;
        }
        this->accountBalance -= amount;
        return true;
    }

    void getBalance()
    {
        cout << "Balance available in the account is: " << this->accountBalance << "\n";
    }
};

int main(void)
{
    Bank objBank(5000);
    objBank.debitMoney(3000);
    objBank.getBalance();
}