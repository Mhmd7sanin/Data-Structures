# Queue Container

Custom implementation of a queue similar to `std::queue`.

- FIFO (First In First Out)
- Restricted interface
- Efficient front/back operations

---

## Design

- Uses underlying structure (likely linked list)
- Maintains:
  - front (HEAD)
  - back (TAIL)

---

## Core Features

- push (enqueue)
- pop (dequeue)
- front
- back
- size
- empty

---

## Comparison with std::queue

| Feature   | My Queue | std::queue | Complexity | Notes |
|----------|----------|------------|------------|------|
| push     | ✅       | ✅         | O(1)       | Insert at back |
| pop      | ✅       | ✅         | O(1)       | Remove from front |
| front    | ✅       | ✅         | O(1)       | Access first element |
| back     | ✅       | ✅         | O(1)       | Access last element |
| size     | ✅       | ✅         | O(1)       | Same |
| empty    | ✅       | ✅         | O(1)       | Same |
| iterators| ❌       | ❌         | —          | Not supported |

---

## Time Complexity

| Operation | Complexity |
|----------|-----------|
| push     | O(1)      |
| pop      | O(1)      |
| front    | O(1)      |
| back     | O(1)      |
| size     | O(1)      |

---

## Performance & Notes

- Constant-time operations for all core methods
- Efficient for streaming data
- No traversal allowed

---

## Memory Model

- Typically implemented using linked structure
- Each element stored separately

---

## Iterator Validity

- Not applicable (no iterators)

---

## Limitations

- No iterators
- No random access
- Limited interface by design

---

## Implementation Status

| Method | Status |
|--------|--------|
| push   | ✅ Implemented |
| pop    | ✅ Implemented |
| front  | ✅ Implemented |
| back   | ✅ Implemented |
| size   | ✅ Implemented |
| empty  | ✅ Implemented |

---

## Design Decisions

- FIFO enforced through restricted interface
- Separate front and back pointers for O(1) operations
- Simplified API compared to list

---

## When to Use

- Task scheduling
- BFS algorithms
- Streaming systems

---

## When NOT to Use

- Need random access
- Need iteration over elements

---

## Example

```cpp
algolib::queue<int> q;

q.push(10);
q.push(20);

std::cout << q.front(); // 10
q.pop();