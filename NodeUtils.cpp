#include "Node.cpp"


template<typename T>
Node<T>* new_node()
{
	//Makes a new pointer to a list node.
	Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
	return node;
}



