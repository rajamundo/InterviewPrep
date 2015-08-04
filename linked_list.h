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

  const int front();

  int removeFront();

  //Node* find(int value);

  void deleteElement(int value);

  void deleteList();

  LinkedList();

  LinkedList(int value);

  ~LinkedList();
};

LinkedList::LinkedList(){
  head = nullptr;
}

LinkedList::LinkedList(int value){
  insertFront(value);
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

const int LinkedList::front(){
  return head->datum;
}
//
// Node* LinkedList::find(int value){
//   bool exists = false;
//   while(head){ //always check for the end
//     Node *np = head;
//     if(np-> datum == value){
//       exists = true;
//       break;
//     }
//     head = head->next;
//   }
//   if(exists) return np;
//   else return nullptr; //need to throw exception instead
// }

LinkedList::~LinkedList(){
  this->RemoveAll();
}

void LinkedList::deleteElement(int value){

}



#endif
