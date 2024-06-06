#include "DoublyLinkedList.h"

template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::editNode(T1 question, T2 data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      temp->data = data;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T1, class T2>
int DoublyLinkedList<T1, T2>::searchQuestionNode(T1 question) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      // cout << "Question found: " << temp->question << endl;
      return 1;
    }
    temp = temp->next;
  }
  return -1;
}

template <class T1, class T2>
int DoublyLinkedList<T1, T2>::searchNode(T2 data) const {
  const string border = "+------------------------------------------+";
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      cout << border << endl;
      cout << "Data found." << endl;
      cout << "Question: " << temp->question << endl;
      cout << "Data: " << temp->data << endl;
      cout << border << endl;
      return 1;
    }
    temp = temp->next;
  }
  cout << border << endl;
  cout << "Data not found." << endl;
  cout << border << endl;
  return -1;
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::deleteQuestionNode(T1 question) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      if (temp == head) {
        head = temp->next;
        head->prev = nullptr;
        cout << "Question " << question << " deleted." << endl;
        delete temp;
        return;
      } else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
        cout << "Question " << question << " deleted." << endl;
        delete temp;
        return;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Question " << question << " deleted." << endl;
        delete temp;
        return;
      }
    }
    temp = temp->next;
  }
  cout << "Question not found." << endl;
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::deleteNode(T2 data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      if (temp == head) {
        head = temp->next;
        head->prev = nullptr;
        cout << "Data " << data << " deleted." << endl;
        delete temp;
        return;
      } else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
        cout << "Data " << data << " deleted." << endl;
        delete temp;
        return;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Data " << data << " deleted." << endl;
        delete temp;
        return;
      }
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T1, class T2>
DoublyLinkedList<T1, T2>::~DoublyLinkedList() {
  Node* temp = head;
  while (temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::insertNode(T1 question, T2 data) {
  Node* newNode = new Node;
  Node* nodePtr;
  Node* previousNode = nullptr;

  newNode->question = question;
  newNode->data = data;

  if (!head) {
    head = newNode;
    tail = newNode;
    newNode->next = nullptr;
    newNode->prev = nullptr;
  } else {
    nodePtr = head;
    previousNode = nullptr;

    while (nodePtr != nullptr && nodePtr->question < question) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (previousNode == nullptr) {
      head = newNode;
      newNode->prev = nullptr;
      newNode->next = nodePtr;
      if (nodePtr != nullptr) {
        nodePtr->prev = newNode;
      }
    } else {
      previousNode->next = newNode;
      newNode->prev = previousNode;
      newNode->next = nodePtr;

      if (nodePtr != nullptr) {
        nodePtr->prev = newNode;
      } else {
        tail = newNode;
      }
    }
  }
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::displayQuestionList() const {
  Node* temp = head;
  int i = 0;
  while (temp != nullptr) {
    cout << ++i << ". " << temp->question << endl;
    temp = temp->next;
  }

  if (head == nullptr) {
    cout << "List is empty." << endl;
  }
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::displayNode(T1 question, string field) const {
  Node* temp = head;
  cout << "Displaying " << field << " for '" << question << "':" << endl;
  const string border = "+------------------------------------------+";
  while (temp != nullptr) {
    if (temp->question == question) {
      cout << border << endl;
      cout << "Question: " << temp->question << endl;
      cout << "Data: " << temp->data << endl;
      cout << border << endl;
      return;
    }
    temp = temp->next;
  }

  if (head == nullptr) {
    cout << "List is empty." << endl;
  }
}

template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getNodeValue(T1 question) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      return temp->data;
    }
    temp = temp->next;
  }
  return T2();
}

template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getHeadValue() const {
  if (head != nullptr) {
    return head->data;
  } else {
    return T2(); // Return default value if list is empty
  }
}

template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getTailValue() const {
  if (tail != nullptr) {
    return tail->data;
  } else {
    return T2(); // Return default value if list is empty
  }
}

template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getPreviousNodeValue(T1 question) const {
  Node* temp = head;

  if (question == head->question) {
    return head->data;
  }

  while (temp != nullptr) {
    if (temp->question == question) {
      if (temp->prev != nullptr) {
        return temp->prev->data;
      } else {
        return T2(); // Return default value if no previous node exists
      }
    }
    temp = temp->next;
  }
  return T2(); // Return default value if question not found in the list
}

template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getNextNodeValue(T1 question) const {
  Node* temp = head;

  if (question == tail->question) {
    return tail->data;
  }

  while (temp != nullptr) {
    if (temp->question == question) {
      if (temp->next != nullptr) {
        return temp->next->data;
      } else {
        return T2(); // Return default value if no next node exists
      }
    }
    temp = temp->next;
  }
  return T2(); // Return default value if question not found in the list
}

template class DoublyLinkedList <string, string>;
template class DoublyLinkedList <string, int>;
template class DoublyLinkedList <string, double>;