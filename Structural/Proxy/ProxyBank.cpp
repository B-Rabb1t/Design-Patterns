#include <iostream>

using std::cout;

class BankService
{
public:
    virtual bool debitMoney(uint32_t amount) = 0;
    virtual ~BankService() {}
};

// Real object - Bank
class Bank : public BankService
{
private:
    uint32_t accountBalance;

public:
    Bank(uint32_t openingBalance)
    {
        this->accountBalance = openingBalance;
    }

    //The copy constructor was implemented to be
    //able to check which constructor was used
    Bank(const Bank &account)
    {
        this->accountBalance = account.accountBalance;
        cout << "Prins la copiat!\n";
    }

    bool debitMoney(uint32_t amount)
    {
        cout << "Real Bank Object has received debitMoney request for amount " << amount << "\n";
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

// Proxy object for Bank
class DebitCard : public BankService
{
private:
    Bank *objRealBank;

    bool verifyAccess()
    {
        cout << "Access to the Bank granted\n";
        return true;
    }

    void logAccess()
    {
        cout << "log: Debit request received\n";
    }

public:
    //Uses the copy constructor of the Bank class
    DebitCard(Bank *objBank) : objRealBank(new Bank(*objBank)) {}

    bool debitMoney(uint32_t amount)
    {
        cout << "Proxy DebitCard object has received debitMoney request\n";
        if (this->verifyAccess())
        {
            this->objRealBank->debitMoney(amount);
            this->logAccess();
            return true;
        }
        else
        {
            cout << "RealBank object access denied\n";
            return false;
        }
    }

    ~DebitCard()
    {
        delete objRealBank;
    }
};

void clientRequest(BankService &clientReq, uint32_t depositAmount)
{
    if (clientReq.debitMoney(depositAmount))
    {
        cout << "Debit money operation was successful\n";
    }
}

int main(void)
{
    cout << "Client: Executing the client request with a real bank object\n";
    Bank *objBank = new Bank(5000);
    clientRequest(*objBank, 2000);

    cout << "\n";

    cout << "Client: Executing the same client request with a proxy debit card object\n";
    DebitCard *proxyDebitCard = new DebitCard(objBank);
    clientRequest(*proxyDebitCard, 1000);

    delete objBank;
    delete proxyDebitCard;
}