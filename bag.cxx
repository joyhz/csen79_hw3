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
    top  = -1;

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
            throw std::out_of_range(std::string("index out of range"));
        return data[i];
    };
    void Bag::setData(const int i, const Data &d) {
        if (i < 0 || i >= DATASIZE)
            throw std::out_of_range(std::string("index out of range"));
        data[i] = d;
    }
    void Bag::push(const Data &d) {
        if (top >= DATASIZE - 1)
            throw std::overflow(std::string("Stack is full"));
        data[++top] = d;
    };
    Bag::Data Bag::pop() {
        //if (isEmpty())
        if (top == -1)
            throw std::out_of_range("Can't pop, stack is empty");
        return data[top--];
    };
    void Bag::print() const {
        //if(isEmpty())
        if (top == -1)
            throw std::out_of_range("Cant print, stack is empty");    // If it's empty, we can't print anything
        for(int i = top - 1; i >= 0; i--)
        {
                std::cout << data[i] << std::endl; // Printing from the top -> down
        }
    };
}
