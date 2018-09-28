/*!
 * Simple (Single) Linked List
 * MIT License by Wisnu Adi Nurcahyo
 */

#include <iostream>
using namespace std;

struct Node {
  int elm;
  Node* next;
  
  Node(int elm) {
    this->elm = elm;
    this->next = NULL;
  }
};

struct List {
  Node* head = NULL;

  void push(int elm) {
    Node* new_element = new Node(elm);

    if (this->head == NULL)
      this->head = new_element;
    else {
      Node* current = this->head;
      while (current->next != NULL) current = current->next;

      current->next = new_element;
    }
  }

  void remove() {
    if (this->head != NULL) {
      Node* current = this->head;
      if (current->next == NULL) {
        this->head = NULL;
        delete current;
      }
      else {
        while (current->next->next != NULL) current = current->next;

        Node* temporary = current->next;
        current->next = NULL;
        delete temporary;
      }
    }
  }

  void insert(int elm) {
    Node* new_element = new Node(elm);

    if (this->head == NULL)
      this->head = new_element;
    else {
      new_element->next = this->head;
      this->head = new_element;
    }
  }

  void pop() {
    if (this->head != NULL) {
      Node* current = this->head;
      if (current->next == NULL) {
        this->head = NULL;
        delete current;
      }
      else {
        this->head = current->next;
        delete current;
      }
    }
  }

  bool exists(int elm) {
    if (this->head == NULL)
      return false;
    else {
      Node* current = this->head;
      while (current != NULL && current->elm != elm) current = current->next;

      return current != NULL;
    }
  }

  void display() {
    Node* current = this->head;
    while (current != NULL) {
      cout << current->elm;

      current = current->next;
      if (current != NULL)
        cout << " -> ";
      else
        cout << endl;
    }
  }
};

int main() {
  int elms[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  List list;
  for (int elm : elms) list.push(elm);

  cout << "Display after nine insertion (push):" << endl;
  list.display();

  for (int i = 0; i < 5; i++) list.remove();

  cout << "Display after five removal (remove):" << endl;
  list.display();

  for (int elm : elms) list.insert(elm);

  cout << "Display after nine insertion (insert):" << endl;
  list.display();

  for (int i = 0; i < 10; i++) list.pop();

  cout << "Display after ten removal (pop):" << endl;
  list.display();

  cout << "Does 4 exists?" << endl;
  cout << (list.exists(4) ? "YES" : "NO") << endl;

  cout << "Does 5 exists?" << endl;
  cout << (list.exists(5) ? "YES" : "NO") << endl;

  return 0;
}

