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
        bool is_empty();
        
        // Manipulator member methods
        void append(int data);
        void prepend(int data);
        void insert(int data, int next_data);

        int pop_back();
        int pop_front();
        void remove(int data);

        void reverse();

        // Output display member methods
        void print_list();
};

#endif