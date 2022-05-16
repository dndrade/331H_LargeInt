/*
    Program: Large Int
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  program handles large integers (positive and negative)
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
struct node {
    T data; // item's date
    node* next; // next node pointer
    node* previous; // previous node pointer
    node(T item = {}, node<T>* prev = nullptr, node<T>* nxt = nullptr)
        : data(item), previous(prev), next(nxt) {} // node constructor
};
#endif