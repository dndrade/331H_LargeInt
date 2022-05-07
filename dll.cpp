#include "dll.h"

template <class T> dll<T>::dll() { init(); }

template <class T> void dll<T>::init() {
    head = nullptr;
    tail = nullptr;
    length = 0;
    found = false;
}

template <class T> dll<T>::~dll() { destroy(); }

template <class T> dll<T>::dll(const dll<T>& other) {
    init();
    copy(other);
}

template <class T> dll<T>& dll<T>::operator=(const dll<T>& other) {
    if (this == &other) {
        return *this;
    }
    copy(other);

    return *this;
} // end of operator=

template <class T> void dll<T>::copy(const dll<T>& other) {
    length = other.length;

    if (other.head == NULL) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        node<T>* temp = other.head;
        while (temp != NULL) {
            insertBack(temp->data);
            temp = temp->next;
        }
    }
} // end of copy()

template <class T> void dll<T>::destroy() {
    node<T>* p = head;
    while (p != nullptr) {
        node<T>* delptr = p;
        p = p->next;
        delete delptr;
    }
    head = tail = nullptr;
} // end of destroy()

// inserting back
template <class T> void dll<T>::insertBack(T item) {
    length++;
    node<T>* n = new node<T>();
    n->data = item;
    n->next = nullptr;

    if (isEmpty()) {
        n->previous = nullptr;
        head = n;
        tail = n;
    }
    else {
        tail->next = n;
        n->previous = tail;
        tail = n;
    } // end of else
} // end of insertBack()

// inserting front
template <class T> void dll<T>::insertFront(T item) {
    node<T>* n = new node<T>();
    length++;
    n->data = item;
    n->previous = nullptr;
    if (isEmpty()) {
        // If list is empty, add the node  and update first and last
        n->next = nullptr;

        head = n;
        tail = n;
    }
    else {
        // If at least one node in the list, link new node
        // to old first and update first
        n->next = head;
        head->previous = n;
        head = n;
    }
} // end of insertFront()

template <class T> bool dll<T>::isEmpty() { return head == NULL; }

template <class T> int dll<T>::getLength() { return length; }

template <class T> void dll<T>::print() {
    if (head == NULL) {
        std::cout << "\nThe list is empty\n";
    }
    else {
        node<T>* p = head;
        while (p != NULL) {
            std::cout << p->data << " ";
            p = p->next;
        }
    }
} // end of print()

template <class T>
void dll<T>::deleteItem(T item) {
    node<T>* itemSearch = search(item);
    if (itemSearch == nullptr)
        return;
    length--;
    if (itemSearch == head) {
        // Do something it's the first node
        head = itemSearch->next;
        delete (itemSearch);
    }
    else if (itemSearch->next == nullptr) {
        // It's the last node
        itemSearch->previous->next = nullptr;
        delete (itemSearch);
    }
    else {
        // It's in the middle
        itemSearch->previous->next = itemSearch->next;
        itemSearch->next->previous = itemSearch->previous;
        delete (itemSearch);
    }
} // end of deleteItem();

template <class T>
node<T>* dll<T>::search(T item) {
    found = false;
    node<T>* n = head;
    while (n != nullptr) {
        if (n->data == item) {
            found = true;
            return n;
        }
        n = n->next;
    }
    std::cerr << "Item is not in the list. \n";
    return nullptr;
} // end of search()