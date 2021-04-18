#include <iostream>
#include "linkedLists.h"

using namespace std;


int main()
{
	List nums;
	
	int count = 10;

	for(int i = 0; i <= count; i++)
	{
		nums.append(i);
		cout << "Appended " << i << endl;
	}
	nums.slice(5, 8);
	nums.print();
	nums.slice(2, 4);
	nums.print();


}
