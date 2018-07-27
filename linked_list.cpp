#include "linked_list.hpp"

linked_list::linked_list() {
    this->head = nullptr;
    this->length = 0;  
}

int linked_list::get_length() {
    return this->length;
}

void linked_list::append(int data) {
    if (this->head == nullptr) {
        this->head = new node(data);
    } else {
        node* appended_node = new node(data);
        node* itor = this->head;
        while (itor->next != nullptr) {
            itor = itor->next;
        }
        itor->next = appended_node;
    }

    return;
}

void linked_list::print_list() {
    node* itor = head;
    while (itor != nullptr) {
        std::cout << itor->data << " ";
        itor = itor->next;
    }
    std::cout << std::endl;
    
    return;
}