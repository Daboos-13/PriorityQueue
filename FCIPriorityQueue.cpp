//
//

#include "FCIPriorityQueue.h"
#include <iostream>


template<class T>
FCIPriorityQueue<T>::FCIPriorityQueue() {

}

//template<class T>
//void FCIPriorityQueue<T>::enqueue(T value, std::size_t priority) {
//    if (!head){
//        head = new Node<T>(value,priority, nullptr);
//        tail = head;
//
//    }else{
//        Node<T>* t = new Node<T> (value,priority, nullptr);
//        Node<T>* q= nullptr;
//        Node<T> * p = head;
//        while (p){
//            if (t->getPriority()<=p->getPriority()){
//                if (p==head){
//                    t->setNext(head);
//                    head= t;
//                    break;
//
//                }else{
//                    t->setNext(p);
//                    q->setNext(t);
//                    break;
//                }
//            }else{
//                q=p;
//                p= p->getNext();
//            }
//
//        }
//        if (!t->getNext()){
//            tail->setNext(t);
//            tail =t;
//
//        }
//
//    }
//}
template<class T>
void FCIPriorityQueue<T>::enqueue(T value) {
        if (list.isEmpty()){
            list.addToHead(value);
            return;
        }
        bool check= false;
       Node<T>*q = list.begin();
       Node<T> *p = nullptr;
        while (q && q->getData()<=value){
//            if (q->getData()<value){
//
//                list.addToIndex(value,i);
//                check = true;
//                break;
//
//                }
//            if (q->getData()==value){
//
//                list.addToIndex(value,i);
//                check = true;
//                break;
//            }
//            q= q->getNext();
//            if (p){
//                p=p->getNext();
//            }
//            i++;
            p=q;
            q = q->getNext();


        }
        if (p){
            if (p->getNext()) {
                auto *t = new Node<T>(value, q);
                p->setNext(t);
            }else{
                auto *t = new Node<T>(value, q);
                p->setNext(t);

                list.setTail(t);

            }

        }else{
            list.addToHead(value);
        }

}

template<class T>
void FCIPriorityQueue<T>::dequeue() {
    list.removeFromHead();
}

template<class T>
T FCIPriorityQueue<T>::first() {
    return list.front();
}

template<class T>
bool FCIPriorityQueue<T>::isEmpty() {
    return list.isEmpty();
}

template<class T>
void FCIPriorityQueue<T>::print() {
std::cout<<list;

}
