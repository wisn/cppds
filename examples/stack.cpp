/*!
 * Stack
 * MIT License by Wisnu Adi Nurcahyo
 *
 * Available methods:
 *   push(x) : Void
 *     Insert new element in the begining of the List.
 *
 *   pop() : Void
 *     Remove the first element of the List.
 *
 *   peek() : Int
 *     Get the first element of the List.
 *
 *   is_empty() : Bool
 *     Return whether the List empty or not.
 *
 *   display() : Void
 *     Print the complete stack elements.
 */

#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
  int elm;
  Node* next;
  
  Node(int elm) {
    this->elm = elm;
    this->next = NULL;
  }
};

struct Stack {
  Node* head = NULL;

  void push(int elm) {
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

  bool is_empty() {
    return this->head == NULL;
  }

  int peek() {
    if (this->head != NULL) return this->head->elm;

    throw runtime_error("The stack is empty.");
  }

  void display() {
    cout << "[";

    Node* current = this->head;
    while (current != NULL) {
      cout << current->elm;

      current = current->next;
      if (current != NULL) cout << " ";
    }

    cout << "]" << endl;
  }
};

int main() {
  int elms[] = {1, 2, 3, 4, 5, 6, 7};

  Stack stack;
  cout << "Does the stack empty?" << endl;
  cout << (stack.is_empty() ? "YES" : "NO") << endl;

  for (int elm : elms) stack.push(elm);

  cout << "Display after seven insertion:" << endl;
  stack.display();

  cout << "What is the top element?" << endl;
  cout << stack.peek() << endl;

  for (int i = 0; i < 4; i++) stack.pop();

  cout << "Display after four removal:" << endl;
  stack.display();

  cout << "Does the stack empty?" << endl;
  cout << (stack.is_empty() ? "YES" : "NO") << endl;

  while (!stack.is_empty()) stack.pop();

  cout << "Display after clearing the stack:" << endl;
  stack.display();

  return 0;
}

