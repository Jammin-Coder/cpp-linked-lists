#include "Node.cpp"


template<typename T>
Node<T>* new_node(int index)
{
	//Makes a new pointer to a list node.
	Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
	node->m_index = index;
	return node;
}



