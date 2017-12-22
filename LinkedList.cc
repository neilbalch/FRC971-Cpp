#include <iostream>
#include <string>

template <class deftype>
class SinglyLinkedList {
 public:
  // Push new item to front of list
  void push_front(deftype value) {
    // Make a new node
    Item* node = this->make_node(value);
    // Make the new node point to the current HEAD
    node->next = head;
    // Make the new node the new HEAD node
    head = node;
  }

  // Push new item to back of list
  void push_back(deftype value) {
    Item* node = this->make_node(value);
    // Put the HEAD node in a temporary working copy
    Item* temp_head = head;
    if (temp_head != nullptr) {
      // List isn't enpty, loop to end of linked list
      while (temp_head->next != nullptr) {
        temp_head = temp_head->next;
      }
      // Make the end of the linked list point to the new item
      temp_head->next = node;
    } else {
      // List is empty, just make HEAD point to new item
      head = node;
    }
  }

  // Detatch item from front of list
  void pop_front() {
    // Put the HEAD node in a temporary working copy
    Item* temp_head = head;
    // Iterate to the 2nd item
    temp_head = temp_head->next;
    // Delete the HEAD item
    delete head;
    // Set hed to the new temp HEAD
    head = temp_head;
  }

  // Detatch item from back of list
  void pop_back() {
    // Put the HEAD node in a temporary working copy
    Item* temp_head = head;
    if (temp_head->next == nullptr) {
      // List has only one item on it, destroy the item
      delete head;
      // Then clean up the HEAD's next pointer, emptying the list
      head = nullptr;
    } else {
      // List has multiple items, identify the 2nd to last item
      while (temp_head->next->next != nullptr) {
        temp_head = temp_head->next;
      }
      // Delete the last item
      delete temp_head->next;
      // Clean up the last item's next pointer
      temp_head->next = nullptr;
    }
  }

  // List all nodes
  void list_nodes() {
    std::cout << "Listing all nodes:" << std::endl;
    // Put the HEAD node in a temporary working copy
    Item* temp_head = head;
    // Loop to end of linked list
    while (temp_head != nullptr) {
      // Print the value of the temp HEAD
      std::cout << temp_head->value << std::endl;
      // Advance the temp HEAD to the next list item
      temp_head = temp_head->next;
    }
  }

  // Deconstructor; Destroys the list and free used memory
  ~SinglyLinkedList() {
    while (head != nullptr) {
      this->pop_back();
    }
  }

 private:
  // Item template for the singly linked list
  struct Item {
    deftype value;
    Item* next = nullptr;
  };

  // Helper for making a node item from a value
  Item* make_node(deftype value) {
    // Make a new node
    Item* node = new Item();
    // Assign the new node the given value
    node->value = value;

    return node;
  }

  // HEAD of the singly linked list
  Item* head = nullptr;
};

int main() {
  {
    SinglyLinkedList<double> newlist;
    newlist.push_front(10.0);
    newlist.push_front(3.14159);
    newlist.push_back(10000.0);
    newlist.push_back(60.64334583);
    newlist.list_nodes();
    newlist.pop_front();
    newlist.list_nodes();
    newlist.pop_back();
    newlist.list_nodes();
  }
  {
    std::cout << "hdfjlsdfklsdjkfljsdlf" << std::endl;
    SinglyLinkedList<double> list;
    list.push_back(10.0);
    list.list_nodes();
    list.pop_front();
    list.push_front(40.0);
    list.list_nodes();
  }
}