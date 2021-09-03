#include "LinkedList.cpp"

#define str const char*

template<typename T>
void log(T data)
{
    std::cout << data << std::endl;
}


List<int> return_list()
{
    List<int> list = List<int>();
    
    for (int i = 0; i < 10; i++)
    {
        list.append(i);
    }
    
    return list;
}

template<typename T>
void print_list(List<T>* lst)
{
    for (int i = 0; i < lst->length; i++)
    {
        log(lst->at(i));
    }
}


int main()
{
	List<int> list = return_list();
	
	const char* word_arr[] = {"Hey", "This is cool", "sup", "yo", ":D"};
	int words_size = sizeof(word_arr)/sizeof(const char*);
	
	
	List<const char*> words = List<const char*>(word_arr, words_size);
	
	print_list(&words);
    
}



