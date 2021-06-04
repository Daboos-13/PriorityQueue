//
//

#ifndef Q4_PRIORITYQUEUE_FCIPRIORITYQUEUE_H
#define Q4_PRIORITYQUEUE_FCIPRIORITYQUEUE_H
#include <iostream>
#include "FCISLL.cpp"




template <class T >
class FCIPriorityQueue {
private:
   FCISLL<T> list ;

public:
    FCIPriorityQueue();

    void enqueue(T value );
    void dequeue();
    T first();
    bool isEmpty();
    void print();




};


#endif //Q4_PRIORITYQUEUE_FCIPRIORITYQUEUE_H
