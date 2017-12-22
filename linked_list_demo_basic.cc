#include <iostream>
#include <stdlib.h>

class Item {
public:
  // Constructor for "Item"
  Item(int iNew) {
    i = iNew;
    printf("Creating item: %d numero: %d\n", __LINE__, i);
  }

  // Destructor for "Item"
  ~Item() { printf("Destroying item: %d numero: %d\n", __LINE__, i); }

  void h() { this->next = nullptr; }
  int i = 0;
  Item *next = nullptr;
};

void iterator(Item *node) {
  printf("iterator: Listing all items in Linked List\n");
  while (node != nullptr) {
    printf("i=%d\n", node->i);
    node = (*node).next; // Could also be done with the shorthand: node->next
  }
}

int main() {
  // Initializes an "Item" on the Stack (Calling the Constructor, and pasing a value to iNew, and creates a reference to the "Item" on the Stack)
  Item a(12);
  // Initializes the "Item" reference phi as the refernce of a
  Item &phi = a;
  Item b(99);
  Item c(37);
  // Sets the "next" atribute of "Item a" to the address reference of "Item b"
  a.next = &b;
  b.next = &c;

  // Initializes an "Item" on the Heap, and passes a parameter
  Item *d = new Item(34);
  (*d).next = &a; // Dereferenceing the pointer d and inserting the address reference of "Item" a

  iterator(d);

  // Frees the "Item" d on the Heap, first calling the "Item" destructor
  delete d;
}