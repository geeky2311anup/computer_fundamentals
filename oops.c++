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
