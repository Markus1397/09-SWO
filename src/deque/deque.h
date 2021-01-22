//       $Id: deque.h 2709 2021-01-10 11:19:47Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS20/VZ/deque/deque.h $
// $Revision: 2709 $
//     $Date: 2021-01-10 12:19:47 +0100 (So., 10 Jän 2021) $
//   $Author: p20068 $
//   Creator: Peter Kulczycki
//  Creation: January 10, 2021
// Copyright: (c) 2021 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg.
//            It is distributed under the Boost Software License (see
//            https://www.boost.org/users/license.html).

#pragma once

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include "./circular_buffer.h"

namespace swo {
    template <typename T> class deque final {
    public:
        using const_reference = T const&;
        using reference = T&;
        using size_type = std::size_t;
        using value_type = T;


        friend bool operator == (deque const& lhs, deque const& rhs) noexcept {
            if (rhs.m_size != lhs.m_size)
                return false;
            for (size_t i = 0; i < lhs.m_size; i++) {
                if (rhs[i] != lhs[i])
                    return false;
            }

            return true;
        }
        friend bool operator != (deque const& lhs, deque const& rhs) noexcept {
            return !(lhs == rhs);
        }
        friend bool operator <  (deque const& lhs, deque const& rhs) noexcept {
            const typename deque<T>::size_type min_size = std::min(lhs.m_size, rhs.m_size);
            for (size_t i = 0; i < min_size; i++) {
                if (lhs[i] < rhs[i])
                    return true;
                else if (lhs[i] > rhs[i])
                    return false;
            }
            return lhs.m_size < rhs.m_size;
        }
        friend bool operator <= (deque const& lhs, deque const& rhs) noexcept {
            return lhs < rhs || lhs == rhs;
        }
        friend bool operator >  (deque const& lhs, deque const& rhs) noexcept {
            return rhs < lhs;
        }
        friend bool operator >= (deque const& lhs, deque const& rhs) noexcept {
            return lhs > rhs || lhs == rhs;
        }

        friend void swap(deque <T>& a, deque <T>& b) noexcept {
            a.swap(b);
        }

        class iterator final {
        public:
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::random_access_iterator_tag;
            using pointer = T*;
            using reference = T&;
            using value_type = T;

            friend bool operator == (iterator const& lhs, iterator const& rhs) noexcept {
                return lhs.m_p_buffer == rhs.m_p_buffer && lhs.m_index == rhs.m_index;
            }
            friend bool operator != (iterator const& lhs, iterator const& rhs) noexcept {
                return !(lhs == rhs);
            }
            friend bool operator <  (iterator const& lhs, iterator const& rhs) noexcept {
                return (*lhs.m_p_buffer)[lhs.m_index] < (*rhs.m_p_buffer)[rhs.m_index];
            }
            friend bool operator <= (iterator const& lhs, iterator const& rhs) noexcept {
                return (*lhs.m_p_buffer)[lhs.m_index] <= (*rhs.m_p_buffer)[rhs.m_index];
            }
            friend bool operator >  (iterator const& lhs, iterator const& rhs) noexcept {
                return (*lhs.m_p_buffer)[lhs.m_index] > (*rhs.m_p_buffer)[rhs.m_index];
            }
            friend bool operator >= (iterator const& lhs, iterator const& rhs) noexcept {
                return (*lhs.m_p_buffer)[lhs.m_index] >= (*rhs.m_p_buffer)[rhs.m_index];
            }

            friend iterator operator + (iterator itor, difference_type offset) noexcept {
                return itor += offset;
            }

            friend iterator operator - (iterator itor, difference_type offset) noexcept {
                return itor -= offset;
            }

            iterator();
            iterator(iterator const& src);

            ~iterator() =default;

            iterator& operator = (iterator const& src);

            reference operator *  ();
            pointer   operator -> ();

            reference operator [] (difference_type offset);

            iterator& operator ++ () noexcept;
            iterator   operator ++ (int) noexcept;
            iterator& operator -- () noexcept;
            iterator   operator -- (int) noexcept;

            iterator& operator += (difference_type offset) noexcept;
            iterator& operator -= (difference_type offset) noexcept;
        private:
            friend class deque;
            iterator(circular_buffer<value_type>* buffer, size_type idx);
            circular_buffer<value_type>* m_p_buffer{ nullptr };
            size_type m_index{ 0 };

        };

        deque();
        explicit deque(size_type count);
        deque(size_type count, T const& value);

        deque(deque const& src);
        deque(deque&& src) noexcept;
        deque(std::initializer_list <T> init);

        ~deque();

        deque& operator = (deque const& src);
        deque& operator = (deque&& src) noexcept;
        deque& operator = (std::initializer_list <T> init);

        const_reference operator [] (size_type pos) const;
        reference       operator [] (size_type pos);

        const_reference at(size_type pos) const;
        reference       at(size_type pos);
        const_reference back() const;
        reference       back();
        const_reference front() const;
        reference       front();

        iterator begin() noexcept;
        iterator end() noexcept;

        bool      empty() const noexcept;
        size_type size() const noexcept;

        void clear() noexcept;

        void push_back(T const& value);
        void push_back(T&& value);
        void pop_back();

        void push_front(T const& value);
        void push_front(T&& value);
        void pop_front();

        void resize(size_type count);
        void resize(size_type count, T const& value);

        void swap(deque& other) noexcept;

    private:
        circular_buffer<T>* m_p_buffer{ nullptr };
        size_type m_size{ 0 };

        void resize_if_full(void);

    };
    //-------------------------------------------------
    //--------------------Deque------------------------
    //-------------------------------------------------
#pragma region Deque


    template <typename T> deque<T>::deque() {

    }

    template <typename T> deque<T>::deque(size_type count) : deque<T>::deque(count, T{}) {

    }
    template <typename T> deque<T>::deque(size_type count, T const& value) : m_size{ count },
        m_p_buffer{ count > 0 ? new circular_buffer<T>(count) : nullptr } {
        for (int i = 0; i < count; i++) {
            m_p_buffer->push_front(value);
        }
    }

    template <typename T> deque<T>::deque(deque const& src) {
        *this = src;
    }

    template <typename T> deque<T>::deque(deque&& src) noexcept {
        *this = src;
    }

    template<typename T> deque<T>::deque(std::initializer_list<T> init) : deque::deque(init.size()) {
        for (T i : init) {
            push_back(i);
        }
    }

    template<typename T> typename deque<T>::size_type deque<T>::size() const noexcept {
        if (m_p_buffer == nullptr)
            return 0;
        return m_p_buffer->size();
    }

    template<typename T> deque<T>& deque<T>::operator = (deque<T> const& src) {
        this->m_size = src.size;
        if (this->m_size > 0) {
            this->m_p_buffer = new circular_buffer<T>(m_size);
            for (int i = 0; i < this->m_size; i++) {
                this->m_p_buffer->push_back(src[i]);
            }
        }
    }
    template<typename T> deque<T>& deque<T>::operator = (deque<T>&& src) noexcept {
        this->m_p_buffer = src.m_p_buffer;
        this->m_size = src.m_size;
        src.m_p_buffer = nullptr;
    }
    template<typename T> deque<T>& deque<T>::operator = (std::initializer_list <T> init) {
        m_size = init.size;
        if (m_size > 0) {
            for (const T val : init) {
                m_p_buffer->push_back(val);
            }
        }
        return this;
    }
    template<typename T>  const  T& deque<T>::operator [] (size_type pos) const {
        if (pos < 0 || pos >= m_size)
            throw new std::invalid_argument("pos");
        if (m_p_buffer != nullptr)
            return (*m_p_buffer)[pos];
        return T{};
    }
    template<typename T>   T& deque<T>::operator [] (size_type pos) {
        if (pos < 0 || pos >= m_size)
            throw new std::invalid_argument("pos");
        if (m_p_buffer != nullptr)
            return (*m_p_buffer)[pos];
        static T def = T{};
        return def;
    }
    template<typename T> const T& deque<T>::at(size_type pos) const {
        return *this[pos];
    }
    template<typename T>  T& deque<T>::at(size_type pos) {
        return *this[pos];
    }


    template<typename T> const T& deque<T>::back() const {
        return at(size() - 1);
    }

    template<typename T> T& deque<T>::back() {
        return at(size() - 1);
    }

    template<typename T> const T& deque<T>::front() const {
        return at(0);
    }

    template<typename T> T& deque<T>::front() {
        return at(0);
    }

    template<typename T> void deque<T>::push_back(T const& value) {
        if (m_p_buffer != nullptr) {
            resize_if_full();
            m_p_buffer->push_back(value);
        }
          
    }
    template<typename T> void deque<T>::push_back(T&& value) {
        if (m_p_buffer != nullptr) {
            resize_if_full();
            m_p_buffer->push_back(value);
        }
            
    }
    template<typename T> void deque<T>::pop_back() {
        if (m_p_buffer != nullptr)
            m_p_buffer->pop_back();
    }

    template<typename T> void deque<T>::push_front(T const& value) {
        if (m_p_buffer != nullptr) {
            resize_if_full();
            m_p_buffer->push_front(value);
        }
          
    }
    template<typename T> void deque<T>::push_front(T&& value) {
        if (m_p_buffer != nullptr) {
            resize_if_full();
            m_p_buffer->push_front(value);
        }
           
    }
    template<typename T> void deque<T>::pop_front() {
        if (m_p_buffer != nullptr)
            m_p_buffer->pop_front();
    }

    template<typename T> void deque<T>::swap(deque& other) noexcept {
        swap(other.m_size, this->m_size);
        swap(other.m_p_buffer, this->m_p_buffer);
    }

    template<typename T> typename deque<T>::iterator deque<T>::begin() noexcept {
        return deque<T>::iterator{ m_p_buffer,0 };
    }

    template<typename T> typename deque<T>::iterator deque<T>::end() noexcept {
        return deque<T>::iterator{ m_p_buffer, size()};
    }


    template<typename T> bool deque<T>::empty() const noexcept {
        if (m_p_buffer == nullptr)
            return true;
        return m_p_buffer->is_empty();
    }

    template<typename T> void deque<T>::clear() noexcept {
        if (m_p_buffer == nullptr)
            m_p_buffer->reset();
    }

    template<typename T> void deque<T>::resize(size_type count) {
        resize(count, T{});
    }

    template<typename T> void deque<T>::resize(size_type count, T const& value) {
        m_size = count;
        if (count >= 0 && m_p_buffer != nullptr) {
            m_p_buffer->resize(count);
            while (count > size()) {
                push_back(value);
            }
        }
    }


    template<typename T> deque<T>::~deque() {
        if (m_p_buffer != nullptr)
            delete m_p_buffer;
    }

    template<typename T> void deque<T>::resize_if_full(void) {
        if (m_p_buffer->is_full()) {
            m_p_buffer->resize(m_p_buffer->capacity()+1);
        }
    }


#pragma endregion
    //-------------------------------------------------
    //--------------------Iterator---------------------
    //-------------------------------------------------
#pragma region Iterator
    template<typename T> deque<T>::iterator::iterator() : m_p_buffer{ nullptr }, m_index{ 0 } {

    }

    template<typename T> deque<T>::iterator::iterator(circular_buffer<value_type>* buffer, size_type idx) : m_p_buffer {buffer}, m_index{idx}{

    }

    template<typename T> deque<T>::iterator::iterator(deque<T>::iterator const& src) : m_index{ src.m_index }, m_p_buffer{src.m_p_buffer} {
       
    }

    template<typename T> typename deque<T>::iterator& deque<T>::iterator::operator+=(deque<T>::iterator::difference_type offset) noexcept {
        m_index += offset;
        return *this;
    }
    template<typename T> typename deque<T>::iterator& deque<T>::iterator::operator-=(deque<T>::iterator::difference_type offset) noexcept {
        m_index -= offset;
        return *this;
    }
    template<typename T> T& deque<T>::iterator::operator *() {
        return (*m_p_buffer)[m_index];
    }
    template<typename T> T* deque<T>::iterator::operator ->() {
        return (*m_p_buffer)[m_index];
    }
    template<typename T> T& deque<T>::iterator::operator[](deque<T>::iterator::difference_type offset) {
        return (*m_p_buffer)[m_index + offset];
    }
    template<typename T> typename deque<T>::iterator& deque<T>::iterator::operator++() noexcept {
        *this += 1;
        return *this;
    }
    template<typename T> typename deque<T>::iterator deque<T>::iterator::operator ++ (int) noexcept {
        deque<T>::iterator old{ *this };
        *this += 1;
        return old;
    }
    template<typename T> typename deque<T>::iterator& deque<T>::iterator::operator--() noexcept {
        *this -= 1;
    }
    template<typename T> typename deque<T>::iterator deque<T>::iterator::operator -- (int) noexcept {
        deque<T>::iterator old{ *this };
        *this -= 1;
        return old;
    }


    template<typename T> typename deque<T>::iterator& deque<T>::iterator::operator=(iterator const& src) {
        m_index =  src.m_index; 
        m_p_buffer= src.m_p_buffer;
    }

    #pragma endregion
}