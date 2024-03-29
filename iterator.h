/*
    Program: Large Int
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  program handles large integers (positive and negative)
*/

#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <class T>
class iterator {
private:
    node<T>* curr;

public:
    iterator() : curr(nullptr) {}
    iterator(node<T>* p) { curr = p; }

    iterator& operator++() {
        curr = curr->next;
        return *this;
    }

    iterator& operator++(int) {
        iterator temp = *this;
        ++(*this);
        return temp;
        // curr = curr->next;
        // return *this;
    }

    iterator& operator--() {
        curr = curr->previous;
        return *this;
    }
    iterator& operator--(int) {
        iterator temp = *this;
        --(*this);
        return temp;
    }
    bool operator!=(const iterator& other) const {
        return this->curr != other.curr;
    }
    const T& operator*() const { return curr->data; }

    operator bool() const { return curr; }
};

#endif