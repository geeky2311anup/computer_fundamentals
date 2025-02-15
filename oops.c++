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