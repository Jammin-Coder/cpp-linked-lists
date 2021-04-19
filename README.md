# C++ Linked Lists
My implementation of doubley-linked lists in C++ 
## NOTE:
This library is best used when you need a dynamicly sized list, and staticly sized arrays are not an option. 
So don't go too crazy with this code. It's always best to try and find a work-around solution before relying 
on linked-lists to bail you out. 

## How it works 
Within the `List` class, first we define list-node type we call `node`.  
```
// Code inspired by someone on the internet. I forget where the post was and the username of the poster, once I find it again I will post it here.
typedef struct Node 
	{  
		 int data; // Integer to be stored.
		 struct Node* next; // node-type pointer to next element in list
		 struct Node* prev; // node-type pointer to previous element in list
	} node;
```
Each node contains placholders for the data(integer), the next list-node, and the previous list-node. The next and prev nodes are pointers. 
A list-head is then initialized with the `list()` method. The list head is the start of the list. This creates a list 
head with the `data` field set to 0, and `next` and `prev` fields set to NULL. This node is not used when accessing the list, 
it's just used to initialize the list. 
This allows you to chain many list-nodes together, making a doubley-linked list.


## How to use this library 

### Create a List object:
`List myList; // Creates an empty List object.` 

### Methods:
```c++
myList.append(54); // Appends 54 to list. 

myList.remel(1); // Returns and removes the element at index 1(or provided index) 

myList.print(); // Prints items in the list. 

myList.index(7); // Returns the element at index 7(or provided index)

// Removes all the elements from the first provided index, and to the last index, including the elements at the provided indices
// When removed multiple items at once, this is MUCH faster than using a for-loop and remel.
myList.slice(9, 18);
```
