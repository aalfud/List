#include <iostream>
#include <stdlib.h>
#include <list>

typedef std::list<int> ListInt;
//using ListInt = std::list<int>;

typedef std::list<int>::iterator ListInt_IT;
using Listint_ReverseIT = std::list<int>::reverse_iterator;


int GetReverse(ListInt data, int m)
{
	int cnt = 0;

	ListInt tempList;
	tempList = data;

	ListInt_IT it;
	ListInt_IT tempit;
	tempit = tempList.begin();

	for (it = data.begin(); it != data.end(); it++) 
	{

		if (cnt > m)
			++tempit;

		++cnt;
	}


	return *tempit;
}


int UseReverseIterator(ListInt data, int m) 
{
	auto r_IT=data.rbegin();

	for (; (r_IT != data.rend()) && (m > 0); ++r_IT, --m);

	return *r_IT;
}

int main() 
{
	ListInt list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	

	std::cout << GetReverse(list, 3) << std::endl;
	std::cout << UseReverseIterator(list, 3) << std::endl;
	getchar();

	return 0;
}