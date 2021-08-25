#include "utils.hpp"


template<typename T>
class Node
{
private:
	#define nodePTR Node<T>*

public:
	T m_data = nullptr;
	int m_index;
	nodePTR m_prev = nullptr;
	nodePTR m_next = nullptr;
};




