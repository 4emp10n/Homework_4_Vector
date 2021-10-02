#include <iostream>
#include "Vector.h"

using namespace std;



int main()
{
	Vector<int> v;
	Vector<int> v2;

	
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for (int i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}

v.printVec();
	
	



	
	return 0;
}

