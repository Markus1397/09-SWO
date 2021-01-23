#include <iostream>
#include <deque>
#include "deque.h"
#include "circular_buffer.h"
#include <functional>

using namespace swo;


template <typename T> void print_deque(T& d) {
	for (int val : d) {
		std::cout << val << '|';
	}
	std::cout << std::endl;
}

template <typename T> void simple_iterator_test() {
	T d(7);
	for (int i = 0; i <= 6; i++) {
		d.push_front(i);
	}
	print_deque<T>(d);
	
}

template <typename T>  void simple_init_list_test() {
	T d{ {7,1,2,3,4,5} };
	print_deque<T>(d);
}

template <typename T> void simple_iterator_test_with_value() {
	T d(7,2);
	print_deque<T>(d);
}

template <typename T> void pop_front() {
	T d{ {7,1,2,3,4,5} };
	d.pop_front();
	print_deque<T>(d);
}

template <typename T> void pop_back() {
	T d{ {7,1,2,3,4,5} };
	d.pop_back();
	print_deque<T>(d);
}

template <typename T> void pop_front_and_push_back() {
	T d{ {7,1,2,3,4,5} };

	d.pop_front();
	d.push_back(6);
	print_deque<T>(d);
}

template <typename T> void pop_front_and_push_front() {
	T d{ {7,1,2,3,4,5} };
	
	d.pop_front();
	d.push_front(6);
	print_deque<T>(d);
}

template <typename T> void shrink() {
	T d{ {7,1,2,3,4,5} };
	print_deque<T>(d);
	std::cout << "resize" << std::endl;
	d.resize(5);
	print_deque<T>(d);
}

template <typename T> void grow() {
	T d{ {7,1,2,3,4,5} };
	print_deque<T>(d);
	std::cout << "resize" << std::endl;
	d.resize(10);
	print_deque<T>(d);
}

template <typename T> void grow_with_value() {
	T d{ {7,1,2,3,4,5} };
	print_deque<T>(d);
	std::cout << "resize" << std::endl;
	d.resize(10,42);
	print_deque<T>(d);
}

void print_divider() {
	std::cout << "---------------------------" << std::endl;
}

void test_function(std::function<void (void)> funcOwn, std::function<void(void)> funcStd) {
	std::cout << "Own Implementation" << std::endl;
	funcOwn();
	std::cout << std::endl;
	std::cout << "Standard Implementation" << std::endl;
	funcStd();
	print_divider();
}



int main() {

	test_function(simple_iterator_test<deque<int>>, simple_iterator_test<std::deque<int>>);
	test_function(simple_init_list_test<deque<int>>, simple_init_list_test<std::deque<int>>);
	test_function(simple_iterator_test_with_value<deque<int>>, simple_iterator_test_with_value<std::deque<int>>);
	test_function(pop_front<deque<int>>, pop_front<std::deque<int>>);
	test_function(pop_back<deque<int>>, pop_back<std::deque<int>>);
	test_function(pop_front_and_push_back<deque<int>>, pop_front_and_push_back<std::deque<int>>);
	test_function(pop_front_and_push_front<deque<int>>, pop_front_and_push_front<std::deque<int>>);
	test_function(shrink<deque<int>>, shrink<std::deque<int>>);
	test_function(grow<deque<int>>, grow<std::deque<int>>);
	test_function(grow_with_value<deque<int>>, grow_with_value<std::deque<int>>);

	return EXIT_SUCCESS;
}