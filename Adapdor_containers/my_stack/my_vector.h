#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list>
#include <utility>

template<typename T>
class my_vector {
private:
    T* _data;
    std::size_t _size;
    std::size_t _capacity;
    void resize() {
        _capacity *= 2;
        T* _newData = new T[_capacity]{};
        for (std::size_t i = 0; i < _size; ++i) {
            _newData[i] = _data[i];
        }
        delete[] _data;
        _data = _newData;
    }
public:
    my_vector()
        : _data{nullptr}, _size{0}, _capacity{2} {
        _data = new T[_capacity];
    }

    explicit my_vector(const std::size_t size)
        : _data(new T[size]{}), _size(size), _capacity(size) {}
    my_vector(std::initializer_list<T> list)
    : _data(new T[list.size()]), _size(list.size()), _capacity(list.size()) {
        int i{};
        for (const auto& item : list) {
            _data[i++] = item;
        }
    }

    ~my_vector() {
        clear();
    }

    my_vector (const my_vector& other)
        : _data(new T[other._capacity]{}), _size(other._size), _capacity(other._capacity) {
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    my_vector& operator=(const my_vector& other) {
        if (this != &other) {
            delete[] _data;
            _capacity = other._capacity;
            _data = new T[_capacity]{};
            _size = other._size;
            for (std::size_t i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    my_vector(my_vector&& other) noexcept
        : _data(other._data), _size(other._size), _capacity(other._capacity) {
        other._data = nullptr;
        other._capacity = 0;
        other._size = 0;
    }

    my_vector& operator=(my_vector&& other) noexcept {
        if (this != &other) {
            delete[] _data;

            _data = other._data;
            _capacity = other._capacity;
            _size = other._size;

            other._data = nullptr;
            other._capacity = 0;
            other._size = 0;
        }
        return *this;
    }
    void push_back(T item) {
        if (_size == _capacity)
            resize();
        _data[_size++] = item;
    }
    // push back(T item, int count )
    // push back(T item, const T* arr)
    void pop_back() {
        if (_size == 0)
            return;

        _data[_size - 1].~T();
        --_size;
    }
    T& operator[](std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Cannot access index");
        }
        return _data[index];
    }
    const T& operator[](std::size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Cannot access index");
        }
        return _data[index];
    }
    std::size_t size() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    void clear() {
        _size = 0 ;
        _capacity = 0;
        delete[] _data;
        _data = nullptr;
    }
    void insert(const T& item, std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Cannot insert index");
        }
        if (index == _capacity) resize();
        for (std::size_t i = _size; i > index; --i) {
            _data[i] = _data[i - 1];
        }
        _data[index] = item;
        ++_size;
    }
    void erase(const std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Cannot erase index");
        }
        for (std::size_t i = index; i < _size - 1; ++i) {
            _data[i] = _data[i + 1];
        }
        --_size;
    }
    T front() const {
        if (_size == 0) {
            throw std::out_of_range("Cannot access front");
        }
        return _data[0];
    }
    T back() const {
        if (_size == 0) {
            throw std::out_of_range("Cannot access back");
        }
        return _data[_size - 1];
    }
    void printVector() const {
        for (std::size_t i = 0; i < _size; ++i) {
            std::cout << _data[i] << " ";
        }
        std::cout << std::endl;
    }

    T* begin() { return _data; }
    T* end() { return _data + _size; }
};

#endif //MYVECTOR_H
