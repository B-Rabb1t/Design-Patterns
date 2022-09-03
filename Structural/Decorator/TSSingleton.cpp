#include <iostream>
#include <thread>
#include <mutex>

class Singleton
{
    static Singleton *sinstance;
    static std::mutex mutex;

protected:
    Singleton(const std::string value) : value(value) {}
    virtual ~Singleton() = default;
    std::string value;

    public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;
    static Singleton *GetInstance(const std::string& value);
    std::string GetValue() const
    {
        return value;
    }
};

Singleton* Singleton::sinstance{nullptr};
std::mutex Singleton::mutex;

Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex);
    if(!sinstance)
        sinstance = new Singleton(value);
    return sinstance;
}

void ThreadFoo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Singleton* singleton = Singleton::GetInstance("Foo");
    std::cout << singleton->GetValue() << "\n";
}
void ThreadBar()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Singleton* singleton = Singleton::GetInstance("Bar");
    std::cout << singleton->GetValue() << "\n";
}

int main()
{
    std::cout << "Singleton was used if the printed values are the same.\n";
    std::thread foo(ThreadFoo);
    std::thread bar(ThreadBar);
    foo.join();
    bar.join();
}