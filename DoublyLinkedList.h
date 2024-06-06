#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class DoublyLinkedList {
  private:
    struct Node {
      T1 question;
      T2 data;
      Node* next;
      Node* prev;
    };
    Node* head;
    Node* tail;
  public:
    DoublyLinkedList();

    void editNode(T1 question, T2 data);
    void searchQuestionNode(T1 question) const;
    void searchNode(T2 data) const;

    void deleteQuestionNode(T1 question);
    void deleteNode(T2 data);

    ~DoublyLinkedList();

    void insertNode(T1 question, T2 data);
    
    void displayList() const;
};

template class DoublyLinkedList <string, string>;
template class DoublyLinkedList <string, int>;
template class DoublyLinkedList <string, double>;

#endif