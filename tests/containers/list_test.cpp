#include <iostream>
#include "../../include/algolib/containers/list.h"

using namespace std;

void line() {
    cout << "----------------------------------------\n";
}

int main() {

    cout << "=== LIST TEST PROGRAM START ===\n\n";

    line();
    cout << "1) Creating empty list\n";
    algolib::list<int> l;
    cout << "List created. Is empty? " << (l.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "2) push_back operations\n";
    cout << "Push 10\n";
    l.push_back(10);
    l.print();

    cout << "Push 20\n";
    l.push_back(20);
    l.print();

    cout << "Push 30\n";
    l.push_back(30);
    l.print();

    line();
    cout << "3) push_front operations\n";
    cout << "Push 5 at front\n";
    l.push_front(5);
    l.print();

    cout << "Push 1 at front\n";
    l.push_front(1);
    l.print();

    line();
    cout << "4) Access functions\n";
    cout << "Front: " << l.front() << "\n";
    cout << "Back: " << l.back() << "\n";
    cout << "Element at index 2: " << l.at(2) << "\n";

    line();
    cout << "5) Insert by position\n";
    cout << "Insert 99 at position 2\n";
    l.insert(2, 99);
    l.print();

    line();
    cout << "6) Iterator traversal\n";
    cout << "Traversing list using iterator:\n";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    line();
    cout << "7) Insert using iterator\n";
    auto it = l.begin();
    ++it; // move to second element
    cout << "Insert 777 before second element\n";
    l.insert(it, 777);
    l.print();

    line();
    cout << "8) Find function\n";
    auto found = l.find(99);
    if (found != l.end()) {
        cout << "Value 99 found: " << *found << "\n";
    } else {
        cout << "Value 99 not found\n";
    }

    line();
    cout << "9) Erase by position\n";
    cout << "Erase element at position 2\n";
    l.erase(2);
    l.print();

    line();
    cout << "10) Erase using iterator\n";
    auto it2 = l.begin();
    ++it2;
    cout << "Erase second element using iterator\n";
    l.erase(it2);
    l.print();

    line();
    cout << "11) pop_front and pop_back\n";
    cout << "pop_front()\n";
    l.pop_front();
    l.print();

    cout << "pop_back()\n";
    l.pop_back();
    l.print();

    line();
    cout << "12) Copy constructor\n";
    algolib::list<int> copyList = l;
    cout << "Copied list:\n";
    copyList.print();

    line();
    cout << "13) Copy assignment\n";
    algolib::list<int> assignList;
    assignList = l;
    cout << "Assigned list:\n";
    assignList.print();

    line();
    cout << "14) Move constructor\n";
    algolib::list<int> movedList = std::move(l);
    cout << "Moved list:\n";
    movedList.print();

    cout << "Original list after move (should be empty):\n";
    cout << (l.empty() ? "Empty" : "Not Empty") << "\n";

    line();
    cout << "15) Move assignment\n";
    algolib::list<int> moveAssign;
    moveAssign = std::move(copyList);
    cout << "Move assigned list:\n";
    moveAssign.print();

    line();
    cout << "16) Clear function\n";
    cout << "Clearing list...\n";
    moveAssign.clear();
    cout << "Is empty? " << (moveAssign.empty() ? "YES" : "NO") << "\n";

    line();
    cout << "=== TEST FINISHED ===\n";

    return 0;
}