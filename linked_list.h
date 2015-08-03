#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList{
private:
  struct Node{
    Node *next;
    int datum;
  };
  //this is the pointer to the beginning of the list
  Node *head;

  //private member function that will be used by overloading the assignment operator and destructor
  //written in order to avoid copying code
  void RemoveAll();

  //used by both overloaded assignment operator and copy constructor
  Node* CopyAll(const LinkedList &list);

public:

  bool isEmpty();

  void insertFront(int value);

  const int front();

  int removeFront();

  Node* find(int value);

  void deleteElement(int value);

  void deleteList();

  LinkedList();

  LinkedList(int value);

  ~LinkedList();
};

LinkedList::LinkedList(){
  this.first = nullptr;
}

LinkedList::LinkedList(int value){
  insertFront(value);
}

void LinkedList::insertFront(int value){
  Node *np = new Node;
  np->next = first;
  np->datum = value;
  first = np;
}

#endif
