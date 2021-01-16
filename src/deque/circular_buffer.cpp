#include "./circular_buffer.h"

template <typename T> circular_buffer<T>::circular_buffer(std::size_t size) : m_max_size{size}, 
    m_p_buffer {size > 0 ? new T[size] : nullptr}{

}

template <typename T> circular_buffer<T>::circular_buffer(const circular_buffer<T>& other){
    this->m_max_size = other.m_max_size;
    this->m_is_full = other.m_is_full;
    this->m_tail = other.m_tail;
    this->m_header = other.m_header;
    if(this->m_max_size > 0){
        this->m_p_buffer = new T[this->m_max_size];
        for (int i = 0; i < this->m_max_size; i++)
        {
            this->m_p_buffer[i] = other.m_p_buffer[i];
        }
        
    }
}

template <typename T> void circular_buffer<T>::put(const T& item) {
    m_p_buffer[m_header] = item;
    if(m_is_full) {
        m_tail = (m_tail + 1) % m_max_size;
    }
    m_header = (m_header + 1) % m_max_size;
    m_is_full = m_header == m_tail;
}

template <typename T> T circular_buffer<T>::get() {
    if(is_empty()) {
        return T();
    }

    //Read data and advance the tail (we now have a free space)
    T val = m_p_buffer[m_tail];
    m_is_full = false;
    m_tail = (m_tail + 1) % m_max_size;

    return val;
}

template <typename T>  bool circular_buffer<T>::is_empty() const{
		//if head and tail are equal, we are empty
		return (!m_is_full && (m_header == m_tail));
}

template <typename T> void circular_buffer<T>::reset() {		
    m_header = m_tail;
    m_is_full = false;
}

template <typename T> std::size_t circular_buffer<T>::capacity() const{
	return m_max_size;
}

template <typename T> std::size_t circular_buffer<T>::size() const {
    std::size_t size = m_max_size;

    if(!m_is_full)
    {
        if(m_header >= m_tail) {
            size = m_header - m_tail;
        }else {
            size = m_max_size + m_header - m_tail;
        }
    }

    return size;
}

template <typename T> bool circular_buffer<T>::is_full() const {
    return m_is_full;
}

template <typename T> circular_buffer<T>::~circular_buffer() {
    if(m_p_buffer != nullptr)
        delete [] m_p_buffer;
}
