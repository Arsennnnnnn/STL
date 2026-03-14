#ifndef MY_PAIR_H
#define MY_PAIR_H

template <typename T1, typename T2>
struct  my_pair {
    T1 first;
    T2 second;
    my_pair() : first(), second() {}
    my_pair(const T1 first, const T2& second) : first(first), second(second) {}
    void swap(my_pair<T1,T2>& other) {
        std::swap(first, other.first);
        std::swap(second, other.second);
    }
};





#endif //MY_PAIR_H
