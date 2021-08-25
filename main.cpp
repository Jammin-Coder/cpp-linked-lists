#include "LinkedList.cpp"

#define str const char*

int main()
{
	List<int> int_list = List<int>(1);
	List<str> str_list = List<str>("Hey");
	
	int_list.append(2);
	str_list.append("HECK YEAH BABY!!");
	std::cout << int_list.at(1) << std::endl;
	
	std::cout << str_list.at(1) << std::endl;
}



