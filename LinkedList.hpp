#include "utils.hpp"
#include "NodeUtils.cpp"

template<typename T>
class List
{
public:
    #define nodePTR Node<T>*
    bool m_has_initialized = false;

    int m_length = 0; // Length of list

	nodePTR m_first_node = new_node<T>();
	nodePTR m_last_node = m_first_node;

    // Methods
    int last_index(); // Returns the last valid index for the list
    nodePTR get_node_at_index(int index); // Returns the node at the given index
    void print(); // Prints all contents of list
    T at(int index); // Returns the data held in node at given index

    // Modifier methods
    void prepend(T data); // Prepends given data to list
    void append(T data); // Appends given data to list
    void insert_after(T data, int index); // Inserted given data after given index
    void insert_before(T data, int index); // Inserts given data before given index
    T remove(int index); // Removes node from list at given index
    T pop(); // Removes last node and returns its data
    int size_bytes(); // Returns the list's size in bytes

    // Constructor and destructor functions
    List(void); // Default initialization

    // Sets the first elements of the list to those of the passed array
    List(T initializer_array[], int arr_size);
    ~List(); // Destroys the list and restores used memory
};