#ifndef STACK_H
#define STACK_H
#include "linked_list.h"

class Stack{
  private:
    LinkedList *stack;
  public:
    Stack();
    bool isEmpty();
    void pop();
    void push(int value);
    int top();
    ~Stack();
};

Stack::Stack(){
  stack = new LinkedList;
}

bool Stack::isEmpty(){
  return stack->isEmpty();
}

void Stack::push(int value){
  stack->insertFront(value);
}

int Stack::top(){
  return stack->front();
}

void Stack::pop(){
  stack->removeFront();
}

Stack::~Stack(){
  delete stack; stack = 0;
}




#endif
