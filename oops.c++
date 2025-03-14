/**
1️⃣ Class and Object
📌 Definition
A class is a blueprint for creating objects (it defines attributes and methods).
An object is an instance of a class.
✅ Example
*/
#include <iostream>
using namespace std;

class Car { // Class definition
public:
    string brand;
    int speed;

    void show() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h\n";
    }
};

int main() {
    Car myCar; // Object creation
    myCar.brand = "Toyota";
    myCar.speed = 120;
    myCar.show();
    return 0;
}
/*
🔹 Output

Brand: Toyota, Speed: 120 km/h
*/

#include <iostream>
using namespace std;

// Base class (Parent class)
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {} // Constructor

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class (Child class)
class Student : public Person {
private:
    int studentID;
public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {} // Constructor

    void displayStudent() {
        displayPerson(); // Calling base class function
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Student s("Anup", 21, 12345);
    s.displayStudent();
    return 0;
}
//////////////////////////////////////////////////////


//**********Polymorphism******************//
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to enable runtime polymorphism
    virtual void speak() const {
        cout << "Animal makes a sound." << endl;
    }
    
    // Virtual destructor for safe polymorphic deletion
    virtual ~Animal() {}
};

// Derived class: Dog
class Dog : public Animal {
public:
    // Override speak() method
    void speak() const override {
        cout << "Dog barks: Woof!" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    // Override speak() method
    void speak() const override {
        cout << "Cat meows: Meow!" << endl;
    }
};

int main() {
    // Create objects of derived classes
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    // Call speak() on each pointer.
    // Due to polymorphism, the correct overridden method is called.
    animal1->speak();  // Outputs: Dog barks: Woof!
    animal2->speak();  // Outputs: Cat meows: Meow!

    // Clean up
    delete animal1;
    delete animal2;

    return 0;
}
//////////////////////////////////////////////////////////////////////

Inheritance Example

#include <iostream>
using namespace std;

// Base class (Parent)
class Vehicle {
public:
    int wheels;
    string brand;

    void showInfo() {
        cout << "Brand: " << brand << ", Wheels: " << wheels << endl;
    }
};

// Derived class (Child) - Car
class Car : public Vehicle {
public:
    int seats;

    void carInfo() {
        cout << "Car has " << seats << " seats." << endl;
    }
};

// Derived class (Child) - Bike
class Bike : public Vehicle {
public:
    bool hasGear;

    void bikeInfo() {
        cout << "Bike has gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

int main() {
    // Creating Car object
    Car myCar;
    myCar.brand = "Toyota";
    myCar.wheels = 4;
    myCar.seats = 5;
    myCar.showInfo();
    myCar.carInfo();

    cout << "--------------------" << endl;

    // Creating Bike object
    Bike myBike;
    myBike.brand = "Yamaha";
    myBike.wheels = 2;
    myBike.hasGear = true;
    myBike.showInfo();
    myBike.bikeInfo();

    return 0;
}
////////////////////////////////////////////////////