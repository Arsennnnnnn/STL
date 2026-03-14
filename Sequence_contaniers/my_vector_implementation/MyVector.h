#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list>
#include <utility>

template<typename T>
class Vector {
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
    Vector()
        : _data{nullptr}, _size{0}, _capacity{2} {
        _data = new T[_capacity];
    }

    explicit Vector(const std::size_t size)
        : _data(new T[size]{}), _size(size), _capacity(size) {}
    Vector(std::initializer_list<T> list)
    : _data(new T[list.size()]), _size(list.size()), _capacity(list.size()) {
        int i{};
        for (const auto& item : list) {
            _data[i++] = item;
        }
    }

    ~Vector() {
        clear();
    }

    Vector (const Vector& other)
        : _data(new T[other._capacity]{}), _size(other._size), _capacity(other._capacity) {
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    Vector& operator=(const Vector& other) {
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

    Vector(Vector&& other) noexcept
        : _data(other._data), _size(other._size), _capacity(other._capacity) {
        other._data = nullptr;
        other._capacity = 0;
        other._size = 0;
    }

    Vector& operator=(Vector&& other) noexcept {
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
        if (_size > 0)
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
    std::size_t Size() const {
        return _size;
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
    void printVector() {
        for (std::size_t i = 0; i < _size; ++i) {
            std::cout << _data[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif //MYVECTOR_H
