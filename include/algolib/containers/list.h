#pragma once 

#include <iostream> 
using namespace std; 

namespace algolib{
	template<typename T>
class list
{
private:
	using VALUE_TYPE = T;
	struct node {
		VALUE_TYPE _VAL;
		node* NEXT;
		node* PREV;
	};

	using reference = T&;

	size_t _SIZE;
	node* HEAD;
	node* LAST;

public:
	// ITERATOR
	class iterator {
	private:
		node* ptr;
		friend class list;

	public:
		iterator(node* ptr = nullptr) : ptr(ptr) {}

		// dereference
		reference operator*() {
			if (ptr == nullptr) throw std::runtime_error("Dereferencing null iterator");
			return ptr->_VAL;
		}

		// move forward
		iterator& operator++() {
			if (ptr) ptr = ptr->NEXT;
			return *this;
		}
		iterator& operator--() {
			if (ptr) ptr = ptr->PREV;
			return *this;
		}

		// comparison
		bool operator==(const iterator& other) const { return ptr == other.ptr; }
		bool operator!=(const iterator& other) const { return ptr != other.ptr; }

	};


	// CONSTRUCTORS
	list() : _SIZE(0), HEAD(nullptr), LAST(nullptr) {}
	list(const list& other) : _SIZE(0), HEAD(nullptr), LAST(nullptr) {
		node* curr = other.HEAD;

		while (curr) {
			push_back(curr->_VAL);
			curr = curr->NEXT;
		}
	}
	list(list&& other) noexcept
		: _SIZE(other._SIZE), HEAD(other.HEAD), LAST(other.LAST)
	{
		other.HEAD = nullptr;
		other.LAST = nullptr;
		other._SIZE = 0;
	}


	// ASSIGNMENT
	list& operator=(const list& other) {
		if (this == &other) return *this;

		clear(); // old

		node* curr = other.HEAD;
		while (curr) {
			push_back(curr->_VAL);
			curr = curr->NEXT;
		}

		return *this;
	}
	list& operator=(list&& other) noexcept {
		if (this != &other) {
			clear();

			HEAD = other.HEAD;
			LAST = other.LAST;
			_SIZE = other._SIZE;

			other.HEAD = nullptr;
			other.LAST = nullptr;
			other._SIZE = 0;
		}
		return *this;
	}

	// CAPACITY
	size_t size() const noexcept { return _SIZE; }
	bool  empty() const noexcept { return _SIZE == 0; }


	// MODIFIERS
	void push_front(const VALUE_TYPE& Val) {
		node* newNode = new node{ Val, nullptr, nullptr };

		if (empty()) HEAD = newNode, LAST = HEAD;
		else {
			newNode->NEXT = HEAD;
			HEAD->PREV = newNode;
			HEAD = newNode;
		}

		this->_SIZE++;
	}

	void push_back(const VALUE_TYPE& Val) {
		node* newNode = new node{ Val, nullptr, nullptr };

		if (empty()) HEAD = newNode, LAST = HEAD;
		else {
			newNode->PREV = LAST;
			LAST->NEXT = newNode;
			LAST = newNode;
		}

		this->_SIZE++;
	}


	void insert(size_t _Pos, const VALUE_TYPE& Val) {
		if (_Pos <= 0) { push_front(Val); return; }
		else if (this->_SIZE <= _Pos) { push_back(Val); return; }

		node* newNode = new node{ Val, nullptr, nullptr };

		node* curr = HEAD->NEXT, * prev = HEAD;
		for (int i = 1; i < _Pos; i++)
		{
			curr = curr->NEXT; prev = prev->NEXT;
		}

		prev->NEXT = newNode; newNode->PREV = prev;
		newNode->NEXT = curr; curr->PREV = newNode;
		this->_SIZE++;
	}

	iterator insert(iterator _Pos, const VALUE_TYPE& Val) {
		if (_Pos.ptr == HEAD) {
			push_front(Val);
			return begin();
		}
		if (_Pos.ptr == nullptr) {
			push_back(Val);
			return iterator(LAST);
		}

		node* curr = _Pos.ptr;
		node* prev = curr->PREV;

		node* newNode = new node{ Val, curr, prev };

		prev->NEXT = newNode;
		curr->PREV = newNode;

		_SIZE++;

		return iterator(newNode);
	}

	void pop_front() {
		if (empty()) return;
		else if (size() == 1)
		{
			delete HEAD; this->_SIZE--;
			HEAD = NULL; LAST = NULL; return;
		}

		node* temp = HEAD;
		HEAD = HEAD->NEXT;
		HEAD->PREV = nullptr;

		delete temp; this->_SIZE--;
	}

	void pop_back() {
		if (empty()) return;
		else if (size() == 1)
		{
			delete HEAD; this->_SIZE--;
			HEAD = NULL; LAST = NULL; return;
		}

		node* temp = LAST;
		LAST = LAST->PREV;
		LAST->NEXT = nullptr;

		delete temp; this->_SIZE--;
	}


	void erase(size_t _Pos) {
		if (_Pos < 0 || _Pos >= this->_SIZE) { throw std::out_of_range("OUT OF LIST RANGE"); }
		if (_Pos == 0) { pop_front(); return; }
		else if (_Pos == this->_SIZE - 1) { pop_back(); return; }

		node* temp = HEAD;

		for (int i = 0; i < _Pos; i++) {
			temp = temp->NEXT;
		}

		temp->PREV->NEXT = temp->NEXT;
		temp->NEXT->PREV = temp->PREV;

		delete temp; this->_SIZE--;
	}

	iterator erase(iterator pos) {
		node* curr = pos.ptr;

		if (!curr) return end();

		node* next = curr->NEXT;

		// Case 1: deleting HEAD
		if (curr == HEAD) {
			pop_front();
			return iterator(next);
		}

		// Case 2: deleting LAST
		if (curr == LAST) {
			pop_back();
			return end();
		}

		node* prev = curr->PREV;

		prev->NEXT = next;
		next->PREV = prev;

		delete curr; this->_SIZE--;

		return iterator(next);
	}

	void clear() {
		while (_SIZE) pop_back();
	}


	const reference front() const {
		if (_SIZE == 0) throw std::out_of_range("EMPTY LIST");
		return HEAD->_VAL;
	}

	const reference back()  const {
		if (_SIZE == 0) throw std::out_of_range("EMPTY LIST");
		return LAST->_VAL;
	}

	const reference at(size_t _Pos) const {
		if (_Pos < 0 || _Pos >= this->_SIZE) { throw std::out_of_range("OUT OF LIST RANGE"); }

		node* temp = HEAD;

		for (int i = 0; i < _Pos; i++) {
			temp = temp->NEXT;
		}

		return temp->_VAL;
	}

	iterator begin() { return iterator(HEAD); }
	iterator end() { return iterator(nullptr); }

	iterator find(const VALUE_TYPE& Val) {
		size_t INDEX = 0; node* temp = HEAD;

		for (int i = 0; i < this->_SIZE; i++) {
			if (temp->_VAL == Val) return iterator(temp);
			else  temp = temp->NEXT, INDEX++;
		}

		return end();
	}

	// OPERATIONS
	void print() {
		node* temp = HEAD;

		cout << "[ ";
		while (temp != NULL)
		{
			cout << temp->_VAL << " ";
			temp = temp->NEXT;
		}
		cout << "]" << endl;
	}

	~list() { clear(); }
};
}