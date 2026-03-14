#ifndef MY_SET_H
#define MY_SET_H

#include <iostream>

template <typename T>
class my_set {
private:
    struct node {
        T value;
        node* left;
        node* right;

        explicit node(const T& v)
            : value(v), left(nullptr), right(nullptr) {}
    };

    node* _root;
    std::size_t _size;

private:
    bool insert(node*& cur, const T& value) {
        if (!cur) {
            cur = new node(value);
            ++_size;
            return true;
        }

        if (value < cur->value)
            return insert(cur->left, value);
        else if (value > cur->value)
            return insert(cur->right, value);
        else
            return false;
    }

    bool contains(node* cur, const T& value) const {
        if (!cur) return false;

        if (value < cur->value)
            return contains(cur->left, value);
        else if (value > cur->value)
            return contains(cur->right, value);
        else
            return true;
    }

    void inorder(node* cur) const {
        if (!cur) return;
        inorder(cur->left);
        std::cout << cur->value << " ";
        inorder(cur->right);
    }

    void postorder(node* cur) const {
        if (!cur) return;
        postorder(cur->left);
        postorder(cur->right);
        std::cout << cur->value << " ";
    }

    void preorder(node* cur) const {
        if (!cur) return;
        std::cout << cur->value << " ";
        preorder(cur->left);
        preorder(cur->right);
    }

    void destroy(node* cur) {
        if (!cur) return;
        destroy(cur->left);
        destroy(cur->right);
        delete cur;
    }

public:
    my_set() : _root(nullptr), _size(0) {}

    ~my_set() {
        destroy(_root);
    }

    bool insert(const T& value) {
        return insert(_root, value);
    }

    bool contains(const T& value) const {
        return contains(_root, value);
    }

    std::size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void print_inorder() const {
        inorder(_root);
        std::cout << std::endl;
    }

    void print_postorder() const {
        postorder(_root);
        std::cout << std::endl;
    }

    void print_preorder() const {
        preorder(_root);
        std::cout << std::endl;
    }
};



#endif //MY_SET_H
