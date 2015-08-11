#include <iostream>
#include "catch.hpp"
#include "linked_list.h"

using namespace std;

//////////////////////////////////Basic Function Tests/////////////////////////////////////////////

TEST_CASE( "linked list is empty", "[linked list]"){
  SECTION("the list is constructed without a default value"){
    LinkedList list;
    REQUIRE( list.isEmpty() == true);
  }
  SECTION("the list is constructed with a single element"){
    LinkedList list(4);
    REQUIRE( list.isEmpty() == false);
  }
}

TEST_CASE("the linked list correctly inserts values to the front", "[linked list]"){
  LinkedList list;
  REQUIRE( list.isEmpty() == true);
  list.insertFront(1);
  REQUIRE( list.front() == 1);
  list.insertFront(2);
  REQUIRE( list.front() == 2);
  list.insertFront(3);
  REQUIRE ( list.front() == 3);
}

TEST_CASE("linked list correctly removes the front value", "[linked list]"){
  LinkedList list;
  list.insertFront(7);
  list.insertFront(5);
  list.insertFront(3);
  REQUIRE( list.removeFront() == 3);
  REQUIRE( list.removeFront() == 5);
  REQUIRE( list.removeFront() == 7);
}

TEST_CASE("linked list knows if element exists in it or not", "[linked list]"){
  LinkedList list;
  list.insertFront(4);
  list.insertFront(9);
  list.insertFront(18);
  list.insertFront(13);
  SECTION(""){
    REQUIRE( list.doesExist(4) == true );
  }
  SECTION(""){
    REQUIRE( list.doesExist(17) == false );
  }
  SECTION(""){
    REQUIRE( list.doesExist(18) == true );
  }
  SECTION(""){
    REQUIRE( list.doesExist(13) == true );
  }
}

TEST_CASE("elements can be successfully deleted from the list", "[linked list]"){
  LinkedList list;
  list.insertFront(31);
  list.insertFront(22);
  list.insertFront(15);
  list.insertFront(16);

  SECTION("deleting the head of list"){
    list.deleteElement(16);
    REQUIRE( list.doesExist(16) == false );
  }
  SECTION(""){
    list.deleteElement(31);
    REQUIRE( list.doesExist(31) == false );

    list.deleteElement(22);
    REQUIRE( list.doesExist(22) == false );
  }
}

//////////////////////////////////////////Stacks////////////////////////////////////////////////////

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

TEST_CASE("stack is initialized and empty", "[stack]"){
  Stack stack;
  REQUIRE(stack.isEmpty() == true);
}
TEST_CASE("elements pushed onto stack", "[stack]"){
  Stack stack;
  stack.push(3);
  REQUIRE(stack.isEmpty() == false);
}

TEST_CASE("top element is the correct element", "[stack]"){
  Stack stack;
  stack.push(7);
  REQUIRE(stack.top() == 7);
  stack.push(4);
  REQUIRE(stack.top() == 4);
}

TEST_CASE("pop works correctly", "[stack]"){
  Stack stack;
  stack.push(12);
  stack.push(15);
  stack.pop();
  REQUIRE(stack.top() == 12);
  stack.pop();
  REQUIRE(stack.isEmpty() == true);
}
