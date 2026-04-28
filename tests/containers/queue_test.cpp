#include <iostream>
#include <utility>
#include "../../include/algolib/containers/queue.h"

using namespace std;

void line() {
    cout << "----------------------------------------\n";
}

int main() {

    cout << "=== QUEUE TEST PROGRAM START ===\n\n";

    line();
    cout << "1) Creating empty queue\n";
    algolib::queue<int> q;
    cout << "Queue created. Is empty? " << (q.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "2) push operations (FIFO behavior)\n";

    cout << "Push 10\n";
    q.push(10);
    cout << "Front: " << q.front() << " | Size: " << q.size() << "\n";

    cout << "Push 20\n";
    q.push(20);
    cout << "Front: " << q.front() << " | Size: " << q.size() << "\n";

    cout << "Push 30\n";
    q.push(30);
    cout << "Front: " << q.front() << " | Size: " << q.size() << "\n";

    line();
    cout << "3) pop operations (FIFO order)\n";

    cout << "Pop\n";
    q.pop();
    cout << "Front: " << q.front() << " | Size: " << q.size() << "\n";

    cout << "Pop\n";
    q.pop();
    cout << "Front: " << q.front() << " | Size: " << q.size() << "\n";

    line();
    cout << "4) Copy constructor\n";

    algolib::queue<int> original;
    for (int i = 1; i <= 5; i++) original.push(i);

    cout << "Original front: " << original.front() << "\n";

    algolib::queue<int> copy = original;
    cout << "Copied front: " << copy.front() << "\n";

    cout << "Popping both queues to compare:\n";
    while (!original.empty()) {
        cout << "Original: " << original.front()
             << " | Copy: " << copy.front() << "\n";
        original.pop();
        copy.pop();
    }

    line();
    cout << "5) Copy assignment\n";

    algolib::queue<int> q1;
    for (int i = 1; i <= 3; i++) q1.push(i);

    algolib::queue<int> q2;
    q2.push(999);

    cout << "Before assignment:\n";
    cout << "q1 front: " << q1.front() << " | q2 front: " << q2.front() << "\n";

    q2 = q1;

    cout << "After assignment, popping q2:\n";
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << "\n";

    line();
    cout << "6) Move constructor\n";

    algolib::queue<int> moveSrc;
    for (int i = 1; i <= 5; i++) moveSrc.push(i);

    algolib::queue<int> moved = std::move(moveSrc);

    cout << "Moved queue front: " << moved.front() << "\n";
    cout << "Original after move (should be empty): "
         << (moveSrc.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "7) Move assignment\n";

    algolib::queue<int> m1;
    for (int i = 1; i <= 4; i++) m1.push(i);

    algolib::queue<int> m2;
    m2.push(777);

    m2 = std::move(m1);

    cout << "m2 after move assignment (popping):\n";
    while (!m2.empty()) {
        cout << m2.front() << " ";
        m2.pop();
    }
    cout << "\n";

    cout << "m1 after move (should be empty): "
         << (m1.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "8) Clear function\n";

    algolib::queue<int> clearTest;
    for (int i = 0; i < 5; i++) clearTest.push(i);

    cout << "Clearing queue...\n";
    clearTest.clear();

    cout << "Is empty? " << (clearTest.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "9) Stress test (push 10000 elements)\n";

    algolib::queue<int> stress;

    for (int i = 0; i < 10000; i++) {
        stress.push(i);
    }

    cout << "Front after pushes: " << stress.front() << "\n";
    cout << "Popping first 5 elements:\n";

    for (int i = 0; i < 5; i++) {
        cout << stress.front() << " ";
        stress.pop();
    }
    cout << "\n";

    line();
    cout << "=== TEST FINISHED ===\n";

    return 0;
}