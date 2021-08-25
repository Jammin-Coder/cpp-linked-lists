#include "utils.hpp"
#include "NodeUtils.cpp"


template<typename T>
class List
{
private:
	int list_size;
	

	int last_index()
	{
		return list_size - 1;
	}

public:
	
	#define nodePTR Node<T>*
	
	
	nodePTR first_node = new_node<T>(last_index());
	nodePTR last_node = first_node;
	
	
	void print()
	{
		nodePTR current_node = first_node;
		std::cout << "[";
		
		for(int i = 0; i < list_size; i++)
		{
			if(&current_node->m_data != NULL)
			{
				std::cout << current_node->m_data;
				nodePTR next_node = current_node->m_next;
				current_node = next_node;
			}
			else break;
			
			if (i != last_index())
				std::cout << ", ";
		}
		
		std::cout << "]" << std::endl;
	}
	
	T at(int index)
	{
		if (index > last_index())
		{
			// << "\tList's highest index is " << last_index() << " but you supplied " << index 
			std::cout << "[-] ERROR: Index out of range." << std::endl;
		}
		
		/*
		* If list_size is greater than 4 and index less than or equal to
		* the last index divided by 2, then the wanted index is located in
		* the lower half of the list.
		*/
		if (index <= last_index()/2)
		{
			/*
			* Start at the beggining of the list and iterates forward over list
			* elements until desired index is reached,
			* and then return the data contained within the list node at the index.
			*/
			nodePTR current_node = first_node;
			for (int i = 0; i <= index; i++)
			{
				if(&current_node->m_next != NULL)
				{
					if (i == index)
					{
						return current_node->m_data;
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
			nodePTR current_node = last_node;
			for (int i = last_index(); i >= index; i--)
			{
				if(&current_node->m_data != NULL)
				{
					if (i == index)
					{
						return current_node->m_data;
					}
					nodePTR prev_node = current_node->m_prev;
					current_node = prev_node;
				}
			}
		}
		std::cout << "[-] ERROR: Something went wrong while accessing list element at index " << index << std::endl;
		exit(-1);
	}
	
	void prepend(T data)
	{
		// New node to be prepended
		nodePTR node = new_node<T>(last_index());
		
		// Sets the new node's previous node to that of the first node
		node->m_prev = first_node->m_prev;
		
		// Sets the previous node of the first node to the new node
		first_node->m_prev = node;
		
		// Sets the new node's next node to the first_node
		node->m_next = first_node;
		
		// Assignes the given data to the new node's data member
		node->m_data = data;
		
		// Sets the first node to the new node
		first_node = node;
		
		list_size++;
	}
	
	void append(T data)
	{
		// New node that will be appended
		nodePTR node = new_node<T>(last_index());
		
		// Sets the new node's next node to the last_node's next node.
		node->m_next = last_node->m_next;
		
		// Sets the new node's previous node to the last node
		node->m_prev = last_node;
		
		// Sets the last_node's next node to the new node
		last_node->m_next = node;
		
		// Assignes the given data to the new node's data member
		node->m_data = data;
		
		// Updates last_node to the new node 
		last_node = node;
		
		list_size++;
	}
	
	
	List(T data)
	{
		first_node->m_next = last_node;
		first_node->m_data = data;
		list_size++;
	}
	
};




