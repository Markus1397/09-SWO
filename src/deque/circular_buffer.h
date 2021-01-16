#pragma once
#include <cstddef>

template <typename T> class circular_buffer {
public:
	circular_buffer(std::size_t size);
    circular_buffer(const circular_buffer<T>& other);
    ~circular_buffer();
	void put(const T& item);

	T get(void);

	void reset(void);

	bool is_empty(void) const;

	bool is_full(void) const;

	std::size_t capacity(void) const;

	std::size_t size(void) const;

private:
	T* m_p_buffer {nullptr};
	std::size_t m_header {0};
	std::size_t m_tail  {0};
	const std::size_t m_max_size;
	bool m_is_full {false};
};