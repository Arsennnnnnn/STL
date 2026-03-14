#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace mstd {
    template <typename T>
    struct Node {
        T data;
        Node* next;

        Node(const T& val);
    };


    template <typename T>
    class List {
    private:
        Node<T>* head;

    public:
        List();
        void push_back(T val);
        void push_front(T val);
        void insert(int pos, T val);

        ~List();
    };

    template<typename T>
    Node<T>::Node(const T& val)
        : data(val), next(nullptr) {
    }

    template <typename T>
    List<T>:: List()
        : head(nullptr) {}

    template <typename T>
    void List<T>::push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    template <typename T>
    void List<T>::push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    template <typename T>
    void List<T>::insert(int pos, T val) {
        if (pos < 0) {
            std::cout << "invalid position" << std::endl;
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        Node<T>* temp = head;
        for (int i = 0; i < pos - 1 && temp; ++i)
            temp = temp->next;

        if (!temp) {
            std::cout << "Position out of bounds\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    template <typename T>
    List<T>::~List() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

#endif //LINKEDLIST_H
