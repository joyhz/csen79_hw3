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
            throw std::out_of_range(std::string("index out of range"));
        return data[i];
    };
    void Bag::setData(const int i, const Data &d) {
        if (i < 0 || i >= DATASIZE)
            throw std::out_of_range(std::string("index out of range"));
        data[i] = (Data) d;
    }
    void Bag::push(const Data &) {
        if (top >= DATASIZE - 1)
            throw std::overflow(std::string("Stack is full"));
        data[++top] = Data d;    // Not entirely sure about this
    };
    Bag::Data Bag::pop() {
        if (isEmpty())
            throw std::out_of_range("Can't pop, stack is empty");
        data[top--];    // Also not too sure about this
        return 0;
    };
    void Bag::print() const {};
}
