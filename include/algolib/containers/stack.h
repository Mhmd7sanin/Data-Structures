#pragma once 

#include <iostream>

namespace algolib {
    template<typename T>
class stack
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
	size_t _SIZE;

public:

	// CONSTRUCTORS
	stack() : _SIZE(0), HEAD(nullptr) {}
	stack(const stack& other) : HEAD(nullptr), _SIZE(0) {
		if (!other.HEAD) return;

		HEAD = new node{ other.HEAD->_VAL, nullptr };

		node* curr = HEAD;
		node* other_curr = other.HEAD->NEXT;

		while (other_curr) {
			curr->NEXT = new node{ other_curr->_VAL, nullptr };
			curr = curr->NEXT;
			other_curr = other_curr->NEXT;
		}

		_SIZE = other._SIZE;
	}
	stack(stack&& other) noexcept
		: HEAD(other.HEAD), _SIZE(other._SIZE)
	{
		other.HEAD = nullptr;
		other._SIZE = 0;
	}

	// ASSIGNMENT
	stack& operator=(const stack& other) {
		if (this == &other) return *this;

		clear();

		if (!other.HEAD) {
			HEAD = nullptr;
			_SIZE = 0;
			return *this;
		}

		HEAD = new node{ other.HEAD->_VAL, nullptr };

		node* curr = HEAD;
		node* other_curr = other.HEAD->NEXT;

		while (other_curr) {
			curr->NEXT = new node{ other_curr->_VAL, nullptr };
			curr = curr->NEXT;
			other_curr = other_curr->NEXT;
		}

		_SIZE = other._SIZE;
		return *this;
	}
	stack& operator=(stack&& other) noexcept {
		if (this == &other) return *this;

		clear();

		HEAD = other.HEAD;
		_SIZE = other._SIZE;

		other.HEAD = nullptr;
		other._SIZE = 0;

		return *this;
	}

	size_t size() const noexcept { return _SIZE; }
	bool  empty() const noexcept { return _SIZE == 0; }


	void push(const VALUE_TYPE& Val) {
		HEAD = new node(Val, HEAD);

		this->_SIZE++;
	}

	void pop() {
		if (empty()) return;

		node* temp = HEAD;
		HEAD = HEAD->NEXT;

		delete temp; this->_SIZE--;
	}

	reference top() {
		if (empty()) throw std::runtime_error("stack is empty");
		return HEAD->_VAL;
	}
	const reference top() const {
		if (empty()) throw std::runtime_error("stack is empty");
		return HEAD->_VAL;
	}

	void clear() {
		while (!empty()) pop();
	}

	~stack() { clear(); };
};

}