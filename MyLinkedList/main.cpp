#include <iostream>

class MyLinkedList {
private:
  struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
  };

  Node *head = nullptr; // Pointer to the first node in the list
  Node *tail = nullptr; // Pointer to the last node in the list
  int size = 0;         // Variable to track the size of the linked list

public:
  MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

  int get(int index) const {
    if (index < 0 || index >= size)
      return -1;

    Node *curr = head;
    // Traverse the list to the specified index
    for (int i = 0; i < index; ++i)
      curr = curr->next;

    return curr->val; // Return the value at the index
  }

  void addAtHead(int val) {
    Node *node = new Node(val);
    if (head == nullptr) {
      // If the list is empty, set both head and tail to the new node
      head = node;
      tail = node;
    } else {
      // Otherwise, update pointers to add the new node at the head
      node->next = head;
      head->prev = node;
      head = node;
    }
    size++;
  }

  void addAtTail(int val) {
    Node *node = new Node(val);
    if (tail == nullptr) {
      // If the list is empty, set both head and tail to the new node
      head = node;
      tail = node;
    } else {
      // Otherwise, update pointers to add the new node at the tail
      node->prev = tail;
      tail->next = node;
      tail = node;
    }
    size++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size)
      return; // Invalid index, do nothing

    if (index == 0) {
      addAtHead(val); // If index is 0, add at the head
      return;
    }

    if (index == size) {
      addAtTail(val); // If index is the size, add at the tail
      return;
    }

    Node *curr = head;
    // Traverse the list to the specified index
    for (int i = 0; i < index; ++i)
      curr = curr->next;

    Node *node = new Node(val);
    // Update pointers to add the new node at the specified index
    node->next = curr; //
    node->prev = curr->prev;
    curr->prev->next = node;
    curr->prev = node;

    size++;
  }

  // Delete the node at the specified index in the linked list
  void deleteAtIndex(int index) {
    if (index < 0 || index >= size)
      return; // Invalid index, do nothing

    if (index == 0) {
      // If index is 0, delete the head node
      Node *temp = head;
      head = head->next;
      if (head != nullptr)
        head->prev = nullptr;
      else
        tail = nullptr;
      delete temp; // Free the memory of the deleted node
    } else if (index == size - 1) {
      // If index is the size - 1, delete the tail node
      Node *temp = tail;
      tail = tail->prev;
      if (tail != nullptr)
        tail->next = nullptr;
      else
        head = nullptr;
      delete temp; // Free the memory of the deleted node
    } else {
      // Otherwise, delete a node in the middle of the list
      Node *curr = head;
      // Traverse the list to the specified index
      for (int i = 0; i < index; ++i)
        curr = curr->next;

      // Update pointers to bypass the node to be deleted
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;

      delete curr; // Free the memory of the deleted node
    }

    size--;
  }

  int getSize() const { return size; }
};

// Main function for testing the MyLinkedList class
int main() {
  MyLinkedList *obj = new MyLinkedList();
  int param_1 = obj->get(0); // Get value at index 0 (empty list, returns -1)
  obj->addAtHead(1);         // Add 1 at the head
  obj->addAtTail(3);         // Add 3 at the tail
  obj->addAtIndex(1, 2);     // Add 2 at index 1
  obj->deleteAtIndex(1);     // Delete node at index 1

  // Output the list to verify its state
  for (int i = 0; i < obj->getSize(); ++i) {
    std::cout << obj->get(i) << " ";
  }

  delete obj; // Free the memory allocated for the MyLinkedList object
  return 0;
}
