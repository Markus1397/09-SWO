#pragma once
#include <cstddef>


template <typename T> class circular_buffer {
public:
	circular_buffer(std::size_t size);
    circular_buffer(const circular_buffer<T>& other);
    ~circular_buffer();
	void put_front(const T& item);
	void put_back(const T& item);


	void pop_back(void);
	void pop_front(void);

	void reset(void);

	bool is_empty(void) const;

	bool is_full(void) const;

	std::size_t capacity(void) const;

	std::size_t size(void) const;

	const T& operator [] (std::size_t pos) const;
	T& operator [] (std::size_t pos);

	const T& at(std::size_t pos) const;
	T& at(std::size_t pos);

private:
	T* m_p_buffer {nullptr};
	std::size_t m_header {0};
	std::size_t m_tail  {0};
	const std::size_t m_max_size;
	bool m_is_full {false};
};