#ifndef MY_FOR_EACH_H
#define MY_FOR_EACH_H

template <typename InputIt, typename UnaryFunction>
UnaryFunction my_for_each(InputIt first, InputIt last, UnaryFunction f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

#endif //MY_FOR_EACH_H
