#include <iostream>
#include <utility>

struct Item {
  // Constructor for "Item"
  Item(int value) {
    value = value;
    printf("Creating item: %d numero: %d\n", __LINE__, value);
  }

  // Destructor for "Item"
  ~Item() { printf("Destroying item: %d numero: %d\n", __LINE__, value); }

  void reset_next_to_nullptr() { this->next = nullptr; }
  int value = 0;
  Item* next = nullptr;
};

class iList {
 public:
  // Makes a method that cannot modify any objects within "this", like node
  void listNodes() const {
    Item* node = head;
    while (node != nullptr) {
      printf("i=%d\n", node->value);
      node = node->next;
    }
  }
  // Adds a value to the top of the list
  void add(int a) {
    Item* node = new Item(a);
    node->next = head;
    head = node;

    // Does the same thing
    // push_node(new Item(a));
  }
  // Adds a node to the top of the list
  void push_node(Item* node) {
    node->next = head;
    head = node;
  }
  // Adds a node to the bottom of the list
  void addToEnd(Item* node) {
    Item** temp = &head;
    while (*temp != nullptr) {
      temp = &(*temp)->next;
    }
    *temp = node;
  }
  bool empty() { return head == nullptr; }
  // Pops a node off the top of the list
  Item* pop_node() {
    Item* temp = head;
    // Setting the head to point at the next item in the list
    head = temp->next;
    // Cleans up the temp object by getting rid of the end of the list
    temp->next = nullptr;
    return temp;
  }
  // Reverses the order of items in the list
  void reverseList() {
    iList other_list;
    // Swaps the contents of both lists
    std::swap(other_list.head, head);
    // Populates head with the contents of other_list
    while (!other_list.empty()) {
      push_node(other_list.pop_node());
    }
  }
  // Deconstructor of iList
  ~iList() {
    while (head) {
      // Removes the top item in the list
      Item* temp = head->next;
      delete head;
      head = temp;
    }
  }

  Item* head = nullptr;
};

// Print out all of the items in the Linked List
void PrintRecurse(Item* node) {
  printf("PrintRecurse: Printing all items in Linked List\n");
  if (node != nullptr) {
    printf("i=%d\n", node->value);
    PrintRecurse(node->next);
  } else {
    return;
  }
}

int main() {
  iList list;
  list.add(12);
  list.add(99);
  list.add(37);
  printf("Reversed List\n");
  list.reverseList();
  PrintRecurse(list.head);

  // Unit Test for the Linked List Demo
  if (list.head->value == 12) {
    printf("Test1: Passed\n");
  } else {
    printf("Test1: Failed value=%d\n", list.head->value);
  }
}
