#ifndef DLL_H
#define DLL_H

#include "node.h"
#include "iterator.h"

template<class T>
class dll {
private:
    node<T>* head; // first node pointer
    node<T>* tail; // last node pointer
    int length; // node counter
    bool found; //

public:
    dll(); // constructor
    ~dll(); // destructor
    void init(); // initialized member variables

    dll(const dll<T>& other); // copy constructor
    dll<T>& operator=(const dll<T>& other); // assignment operator
    void copy(const dll<T>& other); // copies the list
    void destroy(); // destroys the objects
    bool isEmpty(); // returns whether the list is empty
    int getLength(); // returns node count
    bool getFound() { return found == true; } // returns true if node is found

    void insertBack(T item); // inserts a item @ back of list
    void insertFront(T item); // inserts a item @ front of list
    void deleteItem(T item); // deletes a given item
    node<T>* search(T item); // searches for a given item
    void print(); // outputs the list to the console

    // iterators methods
    iterator<T> begin() { return iterator<T>(this->head); }
    iterator<T> tend() { return iterator<T>(this->tail); }
    iterator<T> end() { return iterator<T>(); }
};
#endif // !DLL_H

