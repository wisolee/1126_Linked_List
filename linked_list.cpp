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

// Returns true if list is empty, else false
bool linked_list::is_empty() {
    return (this->length == 0 ? true : false);
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
    if (this->head == nullptr) return -1;   // Case 1: list is empty

    node* popped_node = nullptr;
    int popped_data = 0;
    if (this->length == 1) {                // Case 2: list has one node
        popped_node = head;
        popped_data = popped_node->data;
        this->head = nullptr;
    } else if (this->length == 2) {         // Case 2: list has two nodes
        popped_node = head->next;
        popped_data = popped_node->data;
        this->head->next = nullptr;
    } else {                                // Case 2: list has three or more nodes
        node* curr_node = this->head;
        while (curr_node->next->next != nullptr) {
            curr_node = curr_node->next;
        }
        node* popped_node = curr_node->next;
        int popped_data = popped_node->data;
        curr_node->next = nullptr;
    }
    // Deallocate popped_node
    delete popped_node;
    popped_node = nullptr;
    // Decrement length
    this->length--;

    return popped_data;
}

// Removes the item at the front of the list
// Returns the data stored in the popped item
int linked_list::pop_front() {
    // Case 1: list is empty
    if (this->head == nullptr) return -1;

    // Case 2: list is not empty
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
    // print message for empty list
    if (is_empty()) {
        std::cout << "list is empty\n";
        return; 
    }

    // print contents of list if not empty
    node* itor = head;
    while (itor != nullptr) {
        std::cout << itor->data << " ";
        itor = itor->next;
    }
    std::cout << std::endl;
    
    return;
}