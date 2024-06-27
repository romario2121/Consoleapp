#include <iostream>
#include <string>
using namespace std;


class Vehicle
{
public:

    virtual string getType() const = 0;
    virtual int getNumPlace() const = 0;
    virtual ~Vehicle() {}
};


class Car : public Vehicle 

{
private:
    int numPlace;
public:

   
    Car(int seats) : numPlace(seats) {}


    string getType() const override 
    {
        return "Car";
    }


    int getNumPlace() const override
    {
        return numPlace;
    }
};


class Bus : public Vehicle 
{
private:
    int numPlace;
public:
 
    Bus(int seats ) : numPlace(seats) {}

 
    string getType() const override
    {
        return "Bus";
    }

   
    int getNumPlace() const override
    {
        return numPlace;
    }
};


int main()
{
  
    Car car(7);  
    Bus bus(25); 

    cout << "Type  car: " << car.getType() << endl;
    cout << "Number  seats in car: " << car.getNumPlace() << endl;

    cout << "Type bus: " << bus.getType() << endl;
    cout << "Number seats in bus: " << bus.getNumPlace() << endl;

    return 0;
}
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
public:
    virtual string getType() const = 0;
    virtual int getNumPlace() const = 0;
    virtual ~Vehicle() {}
};


class Car : public Vehicle

{
protected:
    int numPlace;  
public:
    Car(int seats) : numPlace(seats) {}

  
    string getType() const override
    {
        return "Car";
    }


    int getNumPlace() const override
    {
        return numPlace;
    }

    
    virtual string getAdditionalInfo() const
    {
        return "Universal Car";
    }
};


class SportsCar : public Car
{
public:
    SportsCar(int seats) : Car(seats) {}

    string getType() const override 
    {
        return "Sports Car";
    }

    
    int getNumPlace() const override 
    {
        return Car::getNumPlace();
    }

    string getAdditionalInfo() const override 
    {
        return "Sports Car specific ";
    }
};


class Wagon : public Car
{
public:
    Wagon(int seats) : Car(seats) {}

    string getType() const override 
    {
        return "Wagon";
    }

    int getNumPlace() const override 
    {
        return Car::getNumPlace();
    }

    string getAdditionalInfo() const override 
    {
        return "Wagon specific ";
    }
};


class Coupe : public Car 
{
public:
    Coupe(int seats) : Car(seats) {}


    string getType() const override
    {
        return "Coupe";
    }

    int getNumPlace() const override 
    {
        return Car::getNumPlace();
    }

    string getAdditionalInfo() const override 
    {
        return "Coupe specific ";
    }
};

int main() 
{
   
    SportsCar sportsCar(2);
    Wagon wagon(8);
    Coupe coupe(2);

    cout << "Type of sports car: " << sportsCar.getType() << endl;
    cout << "Number of seats in sports car: " << sportsCar.getNumPlace() << endl;
    cout << "Additional info: " << sportsCar.getAdditionalInfo() << endl;

    cout << "Type of wagon: " << wagon.getType() << endl;
    cout << "Number of seats in wagon: " << wagon.getNumPlace() << endl;
    cout << "Additional info: " << wagon.getAdditionalInfo() << endl;

    cout << "Type of coupe: " << coupe.getType() << endl;
    cout << "Number of seats in coupe: " << coupe.getNumPlace() << endl;
    cout << "Additional info: " << coupe.getAdditionalInfo() << endl;

    return 0;
}
///////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class AClass 
{
private:
    int Variable;  
    static int staticVariable;  

public:
    
    AClass(int value) : Variable(value)
    {
        staticVariable++;  
    }
    ~AClass() 
    {
        staticVariable--;  
    }

    static int getStaticVariable() 
    {
        return staticVariable;
    }

    int getVariable() 
    
    {
        return Variable;
    }
};

int AClass::staticVariable = 0;

int main() 
{

    AClass A1(23);
    AClass B2(33);

    cout << "A1 Variable: " << A1.getVariable() << endl;
    cout << "B2 Variable: " << B2.getVariable() << endl;
    cout << "Static variable: " << AClass::getStaticVariable() << endl;

    return 0;
}
