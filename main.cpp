#include <iostream>
#include <cstdlib>

#include "linked_list.hpp"

int main(int argc, const char* argv[])
{
    std::cout << "Working on linked_list" << std::endl;
    // Allocating a linked list on heap memory
    linked_list* list = new linked_list();
    for (int i = 0; i < 10; i++) {
        list->append(i);
    }
    list->print_list();
    return 0;
}