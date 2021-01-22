#include <iostream>
#include <deque>
#include "deque.h"
#include "circular_buffer.h"

using namespace swo;

void simple_iterator_test() {
	deque<int> d(7);
	std::deque<int> dstd(7);
	
	for (int i = 0; i <= 6; i++) {
		d.push_front(i);
		dstd.push_front(i);
	}
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd){
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void simple_init_list_test() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void simple_iterator_test_with_value() {
	deque<int> d(7,2);
	std::deque<int> dstd(7,2);

	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void pop_front() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.pop_front();
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.pop_front();
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void pop_back() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.pop_back();
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.pop_back();
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void pop_front_and_push_back() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.pop_front();
	d.push_back(6);
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.pop_front();
	dstd.push_back(6);
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void pop_front_and_push_front() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.pop_front();
	d.push_front(6);
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.pop_front();
	dstd.push_front(6);
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void shrink() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.resize(5);
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.resize(5);
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void grow() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.resize(10);
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.resize(10);
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void grow_with_value() {
	deque<int> d{ {7,1,2,3,4,5} };
	std::deque<int> dstd{ {7,1,2,3,4,5} };

	d.resize(10,42);
	std::cout << "Own Implementation" << std::endl;
	for (int val : d) {
		std::cout << val << '|';
	}
	dstd.resize(10,42);
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	for (int val : dstd) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

void print_divider() {
	std::cout << "---------------------------" << std::endl;
}

int main() {
	simple_iterator_test();
	print_divider();
	simple_init_list_test();
	print_divider();
	simple_iterator_test_with_value();
	print_divider();
	pop_front();
	print_divider();
	pop_back();
	print_divider();
	pop_front_and_push_back();
	print_divider();
	pop_front_and_push_front();
	print_divider();
	shrink();
	print_divider();
	grow();
	print_divider();
	grow_with_value();
	std::cout << std::endl;
	return EXIT_SUCCESS;
}