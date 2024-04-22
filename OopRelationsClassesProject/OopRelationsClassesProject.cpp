#include <iostream>

class Flat
{
public:
    Flat()
    {
        std::cout << this << " Flat constract\n";
    }

    ~Flat()
    {
        std::cout << "Flat destruct\n";
    }
};

class House
{
    class Window
    {

    };
    Window window;
    Flat flat;
public:
    House()
    {
        std::cout << this << " House constract\n";
    }

    ~House()
    {
        std::cout << "House destruct\n";
    }
};


class Driver
{
    std::string name;
public:
    Driver(std::string name = "Anonim") : name{ name }
    {
        std::cout << this << " Driver constract\n";
    }

    ~Driver()
    {
        std::cout << "Driver destruct\n";
    }

    std::string& Name() { return name; }
};

class Taxi
{
    Driver* driver;
public:
    Taxi(Driver* driver = nullptr) : driver{ driver }
    {
        std::cout << this << " Taxi constract\n";
    }

    ~Taxi()
    {
        std::cout << "Taxi destruct\n";
    }

    std::string DriverName()
    {
        return "Driver " + driver->Name();
    }

    Driver*& Driver() { return driver; }
};


int main()
{
    //House house;

    Driver bob("Bobby");
    Driver tom("Tommy");

    Taxi taxi1(&bob);
    Taxi taxi2(&tom);

    std::cout << taxi1.DriverName() << "\n";
    std::cout << taxi2.DriverName() << "\n";

    taxi1.Driver() = &tom;
    taxi2.Driver() = &bob;

    std::cout << taxi1.DriverName() << "\n";
    std::cout << taxi2.DriverName() << "\n";
}
