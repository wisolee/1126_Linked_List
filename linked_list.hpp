#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <cstdlib>

#include "node.hpp"

// object - identity, attributes, behaviors

class linked_list {
    private:
        int length;
        node* head;
    public:
        // Constructor
        linked_list();

        // Access member methods
        int get_length();
        
        // Manipulator member methods
        void append(int data);

        // Output display member methods
        void print_list();

};

#endif