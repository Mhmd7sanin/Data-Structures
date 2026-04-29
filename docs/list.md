# List Container (Doubly Linked List)

Custom implementation of a doubly linked list similar to `std::list`.

- Dynamic size
- Bidirectional traversal
- Node-based structure
- Iterator support

---

## Design

- Node structure:
  - value (`_VAL`)
  - pointer to next (`NEXT`)
  - pointer to previous (`PREV`)

- Maintains:
  - `HEAD` (first node)
  - `LAST` (last node)
  - `_SIZE` (number of elements)

- Iterator:
  - wraps raw node pointer
  - supports:
    - dereference `*`
    - forward `++`
    - backward `--`

---

## Core Features

- push_front / push_back
- insert (index + iterator)
- erase (index + iterator)
- pop_front / pop_back
- find
- clear
- copy & move semantics
- iterator traversal

---

## Comparison with std::list

| Feature        | My List | std::list | Complexity | Notes |
|----------------|--------|-----------|------------|------|
| push_back      | ✅     | ✅        | O(1)       | Uses tail pointer |
| push_front     | ✅     | ✅        | O(1)       | Same |
| insert (index) | ✅     | ❌        | O(n)       | STL uses iterator only |
| insert (iter)  | ✅     | ✅        | O(1)       | Matches STL behavior |
| erase (index)  | ✅     | ❌        | O(n)       | STL uses iterator |
| erase (iter)   | ✅     | ✅        | O(1)       | Matches STL |
| pop_back       | ✅     | ✅        | O(1)       | Same |
| pop_front      | ✅     | ✅        | O(1)       | Same |
| find           | ✅     | ❌        | O(n)       | STL uses algorithms instead |
| size           | ✅     | ✅        | O(1)       | Stored counter |
| clear          | ✅     | ✅        | O(n)       | Uses pop loop |
| iterator       | ✅     | ✅        | O(1)       | Missing const_iterator |
| rbegin/rend    | ❌     | ✅        | O(1)       | Not implemented |
| cbegin/cend    | ❌     | ✅        | O(1)       | Not implemented |
| sort           | ❌     | ✅        | O(n log n) | Not implemented |
| reverse        | ❌     | ✅        | O(n)       | Not implemented |
| splice         | ❌     | ✅        | O(1)       | Missing advanced feature |

---

## Time Complexity

| Operation     | Complexity |
|--------------|-----------|
| push_front   | O(1)      |
| push_back    | O(1)      |
| pop_front    | O(1)      |
| pop_back     | O(1)      |
| insert (iter)| O(1)      |
| insert (pos) | O(n)      |
| erase (iter) | O(1)      |
| erase (pos)  | O(n)      |
| find         | O(n)      |
| clear        | O(n)      |

---

## Performance & Notes

- Efficient for:
  - insertion/removal at ends → O(1)
  - insertion via iterator → O(1)

- Less efficient for:
  - index-based operations → O(n)
  - traversal-heavy operations

- Differences from STL:
  - supports index-based insert/erase
  - manual `find()` implementation
  - no allocator optimizations

---

## Memory Model

- Each element is stored in a separate heap allocation
- Extra memory per node:
  - 2 pointers (prev, next)

Implications:
- Higher memory overhead than vector
- Poor cache locality

---

## Iterator Validity

- Insertion:
  - does NOT invalidate existing iterators

- Erase:
  - invalidates only the erased iterator

- Other iterators remain valid

---

## Limitations

- No `const_iterator`
- No reverse iterator
- No allocator support
- No exception safety guarantees
- Uses raw pointers (manual memory management)
- `using namespace std;` in header (bad practice)
- Missing advanced STL operations

---

## Implementation Status

### Core Operations

| Method        | Status |
|--------------|--------|
| push_back    | ✅ Implemented |
| push_front   | ✅ Implemented |
| insert       | ✅ Implemented |
| erase        | ✅ Implemented |
| pop_back     | ✅ Implemented |
| pop_front    | ✅ Implemented |
| clear        | ✅ Implemented |
| find         | ✅ Implemented |

---

### Element Access

| Method        | Status |
|--------------|--------|
| front        | ✅ Implemented |
| back         | ✅ Implemented |
| at           | ✅ Implemented |

---

### Iterators

| Method        | Status |
|--------------|--------|
| begin        | ✅ Implemented |
| end          | ✅ Implemented |
| rbegin       | ❌ Not Implemented |
| rend         | ❌ Not Implemented |
| cbegin       | ❌ Not Implemented |
| cend         | ❌ Not Implemented |
| crbegin      | ❌ Not Implemented |
| crend        | ❌ Not Implemented |

---

### Capacity

| Method        | Status |
|--------------|--------|
| size         | ✅ Implemented |
| empty        | ✅ Implemented |

---

### Advanced STL Operations

| Method        | Status |
|--------------|--------|
| sort         | ❌ Not Implemented |
| reverse      | ❌ Not Implemented |
| splice       | ❌ Not Implemented |
| merge        | ❌ Not Implemented |
| unique       | ❌ Not Implemented |
| remove       | ❌ Not Implemented |
| remove_if    | ❌ Not Implemented |

---

## Design Decisions

- Used doubly linked list to allow:
  - O(1) insertion/removal at both ends
  - bidirectional traversal

- Maintained `LAST` pointer:
  - avoids O(n) push_back

- Custom iterator:
  - abstracts raw pointer access
  - supports bidirectional movement

- Added index-based operations:
  - easier to use
  - but less efficient than STL design

- Implemented copy/move semantics:
  - ensures correct ownership handling

---

## When to Use

- Frequent insertions/removals in the middle
- Need stable iterators
- Unknown or dynamic size

---

## When NOT to Use

- Frequent random access (use vector instead)
- Cache-sensitive workloads
- Small datasets (high overhead)

---

## Example

```cpp
algolib::list<int> l;

l.push_back(10);
l.push_front(5);

for (auto it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << " ";
}