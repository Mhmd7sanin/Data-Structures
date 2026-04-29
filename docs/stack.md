# Stack Container

Custom implementation of a stack similar to `std::stack`.

- LIFO (Last In First Out)
- Restricted interface
- Built on underlying container

---

## Design

- Uses underlying container (likely list or vector)
- Only allows access to the top element
- No iterators exposed

---

## Core Features

- push
- pop
- top
- size
- empty

---

## Comparison with std::stack

| Feature   | My Stack | std::stack | Complexity | Notes |
|----------|----------|------------|------------|------|
| push     | ✅       | ✅         | O(1)       | Depends on underlying container |
| pop      | ✅       | ✅         | O(1)       | Removes top |
| top      | ✅       | ✅         | O(1)       | Access last element |
| size     | ✅       | ✅         | O(1)       | Same |
| empty    | ✅       | ✅         | O(1)       | Same |
| iterators| ❌       | ❌         | —          | Not supported by design |

---

## Time Complexity

| Operation | Complexity |
|----------|-----------|
| push     | O(1)      |
| pop      | O(1)      |
| top      | O(1)      |
| size     | O(1)      |

---

## Performance & Notes

- Very lightweight abstraction
- Performance depends on underlying container
- No traversal allowed (by design)

---

## Memory Model

- Uses underlying container storage
- No extra overhead beyond container

---

## Iterator Validity

- Not applicable (no iterators)

---

## Limitations

- No iterators
- No random access
- No direct element access except top

---

## Implementation Status

| Method | Status |
|--------|--------|
| push   | ✅ Implemented |
| pop    | ✅ Implemented |
| top    | ✅ Implemented |
| size   | ✅ Implemented |
| empty  | ✅ Implemented |

---

## Design Decisions

- Restricted interface to enforce LIFO behavior
- Prevented misuse by hiding internal structure
- Relies on underlying container efficiency

---

## When to Use

- Backtracking algorithms
- Expression evaluation
- Recursive simulations

---

## When NOT to Use

- Need iteration or traversal
- Need random access

---

## Example

```cpp
algolib::stack<int> s;

s.push(10);
s.push(20);

std::cout << s.top(); // 20
s.pop();