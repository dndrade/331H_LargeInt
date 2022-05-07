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
            curr = curr->next;
            return *this;
        }

        iterator& operator--() {
            curr = curr->previous;
            return *this;
        }
        iterator& operator--(int) {
            curr = curr->previous;
            return *this;
        }
        bool operator!=(const iterator& other) const {
            return this->curr != other.curr;
        }
        const T& operator*() const { return curr->data; }
};
#endif