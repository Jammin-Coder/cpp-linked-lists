#include <iostream>
#include <string>

using namespace std;

// Some of this code is inspired by someone else who made a post about linked lists, but I forget who it was, when I find the post again, I will give proper attribution.

class List
{
private:
	typedef struct Node
	{
		int data;
		struct Node* next;
		struct Node* prev;
	} node;
	
	node* list()
	{
		node* head = NULL;
		head = (node*)malloc(sizeof(node));

		head->data = 0; // This just initializes the list the first time, so it's ignored.
		head->next = NULL;
		head->prev = NULL;

		return head;
	}
	
	// Private variables.
	int m_size = 0;
	int m_maxIndex = m_size - 1;
	node* m_head = list();
	node* m_first = m_head; // Sets the first list node to the current state of m_head
	node* m_last = m_head;


public:
	// prints list
	void print()
	{
		m_head = m_first;
		// The list function initializes the list
		// with 0, so when the list is printed, we skip the first one.
		if(m_size != 0)
		{
			if(m_head->next !=  NULL)
			{
				m_head = m_head->next;
			}
			while(m_head != NULL)
			{
				printf("%d, ", m_head->data);
				m_head = m_head->next;
			}
		} else
		{
			printf("[-] Nothing in list.\n");
			exit(0);
		}
		printf("\n");
	}

	// removes element from given index
	void remell(int index)
	{
		m_head = m_first;
		if(index != 0)
		{
			m_head = m_head->next; // skip the first one, it's just the initializer.
		}
		if(m_head->next == NULL)
		{
			printf("ERROR: Cannot remove from empty list.\n");
			exit(1);
		}
		
		for(int i = 0; i <= index; i++)
		{	
			if (i == index - 1 || index == 0)
			{
				if(m_head != NULL)
				{
					node* targetHead = m_head->next;
					
					if(targetHead->next != NULL)
					{
						node* nextHead = targetHead->next;
						nextHead->prev = m_head; // New head-prev pointer = current head
						m_head->next = nextHead; // current head-next pointer = nextHead
						
						free(targetHead);
						m_size--;
						break;
					}
					// Target head is last item in list, do this...
					else
					{
						m_head->next = NULL;
						free(targetHead);
						m_size--;
						break;
					}
				}
			}
			m_head = m_head->next;
		}
		
	}

	int index(int index)
	{
		m_head = m_first;
		if (index > m_size - 1)
		{
			cout << "[ERROR] No element at index " << index << "!!!\n";
			cout << "The length of the list you are accessing is only " << m_size << endl;
			exit(1);
		}
		if(m_head->next != NULL)
		{
			m_head = m_head->next;
		}
		for(int i = 0; i <= index; i++)
		{
			if(i == index)
			{
				return m_head->data;
			}
			m_head = m_head->next;
		}
		exit(1);
	}
	
	// appends to list
	void append(int value)
	{
		node* nextNode = list();
		m_last->next = nextNode;
		nextNode->prev = m_last;
		nextNode->data = value;
		m_last = nextNode;

		m_size++;
	}


	int size()
	{
		return m_size;
	}
};



int main()
{
	List nums;
	
	for(int i = 0; i < 10; i++)
	{
		nums.append(i + 13);
		nums.print();
	}
	
	return 0;
}



