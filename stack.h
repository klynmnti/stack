#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#pragma once

const int MAX_SIZE = 20;    // used to set the maximum size of stack array

template<typename T>    // template for stack
class stack {
    public:
        stack();
        stack(const stack &cpy) {}; 
        void push(T val);
        void pop();
        void pop_two();
        T top();
        bool empty();
        // Ostream operator for personal testing
        friend ostream& operator<<(ostream &o, const stack &rhs) {
            for (int i = 0; i < rhs.size; i++) {
                cout << rhs.data[i] << " ";
            }
            return o;
        }
    private:
        T data[MAX_SIZE];   // array of type T, set to a max size of 20
        int size;
};

// Default Constructor sets size to 0
template<typename T>
stack<T>::stack() {
    size = 0;
}
// Empty function returns true if the size of array is 0
template<typename T>
bool stack<T>::empty() {
    if (size == 0) { return true; }
    else { return false; }
}
// Push function adds a new element to the end of the array after increasing the size
// Throws an exception if the array is already full
template<typename T>
void stack<T>::push(T val) {
    if (size == MAX_SIZE) { throw overflow_error("Called push on full stack."); }
    size++;
    data[size] = val;
}
// Pop function removes the last element in the array
// Throws exception if the array is empty
template<typename T>
void stack<T>::pop() {
    if (empty()) { throw out_of_range("Called pop on empty stack."); }
    size--;
}
// Pop_two function removes the last two elements in the array
// Throws exception if there are less than two elements
template<typename T>
void stack<T>::pop_two() {
    if (empty()) { throw out_of_range("Called pop_two on empty stack."); }
    else if (size == 1) { throw out_of_range("Called pop_two on a stack of size 1." ); }
    size -= 2;
}
// Top function returns the value at the top of the stack
// which is the last element in the array
template<typename T>
T stack<T>::top()  {
    if (empty()) { throw underflow_error("Called top on empty stack."); }
    return data[size]; 
}

#endif