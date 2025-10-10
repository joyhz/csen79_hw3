/*
 * Names: Yuto Fraley, Theodore Griffin - Jones, Michael Tiburcio, Joy Zhu
 * Emails: yfraley@scu.edu, tgriffinjones@scu.edu, mtiburcio@scu.edu, jhzhu@scu.edu
 * recipe for containers using C-style array
 */
#ifndef BAG_H
#define BAG_H
namespace csen79 {

class Bag {
public:
    static constexpr size_t DATASIZE = 1000;    // array size
    using Data = int;   // create an alias for the data
    Bag(): data{0}, top(-1) {}

    
    // rule of 5
    ~Bag() = default;
    Bag(const Bag &);
    Bag(Bag &&);
    Bag &operator=(const Bag &);
    Bag &operator=(Bag &&rhs);

    // access functions
    const Data &getData(const int) const;
    void setData(const int, const Data &);
    void push(const Data &);
    Data pop();
    void print() const;
    bool isEmpty() const;
    std::size_t size() const;


private:
    // data storage
    Data data[DATASIZE] {};
    Data top;    // To keep track of the top element of the stack
};

}
#endif // BAG_H
