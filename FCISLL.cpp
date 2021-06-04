// Program: FCISLL is a generic single linked list 
//          Developed for CS214 Data Structures
//          at FCI, Cairo University
// Author:  Mohammad El-Ramly, 8 Mar. 2013
// Link: http://www.mathcs.duq.edu/drozdek/DSinCpp/
#include "FCISLL.h"
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
ostream& operator<< (ostream& out, Node<T> node) {
    out << node.getData() << "->";
    return out;
}

////////////////////////////////
template <class T>
void FCISLL<T>::addToTail(T item) {
    Node<T>* ptr = new Node<T>(item, nullptr);
    if (head == nullptr)
        head = tail = ptr;
    else {
        tail->setNext(ptr);
        tail = ptr;
    }
    counter++;
}

template <class T>
void FCISLL<T>::addToHead(T item) {
    auto* ptr = new Node<T>(item, head);
    head = ptr;
    if (tail == nullptr)
        tail = head;
    counter++;

}

template <class T>
FCISLL<T>::~FCISLL () {}

template <class T>
void FCISLL<T>::addToIndex(T value, int index) {
    if(!head){
        auto *t = new Node<T>(value, nullptr);

        head = t;
        tail =head;
        counter++;
        return;
    }

    Node<T>*p=head;
    for(int i=0;i<index &&p;i++){
        p=p->getNext();
    }
    if (p){
        if(p==tail){
            auto *t=new Node<T>(value, nullptr);
            p->setNext(t);
            tail=t;
            counter++;

        }else {
            auto*t = new Node<T>(value,p->getNext());
            p->setNext(t);
            counter++;

        }
    }

}

template <class T>
bool FCISLL<T>::search(T item) {
    Node<T>* ptr = head;
    while (! (ptr == nullptr) && item != ptr->getData())
        ptr = ptr -> getNext();
    if (ptr != nullptr)
        return true;
    else
        return false;   
}

template <class T>
ostream& operator<<(ostream& stream, FCISLL<T> list) {
        if (list.head != 0) {
            Node<T>* ptr = list.head;
            stream << *ptr;
            while (ptr != list.tail) {
                ptr = ptr->getNext();
                stream << *ptr;
            }
            stream << "NULL" << endl;
        }
        return stream;
}

template<class T>
void FCISLL<T>::removeFromHead() {
    if (!head)
        return ;
    Node<T>* p = head;
    T holdData = p->getData();
    head = head->getNext();
    delete  p;
    if (head == nullptr)
        tail = nullptr;
    counter--;

}

template<class T>
void FCISLL<T>::removeFromTail(Node<T> * ptr) {
    Node<T>* p;
    if (!tail)
        return ;
    if (ptr)
         p = ptr;
    else
         p = head;
    while (p->getNext() != tail){
        p= p->getNext();
    }

    delete tail;
    tail = p;
    tail->setNext(nullptr);
    counter--;


}

template<class T>
T FCISLL<T>::front() {
    return head->getData();
}

template<class T>
T FCISLL<T>::back() {
    return tail->getData();
}

template<class T>
size_t FCISLL<T>::size() {
    return counter;
}

template<class T>
T FCISLL<T>::removeFromIndex(std::size_t index) {
    if (index>=counter){
        cerr<<"the given index is out of bound"<<endl;
        return NULL;
    }
    Node<T> *p = head;
    Node<T> *q = nullptr;
    if (index==0){
      T data =   removeFromHead();
        return data;
    }
    for (int i = 1; i <= index; ++i) {
        q =p;
        p = p->getNext();
    }
    q->setNext(p->getNext()) ;
    T data = p->getData();
    delete p;
    if (tail == p){
        tail = q;
    }
    counter--;

    return data;



}

template<class T>
T FCISLL<T>::removeItem(T item) {
    Node<T> * p= head;
    Node<T> * q= nullptr;
    while (p){
        if (p->getData()==item){
            if (p==head){
                T data = removeFromHead();
                return data;
            }else if (p==tail){
                T data = removeFromTail(q);
                return data;
            }else{
                q->setNext(p->getNext());
                T data = p->getData();
                delete p;
                counter--;
                return data;

            }
        }else{
            q= p;
            p = p->getNext();


        }
    }
    cerr<<"item is t not found "<<endl;
    return NULL;
}

template<class T>
void FCISLL<T>::removeWithPredicate(bool (predication)(T & item)) {
    Node<T> * p= head->getNext();
    Node<T> * q  = head;
    Node<T> *r = nullptr;
    while (q){
        if (predication(q->getData())){
            if (q==head){
                delete q;
                q=head=p;
                if (p)
                p=p->getNext();
                counter--;
                if (head== nullptr)
                    tail= nullptr;

            }else if (q==tail){
                delete q;
                r->setNext(nullptr);
                tail=r;
                counter--;
                if (tail== nullptr)
                    head= nullptr;

            }else {
                delete q;
                r->setNext(p);
                q=p;
                if (p)
                p=p->getNext();

                counter--;
            }
        }else {
            r=q;
            q=p;
            if (p)
            p=p->getNext();

        }
    }
    if (r) {
        if (predication(r->getData())) {
            removeFromTail();
        }
    }
}

template<class T>
bool FCISLL<T>::isEmpty() {
    return head== nullptr;
}

template<class T>
Node<T>* FCISLL<T>::begin() {
    return head;
}

template<class T>
Node<T> *FCISLL<T>::end() {
    return tail;
}

template<class T>
void FCISLL<T>::setTail(Node<T> *t) {
  tail = t;
}


///////////////////////////////

