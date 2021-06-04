//
//

#ifndef Q4_PRIORITYQUEUE_TEST_H
#define Q4_PRIORITYQUEUE_TEST_H
#include <iostream>
template< class T>
class Test{
    template<class TT>
    friend std::ostream &operator<<(std::ostream &os, const Test<TT> &p);
    size_t priority;
    T value;
public:
    Test(T v, std::size_t pr)  :priority{pr}, value{v}{}
    Test() = default;
    bool operator<(const Test<T> &rhs) const {

        return this->priority < rhs.priority;
    }
    bool operator==(const Test<T> &rhs) const {
        return (this->priority == rhs.priority );
    }
    bool operator<=(const Test<T> &rhs) const {
        return (this->priority <= rhs.priority );
    }


};

template<class TT>
std::ostream &operator<<(std::ostream &os, const Test<TT> &p) {
    os<< p.value;
    return os;
}



#endif //Q4_PRIORITYQUEUE_TEST_H
