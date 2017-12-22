#include <iostream>

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

// List all of the items in the linked list that begins at "node"
void iterator(Item *node) {
  printf("iterator: Listing all items in Linked List\n");
  while (node != nullptr) {
    printf("i=%d\n", node->i);
    node = (*node).next;  // Could also be done with the shorthand: node->next
  }
}

int main() {
  // Initializes an "Item" on the Stack.
  Item a(12);
  // Initializes the "Item" reference phi as the reference of a.
  Item &phi = a;
  Item b(99);
  // Sets the "next" atribute of "Item a" to the address reference of "Item b".
  a.next = &b;

  // Initializes an "Item" on the Heap, and passes a parameter.
  Item *c = new Item(34);
  c->next = &a;  // Make the next member variable of d point to the address of a
  b.next = c;

  iterator(c);

  // Frees the "Item" d on the Heap, first calling the "Item" destructor
  delete c;
}