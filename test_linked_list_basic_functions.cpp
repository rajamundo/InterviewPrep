#include <iostream>
#include "catch.hpp"
#include "linked_list.h"

using namespace std;

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

TEST_CASE("linked list correctly removes the front value", "[linked_list]"){
  LinkedList list;
  list.insertFront(7);
  list.insertFront(5);
  list.insertFront(3);
  REQUIRE( list.removeFront() == 3);
  REQUIRE( list.removeFront() == 5);
  REQUIRE ( list.removeFront() == 7);
}
