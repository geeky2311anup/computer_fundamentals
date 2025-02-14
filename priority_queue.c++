/*1️⃣ Basic priority_queue Functions
Function	Description
push(x)	Inserts an element x into the priority queue.
pop()	Removes the top element (largest in max-heap, smallest in min-heap).
top()	Returns the top element without removing it.
empty()	Returns true if the queue is empty, otherwise false.
size()	Returns the number of elements in the queue.
2️⃣ Example: Max-Heap (Default)
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq; // Max-heap (default)

    pq.push(10);
    pq.push(20);
    pq.push(15);

    cout << "Top element: " << pq.top() << endl; // 20

    pq.pop(); // Removes 20
    cout << "Top after pop: " << pq.top() << endl; // 15

    cout << "Size: " << pq.size() << endl; // 2

    return 0;
}
/*
Output

Top element: 20
Top after pop: 15
Size: 2

3️⃣ Example: Min-Heap (Using greater<int>)
A min-heap keeps the smallest element at the top.


priority_queue<int, vector<int>, greater<int>> pq;
Full Example
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    pq.push(10);
    pq.push(20);
    pq.push(15);

    cout << "Top element: " << pq.top() << endl; // 10 (smallest)

    pq.pop(); // Removes 10
    cout << "Top after pop: " << pq.top() << endl; // 15

    return 0;
}
//Output

//Top element: 10
//Top after pop: 15