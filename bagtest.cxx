/*
 * Names: Yuto Fraley, Theodore Griffin - Jones, Michael Tiburcio, Joy Zhu
 * Emails: yfraley@scu.edu, tgriffinjones@scu.edu, mtiburcio@scu.edu, jhzhu@scu.edu
 * Test program
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include "bag.h"

using namespace std;
using namespace csen79;
enum Command { PUSH = 'P', POP = 'O', PRINT = 'D', QUIT = 'Q' };

int main(void) {
    Bag bag;
    string line;
    bool quit = false;
    top = 0;
    while (!quit && std::getline(cin,line)) {
        switch (line[0]) {
        case PUSH: {
            int data;
            try {
                stringstream ss(line.substr(1));
                ss >> data;
            } catch (const out_of_range &e) {
                cerr << "Data out of range" << endl;
                continue;
            }
            bag.push(data);
            top++;    //Might not need bc of the data[++top] in bag.cxx
        }
            break;
        case POP: {
            bag.pop();
        }
        case PRINT:{
            cout << "Bag contents: ";
            bag.print();
            cout << endl;
            cout << "Current size: " << bag.size() << endl;
            break;
        }
            break;
        case QUIT:
            quit = true;
            break;
        default:
            cerr << "Unknown command: " << line << endl;
            break;
        }
    }
    
    return EXIT_SUCCESS;
}
