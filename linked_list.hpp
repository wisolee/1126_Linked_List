#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <cstdlib>

#include "node.hpp"

// object - identity, attributes, behaviors

class linked_list {
    // member variables
    private:
        int length;
        node* head;
    // member methods
    public:
        // Constructor
        linked_list();
        // Destructor 
        ~linked_list();

        // Access member methods
        int get_length();
        
        // Manipulator member methods
        void append(int data);
        void prepend(int data);

        int pop_back();
        int pop_front();

        // Output display member methods
        void print_list();
};

#endif