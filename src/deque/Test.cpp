#include <iostream>
#include "deque.h"
#include "circular_buffer.h"

using namespace swo;


int main() {
	circular_buffer<int> c{7};
	for (int i = 0; i <= 6; i++) {
		c.push_front(i);
	}
	c.pop_front();
	for (int i = 0; i < c.size(); i++) {
		std::cout << c[i] << '|';
	}
	std::cout << std::endl;
	deque<int> d(7);
	for (int i = 0; i <= 6; i++) {
		d.push_front(i);
	}
	d.pop_front();
	if (d.begin() == d.end()) {
		std::cout << "same";

	}
	/*for (int val : d) {
		std::cout << val << '|';
	}*/
	std::cout << std::endl;
	return EXIT_SUCCESS;
}