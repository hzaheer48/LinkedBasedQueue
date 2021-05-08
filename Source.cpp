#include<iostream>
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
};
template<typename T>
class queue {
	node<T>* r;
	node<T>* f;
public:
	queue() {
		r = f = NULL;
	}
	~queue() {
		make_empty();
	}
	bool empty() const {
		return r == NULL;
	}
	void push(const T& val) {
		if (full())
			throw("Queue Overflow!");
		node<T>* temp;
		temp = new node<T>;
		temp->data = val;
		temp->next = NULL;
		if (empty()) {
			r = temp;
			f = r;
		}
		else {
			r->next = temp;
			r = temp;
		}
	}
	void pop() {
		if (empty())
			throw("Queue Underflow!");
		node<T>* temp;
		temp = f;
		f = f->next;
		delete temp;
		if (f == NULL)
			r = NULL;
	}
	T front() const {
		if (empty())
			throw("Queue is empty!");
		return f->data;
	}
	bool full() const {
		node<T>* temp;
		temp = new node<T>;
		if (temp == NULL)
			return true;
		else {
			delete temp;
			return false;
		}
	}
	void make_empty() {
		while (!empty())
			pop();
	}
	void operator=(const queue<T>& rhs) {
		make_empty();
		node<T>* temp;
		temp = rhs.f;
		while (temp != NULL) {
			push(temp->data);
			temp = temp->next;
		}
	}
	queue(const queue<T>& rhs) {
		r = f = NULL;
		operator=(rhs);
	}
};