#include <iostream>
#include <utility>
#include "../../include/algolib/containers/stack.h"

using namespace std;

void line() {
    cout << "----------------------------------------\n";
}

int main() {

    cout << "=== STACK TEST PROGRAM START ===\n\n";

    line();
    cout << "1) Creating empty stack\n";
    algolib::stack<int> s;
    cout << "Stack created. Is empty? " << (s.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "2) push operations (LIFO behavior)\n";

    cout << "Push 10\n";
    s.push(10);
    cout << "Top: " << s.top() << " | Size: " << s.size() << "\n";

    cout << "Push 20\n";
    s.push(20);
    cout << "Top: " << s.top() << " | Size: " << s.size() << "\n";

    cout << "Push 30\n";
    s.push(30);
    cout << "Top: " << s.top() << " | Size: " << s.size() << "\n";

    line();
    cout << "3) pop operations\n";

    cout << "Pop\n";
    s.pop();
    cout << "Top: " << s.top() << " | Size: " << s.size() << "\n";

    cout << "Pop\n";
    s.pop();
    cout << "Top: " << s.top() << " | Size: " << s.size() << "\n";

    line();
    cout << "4) Copy constructor\n";

    algolib::stack<int> original;
    for (int i = 1; i <= 5; i++) original.push(i);

    cout << "Original stack top: " << original.top() << "\n";

    algolib::stack<int> copy = original;
    cout << "Copied stack top: " << copy.top() << "\n";

    cout << "Popping both stacks to compare:\n";
    while (!original.empty()) {
        cout << "Original: " << original.top()
             << " | Copy: " << copy.top() << "\n";
        original.pop();
        copy.pop();
    }

    line();
    cout << "5) Copy assignment\n";

    algolib::stack<int> s1;
    for (int i = 1; i <= 3; i++) s1.push(i);

    algolib::stack<int> s2;
    s2.push(100);

    cout << "Before assignment:\n";
    cout << "s1 top: " << s1.top() << " | s2 top: " << s2.top() << "\n";

    s2 = s1;

    cout << "After assignment, popping s2:\n";
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << "\n";

    line();
    cout << "6) Move constructor\n";

    algolib::stack<int> moveSrc;
    for (int i = 1; i <= 5; i++) moveSrc.push(i);

    algolib::stack<int> moved = std::move(moveSrc);

    cout << "Moved stack top: " << moved.top() << "\n";
    cout << "Original after move (should be empty): "
         << (moveSrc.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "7) Move assignment\n";

    algolib::stack<int> m1;
    for (int i = 1; i <= 4; i++) m1.push(i);

    algolib::stack<int> m2;
    m2.push(999);

    m2 = std::move(m1);

    cout << "m2 after move assignment (popping):\n";
    while (!m2.empty()) {
        cout << m2.top() << " ";
        m2.pop();
    }
    cout << "\n";

    cout << "m1 after move (should be empty): "
         << (m1.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "8) Clear function\n";

    algolib::stack<int> clearTest;
    for (int i = 0; i < 5; i++) clearTest.push(i);

    cout << "Clearing stack...\n";
    clearTest.clear();

    cout << "Is empty? " << (clearTest.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "9) Stress test (push 10000 elements)\n";

    algolib::stack<int> stress;

    for (int i = 0; i < 10000; i++) {
        stress.push(i);
    }

    cout << "Top after pushes: " << stress.top() << "\n";
    cout << "Popping last 5 elements:\n";

    for (int i = 0; i < 5; i++) {
        cout << stress.top() << " ";
        stress.pop();
    }
    cout << "\n";

    line();
    cout << "=== TEST FINISHED ===\n";

    return 0;
}