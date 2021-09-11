#include "utils.hpp"
#include "NodeUtils.cpp"


template<typename T>
class List
{
private:

    bool has_initialized = false;

public:
	#define nodePTR Node<T>*
	
	int length = 0;

	nodePTR first_node = new_node<T>();
	nodePTR last_node = first_node;
	
	int last_index()
	{
	    if (length > 0)
	    {
		    return length - 1;
		} 
		else 
		{
		    return -1;
		} 
	}

	nodePTR get_node_at_index(int index)
	{
	    if (index > last_index())
		{
			// << "\tList's highest index is " << last_index() << " but you supplied " << index 
			std::cout << "[-] ERROR: Index out of range." << std::endl;
		}
		
		/*
		* If length is greater than 4 and index less than or equal to
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
			nodePTR current_node = last_node;
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
	
	void print()
	{
		std::cout << "[";

		for(int i = 0; i < length; i++)
		{
			std::cout << at(i);
			if (i != last_index())
				std::cout << ", ";
		}
		
		std::cout << "]" << std::endl;
	}
	
	T at(int index)
	{
		nodePTR node = get_node_at_index(index);
		return node->m_data;
	}
	
	void prepend(T data)
	{
	    if (has_initialized)
	    {
		    // New node to be prepended
		    nodePTR node = new_node<T>();
		    
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
		}
		else 
		{
		    first_node->m_data = data;
			has_initialized = true;
		}
		
		length++;
	}
	
	void append(T data)
	{
	    if (has_initialized)
	    {
		    // New node that will be appended
		    nodePTR node = new_node<T>();
		    
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
		}
		
		else 
		{
		    first_node->m_data = data;
		    has_initialized = true;
		}
		
		length++;
		
	}
	
	void insert_after(T data, int index)
	{	
		if (index > last_index())
		{
			std::cerr << "[+] ERROR: Index " << index << " out of range for list that is of size " << length << std::endl;
			exit(-1);
		}

		if (index == last_index() || length == 0)
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
			length++;
		}
	}

	void insert_before(T data, int index)
	{
		if (index > last_index())
		{
			std::cout << "[-] ERROR: Index " << index << " out of range for list that is of length " << length << std::endl;
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

	T remove(int index)
	{
	    nodePTR target_node = get_node_at_index(index);
	    T data = target_node->m_data;
	    
	    nodePTR before_node = target_node->m_prev;
	    nodePTR after_node = target_node->m_next;

        if (before_node)
        {
	        before_node->m_next = after_node;
	    }
	     
	    if (after_node)
	    {   
	        after_node->m_prev = before_node;
	    }
	    
	    delete target_node;
	    return data;
	}
	
	T pop()
	{
	    nodePTR target_node = last_node;
	    nodePTR before_node = last_node->m_prev;
	    
	    T data = last_node->m_data;
	    
	    if(before_node != NULL)
	    {
	        last_node = before_node;
	        last_node->m_next = nullptr;
	    }
	    
	    delete target_node;
	    length--;
	    return data;
	}
	
	int size_bytes()
	{
	    int size = 0;
	    nodePTR current_node = first_node;
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
	List(void){};
	
	// Initialize list with values of passed array
	List(T init_arr[], int size)
	{
	    for (int i = 0; i < size; i++)
	    {
	        append(init_arr[i]);
	    }
	}
	
	// Destroy list when it goes out of scope.
	~List()
	{
	    nodePTR current_node = first_node;
	    int removed_items = 0;
	    while (current_node != nullptr)
	    {
            nodePTR target_node = current_node;
            
            if (target_node != nullptr)
            {
                delete target_node;
                removed_items++;
            }
            
            current_node = current_node->m_next;
	    }
	}
	
};

