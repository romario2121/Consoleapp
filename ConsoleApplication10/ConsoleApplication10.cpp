1)#include <iostream>
#include <string>

class Animal
{
private:
    std::string name;

public:
   
    Animal() : name("Some") {}
    Animal(const std::string& name) : name(name) {}

  
    std::string getName() const 
    {
        return name;
    }

    void setName(const std::string& name) 
    {
        this->name = name;
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////

2)#include <iostream>
#include <stdexcept>

template <typename T, std::size_t N>
class BoundedArray 
{
private:
    T data[N];

public:
    
    BoundedArray() = default;

    T& operator[](std::size_t index) 
    {
        if (index >= N) {
            throw std::out_of_range("Out of range");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const 
    {
        if (index >= N) 
        {
            throw std::out_of_range("Out of range");
        }
        return data[index];
    }

    std::size_t size() const
    {
        return N;
    }

    void fill (const T& value) 
    {
        for (std::size_t i = 0; i < N; ++i) 
        {
            data[i] = value;
        }
    }
};

/////////////////////////////////////////////////////////////////////////////


3)#include <iostream>
#include <stdexcept>

template <typename T, std::size_t N>
class BoundedArray 
{
private:
    T data[N];

public:

    BoundedArray() = default;

    
    T& operator[](std::size_t index)
    {
        if (index >= N)
        {
            throw std::out_of_range("Out of range");
        }
        return data[index];
    }


    const T& operator[](std::size_t index) const
    {
        if (index >= N) 
        {
            throw std::out_of_range("Out of range");
        }
        return data[index];
    }

 
    std::size_t size() const
    {
        return N;
    }

    void fill(const T& value) 
    {
        for (std::size_t i = 0; i < N; ++i) 
        {
            data[i] = value;
        }
    }
};

template <typename T, std::size_t N>
class Set
{
private:
    BoundedArray<T, N> elements;
    std::size_t count;

 
    bool contains(const T& value) const {
        for (std::size_t i = 0; i < count; ++i) 
        {
            if (elements[i] == value) {
                return true;
            }
        }
        return false;
    }

public:
  
    Set() : count(0) {}


    void add(const T& value) 
    {
        if (count >= N)
        {
            throw std::out_of_range("Set is full");
        }
        if (!contains(value))
        {
            elements[count++] = value;
        }
    }

    void remove(const T& value) 
    {
        for (std::size_t i = 0; i < count; ++i) 
        {
            if (elements[i] == value) {
                elements[i] = elements[--count];
                return;
            }
        }
    }

    bool exists(const T& value) const 
    {
        return contains(value);
    }

    std::size_t size() const 
    {
        return count;
    }
};

/////////////////////////////////////////////////////////////

4)#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:

    String();
    String(const char* const);
    String(const String&);
    ~String();

    char& operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String&);
    void operator+=(const String&);
    String& operator=(const String&);
    friend istream& operator>>(istream& in, String& str);


    int GetLen() const { return itsLen; }
    const char* GetString() const { return itsString; }

private:
    String(int); 
    char* itsString;
    unsigned short itsLen;
};


String::String()
{
    itsString = new char[1];
    itsString[0] = '\0';
    itsLen = 0;
}


String::String(int len)
{
    itsString = new char[len + 1];
    for (int i = 0; i <= len; i++)
        itsString[i] = '\0';
    itsLen = len;
}


String::String(const char* const cString)
{
    itsLen = strlen(cString);
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
        itsString[i] = cString[i];
    itsString[itsLen] = '\0';
}


String::String(const String& rhs)
{
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
        itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
}


String::~String()
{
    delete[] itsString;
    itsLen = 0;
}


String& String::operator=(const String& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] itsString;
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
        itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    return *this;
}


char& String::operator[](int offset)
{
    if (offset > itsLen)
        return itsString[itsLen - 1];
    else
        return itsString[offset];
}


char String::operator[](int offset) const
{
    if (offset > itsLen)
        return itsString[itsLen - 1];
    else
        return itsString[offset];
}


String String::operator+(const String& rhs)
{
    int totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
        temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
        temp[i] = rhs[j];
    temp[totalLen] = '\0';
    return temp;
}


void String::operator+=(const String& rhs)
{
    unsigned short rhsLen = rhs.GetLen();
    unsigned short totalLen = itsLen + rhsLen;
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
        temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
        temp[i] = rhs[i - itsLen];
    temp[totalLen] = '\0';
    *this = temp;
}


istream& operator>>(istream& in, String& str)
{
    char buffer[1000]; 
    in >> buffer;
    str = String(buffer); 
    return in;
}

int main()
{
    String str;
    cout << "Enter the string: ";
    cin >> str;
    cout << "You entered: " << str.GetString() << endl;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////


5) 1.Невозможно объявить friend в функции, так как friend объявляется только в теле класса.
2.В классе Animal нужно инициализировать переменные - члены или предоставить конструктор для их инициализации.
3.В функции setValue доступ к приватным членам класса Animal невозможен, поскольку эта функция не является другом класса.

6)#include <iostream>
#include <string>

using namespace std;

class Animal
{
   
    friend void setValue(Animal&, int);

public:
    Animal() : itsWeight(0), itsAge(0) {} 
    int GetWeight() const { return itsWeight; }
    int GetAge() const { return itsAge; }

private:
    int itsWeight;
    int itsAge;
};

void setValue(Animal& theAnimal, int theWeight)
{
    theAnimal.itsWeight = theWeight; 
}

int main()
{
    Animal peppy;
    setValue(peppy, 5);
    cout << "Peppy's weight: " << peppy.GetWeight() << endl;
    return 0;
}


///////////////////////////////////////////////////////////////////


7)#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal&, int);

void setValue(Animal&, int, int);

class Animal //  Класс Animal не имеет никакого метода вывода значений itsWeight и itsAge, поэтому даже если вы вызовете функции setValue, нельзя будет проверить, правильно ли установлены значения.
{
{
    friend void setValue(Animal&, int);

private:
    int itsWeight;
    int itsAge; //  itsAge должно быть либо инициализировано в конструкторе, либо нужно изменить его значение в методе setValue.
};

void setValue(Animal& theAnimal, int theWeight)
{
    theAnimal.itsWeight = theWeight;
}

void setValue(Animal& theAnimal, int theWeight, int theAge)
{
    theAnimal.itsWeight = theWeight;
    theAnimal.itsAge = theAge;
}

int main()
{
    Animal peppy;
    setValue(peppy, 5);
    setValue(peppy, 7, 9);
    return 0;
}


////////////////////////////////////////////////////////////////////

8)#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal&, int);

void setValue(Animal&, int, int);

class Animal 
    friend void setValue(Animal&, int);
    friend void setValue(Animal&, int, int);

public:
    Animal() : itsWeight(0), itsAge(0) {}  
    void printInfo() const;  

private:
    int itsWeight;
    int itsAge;
};

void setValue(Animal& theAnimal, int theWeight)
{
    theAnimal.itsWeight = theWeight;
}

void setValue(Animal& theAnimal, int theWeight, int theAge)
{
    theAnimal.itsWeight = theWeight;
    theAnimal.itsAge = theAge;
}

void Animal::printInfo() const
{
    cout << "Weight: " << itsWeight << ", Age: " << itsAge << endl;
}

int main()
{
    Animal peppy;
    setValue(peppy, 5);
    peppy.printInfo(); 
    setValue(peppy, 7, 9);
    peppy.printInfo();  
    return 0;
}

