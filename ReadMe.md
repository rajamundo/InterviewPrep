# Amaraj's Guide To Technical Interviews

## General Advice

* Talk through the problem solving process
* First consider the algorithm that you would want to implement
* Think about the problem for a while and then code it out, so many errors aren't made
* After writing the code, immediately test it by running through an example case
* Check code for all boundary conditions and special cases
* Almost all coding questions have short answers

## Data Structures

### Linked Lists

#### Overview

* Consists of a number of data elements in which each data element has a next pointer or next reference 
* The last element in the list has a null pointer
* A pointer to the first element, or head of the list is needed, and is the element that is typically passed into functions
* The head pointer must be updated when a new element is added to the list or when the existing first element is removed 
* When traversing a linked list, _always check for the end of the list_ to avoid seg faults
* Insertion and deletion require a pointer or reference to the element immediately preceding the deletion or insertion location

