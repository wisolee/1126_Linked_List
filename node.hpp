#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <cstdlib>

class node {
    public:
        int data; //data stored in current node
        node* next;

        // Default Constructor
        node();
        // Constructor with parameter list
        node(int data);
};

#endif