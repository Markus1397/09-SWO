#pragma once
#include <cstddef>
#include <stdexcept>


template <typename T> class circular_buffer {
public:
	circular_buffer(std::size_t size);
    circular_buffer(const circular_buffer<T>& other);
    ~circular_buffer();
	void push_front(const T& item);
	void push_back(const T& item);


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
    void resize(std::size_t capacity);

private:
	T* m_p_buffer {nullptr};
    std::size_t m_head {0};
    std::size_t m_tail {0};
	std::size_t m_max_size;
    std::size_t m_size {0};

    std::size_t next(std::size_t curr) const;
    std::size_t prev(std::size_t curr) const;
};


template <typename T> circular_buffer<T>::circular_buffer(std::size_t size) : m_max_size{ size },
m_p_buffer{ size > 0 ? new T[size] : nullptr }{

}

template <typename T> circular_buffer<T>::circular_buffer(const circular_buffer<T>& other) {
    this->m_max_size = other.m_max_size;
    this->m_is_full = other.m_is_full;

    this->m_head = other.m_head;
    this->m_tail = other.m_tail;

    if (this->m_max_size > 0) {
        this->m_p_buffer = new T[this->m_max_size];

        for (int i = 0; i < this->m_max_size; i++) {
            this->m_p_buffer[i] = other.m_p_buffer[i];
        }

    }
}

template <typename T> void circular_buffer<T>::push_front(const T& item) {
    m_head = prev(m_head);
    m_p_buffer[m_head] = item;
    m_size++;
}

template <typename T> void circular_buffer<T>::push_back(const T& item) {
    m_p_buffer[m_tail] = item;
    m_tail = next(m_tail);
    m_size++;
}


template <typename T> void circular_buffer<T>::pop_back() {
    if (!is_empty()) {
        m_tail = prev(m_tail);
        m_size--;
    }
}

template<typename T> void circular_buffer<T>::pop_front(void) {
    if (!is_empty()) {
        m_head = next(m_head);
        m_size--;
    }
}

template <typename T>  bool circular_buffer<T>::is_empty() const {
    return m_size == 0;
}

template <typename T> void circular_buffer<T>::reset() {
    m_tail = m_head = m_size = 0;
}

template <typename T> std::size_t circular_buffer<T>::capacity() const {
    return m_max_size;
}

template <typename T> std::size_t circular_buffer<T>::size() const {
    return m_size;
}

template<typename T> const T& circular_buffer<T>::operator[](std::size_t pos) const {
    return at(pos);
}

template<typename T> T& circular_buffer<T>::operator[](std::size_t pos) {
    return at(pos);
}

template<typename T>
const T& circular_buffer<T>::at(std::size_t pos) const {
    return at(pos);
}

template<typename T> T& circular_buffer<T>::at(std::size_t pos) {
    if (pos < 0)
        throw std::invalid_argument("pos");
    return m_p_buffer[(m_head + pos) % m_max_size];
}

template <typename T> bool circular_buffer<T>::is_full() const {
    return m_size == m_max_size;
}



template <typename T> std::size_t  circular_buffer<T>::next(std::size_t curr) const {
    return (curr + 1) % m_max_size;
}
template <typename T> std::size_t  circular_buffer<T>::prev(std::size_t curr) const {
    if (curr == 0)
        return m_max_size - 1;
    return (curr - 1) % m_max_size;
}

template <typename T> void circular_buffer<T>::resize(std::size_t capacity) {
    T* new_buffer = new T[capacity];
    std::size_t num_to_cpy =  m_size;
    if (m_size > capacity) {
        num_to_cpy = capacity;
        m_size = capacity;
    }
    for (int i = 0; i < num_to_cpy; i++) {
        new_buffer[i] = at(i);
    }
    delete[] m_p_buffer;
    m_p_buffer = new_buffer;
    if (m_tail == m_head && m_size >0) {
        m_tail = m_max_size >= capacity ? 0 : m_max_size;
    }
    m_head = 0;
    m_max_size = capacity;
}

template <typename T> circular_buffer<T>::~circular_buffer() {
    if (m_p_buffer != nullptr)
        delete[] m_p_buffer;
}
