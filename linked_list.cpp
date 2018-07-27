#include "linked_list.hpp"

// Constructor
linked_list::linked_list() {
    //std::cout << "node constructed!\n";
    this->head = nullptr;
    this->length = 0;  
}

// Destructor
linked_list::~linked_list() {
    node* deleted_node = nullptr;
    node* curr_node = head;
    while (curr_node != nullptr) {
        deleted_node = curr_node;
        curr_node = curr_node->next;

        //std::cout << "node deleted\n";
        delete deleted_node;
    }
    // Reset head attribute/member variable/instance variable
    head = nullptr;
}

// Retrieves the length of the list
int linked_list::get_length() {
    return this->length;
}

// Appends an item to the list
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
    // Increment length
    this->length++;

    return;
}

// Preprends at item to the list
void linked_list::prepend(int data) {
    if (head == nullptr) {
        head = new node(data);
    } else {
        node* prepended_node = new node(data);
        prepended_node->next = head;
        head = prepended_node;
    }
    // Increment length
    this->length++;

    return;
}

// Removes the item at the back of the list
// Returns the data stored in the popped item
int linked_list::pop_back() {
    node* curr_node = this->head;

    while (curr_node->next->next != nullptr) {
        curr_node = curr_node->next;
    }
    node* popped_node = curr_node->next;
    int popped_data = popped_node->data;

    curr_node->next = nullptr; // adjust current list
    delete popped_node;
    popped_node = nullptr;

    // Decrement length
    this->length--;
    
    return popped_data;
}

// Removes the item at the front of the list
// Returns the data stored in the popped item
int linked_list::pop_front() {
    node* popped_node = this->head;
    int popped_data = popped_node->data;
    this->head = this->head->next;

    delete popped_node; // deallocate memory
    popped_node = nullptr; // set ptr equal to NULL

    // Decrement length
    this->length--;

    return popped_data;
}

// Prints the contents of the list
void linked_list::print_list() {
    node* itor = head;
    while (itor != nullptr) {
        std::cout << itor->data << " ";
        itor = itor->next;
    }
    std::cout << std::endl;
    
    return;
}