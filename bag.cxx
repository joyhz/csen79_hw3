/*
 * Names: Yuto Fraley, Theodore Griffin - Jones, Michael Tiburcio, Joy Zhu
 * Emails: yfraley@scu.edu, tgriffinjones@scu.edu, mtiburcio@scu.edu, jhzhu@scu.edu
 * recipe for containers using C-style array
 */
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string.h>
#include "bag.h"

namespace csen79 {
    // assignment
    Bag &Bag::operator=(const Bag &rhs) {
        std::cout << "assign" << std::endl;
        memcpy(this->data, rhs.data, DATASIZE);
        return *this;
    }

    // move constructor
    Bag::Bag(Bag &&rhs) {
        std::cout << "move constructor; calling assignment" << std::endl;
        this->operator=(rhs);
    }    

    // copy constructor
    Bag::Bag(const Bag &rhs) {
        std::cout << "copy; calling assignment" << std::endl;
        this->operator=(rhs);
    }    

    // move
    Bag &Bag::operator=(Bag &&rhs) {
        std::cout << "move; calling assign" << std::endl;
        return this->operator=(rhs);
    }

    // simple access functions
    // replace them with appropriate ones for assignments
    const Bag::Data &Bag::getData(const int i) const {
        if (i < 0 || i >= DATASIZE)
            throw std::out_of_range(std::string("Index out of range"));
        return data[i];
    };

    bool Bag::isEmpty() const {
        return top < 0;
    }

    bool Bag::isFull() const {
        return size() >= DATASIZE;  // Can't compare top w/ DATASIZE, compares int w/ size_t (unsigned int) --> have to convert top to size_t to compare
    }

    std::size_t Bag::size() const {
        return static_cast<std::size_t>(top + 1);
    }

    void Bag::setData(const int i, const Data &d) {
        if (i < 0 || i >= DATASIZE)    // No issue comparing here; neg int --> throw, pos int --> simple comparison
            throw std::out_of_range("Index out of range");
        data[i] = d;
    }
    void Bag::push(const Data &d) {
        if (top < -1) {
            throw std::underflow_error("Data corruption detected");
        }
        if (isFull()) {
            throw std::overflow_error("Stack is full");
        }
        data[++top] = d;
    };
    Bag::Data Bag::pop() {
        if (isEmpty())
            throw std::out_of_range("Can't pop, stack is empty");
        return data[top--];
    };
    void Bag::print() const {
        if(isEmpty())
            std::cout << "Stack is empty" << std::endl;
        for (int i = top; i >= 0; i--) {
            std::cout << data[i] << std::endl; // Printing from the top -> down
        }
    };
}
