#include "./deque.h"
#include <stdexcept>
using namespace swo;
template<typename T>  deque<T>::deque() {

}

template<typename T>  deque<T>::~deque() {
	if (m_p_buffer != nullptr)
		delete m_p_buffer;
}

template<typename T> deque<T>::deque(size_type count) : deque<T>::deque(count, T{}) {
	
}

template<typename T> deque<T>::deque(size_type count, T const& value) {
	if (count <= 0)
		throw std::invalid_argument("count");

	m_p_buffer = new circular_buffer<T>(count);
	for (size_type i = 0; i < count; i++) {
		m_p_buffer->put(value);
	}
}


