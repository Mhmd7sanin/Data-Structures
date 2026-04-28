#pragma once 

#include <iostream>

namespace algolib {
    template<typename T>
class queue
{
private:
	using VALUE_TYPE = T;
	using reference = T&;


	struct node {
		VALUE_TYPE _VAL;
		node* NEXT;

		node(const VALUE_TYPE& v, node* n = nullptr)
			: _VAL(v), NEXT(n) {
		}
	};


	node* HEAD;
	node* TAIL;
	size_t _SIZE;

public:

	// CONSTRUCTORS
	queue() : _SIZE(0), HEAD(nullptr), TAIL(nullptr) {}
	queue(const queue& other) : HEAD(nullptr), TAIL(nullptr), _SIZE(0) {
		if (!other.HEAD) return;

		HEAD = new node{ other.HEAD->_VAL, nullptr };
		TAIL = HEAD;

		node* curr = HEAD;
		node* other_curr = other.HEAD->NEXT;

		while (other_curr) {
			curr->NEXT = new node(other_curr->_VAL);
			curr = curr->NEXT; TAIL = curr;
			other_curr = other_curr->NEXT;
		}

		_SIZE = other._SIZE;
	}
	queue(queue&& other) noexcept
		: HEAD(other.HEAD), TAIL(other.TAIL), _SIZE(other._SIZE)
	{
		other.HEAD = nullptr;
		other.TAIL = nullptr;
		other._SIZE = 0;
	}

	// ASSIGNMENT
	queue& operator=(const queue& other) {
		if (this == &other) return *this;

		clear();

		if (!other.HEAD) {
			HEAD = TAIL = nullptr;
			_SIZE = 0;
			return *this;
		}

		HEAD = new node{ other.HEAD->_VAL, nullptr };
		TAIL = HEAD;

		node* curr = HEAD;
		node* other_curr = other.HEAD->NEXT;

		while (other_curr) {
			curr->NEXT = new node(other_curr->_VAL);
			curr = curr->NEXT; TAIL = curr;
			other_curr = other_curr->NEXT;
		}

		_SIZE = other._SIZE;
		return *this;
	}
	queue& operator=(queue&& other) noexcept {
		if (this == &other) return *this;

		clear();

		HEAD = other.HEAD;
		TAIL = other.TAIL;
		_SIZE = other._SIZE;

		other.HEAD = nullptr;
		other.TAIL = nullptr;
		other._SIZE = 0;

		return *this;
	}

	size_t size() const noexcept { return _SIZE; }
	bool  empty() const noexcept { return _SIZE == 0; }


	void push(const VALUE_TYPE& Val) {
		node* newNode = new node(Val);

		if (!TAIL) {
			HEAD = TAIL = newNode;
		}
		else {
			TAIL->NEXT = newNode;
			TAIL = newNode;
		}

		++_SIZE;
	}

	void pop() {
		if (empty()) return;

		node* temp = HEAD;
		HEAD = HEAD->NEXT;

		if (!HEAD) TAIL = nullptr;

		delete temp; this->_SIZE--;
	}

	reference front() {
		if (empty()) throw std::runtime_error("queue is empty");
		return HEAD->_VAL;
	}
	const reference front() const {
		if (empty()) throw std::runtime_error("queue is empty");
		return HEAD->_VAL;
	}

	void clear() {
		while (!empty()) pop();
	}

	~queue() { clear(); };
};

}