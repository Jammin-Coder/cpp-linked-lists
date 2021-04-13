# cpp-linked-lists
My implementation of linked-lists in c++ 
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

### The methods:
#### Sorry, I need a break, I will explain all the methods later...
