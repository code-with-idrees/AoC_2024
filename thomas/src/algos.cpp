#include "algos.h"
#include <functional>
#include <iostream>
#include <tuple>

bool sort_vector(std::vector<int>* p_vec, e_sort_order order)
{
	if (p_vec == nullptr)
	{
		return false;
	}

	std::function<int(int, int)> sort_function;
	
	switch (order)
	{
		case (ASCENDING):
		{
			sort_function = [](int a, int b) { return a < b; };
		} break;

		case (DESCENDING):
		{

			sort_function = [](int a, int b) { return a > b; };
		} break;

		default: return false;
	}
	
	std::sort(p_vec->begin(), p_vec->end(), sort_function);
	return true;
}

std::unordered_map<int, int> create_occurance_table(std::vector<int>* p_vec)
{
	std::unordered_map<int, int> otable;
	int x = 0;
	int occurances = 1;
	std::vector<int> vec = *p_vec;
	for (auto it = std::begin(vec); it < std::end(vec); it++)
	{
		x = *it;
		if (((it + 1) < std::end(vec)) && (*(it + 1) == x))
		{
			occurances++;
		}
		else
		{
			otable[x] = occurances;
			occurances = 1;
		}
	}

	return otable;
}
