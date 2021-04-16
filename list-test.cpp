#include <iostream>
#include "linkedLists.h"

using namespace std;


int main()
{
	List nums;
	
	int count = 100;
	
	for(int i = 0; i < count; i++)
	{
		nums.append(i);
		cout << "Appended " << i << endl;
	}
	for(int i = 0; i < count; i++)
	{
		int num = nums.remell(0);
		cout << "Removed " << num << endl;
	}
	
}
