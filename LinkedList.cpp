#include "LinkedList.hpp"

/*******
	TODO: Figure out if I can remove all of the template<typename T>s some how.
*******/


// Returns last valid index in list
template<typename T>
int List<T>::last_index()
{
	if (m_length > 0)
	{
		return m_length - 1;
	}
	else
	{
		return -1;
	}
}

template<typename T>
int List<T>::length()
{
	return m_length;
}

template<typename T>
nodePTR List<T>::get_node_at_index(int index)
{
	if (index > last_index())
	{
		std::cout << "[-] ERROR: Index out of range" << std::endl;
		exit(-1);
	}

	/*
		If the provided index less than or equal to the lower-half of the list, 
		start from the beggining of the list and itterate forward. 
	*/
	if (index <= last_index()/2)
	{
		/*
		* Start at the beggining of the list and iterates forward over list
		* elements until desired index is reached,
		* and then return the data contained within the list node at the index.
		*/
		nodePTR current_node = m_first_node;
		for (int i = 0; i <= index; i++)
		{
			if(&current_node->m_next != NULL)
			{
				if (i == index)
				{
					return current_node;
				}
				nodePTR next_node = current_node->m_next;
				current_node = next_node;
			}
		}
	}
	
	/*
	* Starts at the end of the list and iterates backwards through the list
	* until the desired index is reached
	*/
	else 
	{
		nodePTR current_node = m_last_node;
		for (int i = last_index(); i >= index; i--)
		{
			if(&current_node->m_data != NULL)
			{
				if (i == index)
				{
					return current_node;
				}
				nodePTR prev_node = current_node->m_prev;
				current_node = prev_node;
			}
		}
	}
	std::cout << "[-] ERROR: Something went wrong while accessing list element at index " << index << std::endl;
	exit(-1);
}


// Prints the contents of the list
template<typename T>
void List<T>::print()
{
	std::cout << "[";
	for(int i = 0; i < m_length; i++)
	{
		std::cout << at(i);
		if (i != last_index())
			std::cout << ", ";
	}
	
	std::cout << "]" << std::endl;
}


// Returns the data in node at given index
template<typename T>
T List<T>::at(int index)
{
	nodePTR node = get_node_at_index(index);
	return node->m_data;
}


// Prepends a new node with given data to start of list
template<typename T>
void List<T>::prepend(T data)
{
	if (m_has_initialized)
	    {
		    // New node to be prepended
		    nodePTR node = new_node<T>();
		    
		    // Sets the new node's previous node to that of the first node
		    node->m_prev = m_first_node->m_prev;
		    
		    // Sets the previous node of the first node to the new node
		    m_first_node->m_prev = node;
		    
		    // Sets the new node's next node to the first_node
		    node->m_next = m_first_node;
		    
		    // Assignes the given data to the new node's data member
		    node->m_data = data;
		    
		    // Sets the first node to the new node
		    m_first_node = node;
		}
		else 
		{
		    m_first_node->m_data = data;
			m_has_initialized = true;
		}
		
		m_length++;
}


// Appends a new node with given data to end of list.
template<typename T>
void List<T>::append(T data)
{
	if (m_has_initialized)
	    {
		    // New node that will be appended
		    nodePTR node = new_node<T>();
		    
		    // Sets the new node's next node to the last_node's next node.
		    node->m_next = m_last_node->m_next;
		    
		    // Sets the new node's previous node to the last node
		    node->m_prev = m_last_node;
		    
		    // Sets the last_node's next node to the new node
		    m_last_node->m_next = node;
		    
		    // Assignes the given data to the new node's data member
		    node->m_data = data;
		    
		    // Updates last_node to the new node 
		    m_last_node = node;
		}
		
		else 
		{
		    m_first_node->m_data = data;
		    m_has_initialized = true;
		}
		
		m_length++;
}

template<typename T>
T List<T>::remove(int index)
{
	if (index > last_index())
	{
		std::cout << "[+] ERROR: Index out of range" << std::endl;
		exit(-1);
	}

	nodePTR target_node = get_node_at_index(index);
	T data = target_node->m_data;

	if (target_node == m_first_node)
	{
		if (m_first_node->m_next)
		{
			m_first_node = m_first_node->m_next;
			m_first_node->m_prev = nullptr;
		}
	}
	else if (target_node == m_last_node)
	{
		if (m_last_node->m_prev)
		{
			m_last_node = m_last_node->m_prev;
			m_last_node->m_next = nullptr;
		}
	}
	else 
	{
		nodePTR before_node = target_node->m_prev;
		nodePTR after_node = target_node->m_next;

		before_node->m_next = after_node;
		after_node->m_prev = before_node;
	}

	delete target_node;
	m_length--;
	return data;
}

template<typename T>
T List<T>::pop()
{
	nodePTR target_node = m_last_node;
	nodePTR before_node = m_last_node->m_prev;
	
	T data = m_last_node->m_data;
	
	if(before_node != NULL)
	{
		m_last_node = before_node;
		m_last_node->m_next = nullptr;
	}
	
	delete target_node;
	m_length--;
	return data;
}

// Inserts a new node with given data after given index
template<typename T>
void List<T>::insert_after(T data, int index)
{
	// If true, then given index is out of range
	if (index > last_index())
	{
		std::cerr << "[+] ERROR: Index " << index << " out of range for list that is of size " << m_length << std::endl;
		exit(-1);
	}

	// If true, then we just need to append a new node.
	if (index == last_index() || m_length == 0)
	{
		append(data);
		// DO NOT INCREMENT LENGTH AS THIS IS ALREADY DONE IN APPEND METHOD
	}
	else
	{
		
		nodePTR n_node = new_node<T>(); // New node
		nodePTR target_node = get_node_at_index(index); // Node to insert n_node after
		nodePTR after_node = target_node->m_next;
		
		n_node->m_data = data;
		n_node->m_prev = target_node;
		n_node->m_next = after_node;

		target_node->m_next = n_node;
		after_node->m_prev = n_node;
		m_length++;
	}
}


// Inserts a new node with given data before given index
template<typename T>
void List<T>::insert_before(T data, int index)
{	
	// If true, then index is out of range
	if (index > last_index())
	{
		std::cout << "[-] ERROR: Index " << index << " out of range for list that is of length " << m_length << std::endl;
		exit(-1);
	}
	
	// DO NOT INCREMENT SIZE AS THIS IS DONE IN PREPEND AND INSERT_AFTER METHODS
	if (index == 0)
	{
		prepend(data);
	}
	else
	{
		insert_after(data, index - 1);
	}
}

// Returns the list size in bytes
template<typename T>
int List<T>::size_bytes()
{
	int size = 0;
	nodePTR current_node = m_first_node;
	while (current_node != NULL)
	{
		nodePTR next_node = current_node->m_next;
		current_node = next_node;
		size += sizeof(Node<T>);
	}
	return size;
}


/* Constructor and destructor functions */

// Default
template<typename T>
List<T>::List(void){};

// Initialize list with values of passed array
template<typename T>
List<T>::List(T init_arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		append(init_arr[i]);
	}
}

// Destroy list when it goes out of scope.
template<typename T>
List<T>::~List()
{
	if (size_bytes() > sizeof(Node<T>))
	{
		nodePTR current_node = m_first_node;
		while (current_node != nullptr)
		{
			nodePTR target_node = current_node;
			
			if (target_node != nullptr)
			{
				delete target_node;
			}
			
			current_node = current_node->m_next;
		}
	}
}