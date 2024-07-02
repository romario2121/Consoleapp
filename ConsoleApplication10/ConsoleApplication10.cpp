#include <iostream>
using namespace std;

class MyClass


{
private:
    int regulVariable;
    static int staticVariable;

public:

    MyClass (int value) : regulVariable(value)
    {
        staticVariable++;
    }


    ~MyClass()
    {
        staticVariable--;
    }


    int getRegulVariable()
    {
        return regulVariable;
    }


    static int getStaticVariable()
    {
        return staticVariable;
    }
};


int MyClass::staticVariable = 0;

int main()
{

    MyClass object1(3);
    MyClass object2(5);

    cout << "object1.Variable = " << object1.getRegulVariable() << endl;
    cout << "object2.Variable = " << object2.getRegulVariable() << endl;
    cout << "MyClass-staticVariable = " << MyClass::getStaticVariable() << endl;


    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class MyClass

{

private:

    int regulVariable;
    static int staticVariable;

public:

    MyClass(int value) : regulVariable(value)
    {
        staticVariable++;
    }

    ~MyClass()
    {
        staticVariable--;
    }

    int getRegulVariable()
    {
        return regulVariable;
    }

    static int getStaticVariable()
    {
        return staticVariable;
    }
};


int MyClass::staticVariable = 0;

int main()
{

    MyClass object1(3);
    MyClass object2(5);
    MyClass object3(7);

    cout << "object1.Variable = " << object1.getRegulVariable() << endl;
    cout << "object2.Variable = " << object2.getRegulVariable() << endl;
    cout << "object3.Variable = " << object3.getRegulVariable() << endl;
    cout << "MyClass-staticVariable = " << MyClass::getStaticVariable() << endl;


    cout << "Deleting object1..." << endl;
    cout << "MyClass-staticVariable = " << MyClass::getStaticVariable() << endl;
    cout << "Deleting object2..." << endl;
    cout << "MyClass-staticVariable = " << MyClass::getStaticVariable() << endl;
    cout << "Deleting object3..." << endl;
    cout << "MyClass-staticVariable = " << MyClass::getStaticVariable() << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class MyClass
{
private:
    int ordinaryMember;
    static int staticMember;

public:

    MyClass(int value) : ordinaryMember(value)
    {
        incrementStaticMember();
    }

    ~MyClass()
    {
        decrementStaticMember();
    }

    int getOrdinaryMember() const
    {
        return ordinaryMember;
    }

    static int getStaticMember()
    {
        return staticMember;
    }

private:

    static void incrementStaticMember()
    {
        staticMember++;
    }

    static void decrementStaticMember()
    {
        staticMember--;
    }
};

/// /////////////////////////////////////////////////////////////////////

int MyClass::staticMember = 0;

int main()
{

    MyClass obj1(3);
    MyClass obj2(5);
    MyClass obj3(7);

    cout << "obj1 ordinaryMember: " << obj1.getOrdinaryMember() << endl;
    cout << "obj2 ordinaryMember: " << obj2.getOrdinaryMember() << endl;
    cout << "obj3 ordinaryMember: " << obj3.getOrdinaryMember() << endl;
    cout << "Static member after creation: " << MyClass::getStaticMember() << endl;

    cout << "Deleting obj3..." << endl;
    cout << "Static member after deleting obj3: " << MyClass::getStaticMember() << endl;
    cout << "Deleting obj2..." << endl;
    cout << "Static member after deleting obj2: " << MyClass::getStaticMember() << endl;
    cout << "Deleting obj1..." << endl;
    cout << "Static member after deleting obj1: " << MyClass::getStaticMember() << endl;

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
class MyClass
{
private:
    int ordinaryMember;
    static int staticMember;

public:

    MyClass(int value) : ordinaryMember(value)
    {
        incrementStaticMember();
    }

    ~MyClass()
    {
        decrementStaticMember();
    }

    int getOrdinaryMember() const
    {
        return ordinaryMember;
    }

    static int getStaticMember()
    {
        return staticMember;
    }

    int (MyClass::* getOrdinaryMemberPointer)() const = &MyClass::getOrdinaryMember;

private:
    static void incrementStaticMember()
    {
        staticMember++;
    }

    static void decrementStaticMember()
    {
        staticMember--;
    }
};

int MyClass::staticMember = 0;

int main()
{

    MyClass obj1(3);
    MyClass obj2(5);
    MyClass obj3(7);


    cout << "Using member function pointer:" << std::endl;
    cout << "obj1 ordinaryMember: " << (obj1.*(obj1.getOrdinaryMemberPointer))() << endl;
    cout << "obj2 ordinaryMember: " << (obj2.*(obj2.getOrdinaryMemberPointer))() << endl;
    cout << "obj3 ordinaryMember: " << (obj3.*(obj3.getOrdinaryMemberPointer))() << endl;


    cout << "Static member after creation: " << MyClass::getStaticMember() << std::endl;


   cout << "Deleting obj3..." << std::endl;

    cout << "Static member after deleting obj3: " << MyClass::getStaticMember() << endl;
    cout << "Deleting obj2..." << std::endl;
    cout << "Static member after deleting obj2: " << MyClass::getStaticMember() << endl;
    cout << "Deleting obj1..." << std::endl;
    cout << "Static member after deleting obj1: " << MyClass::getStaticMember() << endl;

    return 0;
}


#include <iostream>
using namespace std;
class MyClass
{
private:
    int regularVariable;       
    static int staticVariable;  
    double doubleVariable;       
    std::string stringVariable;  

public:
   
    MyClass(int intValue, double doubleValue, const std::string& stringValue)
        : regularVariable(intValue), doubleVariable(doubleValue), stringVariable(stringValue) 
    {
        staticVariable++; 
    }

    ~MyClass() {
        staticVariable--; 
    }


    int getRegularVariable() const
    {
        return regularVariable;
    }

   
    static int getStaticVariable() 
    {
        return staticVariable;
    }

  
    double getDoubleVariable() const 
    {
        return doubleVariable;
    }


    std::string getStringVariable() const 
    {
        return stringVariable;
    }

   
    using MemberFunctionPtr = decltype(&MyClass::getRegularVariable);
    MemberFunctionPtr ptrGetVariable = &MyClass::getRegularVariable;
};


int MyClass::staticVariable = 0;

int main()
{

    MyClass obj1(3, 3.1, "Roman");
    MyClass obj2(5, 5.1, "Davydko");
    MyClass obj3(7, 7.1, ".");

  
    cout << "obj1: Regular Variable = " << (obj1.*obj1.ptrGetVariable)()
        << ", Double Variable = " << obj1.getDoubleVariable()
        << ", String Variable = " << obj1.getStringVariable()
        << ", Static Variable = " << MyClass::getStaticVariable() << endl;

    cout << "obj2: Regular Variable = " << (obj2.*obj2.ptrGetVariable)()
        << ", Double Variable = " << obj2.getDoubleVariable()
        << ", String Variable = " << obj2.getStringVariable()
        << ", Static Variable = " << MyClass::getStaticVariable() << std::endl;

    cout << "obj3: Regular Variable = " << (obj3.*obj3.ptrGetVariable)()
        << ", Double Variable = " << obj3.getDoubleVariable()
        << ", String Variable = " << obj3.getStringVariable()
        << ", Static Variable = " << MyClass::getStaticVariable() << endl;


    cout << "Deleting obj3..." << endl;
    MyClass::getStaticVariable();
    cout << "Static Variable = " << MyClass::getStaticVariable() << endl;

    cout << "Deleting obj2..." << endl;
    MyClass::getStaticVariable();
    cout << "Static Variable = " << MyClass::getStaticVariable() << endl;

   cout << "Deleting obj1..." <<endl;
    MyClass::getStaticVariable();
    cout << "Static Variable = " << MyClass::getStaticVariable() << endl;

    return 0;
}
