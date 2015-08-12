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
  void RemoveAll(){
    while(head){
      this->removeFront();
    }
  }

  //used by both overloaded assignment operator and copy constructor
  Node* CopyAll(const LinkedList &list);

public:

  bool isEmpty();

  void insertFront(int value);

  int front();

  int removeFront();

  bool doesExist(int value);

  void deleteElement(int value);

  LinkedList();

  LinkedList(int value);

  ~LinkedList();
};

LinkedList::LinkedList(){
  head = NULL;
}

LinkedList::LinkedList(int value){
  head = NULL;
  insertFront(value);
}

bool LinkedList::isEmpty(){
  return !head;
}

void LinkedList::insertFront(int value){
  Node *np = new Node;
  np->next = head;
  np->datum = value;
  head = np;
}

int LinkedList::removeFront(){
  if(!this->isEmpty()){
    Node *np = head;
    head = np->next;
    int value = np->datum;
    delete np; np = 0;
    return value;
  }
  //need to throw an error if there is no more nodes left
  return 0;
}

int LinkedList::front(){
  return head->datum;
}

bool LinkedList::doesExist(int value){
  Node *np;
  np = head;
  while(np){ //always check for the end
    if(np->datum == value){
      break;
    }
    np = np->next;
  }

  return np;
}

LinkedList::~LinkedList(){
  this->RemoveAll();
}

void LinkedList::deleteElement(int value){
  if(head){
    Node *np = NULL;
    Node *future = NULL;
    np = head;
    future = np->next;
    if(np->datum == value){
      head = np->next;
      delete np; np = 0;
    }
    else{
      while(future){
        if(future->datum == value){
          np->next = future->next;
          delete future; future = 0;
          break;
        }
        np = np->next;
        future = future->next;
      }
    }
  }
}




#endif
