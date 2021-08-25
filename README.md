# C++ Linked Lists
My implementation of doubley-linked lists in C++ 
## NOTE:
This library is best used when you need a dynamicly sized list, and staticly sized arrays are not an option. 
So don't go too crazy with this code. It's always best to try and find a work-around solution before relying 
on linked-lists to bail you out. 

## To use:
Include LinkedList.cpp in cpp file:  
`#include "LinkedList.cpp"`  

Instantiate a new List object:  
`List<TYPE> myList = List<TYPE>(FIRST_DATA); `  

TYPE specifies the type of data to be stored in the list, I've tested it with `ints` and `const char*`, but it should work with most, if not all data types.  
FIRST_DATA is the data that you want to be contained at the first index of the list. At the moment it is required that you supply this value when instantiating a new list.  

### Examples:
``` c++
List<int> int_list = List<int>(0); // Creates a new doubly linked list of ints with 0 stored at the first index
int_list.append(2); // Appends 2 to int_list
List<const char*> str_list = List<const char*>("Hello"); // Creates a doubly linked list of const char* (strings) with "Hello" set at the first index
str_list.prepend("HECK YEAH, BABY!"); // Appends new string to str_list
str_list.print(); // Prints all contenst of str_list
```
