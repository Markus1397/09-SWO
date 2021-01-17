#include <iostream>
#include "circular_buffer.h"


int main() {
	circular_buffer<int> c{ 6 };
	/*for (std::size_t i = 0; i < 7; i++) {
		c.put_back((int)i);
	}
	for (std::size_t i = 0; i < c.size(); i++) {
		std::cout << c[i] << '|';
	}*/
	
	return EXIT_SUCCESS;
}