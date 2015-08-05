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

### Arrays
* A fixed-size, zero-indexed, homogeneous aggregate type
* `int array[4]` to initialize and `int array[4] = {1,2,3,4}` would be __static initialization__
* Arrays can be passed into functions in this manner: `int sum(int a[], unsigned int size)` so that the function call would be `sum(array, 4)`
* Arrays are passed by _reference not value_
* C-style string is an array of zero or more chars followed by a null character, which acts as the __sentinel__ and signals the end of an aggregate

### Pointers
* A 'pointer-to-T' is a variable that can hold the address of some other object of type T
* `int *bar` means bar is a pointer to an int
* Bar can be assigned an address of an int:
`int *bar;`
`int foo;`
`bar = &foo;` where the ampersand means "address-of"
* `*bar = 2` means change the value of the object to which bar points to 2, where the * is called the __dereference operator__
* Pointers are used because they provide a convenient mechanism to work with arrays (pointer arithmetic) and allow structures to be created whose size is not known in advance

#### Array Traversal
* `array[3] == *(array + 3)`
* `for(int *i = array; i < array + SIZE; ++i)`
* In `*p++` the ++ "binds tighter" that * so it is saying "dereference the pointer given its current value, and then increment it after you are done"

#### Const Keyword
* const is a _type qualifier_ - something that modifies a type, that means that you cannot change this value once it is initialized
* `const T *p;` - "T" (the pointed-to object) cannot be changed
* `T *const p` - "p" (the pointer) cannot be changed
* Allows any mistakes to be caught by the compiler
* Use const for things that are passed by reference, but won't be changed






## Data Structures

### Linked Lists

#### Overview

* Consists of a number of data elements in which each data element has a next pointer or next reference
* The last element in the list has a null pointer
* A pointer to the first element, or head of the list is needed, and is the element that is typically passed into functions
* The head pointer must be updated when a new element is added to the list or when the existing first element is removed
* When traversing a linked list, _always check for the end of the list_ to avoid seg faults
* Insertion and deletion require a pointer or reference to the element immediately preceding the deletion or insertion location
