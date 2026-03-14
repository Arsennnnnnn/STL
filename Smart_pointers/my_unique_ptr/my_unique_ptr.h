#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H

template<typename T>
class my_unique_ptr {
    T* _ptr;
public:
    my_unique_ptr()
        : _ptr(nullptr) {}
    my_unique_ptr(T* ptr)
        : _ptr(ptr) {}

    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    my_unique_ptr(my_unique_ptr &&unique_ptr) noexcept {
        _ptr = unique_ptr._ptr;
        unique_ptr._ptr = nullptr;
    }
    my_unique_ptr& operator = (my_unique_ptr&& unique_ptr) noexcept {
        if (this != &unique_ptr) {
            delete _ptr;
            _ptr = unique_ptr._ptr;
            unique_ptr._ptr = nullptr;
        }
        return *this;
    }
    ~my_unique_ptr() {
        delete _ptr;
        _ptr = nullptr;
    }

    T* get() const { return _ptr; }

    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }
};




#endif //MY_UNIQUE_PTR_H
