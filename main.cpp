#include "LinkedList.cpp"

#define str const char*


int main()
{   
    std::cout << "\n\n-------- LIST DEMO --------\n" << std::endl;

    List<int> demo_list = List<int>();
    demo_list.append(1); // Append 1 to demo_list
    demo_list.append(2); // Append 2 to demo_list
    demo_list.append(3); // Append 3 to demo_list

    demo_list.insert_after(10, demo_list.last_index()); // Inserts 10 after last index of demo_list
    demo_list.insert_before(-1, 1); // Inserts -1 before index 0 of demo_list

    int demo_list_len = demo_list.length();
    for (int i = 0; i < demo_list_len; i++)
    {
        std::cout << "[+] In demo_list, element at index " << i \
        << " is " << demo_list.at(i) << std::endl;
    }

    std::cout << "[+] The length of demo_list is " << demo_list.length() << std::endl;

    std::cout << "\n\n-------- STRING LIST DEMO --------\n" << std::endl;
    
    /* This will create a list of strings */
    str str_arr[] = {
        "Yo this is kinda neat.",
        "Heck yeah, baby... it's gettin real.",
        "Is this cool? Yes or yes..."
    };

    // Create new string list with first 3 values set to that of str_arr
    List<str> str_list = List<str>(str_arr, 3);
    std::cout << "[+] Here are the contents of str_list." << std::endl;
    str_list.print(); // Print str_list
    std::cout << std::endl;

    std::cout << "\n\n-------- LIST OF LISTS DEMO --------\n" << std::endl;
    /* This produces a 2 demensional list of integers */
    // Create linked list with an array of ints
    int int_arr[] = {1, 2, 3, 4, 5};
    int int_arr2[] = {6, 7, 8, 9, 10};
	List<int> int_list1 = List<int>(int_arr, 5);
    List<int> int_list2 = List<int>(int_arr2, 5);

    // Create a linked list to store pointers to lists of ints
    List<List<int>*> list_of_lists = List<List<int>*>();

    // Append the address of int_list to list_of_list
    list_of_lists.append(&int_list1);
    list_of_lists.append(&int_list2);

    // Prints the addresses of all of the lists stored in list_of_list
    std::cout << "[+] The contents of list_of_lists are:" << std::endl;
    list_of_lists.print();

    std::cout << std::endl;

    // This is a pointer to the first list stored in list_of_lists
    List<int>* p_int_list1 = list_of_lists.at(0);

    // Get the value of index 3 in p_int_list1
    int dereferenced_value = p_int_list1->at(3);
    std::cout << "[+] The value of p_int_list1->at(3) is " << dereferenced_value << std::endl;

    // Access the value of the first list in list_of_list 
    // then access the second value of the returned item
    List<int>* p_int_list2 = list_of_lists.at(1);

    std::cout << "[+] Address of int_list in list_of_list is " \
    << p_int_list2 << std::endl;

    std::cout << "[+] Dereferenced value of " << p_int_list2 << " is " \
    << p_int_list2->at(3) << std::endl;
}



