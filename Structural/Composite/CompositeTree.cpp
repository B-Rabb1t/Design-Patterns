#include <iostream>
#include <vector>

class Component
{
public:
    virtual void traverse() = 0;
};

class Leaf : public Component
{
    int value;

public:
    Leaf(int val) : value(val){};

    void traverse() override
    {
        std::cout << value << " ";
    }
};

class Composite : public Component
{
    std::vector<Component *> children;

public:
    void add(Component *element)
    {
        children.push_back(element);
    }

    void traverse() override
    {
        for (auto leaf : children)
            leaf->traverse();
    }
};

int main()
{
    std::vector<Composite> containers{4};

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            containers[i].add(new Leaf(i * 3 + j));

    for (int i = 1; i < 4; i++)
        containers[0].add(&containers[i]);

    for (auto branch : containers)
    {
        branch.traverse();
        std::cout << std::endl;
    }
}