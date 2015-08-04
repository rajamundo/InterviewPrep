# Amaraj's Guide To Technical Interviews

## General Advice

* Talk through the problem solving process
* First consider the algorithm that you would want to implement
* Think about the problem for a while and then code it out, so many errors aren't made
* After writing the code, immediately test it by running through an example case
* Check code for all boundary conditions and special cases
* Almost all coding questions have short answers

## Object Oriented Programming
### Recursion
* A function is recursive if it calls itself
* A recursive problem will have at least one "trivial" base or "stopping" case and all other cases can be solved by first solving one or more smaller cases, and then combining the solutions
* With tail recursion there is no pending computation at each recursive step, so the activation record on the stack can be reused
* Writing a tail recursive function often requires a helper function that is passed "extra" arguments that keep track of the current "state" of the computation

### Function Pointers
* `int  (*foo)(int, int)` means foo is a pointer to a function that takes in two ints as arguments and returns an int
*  Once foo has been declared, any defined function that matches the type signature can be assigned to it `foo = min` and can then be called by `foo(3,5)`

## Data Structures

### Linked Lists

#### Overview

* Consists of a number of data elements in which each data element has a next pointer or next reference
* The last element in the list has a null pointer
* A pointer to the first element, or head of the list is needed, and is the element that is typically passed into functions
* The head pointer must be updated when a new element is added to the list or when the existing first element is removed
* When traversing a linked list, _always check for the end of the list_ to avoid seg faults
* Insertion and deletion require a pointer or reference to the element immediately preceding the deletion or insertion location
