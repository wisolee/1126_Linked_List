#include <iostream>
#include <cstdlib>

#include "linked_list.hpp"

int main(int argc, const char* argv[])
{
    // Allocating a linked list on heap memory
    linked_list* list = new linked_list();
    linked_list* list_1 = new linked_list();
    for (int i = 0; i < 10; i++) {
        list->append(i);
        list_1->prepend(i);
    }

    // Printing contents of the linked list
    list->print_list();
    std::cout << "length: " << list->get_length() << std::endl;
    list_1->print_list();
    std::cout << "length: " << list_1->get_length() << std::endl;

    std::cout << "Reversed list: \n";
    list->reverse();
    list->print_list();

    list->insert(5, 7);
    list->print_list();

    list->remove(5);
    list->print_list();

    // pop_back()
    while (!list->is_empty()) {
        list->pop_back();
    }
    list->print_list();

    // pop_front() 
    while (!list_1->is_empty()) {
        list_1->pop_front();
    }
    list->print_list();
   
    // Deallocating linked list
    list->~linked_list();
    list_1->~linked_list();
    return 0;
}