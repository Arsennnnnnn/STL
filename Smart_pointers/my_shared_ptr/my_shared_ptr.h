#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H
#include <cstddef>

template<typename T>
class my_shared_ptr {
    T* _ptr;
    std::size_t* _ref_count;

    void add_ref() {
        if (_ref_count) {
            ++(*_ref_count);
        }
    }
    void release() {
        if (_ref_count) {
            --(*_ref_count);
            if (*_ref_count == 0) {
                delete _ptr;
                delete _ref_count;
            }
        }
    }

public:
    explicit my_shared_ptr()
        : _ptr(nullptr), _ref_count(nullptr) {}

    explicit my_shared_ptr(T* p)
        : _ptr(p), _ref_count(new std::size_t(1)) {}

    ~my_shared_ptr() {
        release();
    }

    my_shared_ptr(const my_shared_ptr& other)
        : _ptr(other._ptr), _ref_count(other._ref_count) {
        add_ref();
    }

    my_shared_ptr& operator=(const my_shared_ptr& other) {
        if (this != &other) {
            release();
            _ptr = other._ptr;
            _ref_count = other._ref_count;
            other._ptr = nullptr;
            other._ref_count = nullptr;
        }
        return *this;
    }

    T& operator*() const {return *_ptr;}
    T* operator->() const {return _ptr;}

    T* get() const {return _ptr;}

    std::size_t refCount() const {
        return _ref_count ? *_ref_count : 0;
    }
};



#endif //MY_SHARED_PTR_H
